
/********************************************
init.c
copyright 1991,2014-2016 Michael D. Brennan

This is a source file for mawk, an implementation of
the AWK programming language.

Mawk is distributed without warranty under the terms of
the GNU General Public License, version 3, 2007.

If you import elements of this code into another product,
you agree to not name that product mawk.
********************************************/

/* init.c */
#include <signal.h>
#include <stdbool.h>
#include "mawk.h"
#include "code.h"
#include "memory.h"
#include "symtype.h"
#include "init.h"
#include "bi_vars.h"
#include "field.h"

static void process_cmdline( int, char ** );
static void set_ARGV( int, char **, int );
static void exit_bad_option( const char * );
static void exit_no_program( void );
static void print_help( void );
static void catch_fpe( int );

extern void print_version( void );
extern int  is_cmdline_assign( char * );

#if MSDOS
void stdout_init( void );
#if HAVE_REARGV
void reargv( int *, char *** );
#endif
#endif

const char * progname;
int          interactive_flag = 0;

#ifndef SET_PROGNAME
#define SET_PROGNAME()                      \
    {                                       \
        char * p = strrchr( argv[0], '/' ); \
        progname = p ? p + 1 : argv[0];     \
    }
#endif

static void
buffer_init( void )
{
    string_buff     = (char *)emalloc( SPRINTF_LIMIT );
    string_buff_end = string_buff + SPRINTF_LIMIT;
}

void
initialize( int argc, char ** argv )
{

    SET_PROGNAME();

    buffer_init();
    bi_vars_init();  /* load the builtin variables */
    bi_funct_init(); /* load the builtin functions */
    kw_init();       /* load the keywords */
    field_init();

#if MSDOS
    {
        char * p = getenv( "MAWKBINMODE" );

        if ( p )
            set_binmode( atoi( p ) );
    }
#endif

    process_cmdline( argc, argv );

    code_init();
    signal( SIGFPE, catch_fpe );
    set_stdoutput();

#if MSDOS
    stdout_init();
#endif
}

int dump_code_flag; /* if on dump internal code */
int posix_space_flag;

#ifdef DEBUG
int dump_RE = 1; /* if on dump compiled REs  */
#endif

// #define optarg optarg_ /* remove conflict with optarg in <getopt.h> */

#define MAWKCLI_REQ_ARG_VAL( ARGKEY )                         \
    do {                                                        \
        if ( ++i == argc ) {                                    \
            errmsg( 0, "arg key missing val: %s", ( ARGKEY ) ); \
            mawk_exit( 2 );                                     \
        }                                                       \
    } while ( 0 )


