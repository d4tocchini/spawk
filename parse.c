/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 19 "parse.y" /* yacc.c:337  */

#include <stdio.h>
#include "mawk.h"
#include "symtype.h"
#include "code.h"
#include "memory.h"
#include "bi_funct.h"
#include "bi_vars.h"
#include "jmp.h"
#include "field.h"
#include "files.h"
#include "scan.h"
#include "printf.h"

#define  YYMAXDEPTH	200

extern void     eat_nl(YYSTYPE *yylval) ;
static void     resize_fblock(FBLOCK *) ;
static void     code_array(SYMTAB *) ;
static void     code_call_id(CA_REC *, SYMTAB *) ;
static void     field_A2I(void) ;
static void     check_var(SYMTAB *) ;
static void     check_array(SYMTAB *) ;
static void     RE_as_arg(void) ;
       int      REempty(PTR) ;
static int      scope ;
static FBLOCK * active_funct ;
      /* when scope is SCOPE_FUNCT  */

#define  code_address(x)            if ( is_local(x) ) \
                                        code2op(L_PUSHA, (x)->offset) ;\
                                    else \
                                        code2(_PUSHA, (x)->stval.cp)

#define  CDP(x)                     (code_base+(x))
/* WARNING: These CDP() calculations become invalid after calls
   that might change code_base.  Which are:  code2(), code2op(),
   code_jmp() and code_pop().
*/

/* this nonsense caters to MSDOS large model */
#define  CODE_FE_PUSHA()            code_ptr->ptr = (PTR) 0 ; \
                                    code1(FE_PUSHA)


/* moves the active_code from MAIN to a BEGIN or END */

#define CODE_OPEN_BEGIN             _code_open_BEGIN(&scope)
#define CODE_OPEN_END               _code_open_END(&scope)
#define CODE_CLOSE_ACTIVE           _code_close_active(&scope)
#define CODE_CLOSE_BEGIN            _code_close_BEGIN(&scope)
#define CODE_CLOSE_END              _code_close_END(&scope)
#define CODE_CLOSE_ACTIVE           _code_close_active(&scope)
#define CODE_NOT_SCOPE(SCOPE, MSG)  if ( scope != SCOPE ) \
                                        compile_error("MSG") ;

static void
_code_open_BEGIN( int * scope ) {
    *scope = SCOPE_BEGIN ;
    *main_code_p = active_code;
    if ( !begin_code_p )
        begin_code_p = code_create_block();
    active_code = *begin_code_p;
}

static void
_code_open_END( int * scope ) {
    *scope = SCOPE_END ;
    *main_code_p = active_code;
    if ( !end_code_p )
        end_code_p = code_create_block();
    active_code = *end_code_p;
}

static inline void
__code_close_active( void ) {
    active_code = *main_code_p ;
    active_funct = (FBLOCK*) 0 ;
}

static void
_code_close_BEGIN(
    int * scope
    // CODEBLOCK * active_code_p
) {
    // *begin_code_p = *active_code_p ;
    *begin_code_p = active_code ;
	__code_close_active();
    *scope = SCOPE_MAIN ;
}

static void
_code_close_END(
    int * scope
    // CODEBLOCK * active_code_p
) {
    // *end_code_p = *active_code_p ;
    *end_code_p = active_code ;
	__code_close_active();
    *scope = SCOPE_MAIN ;
}

static void
_code_close_FUNCT(
    int * scope
) {
	__code_close_active();
    *scope = SCOPE_MAIN ;
}

/* reset the active_code back to the MAIN block */
static void
_code_close_active( int * scope ) // switch_code_to_main(void)
{
    switch (*scope) {
        case SCOPE_MAIN :
            __code_close_active();
            break ;
        case SCOPE_BEGIN :
	        _code_close_BEGIN(scope);
	        break ;
        case SCOPE_END :
	        _code_close_END(scope);
	        break ;
        case SCOPE_FUNCT :
            _code_close_FUNCT(scope);
            break ;
    }
//         case SCOPE_FUNCT :
// 	        active_code = *main_code_p ;
// 	        break ;
//         case SCOPE_MAIN :
// 	        break ;
//    }
//    active_funct = (FBLOCK*) 0 ;
//    scope = SCOPE_MAIN ;
}


#line 210 "y.tab.c" /* yacc.c:337  */
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    UNEXPECTED = 258,
    BAD_DECIMAL = 259,
    NL = 260,
    SEMI_COLON = 261,
    LBRACE = 262,
    RBRACE = 263,
    LBOX = 264,
    RBOX = 265,
    COMMA = 266,
    IO_OUT = 267,
    ASSIGN = 268,
    ADD_ASG = 269,
    SUB_ASG = 270,
    MUL_ASG = 271,
    DIV_ASG = 272,
    MOD_ASG = 273,
    POW_ASG = 274,
    QMARK = 275,
    COLON = 276,
    OR = 277,
    AND = 278,
    IN = 279,
    MATCH = 280,
    EQ = 281,
    NEQ = 282,
    LT = 283,
    LTE = 284,
    GT = 285,
    GTE = 286,
    CAT = 287,
    GETLINE = 288,
    PLUS = 289,
    MINUS = 290,
    MUL = 291,
    DIV = 292,
    MOD = 293,
    NOT = 294,
    UMINUS = 295,
    IO_IN = 296,
    PIPE = 297,
    POW = 298,
    INC_or_DEC = 299,
    DOLLAR = 300,
    FIELD = 301,
    LPAREN = 302,
    RPAREN = 303,
    DOUBLE = 304,
    STRING_ = 305,
    RE = 306,
    ID = 307,
    D_ID = 308,
    FUNCT_ID = 309,
    BUILTIN = 310,
    LENGTH = 311,
    PRINT = 312,
    PRINTF = 313,
    SPLIT = 314,
    MATCH_FUNC = 315,
    SUB = 316,
    GSUB = 317,
    SPRINTF = 318,
    DO = 319,
    WHILE = 320,
    FOR = 321,
    BREAK = 322,
    CONTINUE = 323,
    IF = 324,
    ELSE = 325,
    DELETE = 326,
    BEGIN = 327,
    END = 328,
    EXIT = 329,
    NEXT = 330,
    NEXTFILE = 331,
    RETURN = 332,
    FUNCTION = 333
  };
#endif
/* Tokens.  */
#define UNEXPECTED 258
#define BAD_DECIMAL 259
#define NL 260
#define SEMI_COLON 261
#define LBRACE 262
#define RBRACE 263
#define LBOX 264
#define RBOX 265
#define COMMA 266
#define IO_OUT 267
#define ASSIGN 268
#define ADD_ASG 269
#define SUB_ASG 270
#define MUL_ASG 271
#define DIV_ASG 272
#define MOD_ASG 273
#define POW_ASG 274
#define QMARK 275
#define COLON 276
#define OR 277
#define AND 278
#define IN 279
#define MATCH 280
#define EQ 281
#define NEQ 282
#define LT 283
#define LTE 284
#define GT 285
#define GTE 286
#define CAT 287
#define GETLINE 288
#define PLUS 289
#define MINUS 290
#define MUL 291
#define DIV 292
#define MOD 293
#define NOT 294
#define UMINUS 295
#define IO_IN 296
#define PIPE 297
#define POW 298
#define INC_or_DEC 299
#define DOLLAR 300
#define FIELD 301
#define LPAREN 302
#define RPAREN 303
#define DOUBLE 304
#define STRING_ 305
#define RE 306
#define ID 307
#define D_ID 308
#define FUNCT_ID 309
#define BUILTIN 310
#define LENGTH 311
#define PRINT 312
#define PRINTF 313
#define SPLIT 314
#define MATCH_FUNC 315
#define SUB 316
#define GSUB 317
#define SPRINTF 318
#define DO 319
#define WHILE 320
#define FOR 321
#define BREAK 322
#define CONTINUE 323
#define IF 324
#define ELSE 325
#define DELETE 326
#define BEGIN 327
#define END 328
#define EXIT 329
#define NEXT 330
#define NEXTFILE 331
#define RETURN 332
#define FUNCTION 333

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 159 "parse.y" /* yacc.c:352  */

    CELL     *      cp          ;
    SYMTAB   *      stp         ;
    int             start       ; /* code starting address as offset from code_base */
    PF_CP           fp          ; /* ptr to a (print/printf) or (sub/gsub) function */
    BI_REC   *      bip         ; /* ptr to info about a builtin */
    FBLOCK   *      fbp         ; /* ptr to a function block */
    ARG2_REC *      arg2p       ;
    CA_REC   *      ca_p        ;
    int             ival        ;
    PTR             ptr         ;

#line 422 "y.tab.c" /* yacc.c:352  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  100
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1451

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  79
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  61
/* YYNRULES -- Number of rules.  */
#define YYNRULES  186
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  367

#define YYUNDEFTOK  2
#define YYMAXUTOK   333

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   234,   234,   236,   236,   241,   242,   244,   245,   246,
     248,   250,   250,   254,   254,   259,   259,   264,   278,   264,
     286,   288,   293,   294,   300,   301,   303,   304,   306,   308,
     313,   317,   321,   323,   327,   333,   334,   337,   338,   340,
     342,   344,   346,   348,   350,   352,   354,   356,   358,   360,
     362,   364,   389,   389,   396,   396,   402,   404,   402,   410,
     411,   414,   417,   420,   429,   432,   436,   438,   440,   442,
     444,   446,   448,   451,   454,   457,   459,   467,   474,   479,
     486,   491,   493,   495,   497,   500,   521,   524,   535,   540,
     549,   552,   564,   572,   584,   597,   601,   604,   606,   610,
     614,   618,   622,   623,   627,   633,   636,   641,   645,   650,
     656,   674,   693,   709,   711,   715,   717,   731,   735,   743,
     747,   755,   768,   779,   796,   803,   810,   821,   833,   836,
     844,   854,   857,   861,   864,   865,   866,   867,   868,   869,
     870,   876,   879,   884,   886,   916,   920,   924,   927,   968,
     973,   989,   992,   995,   998,  1002,  1008,  1013,  1018,  1022,
    1028,  1030,  1031,  1033,  1036,  1042,  1058,  1060,  1064,  1067,
    1073,  1078,  1099,  1116,  1121,  1123,  1126,  1131,  1144,  1151,
    1167,  1169,  1181,  1183,  1189,  1196,  1200
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "UNEXPECTED", "BAD_DECIMAL", "NL",
  "SEMI_COLON", "LBRACE", "RBRACE", "LBOX", "RBOX", "COMMA", "IO_OUT",
  "ASSIGN", "ADD_ASG", "SUB_ASG", "MUL_ASG", "DIV_ASG", "MOD_ASG",
  "POW_ASG", "QMARK", "COLON", "OR", "AND", "IN", "MATCH", "EQ", "NEQ",
  "LT", "LTE", "GT", "GTE", "CAT", "GETLINE", "PLUS", "MINUS", "MUL",
  "DIV", "MOD", "NOT", "UMINUS", "IO_IN", "PIPE", "POW", "INC_or_DEC",
  "DOLLAR", "FIELD", "LPAREN", "RPAREN", "DOUBLE", "STRING_", "RE", "ID",
  "D_ID", "FUNCT_ID", "BUILTIN", "LENGTH", "PRINT", "PRINTF", "SPLIT",
  "MATCH_FUNC", "SUB", "GSUB", "SPRINTF", "DO", "WHILE", "FOR", "BREAK",
  "CONTINUE", "IF", "ELSE", "DELETE", "BEGIN", "END", "EXIT", "NEXT",
  "NEXTFILE", "RETURN", "FUNCTION", "$accept", "start", "$@1", "program",
  "program_block", "PA_block", "$@2", "$@3", "$@4", "$@5", "$@6", "block",
  "block_or_separator", "stmt_list", "statement", "separator", "expr",
  "$@7", "$@8", "$@9", "$@10", "cat_expr", "p_expr", "lvalue", "arglist",
  "args", "builtin", "string_comma", "mark", "pmark", "printf_args",
  "pr_args", "arg2", "pr_direction", "if_front", "else", "do",
  "while_front", "for1", "for2", "for3", "array_loop_front", "field",
  "split_front", "split_back", "re_arg", "return_stmt", "getline",
  "fvalue", "getline_file", "sub_or_gsub", "sub_back", "function_def",
  "funct_start", "funct_head", "f_arglist", "f_args", "outside_error",
  "call_args", "ca_front", "ca_back", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333
};
# endif

#define YYPACT_NINF -214

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-214)))

