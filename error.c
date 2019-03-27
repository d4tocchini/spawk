
/********************************************
error.c
copyright 1991, 1992,2014-2016 Michael D. Brennan

This is a source file for mawk, an implementation of
the AWK programming language.

Mawk is distributed without warranty under the terms of
the GNU General Public License, version 3, 2007.

If you import elements of this code into another product,
you agree to not name that product mawk.
********************************************/

#include <stdarg.h>
#include "mawk.h"
#include "scan.h"
#include "bi_vars.h"

static void         rt_where( void );
static const char * type_to_str( int );

/* for run time error messages only */
unsigned rt_nr, rt_fnr;

/* generic error message with a hook into the system error
   messages if errnum > 0 */

void
errmsg( int errnum, const char * format, ... )
{
    va_list args;
    fprintf( stderr, "%s: ", progname );
    va_start( args, format );
    vfprintf( stderr, format, args );
    va_end( args );

    if ( errnum > 0 )
        fprintf( stderr, " (%s)", strerror( errnum ) );

    fprintf( stderr, "\n" );
    fflush( stderr );
}

void
compile_error( const char * format, ... )
{
    va_list      args;
    const char * s0;
    const char * s1;

    /* with multiple program files put program name in
       error message */
    if ( pfile_name ) {
        s0 = pfile_name;
        s1 = ": ";
    }
    else {
        s0 = s1 = "";
    }

    fprintf( stderr, "%s: %s%sline %u: ", progname, s0, s1, token_lineno );
    va_start( args, format );
    vfprintf( stderr, format, args );
    va_end( args );
    fprintf( stderr, "\n" );
    fflush( stderr );
    if ( ++compile_error_count == MAX_COMPILE_ERRORS )
        mawk_exit( 2 );
}

void
call_error( unsigned lineno, const char * format, ... )
{
    va_list      args;
    const char * s0 = pfile_name;
    const char * s1 = ": ";

    if ( !pfile_name ) {
        s0 = s1 = "";
    }

    fprintf( stderr, "%s: %s%sline %u: ", progname, s0, s1, lineno );
    va_start( args, format );
    vfprintf( stderr, format, args );
    va_end( args );
    fprintf( stderr, "\n" );
    fflush( stderr );
    if ( ++compile_error_count == MAX_COMPILE_ERRORS )
        mawk_exit( 2 );
}

void
rt_error( const char * format, ... )
{
    va_list args;

    fprintf( stderr, "%s: run time error: ", progname );
    va_start( args, format );
    vfprintf( stderr, format, args );
    va_end( args );
    fputc( '\n', stderr );
    rt_where();
    mawk_exit( 2 );
}

void
compile_or_rt_error( const char * format, ... )
{
    /* up to caller not to exceed this buffer */
    char    buffer[1024];
    va_list args;

    va_start( args, format );
    vsprintf( buffer, format, args );
    if ( mawk_state == EXECUTION ) {
        rt_error( buffer );
    }
    else {
        compile_error( buffer );
    }
}

void
bozo( const char * s )
{
    errmsg( 0, "bozo: %s", s );
    mawk_exit( 3 );
}

void
overflow( const char * s, unsigned size )
{
    errmsg( 0, "program limit exceeded: %s size=%u", s, size );
    mawk_exit( 2 );
}

/* print as much as we know about where a rt error occured */

static void
rt_where( void )
{
    if ( FILENAME->type != C_STRING )
        cast1_to_s( FILENAME );

    fprintf( stderr, "\tFILENAME=\"%s\" FNR=%u NR=%u\n",
             string( FILENAME )->str, rt_fnr, rt_nr );
}

/* run time */
void
rt_overflow( const char * s, unsigned size )
{
    errmsg( 0, "program limit exceeded: %s size=%u", s, size );
    rt_where();
    mawk_exit( 2 );
}

static const char *
type_to_str( int type )
{
    const char * retval;

    switch ( type ) {
        case ST_VAR:
            retval = "variable";
            break;
        case ST_ARRAY:
            retval = "array";
            break;
        case ST_FUNCT:
            retval = "function";
            break;
        case ST_LOCAL_VAR:
            retval = "local variable";
            break;
        case ST_LOCAL_ARRAY:
            retval = "local array";
            break;
        default:
            bozo( "type_to_str" );
            /* not reached */
            retval = 0;
    }
    return retval;
}

/* emit an error message about a type clash */
void
type_error( SYMTAB * p )
{
    compile_error( "illegal reference to %s %s",
                   type_to_str( p->type ), p->name );
}