static void
process_cmdline( int argc, char ** argv )
{
   
    int     i;
    PFILE   dummy; /* starts linked list of filenames */
    PFILE * tail = &dummy;

    for ( i = 1; i < argc && argv[i][0] == '-'; ) {

        const char c1 = argv[i][1];
        if ( c1 == 0 ) { // -  alone
            if ( !pfile_name )
                exit_no_program();
            break;
        }
        // safe to look at argv[i][2]
        const char c2          = argv[i][2];
        const bool isdubdash   = c1 == '-';
        const bool ismultichar = c2 != 0;
        const char c           = isdubdash && ismultichar
                           ? c2
                           : c1;

        switch ( c ) {

            case 'i':
                interactive_flag = 1;
                setbuf( stdout, (char *)0 );
                i++;
                continue;

            case '-':
                i++;
                goto no_more_opts;

            case 'F':
                MAWKCLI_REQ_ARG_VAL( "-F --FS field_separator" );
                {
                    // recognize escape sequences
                    const size_t len = rm_escape( argv[i] );
                    cell_destroy( FS );
                    FS->type = C_STRING;
                    FS->ptr  = new_STRING2( argv[i], len );
                    cast_for_split(
                        cellcpy( &fs_shadow, FS )
                    );
                }
                i++;
                continue;

            case 'f':
                // TODO: ASSERT -e option not set
                // first file goes in pfile_name ; any more go on a list
                MAWKCLI_REQ_ARG_VAL( "-f file" );
                if ( !pfile_name )
                    pfile_name = argv[i];
                else {
                    tail = tail->link = ZMALLOC( PFILE );
                    tail->fname       = argv[i];
                }
                i++;
                continue;

            case 'e':
                // -e --exec file
                MAWKCLI_REQ_ARG_VAL( "-e --exec file" );
                if ( pfile_name ) {
                    errmsg( 0, "--exec is incompatible with -f" );
                    mawk_exit( 2 );
                }
                pfile_name = argv[i];
                i++;
                goto no_more_opts;

            case 'v':
                // --version
                if (ismultichar) {
                    print_version();
                    i++;
                }

                // -v var=val
                else {
                    MAWKCLI_REQ_ARG_VAL( "-v var=val" );
                    if ( !is_cmdline_assign( argv[i] ) ) {
                        errmsg( 0, "improper assignment: -v %s", argv[i] );
                        mawk_exit( 2 );
                    }
                    i++;
                }
                continue;

            case 'h':
                // -h --help
                print_help();
                i++;
                continue;

            case 'd':
                // -d --dump
                dump_code_flag = 1;
                i++;
                continue;

            case 'p':
                posix_space_flag     = 1;
                posix_repl_scan_flag = 1;
                i++;
                continue;

#if MSDOS
            case 'b':

                // --bin-mode=...?
                if (ismultichar) {
                    char * p = strchr( argv[i], '=' );
                    int    x = p ? atoi( p + 1 ) : 0;
                    set_binmode( x );
                    i++;
                }
                // -b ...?
                // -bin-mode ...?
                else {
                    MAWKCLI_REQ_ARG_VAL( "-b bin-mode" );
                }
                continue;
#endif
            case 's': // -s !!OBSELETE!!
                i++;
                continue;
            default:
                exit_bad_option( argv[i] );
        }


        // TODO:
        // else { // argument glued to option
        //     optarg  = &argv[i][2];
        //     nextarg = i + 1;
        // }
    }

no_more_opts:

    tail->link = (PFILE *)0;
    pfile_list = dummy.link;

    if ( pfile_name ) {
        set_ARGV( argc, argv, i );
        scan_init( (char *)0 );
    }
    else /* program on command line */
    {
        if ( i == argc )
            exit_no_program();
        set_ARGV( argc, argv, i + 1 );

#if MSDOS && !HAVE_REARGV /* reversed quotes */
        {
            char * p;

            for ( p = argv[i]; *p; p++ )
                if ( *p == '\'' )
                    *p = '\"';
        }
#endif
        scan_init( argv[i] );
        /* #endif  */
    }
}

static void
set_ARGV( int argc, char ** argv, int i )
/* argv[i] = ARGV[i] */
{
    SYMTAB *        st_p;
    CELL            argi;
    register CELL * cp;

    st_p       = insert( "ARGV" );
    st_p->type = ST_ARRAY;
    Argv = st_p->stval.array = new_ARRAY();
    argi.type                = C_DOUBLE;
    argi.dval                = 0.0;
    cp                       = array_find( st_p->stval.array, &argi, CREATE );
    cp->type                 = C_STRING;
    cp->ptr                  = (PTR)new_STRING( argv[0] );

    /* ARGV[0] is set, do the rest
     The type of ARGV[1] ... should be C_MBSTRN
     because the user might enter numbers from the command line */

    for ( argi.dval = 1.0; i < argc; i++, argi.dval += 1.0 ) {
        cp       = array_find( st_p->stval.array, &argi, CREATE );
        cp->type = C_MBSTRN;
        cp->ptr  = (PTR)new_STRING( argv[i] );
    }
    ARGC->type = C_DOUBLE;
    ARGC->dval = argi.dval;
}