#define YYTABLE_NINF -122

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-122)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     378,  -214,   611,  -214,  1034,  1034,  1034,   -15,   848,  -214,
    1065,  -214,  -214,  -214,   387,  -214,  -214,   -38,   -11,    -2,
    -214,  -214,  -214,  -214,  -214,    23,    62,   688,   315,  -214,
    -214,  -214,  1354,  1034,   144,   318,  -214,   753,    -5,    33,
    1034,     8,  -214,    65,    42,    65,     6,  -214,  -214,  -214,
    -214,  -214,    51,    53,    -1,    -1,    59,    90,   755,    -1,
      -1,   755,  -214,   534,  -214,  -214,  1295,   688,   688,   688,
     786,   688,  -214,  1065,    20,   -27,    64,   -27,   -27,    41,
     135,  -214,  -214,   135,  -214,   449,    -4,   179,  -214,   137,
     107,   112,   879,  1065,  1065,   119,    65,    65,  -214,  -214,
    -214,    -1,   457,  -214,  -214,  -214,  -214,  -214,   116,  1065,
    1065,  1065,  1065,  1065,  1065,  1065,    98,   144,  1034,  1034,
    1034,  1034,  1034,   136,  1034,  1065,  1065,  1065,  1065,  1065,
    1065,  1065,  1065,  1065,  1065,  1065,  1065,  1065,  1065,  -214,
    1065,  -214,  -214,  -214,  -214,  -214,   130,   -18,  1065,  -214,
     121,  -214,  -214,  -214,  1096,  1127,  1065,   817,  -214,  -214,
    1065,    -1,  -214,  1295,  -214,  -214,  -214,  1295,  -214,  -214,
    -214,   104,   134,  -214,  -214,  1321,   910,  -214,  1202,   166,
     129,   175,   191,  1065,  -214,  1065,   181,  -214,  1065,   159,
    -214,  1158,  1065,  -214,   257,  1214,  1375,  1396,   941,  -214,
    -214,  1065,  1065,  1065,  1065,  -214,   609,  -214,  -214,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,   195,   195,   -27,   -27,
     -27,   -15,   165,  1420,  1420,  1420,  1420,  1420,  1420,  1420,
    1420,  1420,  1420,  1420,  1420,  1420,  1420,  1229,  -214,  1420,
     198,  -214,   168,   208,   972,  1420,  -214,   209,   205,  1003,
     211,  1065,   205,  1241,  -214,   687,  1333,  1256,  -214,   215,
    -214,  -214,  -214,   688,   178,  -214,  -214,  1268,   688,  1065,
    1065,  1065,  1420,  1420,   174,    55,  -214,   241,   526,  -214,
     180,  -214,  -214,   177,  1065,  -214,     9,  1065,  1420,  1408,
     458,   535,  -214,  -214,  1065,  -214,   182,  -214,    11,  1065,
    1065,    -1,  1065,  -214,   209,   205,    -1,  -214,   183,  -214,
    -214,  1065,  -214,  1065,  -214,  -214,   108,   110,   113,  -214,
     764,  -214,  -214,  -214,  -214,  -214,  -214,   192,  -214,    12,
      98,  -214,   603,  -214,   181,  1420,  1420,  -214,   193,    -1,
    -214,   194,   140,  1283,   199,  -214,  -214,  -214,  -214,  -214,
    -214,  1065,   -15,  -214,  -214,   205,  -214,  -214,    -1,    -1,
    1420,   197,    -1,  -214,  -214,  -214,  -214
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   178,     0,   160,     0,     0,     0,     0,     0,   128,
       0,    61,    62,    65,    63,    90,    90,   145,     0,     0,
     166,   167,    90,    11,    13,     0,     0,     0,     0,     5,
       7,    10,    15,    37,    59,     0,    75,   133,     0,   155,
       0,     0,     8,     0,     0,     0,     0,    35,    36,    95,
      95,   108,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    26,     0,    24,    28,     0,     0,     0,     0,
       0,     0,    32,     0,    63,    73,   133,    74,    72,     0,
      80,    77,    79,   129,   131,     0,     0,   133,    76,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   172,   173,
       1,     0,     0,     6,    17,    56,    52,    54,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    60,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    78,
       0,   143,   141,   163,   161,   162,   156,   157,     0,   170,
     174,     9,    21,    29,    81,    81,     0,     0,    30,    31,
       0,    90,   151,     0,    33,    34,   153,     0,    20,    25,
      27,   105,     0,   111,   115,     0,     0,   127,     0,     0,
       0,     0,     0,     0,    64,     0,     0,   132,     0,   182,
     179,     0,    81,   146,    63,     0,     0,     0,     0,    12,
      14,     0,     0,     0,     0,   119,    51,    45,    46,    47,
      48,    49,    50,    22,    16,    23,    66,    67,    68,    69,
      70,   158,    71,    38,    39,    40,    41,    42,    43,    44,
     134,   135,   136,   137,   138,   139,   140,     0,   164,   150,
       0,   176,     0,   175,     0,    83,    97,    82,   102,     0,
      62,     0,   102,     0,   113,    63,     0,     0,   125,     0,
     152,   154,   106,     0,     0,   116,   117,     0,     0,     0,
       0,     0,   100,   101,     0,     0,   180,    63,     0,   181,
       0,   148,   147,     0,     0,    86,     0,     0,    18,     0,
      53,    55,   159,   144,     0,   171,     0,    99,     0,     0,
       0,     0,     0,    89,    96,   102,     0,   110,     0,   114,
     104,     0,   107,     0,   118,   112,     0,     0,     0,   120,
     122,   184,   186,   183,   185,    85,   142,     0,    88,     0,
       0,    57,     0,   177,    98,    84,   103,    91,     0,     0,
      92,     0,     0,     0,   122,   121,   130,   123,   149,    87,
      19,     0,     0,   168,   165,   102,    93,   126,     0,     0,
      58,     0,     0,   124,   109,   169,    94
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -214,  -214,  -214,  -214,   219,  -214,  -214,  -214,  -214,  -214,
    -214,    56,   -82,   224,   -50,   -20,     0,  -214,  -214,  -214,
    -214,  -214,   206,    -6,    61,   -81,  -214,  -195,    75,   212,
     -41,   114,   255,  -210,  -214,  -214,  -214,  -214,  -214,  -214,
    -214,  -214,    43,  -214,  -214,   -17,  -214,  -214,  -213,  -214,
    -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,  -214,
    -214
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    26,    27,    28,    29,    30,    96,    97,   116,   201,
     330,    62,   214,    63,    64,    65,   245,   203,   204,   202,
     351,    33,    34,    35,   246,   247,    36,   251,    89,   154,
     305,   248,   298,   301,    67,   263,    68,    69,    70,   176,
     268,    71,    37,    38,   142,   240,    72,    39,   146,    40,
      41,   354,    42,    43,    44,   242,   243,    45,   190,   191,
     279
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      32,    81,    66,   287,    47,    48,   140,   185,   292,    92,
      85,    47,    48,   169,   152,   123,   124,   171,   172,   173,
     299,   177,   185,   299,  -122,   124,   153,    66,    32,   -90,
       8,     9,    79,   144,   158,   159,    93,    80,   162,   164,
     165,   166,   306,   141,   186,    94,   170,    76,    76,    76,
      82,    76,   169,    87,   302,   148,    31,   328,   163,   334,
     349,   167,   100,    66,    88,   320,   299,    66,    66,    66,
     175,    66,     2,   178,   143,    98,    76,    99,     8,     9,
      79,   153,   145,    76,    31,    80,     8,     9,    79,   150,
      90,    91,   195,   196,   197,   339,   215,    95,   156,   149,
     157,   151,    66,    47,    48,     2,   160,   275,   139,   206,
     207,   208,   209,   210,   211,   212,    87,   286,   344,   299,
     345,   299,   180,   346,   299,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   361,
     237,   258,   161,   260,   -90,   362,   188,   261,   239,   179,
     358,   299,   199,   200,   189,   181,   253,   256,   182,   192,
     257,    76,    76,    76,    76,    76,   198,    76,   205,   221,
     304,   238,   213,   241,   262,   269,   267,   187,   118,   119,
     120,   121,   122,   272,   270,   273,   123,   124,   316,   317,
     318,   278,   132,   133,   134,   135,   136,   137,   138,   264,
     271,   288,   289,   290,   291,   274,   329,   276,   124,   294,
      75,    77,    78,   312,    84,   144,   295,   300,   315,   296,
     299,   304,   303,   139,   311,   313,   319,   187,   325,   326,
     342,   120,   121,   122,   333,   341,   259,   123,   124,   117,
     348,   355,   357,   347,    85,   365,   147,   103,   350,    85,
     -90,   102,   321,   280,   -80,   -80,   -80,   -80,   -80,   -80,
     -80,   338,   155,    66,   145,    86,   -90,   327,    66,   252,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,     0,     0,     0,
       0,   337,     0,     0,   239,    88,   340,    87,     0,   322,
       0,     0,    87,     0,   332,     0,     0,     0,     0,   335,
     336,    88,     0,     0,     0,   281,     0,     0,     0,     0,
     215,     0,     0,   343,     0,    -2,     1,     0,     0,   356,
       0,     0,     2,     0,   216,   217,   218,   219,   220,     0,
     222,   125,   126,   127,   128,   129,   130,   131,   363,   364,
       0,     0,   366,     0,     0,     0,   144,     0,     3,     4,
       5,   360,     0,     0,     6,     0,     0,     0,     0,     7,
       8,     9,    10,     0,    11,    12,    13,    14,     0,    15,
      16,    17,     0,     0,    18,    19,    20,    21,    22,     1,
       0,     0,     0,    -3,    -3,     2,   213,    23,    24,     0,
       0,     0,     0,    25,     0,   145,   -90,     0,     0,     0,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,     0,     0,     0,
       0,     3,     4,     5,     0,     0,     0,     6,     0,     0,
       0,     0,     7,     8,     9,    10,     0,    11,    12,    13,
      14,    88,    15,    16,    17,    -3,    -3,    18,    19,    20,
      21,    22,    -3,    -3,    -3,    -3,    -3,    -3,     0,    -3,
      23,    24,    -3,    -3,    -3,    -3,    25,    -4,   101,     0,
     183,     0,    47,    48,     2,     0,     0,     0,     0,   105,
       0,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   107,   108,   109,   110,   111,   112,   113,   114,   115,
       3,     4,     5,     0,     0,     0,     6,   184,     0,     0,
       0,     7,     8,     9,    10,     0,    11,    12,    13,    14,
       0,    15,    16,    17,    49,    50,    18,    19,    20,    21,
      22,    51,    52,    53,    54,    55,    56,     0,    57,     0,
       0,    58,    59,    60,    61,   101,     0,   323,     0,    47,
      48,     2,   168,     0,     0,     0,   105,     0,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,     0,   108,
     109,   110,   111,   112,   113,   114,   115,     3,     4,     5,
       0,     0,     0,     6,   324,     0,     0,     0,     7,     8,
       9,    10,     0,    11,    12,    13,    14,     0,    15,    16,
      17,    49,    50,    18,    19,    20,    21,    22,    51,    52,
      53,    54,    55,    56,     0,    57,     0,     0,    58,    59,
      60,    61,    46,     0,   352,     0,    47,    48,     2,     0,
       0,     0,     0,   105,     0,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   110,   111,   112,   113,   114,
     115,     0,     0,     0,     3,     4,     5,     0,     0,     0,
       6,   353,     0,     0,     0,     7,     8,     9,    10,     0,
      11,    12,    13,    14,     0,    15,    16,    17,    49,    50,
      18,    19,    20,    21,    22,    51,    52,    53,    54,    55,
      56,     0,    57,     0,     0,    58,    59,    60,    61,   101,
       0,     0,     0,    47,    48,     2,   -90,     0,     0,     0,
     -80,   -80,   -80,   -80,   -80,   -80,   -80,     0,     0,     0,
       0,   308,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     3,     4,     5,     0,     0,     0,     6,     0,     0,
       0,    88,     7,     8,     9,    10,     0,    11,    12,    13,
      14,     0,    15,    16,    17,    49,    50,    18,    19,    20,
      21,    22,    51,    52,    53,    54,    55,    56,     0,    57,
      47,    48,    58,    59,    60,    61,   132,   133,   134,   135,
     136,   137,   138,     0,     0,     0,     0,  -121,  -121,  -121,
    -121,  -121,  -121,  -121,     0,     0,     0,     0,     3,     4,
       5,     0,   174,     0,     6,     0,     0,   139,     0,     7,
       8,     9,    10,     0,    11,    12,    13,    14,   347,    15,
      16,    17,     0,     0,    18,    19,    20,    21,    22,     3,
       4,     5,     0,   254,     0,     6,     0,     0,     0,     0,
       7,     8,     9,    10,     0,    11,    12,    13,    14,     0,
      15,    16,    17,     0,     0,    18,    19,    20,    21,    22,
       3,     4,     5,     0,     0,     0,     6,     0,     0,     0,
       0,     7,     8,     9,    10,     0,    11,    12,    13,   255,
       0,    15,    16,    17,     0,     0,    18,    19,    20,    21,
      22,     3,     4,     5,     0,     0,     0,     6,     0,     0,
       0,     0,     7,     8,     9,    73,     0,    11,    12,    13,
      74,    83,    15,    16,    17,     0,     0,    18,    19,    20,
      21,    22,     3,     4,     5,     0,     0,     0,     6,     0,
       0,     0,     0,     7,     8,     9,    10,   193,    11,    12,
      13,   194,     0,    15,    16,    17,     0,     0,    18,    19,
      20,    21,    22,     3,     4,     5,     0,     0,     0,     6,
       0,     0,     0,     0,     7,     8,     9,    10,   266,    11,
      12,    13,    14,     0,    15,    16,    17,     0,     0,    18,
      19,    20,    21,    22,     3,     4,     5,     0,     0,     0,
       6,     0,     0,     0,     0,     7,     8,     9,    10,   285,
      11,   250,    13,    14,     0,    15,    16,    17,     0,     0,
      18,    19,    20,    21,    22,     3,     4,     5,     0,     0,
       0,     6,     0,     0,     0,     0,     7,     8,     9,    10,
     297,    11,    12,    13,    14,     0,    15,    16,    17,     0,
       0,    18,    19,    20,    21,    22,     3,     4,     5,     0,
       0,     0,     6,     0,     0,     0,     0,     7,     8,     9,
      10,   297,    11,   250,    13,    14,     0,    15,    16,    17,
       0,     0,    18,    19,    20,    21,    22,     3,     4,     5,
       0,     0,     0,     6,     0,     0,     0,     0,     7,     8,
       9,    73,     0,    11,    12,    13,    74,     0,    15,    16,
      17,     0,     0,    18,    19,    20,    21,    22,     3,     4,
       5,     0,     0,     0,     6,     0,     0,     0,     0,     7,
       8,     9,    10,     0,    11,    12,    13,    14,     0,    15,
      16,    17,     0,     0,    18,    19,    20,    21,    22,     3,
       4,     5,     0,     0,     0,     6,     0,     0,     0,     0,
       7,     8,     9,   244,     0,    11,    12,    13,    14,     0,
      15,    16,    17,     0,     0,    18,    19,    20,    21,    22,
       3,     4,     5,     0,     0,     0,     6,     0,     0,     0,
       0,     7,     8,     9,   249,     0,    11,   250,    13,    14,
       0,    15,    16,    17,     0,     0,    18,    19,    20,    21,
      22,     3,     4,     5,     0,     0,     0,     6,     0,     0,
       0,     0,     7,     8,     9,    10,     0,    11,    12,    13,
     277,     0,    15,    16,    17,     0,     0,    18,    19,    20,
      21,    22,   105,     0,   106,   107,   108,   109,   110,   111,
     112,   113,   114,   115,   105,     0,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,     0,     0,     0,   105,
     184,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   105,   282,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,     0,     0,     0,   105,   293,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   105,   307,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
      47,    48,     0,   105,   310,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   105,   314,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   265,     0,     0,
       0,   359,     0,     0,     0,     0,     0,     0,     0,   309,
       0,   105,     0,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   105,     0,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   104,     0,     0,     0,     0,
       0,     0,     0,     0,   105,     0,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   283,     0,     0,     0,
       0,     0,     0,     0,     0,   105,     0,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   284,     0,     0,
       0,     0,     0,     0,     0,     0,   105,     0,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   105,   331,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     105,     0,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115
};

static const yytype_int16 yycheck[] =
{
       0,     7,     2,   198,     5,     6,    11,    11,   221,    47,
      10,     5,     6,    63,     8,    42,    43,    67,    68,    69,
      11,    71,    11,    11,    42,    43,    46,    27,    28,     9,
      45,    46,    47,    39,    54,    55,    47,    52,    58,    59,
      60,    61,   252,    48,    48,    47,    66,     4,     5,     6,
       7,     8,   102,    10,   249,    47,     0,    48,    58,    48,
      48,    61,     0,    63,    44,    10,    11,    67,    68,    69,
      70,    71,     7,    73,    41,    52,    33,    54,    45,    46,
      47,   101,    39,    40,    28,    52,    45,    46,    47,    47,
      15,    16,    92,    93,    94,   305,   116,    22,    47,    43,
      47,    45,   102,     5,     6,     7,    47,   188,    44,   109,
     110,   111,   112,   113,   114,   115,    73,   198,    10,    11,
      10,    11,    79,    10,    11,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,   137,   138,   352,
     140,   161,    52,   163,     9,   355,     9,   167,   148,    74,
      10,    11,    96,    97,    47,    80,   156,   157,    83,    47,
     160,   118,   119,   120,   121,   122,    47,   124,    52,    33,
     251,    41,   116,    52,    70,     9,   176,    48,    34,    35,
      36,    37,    38,   183,     9,   185,    42,    43,   269,   270,
     271,   191,    13,    14,    15,    16,    17,    18,    19,    65,
       9,   201,   202,   203,   204,    24,   287,    48,    43,    11,
       4,     5,     6,   263,     8,   221,    48,    12,   268,    11,
      11,   302,    11,    44,     9,    47,    52,    48,    48,    52,
     311,    36,    37,    38,    52,    52,   161,    42,    43,    33,
      48,    48,    48,    44,   244,    48,    40,    28,   330,   249,
       9,    27,    11,   192,    13,    14,    15,    16,    17,    18,
      19,   302,    50,   263,   221,    10,     9,   284,   268,   155,
      13,    14,    15,    16,    17,    18,    19,    -1,    -1,    -1,
      -1,   301,    -1,    -1,   284,    44,   306,   244,    -1,    48,
      -1,    -1,   249,    -1,   294,    -1,    -1,    -1,    -1,   299,
     300,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,
     330,    -1,    -1,   313,    -1,     0,     1,    -1,    -1,   339,
      -1,    -1,     7,    -1,   118,   119,   120,   121,   122,    -1,
     124,    13,    14,    15,    16,    17,    18,    19,   358,   359,
      -1,    -1,   362,    -1,    -1,    -1,   352,    -1,    33,    34,
      35,   351,    -1,    -1,    39,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    -1,    49,    50,    51,    52,    -1,    54,
      55,    56,    -1,    -1,    59,    60,    61,    62,    63,     1,
      -1,    -1,    -1,     5,     6,     7,   330,    72,    73,    -1,
      -1,    -1,    -1,    78,    -1,   352,     9,    -1,    -1,    -1,
      13,    14,    15,    16,    17,    18,    19,    -1,    -1,    -1,
      -1,    33,    34,    35,    -1,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    -1,    49,    50,    51,
      52,    44,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,    71,
      72,    73,    74,    75,    76,    77,    78,     0,     1,    -1,
      11,    -1,     5,     6,     7,    -1,    -1,    -1,    -1,    20,
      -1,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      33,    34,    35,    -1,    -1,    -1,    39,    48,    -1,    -1,
      -1,    44,    45,    46,    47,    -1,    49,    50,    51,    52,
      -1,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    -1,    71,    -1,
      -1,    74,    75,    76,    77,     1,    -1,    11,    -1,     5,
       6,     7,     8,    -1,    -1,    -1,    20,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    -1,    24,
      25,    26,    27,    28,    29,    30,    31,    33,    34,    35,
      -1,    -1,    -1,    39,    48,    -1,    -1,    -1,    44,    45,
      46,    47,    -1,    49,    50,    51,    52,    -1,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    -1,    71,    -1,    -1,    74,    75,
      76,    77,     1,    -1,    11,    -1,     5,     6,     7,    -1,
      -1,    -1,    -1,    20,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    26,    27,    28,    29,    30,
      31,    -1,    -1,    -1,    33,    34,    35,    -1,    -1,    -1,
      39,    48,    -1,    -1,    -1,    44,    45,    46,    47,    -1,
      49,    50,    51,    52,    -1,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    -1,    71,    -1,    -1,    74,    75,    76,    77,     1,
      -1,    -1,    -1,     5,     6,     7,     9,    -1,    -1,    -1,
      13,    14,    15,    16,    17,    18,    19,    -1,    -1,    -1,
      -1,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    33,    34,    35,    -1,    -1,    -1,    39,    -1,    -1,
      -1,    44,    44,    45,    46,    47,    -1,    49,    50,    51,
      52,    -1,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,    71,
       5,     6,    74,    75,    76,    77,    13,    14,    15,    16,
      17,    18,    19,    -1,    -1,    -1,    -1,    13,    14,    15,
      16,    17,    18,    19,    -1,    -1,    -1,    -1,    33,    34,
      35,    -1,     6,    -1,    39,    -1,    -1,    44,    -1,    44,
      45,    46,    47,    -1,    49,    50,    51,    52,    44,    54,
      55,    56,    -1,    -1,    59,    60,    61,    62,    63,    33,
      34,    35,    -1,     6,    -1,    39,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    -1,    49,    50,    51,    52,    -1,
      54,    55,    56,    -1,    -1,    59,    60,    61,    62,    63,
      33,    34,    35,    -1,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    -1,    49,    50,    51,    52,
      -1,    54,    55,    56,    -1,    -1,    59,    60,    61,    62,
      63,    33,    34,    35,    -1,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    -1,    -1,    59,    60,    61,
      62,    63,    33,    34,    35,    -1,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    -1,    54,    55,    56,    -1,    -1,    59,    60,
      61,    62,    63,    33,    34,    35,    -1,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    -1,    54,    55,    56,    -1,    -1,    59,
      60,    61,    62,    63,    33,    34,    35,    -1,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    54,    55,    56,    -1,    -1,
      59,    60,    61,    62,    63,    33,    34,    35,    -1,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    56,    -1,
      -1,    59,    60,    61,    62,    63,    33,    34,    35,    -1,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    54,    55,    56,
      -1,    -1,    59,    60,    61,    62,    63,    33,    34,    35,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    -1,    49,    50,    51,    52,    -1,    54,    55,
      56,    -1,    -1,    59,    60,    61,    62,    63,    33,    34,
      35,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    -1,    49,    50,    51,    52,    -1,    54,
      55,    56,    -1,    -1,    59,    60,    61,    62,    63,    33,
      34,    35,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      44,    45,    46,    47,    -1,    49,    50,    51,    52,    -1,
      54,    55,    56,    -1,    -1,    59,    60,    61,    62,    63,
      33,    34,    35,    -1,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    44,    45,    46,    47,    -1,    49,    50,    51,    52,
      -1,    54,    55,    56,    -1,    -1,    59,    60,    61,    62,
      63,    33,    34,    35,    -1,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    44,    45,    46,    47,    -1,    49,    50,    51,
      52,    -1,    54,    55,    56,    -1,    -1,    59,    60,    61,
      62,    63,    20,    -1,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    20,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    -1,    -1,    -1,    20,
      48,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    20,    48,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    -1,    -1,    -1,    20,    48,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    20,    48,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
       5,     6,    -1,    20,    48,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    20,    48,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,     6,    -1,    -1,
      -1,    48,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     6,
      -1,    20,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    20,    -1,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      20,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     7,    33,    34,    35,    39,    44,    45,    46,
      47,    49,    50,    51,    52,    54,    55,    56,    59,    60,
      61,    62,    63,    72,    73,    78,    80,    81,    82,    83,
      84,    90,    95,   100,   101,   102,   105,   121,   122,   126,
     128,   129,   131,   132,   133,   136,     1,     5,     6,    57,
      58,    64,    65,    66,    67,    68,    69,    71,    74,    75,
      76,    77,    90,    92,    93,    94,    95,   113,   115,   116,
     117,   120,   125,    47,    52,   101,   121,   101,   101,    47,
      52,   102,   121,    53,   101,    95,   111,   121,    44,   107,
     107,   107,    47,    47,    47,   107,    85,    86,    52,    54,
       0,     1,    92,    83,    11,    20,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    87,   101,    34,    35,
      36,    37,    38,    42,    43,    13,    14,    15,    16,    17,
      18,    19,    13,    14,    15,    16,    17,    18,    19,    44,
      11,    48,   123,    41,   102,   121,   127,   101,    47,    90,
      47,    90,     8,    94,   108,   108,    47,    47,    94,    94,
      47,    52,    94,    95,    94,    94,    94,    95,     8,    93,
      94,    93,    93,    93,     6,    95,   118,    93,    95,   107,
     121,   107,   107,    11,    48,    11,    48,    48,     9,    47,
     137,   138,    47,    48,    52,    95,    95,    95,    47,    90,
      90,    88,    98,    96,    97,    52,    95,    95,    95,    95,
      95,    95,    95,    90,    91,    94,   101,   101,   101,   101,
     101,    33,   101,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    41,    95,
     124,    52,   134,   135,    47,    95,   103,   104,   110,    47,
      50,   106,   110,    95,     6,    52,    95,    95,    94,   107,
      94,    94,    70,   114,    65,     6,    48,    95,   119,     9,
       9,     9,    95,    95,    24,   104,    48,    52,    95,   139,
     103,    48,    48,    11,    11,    48,   104,   106,    95,    95,
      95,    95,   127,    48,    11,    48,    11,    48,   111,    11,
      12,   112,   106,    11,   104,   109,   112,    48,    24,     6,
      48,     9,    93,    47,    48,    93,   104,   104,   104,    52,
      10,    11,    48,    11,    48,    48,    52,   124,    48,   104,
      89,    21,    95,    52,    48,    95,    95,    94,   109,   112,
      94,    52,   104,    95,    10,    10,    10,    44,    48,    48,
      91,    99,    11,    48,   130,    48,    94,    48,    10,    48,
      95,   127,   112,    94,    94,    48,    94
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    79,    80,    81,    80,    82,    82,    83,    83,    83,
      84,    85,    84,    86,    84,    87,    84,    88,    89,    84,
      90,    90,    91,    91,    92,    92,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    94,    94,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    95,    96,    95,    97,    95,    98,    99,    95,   100,
     100,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     102,   103,   103,   104,   104,   105,   105,   105,   105,   106,
     107,    93,    93,    93,    93,   108,   109,   110,   110,   110,
     111,   111,   112,   112,   113,    93,   114,    93,   115,    93,
     116,    93,    93,   117,   117,   118,   118,   119,   119,    95,
      95,   102,   101,   101,    93,    93,   120,    93,   121,   121,
     121,   121,   121,   101,    95,    95,    95,    95,    95,    95,
      95,   101,   122,   123,   123,   101,   101,   101,   101,   101,
     124,    93,    93,   125,   125,   101,   101,   101,   101,   101,
     126,   127,   127,   128,   128,   101,   129,   129,   130,   130,
     131,   132,   133,   133,   134,   134,   135,   135,   136,   101,
     137,   137,   138,   138,   138,   139,   139
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     2,     1,     1,     2,
       1,     0,     3,     0,     3,     0,     3,     0,     0,     6,
       3,     3,     1,     1,     1,     2,     1,     2,     1,     2,
       2,     2,     1,     2,     2,     1,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     0,     4,     0,     4,     0,     0,     7,     1,
       2,     1,     1,     1,     3,     1,     3,     3,     3,     3,
       3,     3,     2,     2,     2,     1,     2,     2,     2,     2,
       1,     0,     1,     1,     3,     5,     4,     6,     5,     2,
       0,     5,     5,     6,     8,     0,     1,     1,     3,     2,
       3,     3,     0,     2,     4,     2,     1,     4,     1,     7,
       4,     2,     4,     3,     4,     1,     2,     1,     2,     3,
       5,     5,     5,     6,     7,     3,     6,     2,     1,     2,
       6,     2,     3,     1,     3,     3,     3,     3,     3,     3,
       3,     2,     5,     1,     3,     1,     3,     4,     4,     6,
       1,     2,     3,     2,     3,     1,     2,     2,     3,     4,
       1,     1,     1,     2,     3,     6,     1,     1,     1,     3,
       2,     4,     2,     2,     0,     1,     1,     3,     1,     3,
       2,     2,     1,     3,     3,     2,     2
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
/* The lookahead symbol.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs;

    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex (&yylval);
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 236 "parse.y" /* yacc.c:1667  */
    {                                           CODE_OPEN_BEGIN;
                        }
#line 2004 "y.tab.c" /* yacc.c:1667  */
    break;

  case 4:
#line 238 "parse.y" /* yacc.c:1667  */
    {   CODE_CLOSE_BEGIN;
                                                                }
#line 2011 "y.tab.c" /* yacc.c:1667  */
    break;

  case 10:
#line 248 "parse.y" /* yacc.c:1667  */
    {   /* this do nothing removes a vacuous warning from Bison */
                                                                }
#line 2018 "y.tab.c" /* yacc.c:1667  */
    break;

  case 11:
#line 250 "parse.y" /* yacc.c:1667  */
    {                               CODE_OPEN_BEGIN;
                                    }
#line 2025 "y.tab.c" /* yacc.c:1667  */
    break;

  case 12:
#line 252 "parse.y" /* yacc.c:1667  */
    {   CODE_CLOSE_BEGIN;
                                                                }
#line 2032 "y.tab.c" /* yacc.c:1667  */
    break;

  case 13:
#line 254 "parse.y" /* yacc.c:1667  */
    {                               CODE_OPEN_END;
                                    }
#line 2039 "y.tab.c" /* yacc.c:1667  */
    break;

  case 14:
#line 256 "parse.y" /* yacc.c:1667  */
    {   CODE_CLOSE_END;
                                                                }
#line 2046 "y.tab.c" /* yacc.c:1667  */
    break;

  case 15:
#line 259 "parse.y" /* yacc.c:1667  */
    {                               code_jmp(_JZ, (INST*)0);
                                    }
#line 2053 "y.tab.c" /* yacc.c:1667  */
    break;

  case 16:
#line 261 "parse.y" /* yacc.c:1667  */
    {   patch_jmp( code_ptr ) ;
                                                                }
#line 2060 "y.tab.c" /* yacc.c:1667  */
    break;

  case 17:
#line 264 "parse.y" /* yacc.c:1667  */
    {                                INST *p1 = CDP((yyvsp[-1].start)) ;
                                                                    int len ;

                                                                    code_push(p1, code_ptr - p1, scope, active_funct) ;
                                                                    code_ptr = p1 ;

                                                                    code2op(_RANGE, 1) ;
                                                                    code_ptr += 3 ;
                                                                    len = code_pop(code_ptr) ;
                                                                    code_ptr += len ;
                                                                    code1(_STOP) ;
                                                                    p1 = CDP((yyvsp[-1].start)) ;
                                                                    p1[2].op = code_ptr - (p1+1) ;
                                    }
#line 2079 "y.tab.c" /* yacc.c:1667  */
    break;

  case 18:
#line 278 "parse.y" /* yacc.c:1667  */
    {                       code1(_STOP);
                                            }
#line 2086 "y.tab.c" /* yacc.c:1667  */
    break;

  case 19:
#line 280 "parse.y" /* yacc.c:1667  */
    {   INST *p1 = CDP((yyvsp[-5].start)) ;
                                                                    p1[3].op = CDP((yyvsp[0].start)) - (p1+1) ;
                                                                    p1[4].op = code_ptr - (p1+1) ;
                                                                }
#line 2095 "y.tab.c" /* yacc.c:1667  */
    break;

  case 20:
#line 286 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = (yyvsp[-1].start);
                                                                }