/*----- ENVIRON ----------*/

void
load_environ( ARRAY ENV )
{
    CELL             c;
    extern char **   environ;
    register char ** p = environ; /* walks environ */
    char *           s;           /* looks for the '=' */
    CELL *           cp;          /* pts at ENV[&c] */

    c.type = C_STRING;

    while ( *p ) {
        if ( ( s = strchr( *p, '=' ) ) ) /* shouldn't fail */
        {
            int len = s - *p;
            c.ptr   = (PTR)new_STRING0( len );
            memcpy( string( &c )->str, *p, len );
            s++;

            cp       = array_find( ENV, &c, CREATE );
            cp->type = C_MBSTRN;
            cp->ptr  = (PTR)new_STRING( s );

            free_STRING( string( &c ) );
        }
        p++;
    }
}

/*  FPE exceptions

mawk 1.x.x  in 199x tried hard to catch fpe when necessary,
      have optimal settings and
      maximize information passed to user

      What to do in 201x?

      Odds of fpe in an awk program is verrrrrrrrrry small
      probablity it generates an INF or NAN is at least .9
          probably higher

    Since an fpe is unlikely, mawk 2.x.x will deal with 
    it very simply.

*/

static void
catch_fpe( int x )
{
    if ( x == SIGFPE ) {
        rt_error( "floating point arithmetic exception" );
    }
    else
        bozo( "catch_fpe" );
    mawk_exit( 2 );
}

static void
exit_bad_option( const char * s )
{
    errmsg( 0, "not an option: %s", s );
    mawk_exit( 2 );
}

static void
exit_no_program( void )
{
    mawk_exit( 0 );
}

/*   HELP  */

/* to change this
   edit help.txt
   run $ mawk -f help.awk help.txt > out
   with an editor put out into help[]
*/

static const char * const help[] = {
    "Usage:",
    "\tmawk [--help]",
    "\tmawk [--version]",
    "\tmawk [-W option] [-F value] [-v var=value] [--] 'program text' file(s)",
    "\tmawk [-W option] [-F value] [-v var=value] [-f program-file] [--] file(s)",
    "",
    "Generic options:",
    "",
    "\t--help         displays this help message and exits 0.",
    "",
    "\t--version      displays mawk version and exits 0.",
    "",
    "Normal awk-implementation options:",
    "",
    "\t-F value       sets the field separator, FS, to value.",
    "",
    "\t-f file        program text is read from file instead of from the",
    "\t               command line.  Multiple -f options are allowed.",
    "",
    "\t-v var=value   assigns value to program variable var.",
    "",
    "\t--             indicates the unambiguous end of options.",
    "",
    "The above options are available with any IEEE 1003 POSIX-compatible",
    "implementation of AWK.  mawk-specific options are prefaced with -W.",
    "",
    "\t-W dump        writes an assembler-like listing of the internal",
    "\t               representation of the program to stdout and exits 0 (on",
    "\t               successful compilation).",
    "",
    "\t-W exec file   program text is read from file and this is the last",
    "\t               option.  It is useful on systems that support the",
    "\t               #! \"magic number\" convention for executable scripts.",
    "",
    "\t-W help        displays this help message and exits 0.",
    "",
    "\t-W interactive sets unbuffered writes to stdout and line buffered reads",
    "\t               from stdin.  Records from stdin are lines regardless of",
    "\t               the value of RS.",
    "",
    "\t-W posix       forces mawk not to consider '\\n' to be space and \\\\",
    "\t               is always \\ on the second scan of a replacement string.",
    "",
    "\t-W version     displays mawk version and exits 0.",
    "",
    "Just the first letter for each option is enough.  For example, -Wv, -W v ",
    "and --v are equivalent to -W version or --version.",
    0
};

static void
print_help()
{
    int i = 0;
    while ( help[i] ) {
        printf( "%s\n", help[i] );
        i++;
    }
    mawk_exit( 0 );
}