#line 2102 "y.tab.c" /* yacc.c:1667  */
    break;

  case 21:
#line 288 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = code_offset ; /* does nothing won't be executed */
                                                                    print_flag = getline_flag = paren_cnt = 0 ;
                                                                    yyerrok ;
                                                                }
#line 2111 "y.tab.c" /* yacc.c:1667  */
    break;

  case 23:
#line 294 "parse.y" /* yacc.c:1667  */
    {   /* default print action */
                                                                    (yyval.start) = code_offset ;
                                                                    code1(_PUSHINT) ; code1(0) ;
                                                                    code2(_PRINT, bi_print) ;
                                                                }
#line 2121 "y.tab.c" /* yacc.c:1667  */
    break;

  case 27:
#line 304 "parse.y" /* yacc.c:1667  */
    {   code1(_POP) ;
                                                                }
#line 2128 "y.tab.c" /* yacc.c:1667  */
    break;

  case 28:
#line 306 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = code_offset ;
                                                                }
#line 2135 "y.tab.c" /* yacc.c:1667  */
    break;

  case 29:
#line 308 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = code_offset ;
                                                                    print_flag = getline_flag = 0 ;
                                                                    paren_cnt = 0 ;
                                                                    yyerrok ;
                                                                }
#line 2145 "y.tab.c" /* yacc.c:1667  */
    break;

  case 30:
#line 313 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = code_offset ;
                                                                    BC_insert('B', code_ptr+1) ;
                                                                    code2(_JMP, 0) ; /* don't use code_jmp ! */
                                                                }
#line 2154 "y.tab.c" /* yacc.c:1667  */
    break;

  case 31:
#line 317 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = code_offset ;
                                                                    BC_insert('C', code_ptr+1) ;
                                                                    code2(_JMP, 0) ;
                                                                }
#line 2163 "y.tab.c" /* yacc.c:1667  */
    break;

  case 32:
#line 321 "parse.y" /* yacc.c:1667  */
    {   CODE_NOT_SCOPE( SCOPE_FUNCT, "return outside function body") ;
                                                                }
#line 2170 "y.tab.c" /* yacc.c:1667  */
    break;

  case 33:
#line 323 "parse.y" /* yacc.c:1667  */
    {   CODE_NOT_SCOPE( SCOPE_MAIN, "improper use of next") ;
                                                                    (yyval.start) = code_offset ;
                                                                    code1(_NEXT) ;
                                                                }
#line 2179 "y.tab.c" /* yacc.c:1667  */
    break;

  case 34:
#line 327 "parse.y" /* yacc.c:1667  */
    {   CODE_NOT_SCOPE( SCOPE_MAIN, "improper use of nextfile" ) ;
                                                                    (yyval.start) = code_offset ;
                                                                    code1(_NEXTFILE) ;
                                                                }
#line 2188 "y.tab.c" /* yacc.c:1667  */
    break;

  case 38:
#line 338 "parse.y" /* yacc.c:1667  */
    {   code1(_ASSIGN)  ;
                                                                }
#line 2195 "y.tab.c" /* yacc.c:1667  */
    break;

  case 39:
#line 340 "parse.y" /* yacc.c:1667  */
    {   code1(_ADD_ASG) ; 
                                                                }
#line 2202 "y.tab.c" /* yacc.c:1667  */
    break;

  case 40:
#line 342 "parse.y" /* yacc.c:1667  */
    {   code1(_SUB_ASG) ; 
                                                                }
#line 2209 "y.tab.c" /* yacc.c:1667  */
    break;

  case 41:
#line 344 "parse.y" /* yacc.c:1667  */
    {   code1(_MUL_ASG) ; 
                                                                }
#line 2216 "y.tab.c" /* yacc.c:1667  */
    break;

  case 42:
#line 346 "parse.y" /* yacc.c:1667  */
    {   code1(_DIV_ASG) ; 
                                                                }
#line 2223 "y.tab.c" /* yacc.c:1667  */
    break;

  case 43:
#line 348 "parse.y" /* yacc.c:1667  */
    {   code1(_MOD_ASG) ; 
                                                                }
#line 2230 "y.tab.c" /* yacc.c:1667  */
    break;

  case 44:
#line 350 "parse.y" /* yacc.c:1667  */
    {   code1(_POW_ASG) ; 
                                                                }
#line 2237 "y.tab.c" /* yacc.c:1667  */
    break;

  case 45:
#line 352 "parse.y" /* yacc.c:1667  */
    {   code1(_EQ)  ;
                                                                }
#line 2244 "y.tab.c" /* yacc.c:1667  */
    break;

  case 46:
#line 354 "parse.y" /* yacc.c:1667  */
    {   code1(_NEQ) ; 
                                                                }
#line 2251 "y.tab.c" /* yacc.c:1667  */
    break;

  case 47:
#line 356 "parse.y" /* yacc.c:1667  */
    {   code1(_LT)  ; 
                                                                }
#line 2258 "y.tab.c" /* yacc.c:1667  */
    break;

  case 48:
#line 358 "parse.y" /* yacc.c:1667  */
    {   code1(_LTE) ; 
                                                                }
#line 2265 "y.tab.c" /* yacc.c:1667  */
    break;

  case 49:
#line 360 "parse.y" /* yacc.c:1667  */
    {   code1(_GT)  ; 
                                                                }
#line 2272 "y.tab.c" /* yacc.c:1667  */
    break;

  case 50:
#line 362 "parse.y" /* yacc.c:1667  */
    {   code1(_GTE) ; 
                                                                }
#line 2279 "y.tab.c" /* yacc.c:1667  */
    break;

  case 51:
#line 364 "parse.y" /* yacc.c:1667  */
    {   INST *p3 = CDP((yyvsp[0].start)) ;
                                                                    if ( p3 == code_ptr - 2 ) {
                                                                        if ( p3->op == _MATCH0 )
                                                                            p3->op = _MATCH1 ;
                                                                        else /* check for string */
                                                                            if ( p3->op == _PUSHS ) {
                                                                                CELL *cp = ZMALLOC(CELL) ;
                                                                                cp->type = C_STRING ;
                                                                                cp->ptr = p3[1].ptr ;
                                                                                cast_to_RE(cp) ;
                                                                                code_ptr -= 2 ;
                                                                                code2(_MATCH1, cp->ptr) ;
                                                                                ZFREE(cp) ;
                                                                            }
                                                                            else
                                                                                code1(_MATCH2) ;
                                                                    }
                                                                    else
                                                                        code1(_MATCH2) ;
            
                                                                    if ( !(yyvsp[-1].ival) )
                                                                        code1(_NOT) ;
                                                                }
#line 2307 "y.tab.c" /* yacc.c:1667  */
    break;

  case 52:
#line 389 "parse.y" /* yacc.c:1667  */
    {                               code1(_TEST) ;
                                                                    code_jmp(_LJNZ, (INST*)0) ;
                                    }
#line 2315 "y.tab.c" /* yacc.c:1667  */
    break;

  case 53:
#line 392 "parse.y" /* yacc.c:1667  */
    {   code1(_TEST) ;
                                                                    patch_jmp(code_ptr) ;
                                                                }
#line 2323 "y.tab.c" /* yacc.c:1667  */
    break;

  case 54:
#line 396 "parse.y" /* yacc.c:1667  */
    {   code1(_TEST) ;
		                                                            code_jmp(_LJZ, (INST*)0) ;
	                                                            }
#line 2331 "y.tab.c" /* yacc.c:1667  */
    break;

  case 55:
#line 399 "parse.y" /* yacc.c:1667  */
    {   code1(_TEST) ;
                                                                    patch_jmp(code_ptr) ;
                                                                }
#line 2339 "y.tab.c" /* yacc.c:1667  */
    break;

  case 56:
#line 402 "parse.y" /* yacc.c:1667  */
    {   code_jmp(_JZ, (INST*)0) ;
                                                                }
#line 2346 "y.tab.c" /* yacc.c:1667  */
    break;

  case 57:
#line 404 "parse.y" /* yacc.c:1667  */
    {   code_jmp(_JMP, (INST*)0) ;
                                                                }
#line 2353 "y.tab.c" /* yacc.c:1667  */
    break;

  case 58:
#line 406 "parse.y" /* yacc.c:1667  */
    {   patch_jmp(code_ptr) ;
                                                                    patch_jmp(CDP((yyvsp[0].start))) ;
                                                                }
#line 2361 "y.tab.c" /* yacc.c:1667  */
    break;

  case 60:
#line 411 "parse.y" /* yacc.c:1667  */
    {   code1(_CAT) ;
                                                                }
#line 2368 "y.tab.c" /* yacc.c:1667  */
    break;

  case 61:
#line 414 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = code_offset ;
                                                                    code2(_PUSHD, (yyvsp[0].ptr)) ;
                                                                }
#line 2376 "y.tab.c" /* yacc.c:1667  */
    break;

  case 62:
#line 417 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = code_offset ;
                                                                    code2(_PUSHS, (yyvsp[0].ptr)) ;
                                                                }
#line 2384 "y.tab.c" /* yacc.c:1667  */
    break;

  case 63:
#line 420 "parse.y" /* yacc.c:1667  */
    {   /* anything less than IN */
                                                                    check_var((yyvsp[0].stp)) ;
                                                                    (yyval.start) = code_offset ;
                                                                    if ( is_local((yyvsp[0].stp)) ) {
                                                                        code2op(L_PUSHI, (yyvsp[0].stp)->offset) ;
                                                                    }
                                                                    else
                                                                        code2(_PUSHI, (yyvsp[0].stp)->stval.cp) ;
                                                                }
#line 2398 "y.tab.c" /* yacc.c:1667  */
    break;

  case 64:
#line 429 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = (yyvsp[-1].start) ;
                                                                }
#line 2405 "y.tab.c" /* yacc.c:1667  */
    break;

  case 65:
#line 432 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = code_offset ;
                                                                    code2(_MATCH0, (yyvsp[0].ptr)) ;
                                                                }
#line 2413 "y.tab.c" /* yacc.c:1667  */
    break;

  case 66:
#line 436 "parse.y" /* yacc.c:1667  */
    {   code1(_ADD) ;
                                            }
#line 2420 "y.tab.c" /* yacc.c:1667  */
    break;

  case 67:
#line 438 "parse.y" /* yacc.c:1667  */
    {   code1(_SUB) ; 
                                                                }
#line 2427 "y.tab.c" /* yacc.c:1667  */
    break;

  case 68:
#line 440 "parse.y" /* yacc.c:1667  */
    {   code1(_MUL) ; 
                                                                }
#line 2434 "y.tab.c" /* yacc.c:1667  */
    break;

  case 69:
#line 442 "parse.y" /* yacc.c:1667  */
    {   code1(_DIV) ; 
                                                                }
#line 2441 "y.tab.c" /* yacc.c:1667  */
    break;

  case 70:
#line 444 "parse.y" /* yacc.c:1667  */
    {   code1(_MOD) ; 
                                                                }
#line 2448 "y.tab.c" /* yacc.c:1667  */
    break;

  case 71:
#line 446 "parse.y" /* yacc.c:1667  */
    {   code1(_POW) ; 
                                                                }
#line 2455 "y.tab.c" /* yacc.c:1667  */
    break;

  case 72:
#line 448 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = (yyvsp[0].start) ;
                                                                    code1(_NOT) ;
                                                                }
#line 2463 "y.tab.c" /* yacc.c:1667  */
    break;

  case 73:
#line 451 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = (yyvsp[0].start) ;
                                                                    code1(_UPLUS) ;
                                                                }
#line 2471 "y.tab.c" /* yacc.c:1667  */
    break;

  case 74:
#line 454 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = (yyvsp[0].start) ;
                                                                    code1(_UMINUS) ;
                                                                }
#line 2479 "y.tab.c" /* yacc.c:1667  */
    break;

  case 76:
#line 459 "parse.y" /* yacc.c:1667  */
    {   check_var((yyvsp[-1].stp)) ;
                                                                    (yyval.start) = code_offset ;
                                                                    code_address((yyvsp[-1].stp)) ;
                                                                    if ( (yyvsp[0].ival) == '+' )
                                                                        code1(_POST_INC) ;
                                                                    else
                                                                        code1(_POST_DEC) ;
                                                                }
#line 2492 "y.tab.c" /* yacc.c:1667  */
    break;

  case 77:
#line 467 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = (yyvsp[0].start) ;
                                                                    if ( (yyvsp[-1].ival) == '+' )
                                                                        code1(_PRE_INC) ;
                                                                    else
                                                                        code1(_PRE_DEC) ;
                                                                }
#line 2503 "y.tab.c" /* yacc.c:1667  */
    break;

  case 78:
#line 474 "parse.y" /* yacc.c:1667  */
    {   if ((yyvsp[0].ival) == '+' )
                                                                        code1(F_POST_INC ) ;
                                                                    else
                                                                        code1(F_POST_DEC) ;
                                                                }
#line 2513 "y.tab.c" /* yacc.c:1667  */
    break;

  case 79:
#line 479 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = (yyvsp[0].start) ;
                                                                    if ( (yyvsp[-1].ival) == '+' )
                                                                        code1(F_PRE_INC) ;
                                                                    else
                                                                        code1( F_PRE_DEC) ;
                                                                }
#line 2524 "y.tab.c" /* yacc.c:1667  */
    break;

  case 80:
#line 486 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = code_offset ;
                                                                    check_var((yyvsp[0].stp)) ;
                                                                    code_address((yyvsp[0].stp)) ;
                                                                }
#line 2533 "y.tab.c" /* yacc.c:1667  */
    break;

  case 81:
#line 491 "parse.y" /* yacc.c:1667  */
    {   (yyval.ival) = 0 ;
                                                                }
#line 2540 "y.tab.c" /* yacc.c:1667  */
    break;

  case 83:
#line 495 "parse.y" /* yacc.c:1667  */
    {   (yyval.ival) = 1 ;
                                                                }
#line 2547 "y.tab.c" /* yacc.c:1667  */
    break;

  case 84:
#line 497 "parse.y" /* yacc.c:1667  */
    {   (yyval.ival) = (yyvsp[-2].ival) + 1 ;
                                                                }
#line 2554 "y.tab.c" /* yacc.c:1667  */
    break;

  case 85:
#line 500 "parse.y" /* yacc.c:1667  */
    {   BI_REC *p = (yyvsp[-4].bip) ;
                                                                    (yyval.start) = (yyvsp[-3].start) ;
                                                                    if ( (int)p->min_args > (yyvsp[-1].ival) || (int)p->max_args < (yyvsp[-1].ival) )
                                                                        compile_error(
                                                                            "wrong number of arguments in call to %s" ,
                                                                            p->name
                                                                        ) ;
                                                                    /* variable args */
                                                                    if ( p->min_args != p->max_args ) {
                                                                        code1(_PUSHINT) ;
                                                                        code1((yyvsp[-1].ival)) ;
                                                                    }
                                                                    code2(_BUILTIN , p->fp) ;
                                                                }
#line 2573 "y.tab.c" /* yacc.c:1667  */
    break;

  case 86:
#line 521 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = (yyvsp[-2].start) ;
                                                                    compile_error("no argments in call to sprintf()") ;
                                                                }
#line 2581 "y.tab.c" /* yacc.c:1667  */
    break;

  case 87:
#line 525 "parse.y" /* yacc.c:1667  */
    {   /* the usual case */
                                                                    const Form* form = (Form*) (yyvsp[-2].ptr) ;
                                                                    (yyval.start) = (yyvsp[-4].start) ;
                                                                    if (form && form->num_args != (yyvsp[-1].ival)) {
                                                                        compile_error("wrong number of arguments to sprintf, needs %d, has %d",
                                                                            form->num_args+1, (yyvsp[-1].ival)+1) ;
                                                                        }
                                                                        code2op(_PUSHINT, (yyvsp[-1].ival) + 1) ;
                                                                        code2(_BUILTIN, bi_sprintf) ;
                                                                }
#line 2596 "y.tab.c" /* yacc.c:1667  */
    break;

  case 88:
#line 535 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = (yyvsp[-3].start) ;
                                                                    code2op(_PUSHINT, (yyvsp[-1].ival)) ;
                                                                    code2(_BUILTIN, bi_sprintf1) ;
                                                                }
#line 2605 "y.tab.c" /* yacc.c:1667  */
    break;

  case 89:
#line 540 "parse.y" /* yacc.c:1667  */
    {   STRING* str = (STRING*) (yyvsp[-1].ptr) ;
                                                                    const Form* form = parse_form(str) ;
                                                                    free_STRING(str) ;
                                                                    (yyval.ptr) = (PTR) form ;
                                                                    code2(PUSHFM, form) ;
                                                                }
#line 2616 "y.tab.c" /* yacc.c:1667  */
    break;

  case 90:
#line 549 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = code_offset ;
                                                                }
#line 2623 "y.tab.c" /* yacc.c:1667  */
    break;

  case 91:
#line 553 "parse.y" /* yacc.c:1667  */
    {   code2(_PRINT, bi_print) ;
                                                                    print_flag = 0 ;
                                                                    (yyval.start) = (yyvsp[-3].start) ;
                                                                }
#line 2632 "y.tab.c" /* yacc.c:1667  */
    break;

  case 92:
#line 565 "parse.y" /* yacc.c:1667  */
    {   code2(_PRINT, bi_printf1) ;
                                                                    print_flag = 0 ;
                                                                    (yyval.start) = (yyvsp[-3].start) ;
                                                                    if ((yyvsp[-2].ival) == 0) {
                                                                        compile_error("no arguments in call to printf") ;
                                                                    }
                                                                }
#line 2644 "y.tab.c" /* yacc.c:1667  */
    break;

  case 93:
#line 573 "parse.y" /* yacc.c:1667  */
    {   const Form* form = (Form*) (yyvsp[-3].ptr) ;
                                                                    if (form && form->num_args != (yyvsp[-2].ival)) {
                                                                        compile_error(
                                                                            "wrong number of arguments to printf, needs %d, has %d",
                                                                            form->num_args+1, (yyvsp[-2].ival)+1
                                                                        ) ;
                                                                    }
                                                                    code2(_PRINT, bi_printf) ;
                                                                    print_flag = 0 ;
                                                                    (yyval.start) = (yyvsp[-4].start) ;
                                                                }
#line 2660 "y.tab.c" /* yacc.c:1667  */
    break;

  case 94:
#line 585 "parse.y" /* yacc.c:1667  */
    {   const Form* form = (Form*) (yyvsp[-4].ptr) ;
                                                                    if (form && form->num_args != (yyvsp[-3].ival)) {
                                                                        compile_error(
                                                                            "wrong number of arguments to printf, needs %d, has %d",
                                                                            form->num_args+1, (yyvsp[-3].ival)+1
                                                                        ) ;
                                                                    }
                                                                    code2(_PRINT, bi_printf) ;
                                                                    print_flag = 0 ;
                                                                    (yyval.start) = (yyvsp[-6].start) ;
                                                                }
#line 2676 "y.tab.c" /* yacc.c:1667  */
    break;

  case 95:
#line 597 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = code_offset ;
	                                                                print_flag = 1 ;
	                                                            }
#line 2684 "y.tab.c" /* yacc.c:1667  */
    break;

  case 96:
#line 601 "parse.y" /* yacc.c:1667  */
    {   code2op(_PUSHINT, (yyvsp[0].ival) + 1) ;
	                                                            }
#line 2691 "y.tab.c" /* yacc.c:1667  */
    break;

  case 97:
#line 604 "parse.y" /* yacc.c:1667  */
    {   code2op(_PUSHINT, (yyvsp[0].ival)) ;
                                                                }
#line 2698 "y.tab.c" /* yacc.c:1667  */
    break;

  case 98:
#line 606 "parse.y" /* yacc.c:1667  */
    {   (yyval.ival) = (yyvsp[-1].arg2p)->cnt ;
                                                                    zfree((yyvsp[-1].arg2p),sizeof(ARG2_REC)) ;
                                                                    code2op(_PUSHINT, (yyval.ival)) ;
                                                                }
#line 2707 "y.tab.c" /* yacc.c:1667  */
    break;

  case 99:
#line 610 "parse.y" /* yacc.c:1667  */
    {   (yyval.ival)=0 ;
                                                                    code2op(_PUSHINT, 0) ;
                                                                }
#line 2715 "y.tab.c" /* yacc.c:1667  */
    break;

  case 100:
#line 614 "parse.y" /* yacc.c:1667  */
    {   (yyval.arg2p) = (ARG2_REC*) zmalloc(sizeof(ARG2_REC)) ;
                                                                    (yyval.arg2p)->start = (yyvsp[-2].start) ;
                                                                    (yyval.arg2p)->cnt = 2 ;
                                                                }
#line 2724 "y.tab.c" /* yacc.c:1667  */
    break;

  case 101:
#line 618 "parse.y" /* yacc.c:1667  */
    {   (yyval.arg2p) = (yyvsp[-2].arg2p) ;
                                                                    (yyval.arg2p)->cnt++ ;
                                                                }
#line 2732 "y.tab.c" /* yacc.c:1667  */
    break;

  case 103:
#line 623 "parse.y" /* yacc.c:1667  */
    {   code2op(_PUSHINT, (yyvsp[-1].ival)) ;
                                                                }
#line 2739 "y.tab.c" /* yacc.c:1667  */
    break;

  case 104:
#line 627 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = (yyvsp[-1].start) ;
                                                                    EAT_NL_ ;
                                                                    code_jmp(_JZ, (INST*)0) ;
                                                                }
#line 2748 "y.tab.c" /* yacc.c:1667  */
    break;

  case 105:
#line 633 "parse.y" /* yacc.c:1667  */
    {   patch_jmp( code_ptr ) ;
                                                                }
#line 2755 "y.tab.c" /* yacc.c:1667  */
    break;

  case 106:
#line 636 "parse.y" /* yacc.c:1667  */
    {   EAT_NL_ ;
                                                                    code_jmp(_JMP, (INST*)0) ;
                                                                }
#line 2763 "y.tab.c" /* yacc.c:1667  */
    break;

  case 107:
#line 641 "parse.y" /* yacc.c:1667  */
    {   patch_jmp(code_ptr) ;
		                                                            patch_jmp(CDP((yyvsp[0].start))) ;
		                                                        }
#line 2771 "y.tab.c" /* yacc.c:1667  */
    break;

  case 108:
#line 645 "parse.y" /* yacc.c:1667  */
    {   EAT_NL_ ;
                                                                    BC_new() ;
                                                                }
#line 2779 "y.tab.c" /* yacc.c:1667  */
    break;

  case 109:
#line 651 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = (yyvsp[-5].start) ;
                                                                    code_jmp(_JNZ, CDP((yyvsp[-5].start))) ;
                                                                    BC_clear(code_ptr, CDP((yyvsp[-2].start))) ;
                                                                }
#line 2788 "y.tab.c" /* yacc.c:1667  */
    break;

  case 110:
#line 656 "parse.y" /* yacc.c:1667  */
    {   EAT_NL_ ;
                                                                    BC_new() ;
                                                                    (yyval.start) = (yyvsp[-1].start) ;
                                                                    /* check if const expression */
                                                                    if ( code_ptr - 2 == CDP((yyvsp[-1].start)) &&
                                                                    code_ptr[-2].op == _PUSHD &&
                                                                    *(double*)code_ptr[-1].ptr != 0.0
                                                                    )
                                                                        code_ptr -= 2 ;
                                                                    else {
                                                                        INST *p3 = CDP((yyvsp[-1].start)) ;
                                                                        code_push(p3, code_ptr-p3, scope, active_funct) ;
                                                                        code_ptr = p3 ;
                                                                        code2(_JMP, (INST*)0) ; /* code2() not code_jmp() */
                                                                    }
                                                                }
#line 2809 "y.tab.c" /* yacc.c:1667  */
    break;

  case 111:
#line 674 "parse.y" /* yacc.c:1667  */
    {   int   saved_offset ;
                                                                    int   len ;
                                                                    INST *p1 = CDP((yyvsp[-1].start)) ;
                                                                    INST *p2 = CDP((yyvsp[0].start)) ;
                                                                    if ( p1 != p2 ) {  /* real test in loop */
                                                                        p1[1].op = code_ptr-(p1+1) ;
                                                                        saved_offset = code_offset ;
                                                                        len = code_pop(code_ptr) ;
                                                                        code_ptr += len ;
                                                                        code_jmp(_JNZ, CDP((yyvsp[0].start))) ;
                                                                        BC_clear(code_ptr, CDP(saved_offset)) ;
                                                                    }
                                                                    else { /* while(1) */
                                                                        code_jmp(_JMP, p1) ;
                                                                        BC_clear(code_ptr, CDP((yyvsp[0].start))) ;
                                                                    }
                                                                }
#line 2831 "y.tab.c" /* yacc.c:1667  */
    break;

  case 112:
#line 693 "parse.y" /* yacc.c:1667  */
    {   int cont_offset = code_offset ;
                                                                    unsigned len = code_pop(code_ptr) ;
                                                                    INST *   p2  = CDP((yyvsp[-2].start)) ;
                                                                    INST *   p4  = CDP((yyvsp[0].start)) ;
                                                                    code_ptr += len ;
                                                                    if ( p2 != p4 ) {  /* real test in for2 */
                                                                        p4[-1].op = code_ptr - p4 + 1 ;
                                                                        len = code_pop(code_ptr) ;
                                                                        code_ptr += len ;
                                                                        code_jmp(_JNZ, CDP((yyvsp[0].start))) ;
                                                                    }
                                                                    else /*  for(;;) */
                                                                        code_jmp(_JMP, p4) ;
                                                                    BC_clear(code_ptr, CDP(cont_offset)) ;
                                                                }
#line 2851 "y.tab.c" /* yacc.c:1667  */
    break;

  case 113:
#line 709 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = code_offset ;
                                                                }
#line 2858 "y.tab.c" /* yacc.c:1667  */
    break;

  case 114:
#line 711 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = (yyvsp[-1].start) ;
                                                                    code1(_POP) ;
                                                                }
#line 2866 "y.tab.c" /* yacc.c:1667  */
    break;

  case 115:
#line 715 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = code_offset ;
                                                                }
#line 2873 "y.tab.c" /* yacc.c:1667  */
    break;

  case 116:
#line 717 "parse.y" /* yacc.c:1667  */
    {   if ( code_ptr - 2 == CDP((yyvsp[-1].start)) &&
                                                                        code_ptr[-2].op == _PUSHD &&
                                                                        * (double*) code_ptr[-1].ptr != 0.0
                                                                    ) {
                                                                        code_ptr -= 2 ;
                                                                    }
                                                                    else {
                                                                        INST *p1 = CDP((yyvsp[-1].start)) ;
                                                                        code_push(p1, code_ptr-p1, scope, active_funct) ;
                                                                        code_ptr = p1 ;
                                                                        code2(_JMP, (INST*)0) ;
                                                                    }
                                                                }
#line 2891 "y.tab.c" /* yacc.c:1667  */
    break;

  case 117:
#line 731 "parse.y" /* yacc.c:1667  */
    {   EAT_NL_ ;
                                                                    BC_new() ;
	                                                                code_push((INST*)0,0, scope, active_funct) ;
	                                                            }
#line 2900 "y.tab.c" /* yacc.c:1667  */
    break;

  case 118:
#line 735 "parse.y" /* yacc.c:1667  */
    {   INST *p1 = CDP((yyvsp[-1].start)) ;
                                                                    EAT_NL_ ; BC_new() ;
                                                                    code1(_POP) ;
                                                                    code_push(p1, code_ptr - p1, scope, active_funct) ;
                                                                    code_ptr -= code_ptr - p1 ;
                                                                }
#line 2911 "y.tab.c" /* yacc.c:1667  */
    break;

  case 119:
#line 743 "parse.y" /* yacc.c:1667  */
    {   check_array((yyvsp[0].stp)) ;
                                                                    code_array((yyvsp[0].stp)) ;
                                                                    code1(A_TEST) ;
                                                                }
#line 2920 "y.tab.c" /* yacc.c:1667  */
    break;

  case 120:
#line 747 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = (yyvsp[-3].arg2p)->start ;
                                                                    code2op(A_CAT, (yyvsp[-3].arg2p)->cnt) ;
                                                                    zfree((yyvsp[-3].arg2p), sizeof(ARG2_REC)) ;
                                                                    check_array((yyvsp[0].stp)) ;
                                                                    code_array((yyvsp[0].stp)) ;
                                                                    code1(A_TEST) ;
                                                                }
#line 2932 "y.tab.c" /* yacc.c:1667  */
    break;

  case 121:
#line 755 "parse.y" /* yacc.c:1667  */
    {   if ( (yyvsp[-1].ival) > 1 ) {
                                                                        code2op(A_CAT, (yyvsp[-1].ival)) ;
                                                                    }
                                                                    check_array((yyvsp[-4].stp)) ;
                                                                    if ( is_local((yyvsp[-4].stp)) ) {
                                                                        code2op(LAE_PUSHA, (yyvsp[-4].stp)->offset) ;
                                                                    }
                                                                    else
                                                                        code2(AE_PUSHA, (yyvsp[-4].stp)->stval.array) ;
                                                                    (yyval.start) = (yyvsp[-3].start) ;
                                                                }
#line 2948 "y.tab.c" /* yacc.c:1667  */
    break;

  case 122:
#line 768 "parse.y" /* yacc.c:1667  */
    {   if ( (yyvsp[-1].ival) > 1 ) {
                                                                        code2op(A_CAT, (yyvsp[-1].ival)) ;
                                                                    }
                                                                    check_array((yyvsp[-4].stp)) ;
                                                                    if( is_local((yyvsp[-4].stp)) ) {
                                                                        code2op(LAE_PUSHI, (yyvsp[-4].stp)->offset) ;
                                                                    }
                                                                    else
                                                                        code2(AE_PUSHI, (yyvsp[-4].stp)->stval.array) ;
                                                                    (yyval.start) = (yyvsp[-3].start) ;
                                                                }
#line 2964 "y.tab.c" /* yacc.c:1667  */
    break;

  case 123:
#line 779 "parse.y" /* yacc.c:1667  */
    {   if ( (yyvsp[-2].ival) > 1 ) {
                                                                        code2op(A_CAT,(yyvsp[-2].ival)) ;
                                                                    }
                                                                    check_array((yyvsp[-5].stp)) ;
                                                                    if ( is_local((yyvsp[-5].stp)) ) {
                                                                        code2op(LAE_PUSHA, (yyvsp[-5].stp)->offset) ;
                                                                    }
                                                                    else
                                                                        code2(AE_PUSHA, (yyvsp[-5].stp)->stval.array) ;
                                                                    if ( (yyvsp[0].ival) == '+' )
                                                                        code1(_POST_INC) ;
                                                                    else
                                                                        code1(_POST_DEC) ;
                                                                    (yyval.start) = (yyvsp[-4].start) ;
                                                                }
#line 2984 "y.tab.c" /* yacc.c:1667  */
    break;

  case 124:
#line 797 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = (yyvsp[-4].start) ;
                                                                    if ( (yyvsp[-2].ival) > 1 ) { code2op(A_CAT, (yyvsp[-2].ival)) ; }
                                                                    check_array((yyvsp[-5].stp)) ;
                                                                    code_array((yyvsp[-5].stp)) ;
                                                                    code1(A_DEL) ;
                                                                }
#line 2995 "y.tab.c" /* yacc.c:1667  */
    break;

  case 125:
#line 803 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = code_offset ;
                                                                    check_array((yyvsp[-1].stp)) ;
                                                                    code_array((yyvsp[-1].stp)) ;
                                                                    code1(DEL_A) ;
                                                                }
#line 3005 "y.tab.c" /* yacc.c:1667  */
    break;

  case 126:
#line 810 "parse.y" /* yacc.c:1667  */
    {   EAT_NL_ ;
                                                                    BC_new() ;
                                                                    (yyval.start) = code_offset ;
                                                                    check_var((yyvsp[-3].stp)) ;
                                                                    code_address((yyvsp[-3].stp)) ;
                                                                    check_array((yyvsp[-1].stp)) ;
                                                                    code_array((yyvsp[-1].stp)) ;
                                                                    code2(SET_ALOOP, (INST*)0) ;
                                                                }
#line 3019 "y.tab.c" /* yacc.c:1667  */
    break;

  case 127:
#line 821 "parse.y" /* yacc.c:1667  */
    {   INST *p2 = CDP((yyvsp[0].start)) ;
                                                                    p2[-1].op = code_ptr - p2 + 1 ;
                                                                    BC_clear( code_ptr+2 , code_ptr) ;
                                                                    code_jmp(ALOOP, p2) ;
                                                                    code1(POP_AL) ;
                                                                }
#line 3030 "y.tab.c" /* yacc.c:1667  */
    break;

  case 128:
#line 833 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = code_offset ;
                                                                    code2(F_PUSHA, (yyvsp[0].cp)) ;
                                                                }
#line 3038 "y.tab.c" /* yacc.c:1667  */
    break;

  case 129:
#line 836 "parse.y" /* yacc.c:1667  */
    {   check_var((yyvsp[0].stp)) ;
                                                                    (yyval.start) = code_offset ;
                                                                    if ( is_local((yyvsp[0].stp)) )
                                                                        code2op(L_PUSHI, (yyvsp[0].stp)->offset) ;
                                                                    else
                                                                        code2(_PUSHI, (yyvsp[0].stp)->stval.cp) ;
                                                                    CODE_FE_PUSHA() ;
                                                                }
#line 3051 "y.tab.c" /* yacc.c:1667  */
    break;

  case 130:
#line 844 "parse.y" /* yacc.c:1667  */
    {   if ( (yyvsp[-1].ival) > 1 )
                                                                        code2op(A_CAT, (yyvsp[-1].ival)) ;
                                                                    check_array((yyvsp[-4].stp)) ;
                                                                    if ( is_local((yyvsp[-4].stp)) )
                                                                        code2op(LAE_PUSHI, (yyvsp[-4].stp)->offset) ;
                                                                    else
                                                                        code2(AE_PUSHI, (yyvsp[-4].stp)->stval.array) ;
                                                                    CODE_FE_PUSHA() ;
                                                                    (yyval.start) = (yyvsp[-3].start) ;
                                                                }
#line 3066 "y.tab.c" /* yacc.c:1667  */
    break;

  case 131:
#line 854 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = (yyvsp[0].start) ;
                                                                    CODE_FE_PUSHA() ;
                                                                }
#line 3074 "y.tab.c" /* yacc.c:1667  */
    break;

  case 132:
#line 857 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = (yyvsp[-1].start) ;
                                                                }
#line 3081 "y.tab.c" /* yacc.c:1667  */
    break;

  case 133:
#line 861 "parse.y" /* yacc.c:1667  */
    {   field_A2I() ;
                                                                }
#line 3088 "y.tab.c" /* yacc.c:1667  */
    break;

  case 134:
#line 864 "parse.y" /* yacc.c:1667  */
    {   code1(F_ASSIGN)  ; }
#line 3094 "y.tab.c" /* yacc.c:1667  */
    break;

  case 135:
#line 865 "parse.y" /* yacc.c:1667  */
    {   code1(F_ADD_ASG) ; }
#line 3100 "y.tab.c" /* yacc.c:1667  */
    break;

  case 136:
#line 866 "parse.y" /* yacc.c:1667  */
    {   code1(F_SUB_ASG) ; }
#line 3106 "y.tab.c" /* yacc.c:1667  */
    break;

  case 137:
#line 867 "parse.y" /* yacc.c:1667  */
    {   code1(F_MUL_ASG) ; }
#line 3112 "y.tab.c" /* yacc.c:1667  */
    break;

  case 138:
#line 868 "parse.y" /* yacc.c:1667  */
    {   code1(F_DIV_ASG) ; }
#line 3118 "y.tab.c" /* yacc.c:1667  */
    break;

  case 139:
#line 869 "parse.y" /* yacc.c:1667  */
    {   code1(F_MOD_ASG) ; }
#line 3124 "y.tab.c" /* yacc.c:1667  */
    break;

  case 140:
#line 870 "parse.y" /* yacc.c:1667  */
    {   code1(F_POW_ASG) ; }
#line 3130 "y.tab.c" /* yacc.c:1667  */
    break;

  case 141:
#line 876 "parse.y" /* yacc.c:1667  */
    {   code2(_BUILTIN, bi_split) ;
                                                                }
#line 3137 "y.tab.c" /* yacc.c:1667  */
    break;

  case 142:
#line 879 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = (yyvsp[-2].start) ;
                                                                    check_array((yyvsp[0].stp)) ;
                                                                    code_array((yyvsp[0].stp))  ;
                                                                }
#line 3146 "y.tab.c" /* yacc.c:1667  */
    break;

  case 143:
#line 884 "parse.y" /* yacc.c:1667  */
    {   code2(_PUSHI, &fs_shadow) ;
                                                                }
#line 3153 "y.tab.c" /* yacc.c:1667  */
    break;

  case 144:
#line 886 "parse.y" /* yacc.c:1667  */
    {   if ( CDP((yyvsp[-1].start)) == code_ptr - 2 ) {
                                                                        if (code_ptr[-2].op == _MATCH0) {
                                                                            RE_as_arg() ;
			                                                                {
                                                                                /* see if // needs conversion */
                                                                                CELL* cp = (CELL*) code_ptr[-1].ptr ;
                                                                                if (REempty(cp->ptr)) {
                                                                                    cp->type = C_SNULL ;
                                                                                    cp->ptr = 0 ;
                                                                                }
                                                                            }
                                                                        }
                                                                        else {
                                                                            if ( code_ptr[-2].op == _PUSHS ) {
                                                                                CELL *cp = ZMALLOC(CELL) ;
                                                                                cp->type = C_STRING ;
                                                                                cp->ptr = code_ptr[-1].ptr ;
                                                                                cast_for_split(cp) ;
                                                                                code_ptr[-2].op = _PUSHC ;
                                                                                code_ptr[-1].ptr = (PTR) cp ;
                                                                            }
                                                                        }
                                                                    }
                                                                }
#line 3182 "y.tab.c" /* yacc.c:1667  */
    break;

  case 145:
#line 916 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = code_offset ;
                                                                    code2(_PUSHI,field) ;
                                                                    code2(_BUILTIN,bi_length) ;
                                                                }
#line 3191 "y.tab.c" /* yacc.c:1667  */
    break;

  case 146:
#line 920 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = code_offset ;
                                                                    code2(_PUSHI,field) ;
                                                                    code2(_BUILTIN,bi_length) ;
                                                                }
#line 3200 "y.tab.c" /* yacc.c:1667  */
    break;

  case 147:
#line 924 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = (yyvsp[-1].start) ;
                                                                    code2(_BUILTIN,bi_length) ;
	                                                            }
#line 3208 "y.tab.c" /* yacc.c:1667  */
    break;

  case 148:
#line 927 "parse.y" /* yacc.c:1667  */
    {   SYMTAB* stp = (yyvsp[-1].stp) ;
                                                                    (yyval.start) = code_offset ;
                                                                    switch(stp->type) {
                                                                        case ST_VAR:
                                                                            code2(_PUSHI, stp->stval.cp) ;
                                                                            code2(_BUILTIN, bi_length) ;
                                                                            break ;
                                                                        case ST_ARRAY:
                                                                            code2(A_PUSHA, stp->stval.array) ;
                                                                            code2(_BUILTIN, bi_alength) ;
                                                                            break ;
                                                                        case ST_LOCAL_VAR:
                                                                            code2op(L_PUSHI, stp->offset) ;
                                                                            code2(_BUILTIN, bi_length) ;
                                                                            break ;
                                                                        case ST_LOCAL_ARRAY:
                                                                            code2op(LA_PUSHA, stp->offset) ;
                                                                            code2(_BUILTIN, bi_alength) ;
                                                                            break ;
                                                                        case ST_NONE:
                                                                            /* could go on modified resolve list, but too much work to
                                                                                figure that out.  Will be patched at run time */
                                                                            code2(PI_LOAD, stp) ;
                                                                            code2(_BUILTIN, bi_length) ;
                                                                            break ;
                                                                        case ST_LOCAL_NONE:
                                                                            {   /* ditto, patched at run-time */
                                                                                Local_PI* pi = (Local_PI *)zmalloc(sizeof(Local_PI)) ;
                                                                            pi->fbp = active_funct ;
                                                                            pi->offset = stp->offset ;
                                                                            code2(LPI_LOAD, pi) ;
                                                                            code2(_BUILTIN, bi_length) ;
                                                                            }
                                                                            break ;
                                                                        default:
                                                                            type_error(stp) ;
                                                                            break ;
                                                                    }
                                                                }
#line 3252 "y.tab.c" /* yacc.c:1667  */
    break;

  case 149:
#line 969 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = (yyvsp[-3].start) ;
                                                                    code2(_BUILTIN, bi_match) ;
                                                                }
#line 3260 "y.tab.c" /* yacc.c:1667  */
    break;

  case 150:
#line 973 "parse.y" /* yacc.c:1667  */
    {   INST *p1 = CDP((yyvsp[0].start)) ;
                                                                    if ( p1 == code_ptr - 2 ) {
                                                                        if ( p1->op == _MATCH0 )
                                                                            RE_as_arg() ;
                                                                        else
                                                                            if ( p1->op == _PUSHS ) {
                                                                                CELL *cp = ZMALLOC(CELL) ;
                                                                                cp->type = C_STRING ;
                                                                                cp->ptr = p1[1].ptr ;
                                                                                cast_to_RE(cp) ;
                                                                                p1->op = _PUSHC ;
                                                                                p1[1].ptr = (PTR) cp ;
                                                                            }
                                                                    }
                                                                }
#line 3280 "y.tab.c" /* yacc.c:1667  */
    break;

  case 151:
#line 989 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = code_offset ;
                                                                    code1(_EXIT0) ;
                                                                }
#line 3288 "y.tab.c" /* yacc.c:1667  */
    break;

  case 152:
#line 992 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = (yyvsp[-1].start) ;
                                                                    code1(_EXIT) ;
                                                                }
#line 3296 "y.tab.c" /* yacc.c:1667  */
    break;

  case 153:
#line 995 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = code_offset ;
                                                                    code1(_RET0) ;
                                                                }
#line 3304 "y.tab.c" /* yacc.c:1667  */
    break;

  case 154:
#line 998 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = (yyvsp[-1].start) ;
                                                                    code1(_RET) ;
                                                                }
#line 3312 "y.tab.c" /* yacc.c:1667  */
    break;

  case 155:
#line 1002 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = code_offset ;
                                                                    code2(F_PUSHA, &field[0]) ;
                                                                    code1(_PUSHINT) ; code1(0) ;
                                                                    code2(_BUILTIN, bi_getline) ;
                                                                    getline_flag = 0 ;
                                                                }
#line 3323 "y.tab.c" /* yacc.c:1667  */
    break;

  case 156:
#line 1008 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = (yyvsp[0].start) ;
                                                                    code1(_PUSHINT) ; code1(0) ;
                                                                    code2(_BUILTIN, bi_getline) ;
                                                                    getline_flag = 0 ;
                                                                }
#line 3333 "y.tab.c" /* yacc.c:1667  */
    break;

  case 157:
#line 1013 "parse.y" /* yacc.c:1667  */
    {   code1(_PUSHINT) ;
                                                                    code1(F_IN) ;
                                                                    code2(_BUILTIN, bi_getline) ;
                                                                    /* getline_flag already off in yylex() */
                                                                }
#line 3343 "y.tab.c" /* yacc.c:1667  */
    break;

  case 158:
#line 1018 "parse.y" /* yacc.c:1667  */
    {   code2(F_PUSHA, &field[0]) ;
                                                                    code1(_PUSHINT) ; code1(PIPE_IN) ;
                                                                    code2(_BUILTIN, bi_getline) ;
                                                                }
#line 3352 "y.tab.c" /* yacc.c:1667  */
    break;

  case 159:
#line 1022 "parse.y" /* yacc.c:1667  */
    {   code1(_PUSHINT) ;
                                                                    code1(PIPE_IN) ;
                                                                    code2(_BUILTIN, bi_getline) ;
                                                                }
#line 3361 "y.tab.c" /* yacc.c:1667  */
    break;

  case 160:
#line 1028 "parse.y" /* yacc.c:1667  */
    {   getline_flag = 1 ;
                                                                }
#line 3368 "y.tab.c" /* yacc.c:1667  */
    break;

  case 163:
#line 1033 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = code_offset ;
                                                                    code2(F_PUSHA, field+0) ;
                                                                }
#line 3376 "y.tab.c" /* yacc.c:1667  */
    break;

  case 164:
#line 1036 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = (yyvsp[-1].start) ;
                                                                }
#line 3383 "y.tab.c" /* yacc.c:1667  */
    break;

  case 165:
#line 1043 "parse.y" /* yacc.c:1667  */
    {   INST *p5 = CDP((yyvsp[-1].start)) ;
                                                                    INST *p6 = CDP((yyvsp[0].start)) ;
                                                                    if ( p6 - p5 == 2 && p5->op == _PUSHS ) {
                                                                        /* cast from STRING to REPL at compile time */
                                                                        CELL *cp = ZMALLOC(CELL) ;
                                                                        cp->type = C_STRING ;
                                                                        cp->ptr = p5[1].ptr ;
                                                                        cast_to_REPL(cp) ;
                                                                        p5->op = _PUSHC ;
                                                                        p5[1].ptr = (PTR) cp ;
                                                                    }
                                                                    code2(_BUILTIN, (yyvsp[-5].fp)) ;
                                                                    (yyval.start) = (yyvsp[-3].start) ;
                                                                }
#line 3402 "y.tab.c" /* yacc.c:1667  */
    break;

  case 166:
#line 1058 "parse.y" /* yacc.c:1667  */
    {   (yyval.fp) = bi_sub ;
                                                                }
#line 3409 "y.tab.c" /* yacc.c:1667  */
    break;

  case 167:
#line 1060 "parse.y" /* yacc.c:1667  */
    {   (yyval.fp) = bi_gsub ;
                                                                }
#line 3416 "y.tab.c" /* yacc.c:1667  */
    break;

  case 168:
#line 1064 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = code_offset ;
                                                                    code2(F_PUSHA, &field[0]) ;
                                                                }
#line 3424 "y.tab.c" /* yacc.c:1667  */
    break;

  case 169:
#line 1067 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = (yyvsp[-1].start) ;
                                                                }
#line 3431 "y.tab.c" /* yacc.c:1667  */
    break;

  case 170:
#line 1073 "parse.y" /* yacc.c:1667  */
    {   resize_fblock((yyvsp[-1].fbp)) ;
                                                                    restore_ids() ;
                                                                    CODE_CLOSE_ACTIVE;
                                                                }
#line 3440 "y.tab.c" /* yacc.c:1667  */
    break;

  case 171:
#line 1078 "parse.y" /* yacc.c:1667  */
    {   EAT_NL_ ;
                                                                    scope        = SCOPE_FUNCT ;
                                                                    active_funct = (yyvsp[-3].fbp) ;
                                                                    *main_code_p = active_code ;
                                                                    (yyvsp[-3].fbp)->nargs    = (yyvsp[-1].ival) ;
                                                                    if ( (yyvsp[-1].ival) )
                                                                        (yyvsp[-3].fbp)->typev = (char *) memset(
                                                                            zmalloc((yyvsp[-1].ival)),
                                                                            ST_LOCAL_NONE,
                                                                            (yyvsp[-1].ival)
                                                                        ) ;
                                                                    else
                                                                        (yyvsp[-3].fbp)->typev = (char *) 0 ;
                                                                    code_ptr      =
                                                                    code_base     =
                                                                                    (INST *) zmalloc(INST_BYTES(PAGESZ))
                                                                    ;
                                                                    code_limit    = code_base + PAGESZ ;
                                                                    code_warn     = code_limit - CODEWARN ;
                                                                }
#line 3465 "y.tab.c" /* yacc.c:1667  */
    break;

  case 172:
#line 1099 "parse.y" /* yacc.c:1667  */
    {   FBLOCK  *fbp ;
                                                                    if ( (yyvsp[0].stp)->type == ST_NONE ) {
                                                                        (yyvsp[0].stp)->type = ST_FUNCT ;
                                                                        fbp               =
                                                                        (yyvsp[0].stp)->stval.fbp     =
                                                                                            (FBLOCK *) zmalloc(sizeof(FBLOCK)) ;
                                                                        fbp->name         = (yyvsp[0].stp)->name ;
                                                                        fbp->code         = (INST*) 0 ;
                                                                    }
                                                                    else {
                                                                        type_error( (yyvsp[0].stp) ) ;
                                                                        /* this FBLOCK will not be put in the symbol table */
                                                                        fbp       = (FBLOCK*) zmalloc(sizeof(FBLOCK)) ;
                                                                        fbp->name = "" ;
                                                                    }
                                                                    (yyval.fbp) = fbp ;
                                                                }
#line 3487 "y.tab.c" /* yacc.c:1667  */
    break;

  case 173:
#line 1116 "parse.y" /* yacc.c:1667  */
    {   (yyval.fbp) = (yyvsp[0].fbp) ;
                                                                    if ( (yyvsp[0].fbp)->code )
                                                                        compile_error("redefinition of %s" , (yyvsp[0].fbp)->name) ;
                                                                }
#line 3496 "y.tab.c" /* yacc.c:1667  */
    break;

  case 174:
#line 1121 "parse.y" /* yacc.c:1667  */
    {   (yyval.ival) = 0 ;
                                                                }
#line 3503 "y.tab.c" /* yacc.c:1667  */
    break;

  case 176:
#line 1126 "parse.y" /* yacc.c:1667  */
    {   (yyvsp[0].stp) = save_id((yyvsp[0].stp)->name) ;
                                                                    (yyvsp[0].stp)->type = ST_LOCAL_NONE ;
                                                                    (yyvsp[0].stp)->offset = 0 ;
                                                                    (yyval.ival) = 1 ;
                                                                }
#line 3513 "y.tab.c" /* yacc.c:1667  */
    break;

  case 177:
#line 1131 "parse.y" /* yacc.c:1667  */
    {   if ( is_local((yyvsp[0].stp)) )
                                                                        compile_error
                                                                            ("%s is duplicated in argument list",
                                                                            (yyvsp[0].stp)->name
                                                                        ) ;
                                                                    else {
                                                                        (yyvsp[0].stp) = save_id((yyvsp[0].stp)->name) ;
                                                                        (yyvsp[0].stp)->type = ST_LOCAL_NONE ;
                                                                        (yyvsp[0].stp)->offset = (yyvsp[-2].ival) ;
                                                                        (yyval.ival) = (yyvsp[-2].ival) + 1 ;
                                                                    }
                                                                }
#line 3530 "y.tab.c" /* yacc.c:1667  */
    break;

  case 178:
#line 1144 "parse.y" /* yacc.c:1667  */
    {   // we may have to recover from a bungled function definition
                                                                    // can have local ids, before code scope changes
                                                                    restore_ids() ;
                                                                    CODE_CLOSE_ACTIVE;
                                                                }
#line 3540 "y.tab.c" /* yacc.c:1667  */
    break;

  case 179:
#line 1151 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = (yyvsp[-1].start) ;
                                                                    code2(_CALL, (yyvsp[-2].fbp)) ;
                                                                    if ( (yyvsp[0].ca_p) )
                                                                        code1((yyvsp[0].ca_p)->arg_num+1) ;
                                                                    else
                                                                        code1(0) ;
                                                                    check_fcall(
                                                                        (yyvsp[-2].fbp),
                                                                        scope,
                                                                        code_move_level,
                                                                        active_funct,
                                                                        (yyvsp[0].ca_p),
                                                                        token_lineno
                                                                    ) ;
                                                                }
#line 3560 "y.tab.c" /* yacc.c:1667  */
    break;

  case 180:
#line 1167 "parse.y" /* yacc.c:1667  */
    {   (yyval.ca_p) = (CA_REC *) 0 ;
                                                                }
#line 3567 "y.tab.c" /* yacc.c:1667  */
    break;

  case 181:
#line 1169 "parse.y" /* yacc.c:1667  */
    {   (yyval.ca_p) = (yyvsp[0].ca_p) ;
                                                                    (yyval.ca_p)->link = (yyvsp[-1].ca_p) ;
                                                                    (yyval.ca_p)->arg_num = (yyvsp[-1].ca_p) ? (yyvsp[-1].ca_p)->arg_num+1 : 0 ;
                                                                }
#line 3576 "y.tab.c" /* yacc.c:1667  */
    break;

  case 182:
#line 1181 "parse.y" /* yacc.c:1667  */
    {   (yyval.ca_p) = (CA_REC *) 0 ;
                                                                }
#line 3583 "y.tab.c" /* yacc.c:1667  */
    break;

  case 183:
#line 1183 "parse.y" /* yacc.c:1667  */
    {   (yyval.ca_p) = ZMALLOC(CA_REC) ;
                                                                    (yyval.ca_p)->link = (yyvsp[-2].ca_p) ;
                                                                    (yyval.ca_p)->type = CA_EXPR  ;
                                                                    (yyval.ca_p)->arg_num = (yyvsp[-2].ca_p) ? (yyvsp[-2].ca_p)->arg_num+1 : 0 ;
                                                                    (yyval.ca_p)->call_offset = code_offset ;
                                                                }
#line 3594 "y.tab.c" /* yacc.c:1667  */
    break;

  case 184:
#line 1189 "parse.y" /* yacc.c:1667  */
    {   (yyval.ca_p) = ZMALLOC(CA_REC) ;
                                                                    (yyval.ca_p)->link = (yyvsp[-2].ca_p) ;
                                                                    (yyval.ca_p)->arg_num = (yyvsp[-2].ca_p) ? (yyvsp[-2].ca_p)->arg_num+1 : 0 ;
                                                                    code_call_id((yyval.ca_p), (yyvsp[-1].stp)) ;
                                                                }
#line 3604 "y.tab.c" /* yacc.c:1667  */
    break;

  case 185:
#line 1196 "parse.y" /* yacc.c:1667  */
    {   (yyval.ca_p) = ZMALLOC(CA_REC) ;
                                                                    (yyval.ca_p)->type = CA_EXPR ;
                                                                    (yyval.ca_p)->call_offset = code_offset ;
                                                                }
#line 3613 "y.tab.c" /* yacc.c:1667  */
    break;

  case 186:
#line 1200 "parse.y" /* yacc.c:1667  */
    {   (yyval.ca_p) = ZMALLOC(CA_REC) ;
                                                                    code_call_id((yyval.ca_p), (yyvsp[-1].stp)) ;
                                                                }
#line 3621 "y.tab.c" /* yacc.c:1667  */
    break;


#line 3625 "y.tab.c" /* yacc.c:1667  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 1204 "parse.y" /* yacc.c:1918  */


/* resize the code for a user function */

static void
resize_fblock( FBLOCK * fbp ) {
    CODEBLOCK *p = ZMALLOC(CODEBLOCK) ;
    unsigned dummy ;

    code2op(_RET0, _HALT) ;
        /* make sure there is always a return */

    *p = active_code ;
    fbp->code = code_shrink(p, &dummy) ;
        /* code_shrink() zfrees p */

    if ( dump_code_flag )
        add_to_fdump_list(fbp) ;
}


/* convert FE_PUSHA  to  FE_PUSHI
   or F_PUSH to F_PUSHI
*/

static void
field_A2I(void) {
    CELL *cp ;
    if ( code_ptr[-1].op == FE_PUSHA &&
        code_ptr[-1].ptr == (PTR) 0) {
        /*  On most architectures, the two tests are the same; a good
            compiler might eliminate one.  On LM_DOS, and possibly other
            segmented architectures, they are not */
        code_ptr[-1].op = FE_PUSHI ;
    }
    else {
        cp = (CELL *) code_ptr[-1].ptr ;
        if ( cp == field  || (cp > NF && cp <= LAST_PFIELD) ) {
            code_ptr[-2].op = _PUSHI  ;
        }
        else if ( cp == NF ) {
            code_ptr[-2].op = NF_PUSHI ; code_ptr-- ;
        }
        else {
            code_ptr[-2].op = F_PUSHI ;
            code_ptr -> op = field_addr_to_index( (CELL *)code_ptr[-1].ptr ) ;
            code_ptr++ ;
        }
    }
}

/* we've seen an ID in a context where it should be a VAR,
   check that's consistent with previous usage */

static void
check_var(SYMTAB * p ) {
    switch (p->type) {
        case ST_NONE : /* new id */
            p->type = ST_VAR ;
            p->stval.cp = ZMALLOC(CELL) ;
            p->stval.cp->type = C_NOINIT ;
            break ;
        case ST_LOCAL_NONE :
            p->type = ST_LOCAL_VAR ;
            active_funct->typev[p->offset] = ST_LOCAL_VAR ;
            break ;
        case ST_VAR :
        case ST_LOCAL_VAR :
            break ;
        default :
            type_error(p) ;
            break ;
    }
}

/* we've seen an ID in a context where it should be an ARRAY,
   check that's consistent with previous usage */
static void
check_array(SYMTAB *p) {
    switch (p->type) {
        case ST_NONE :  /* a new array */
            p->type = ST_ARRAY ;
            p->stval.array = new_ARRAY() ;
            break ;
        case  ST_ARRAY :
        case  ST_LOCAL_ARRAY :
            break ;
        case  ST_LOCAL_NONE  :
            p->type = ST_LOCAL_ARRAY ;
            active_funct->typev[p->offset] = ST_LOCAL_ARRAY ;
            break ;
        default :
            type_error(p) ;
            break ;
    }
}

static void
code_array(SYMTAB* p) {
    if ( is_local(p) )
        code2op(LA_PUSHA, p->offset) ;
    else
        code2(A_PUSHA, p->stval.array) ;
}

/* we've seen an ID as an argument to a user defined function */

static void
code_call_id(CA_REC * p, SYMTAB * ip ) {
    static CELL dummy ;

    p->call_offset = code_offset ;
    /* This always get set now.  So that fcall:relocate_arglist
	works. */
    switch( ip->type ) {
        case  ST_VAR  :
            p->type = CA_EXPR ;
            code2(_PUSHI, ip->stval.cp) ;
            break ;
        case  ST_LOCAL_VAR  :
            p->type = CA_EXPR ;
            code2op(L_PUSHI, ip->offset) ;
            break ;
        case  ST_ARRAY  :
            p->type = CA_ARRAY ;
            code2(A_PUSHA, ip->stval.array) ;
            break ;
        case  ST_LOCAL_ARRAY :
            p->type = CA_ARRAY ;
            code2op(LA_PUSHA, ip->offset) ;
            break ;
        /*
        not enough info to code it now; it will have to
        be patched later */
        case  ST_NONE :
            p->type = ST_NONE ;
            p->sym_p = ip ;
            code2(_PUSHI, &dummy) ;
            break ;
        case  ST_LOCAL_NONE :
            p->type = ST_LOCAL_NONE ;
            p->type_p = & active_funct->typev[ip->offset] ;
            code2op(L_PUSHI, ip->offset) ;
            break ;

#ifdef  DEBUG
        default :
            bozo("code_call_id") ;
#endif
    }
}

/*
an RE by itself was coded as _MATCH0 , change to
push as an expression */
static void
RE_as_arg(void) {
    CELL *cp = ZMALLOC(CELL) ;
    code_ptr -= 2 ;
    cp->type = C_RE ;
    cp->ptr = code_ptr[1].ptr ;
    code2(_PUSHC, cp) ;
}

void
parse(void) {
    if ( yyparse() || compile_error_count != 0 )
        mawk_exit(2) ;
    scan_cleanup() ;
    set_code() ;
    /* code must be set before call to resolve_fcalls() */
    if ( resolve_list )
        resolve_fcalls() ;
    if ( compile_error_count != 0 )
        mawk_exit(2) ;
    if ( dump_code_flag ) {
        dump_code() ;
        mawk_exit(0) ;
    }
}
