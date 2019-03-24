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
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 17 "parse.y" /* yacc.c:337  */

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
#include "printf.h"


#define  YYMAXDEPTH	200


extern void   eat_nl(void) ;
static void   resize_fblock(FBLOCK *) ;
static void   switch_code_to_main(void) ;
static void   code_array(SYMTAB *) ;
static void   code_call_id(CA_REC *, SYMTAB *) ;
static void   field_A2I(void) ;
static void   check_var(SYMTAB *) ;
static void   check_array(SYMTAB *) ;
static void   RE_as_arg(void) ;
int REempty(PTR) ;

static int scope ;
static FBLOCK *active_funct ;
      /* when scope is SCOPE_FUNCT  */

#define  code_address(x)  if( is_local(x) ) \
			     code2op(L_PUSHA, (x)->offset) ;\
                          else  code2(_PUSHA, (x)->stval.cp)

#define  CDP(x)  (code_base+(x))
/* WARNING: These CDP() calculations become invalid after calls
   that might change code_base.  Which are:  code2(), code2op(),
   code_jmp() and code_pop().
*/

/* this nonsense caters to MSDOS large model */
#define  CODE_FE_PUSHA()  code_ptr->ptr = (PTR) 0 ; code1(FE_PUSHA)


#line 117 "y.tab.c" /* yacc.c:337  */
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
#line 64 "parse.y" /* yacc.c:352  */

CELL *cp ;
SYMTAB *stp ;
int  start ; /* code starting address as offset from code_base */
PF_CP  fp ;  /* ptr to a (print/printf) or (sub/gsub) function */
BI_REC *bip ; /* ptr to info about a builtin */
FBLOCK  *fbp  ; /* ptr to a function block */
ARG2_REC *arg2p ;
CA_REC   *ca_p  ;
int   ival ;
PTR   ptr ;

#line 329 "y.tab.c" /* yacc.c:352  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

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
#define YYFINAL  98
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1312

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  79
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  59
/* YYNRULES -- Number of rules.  */
#define YYNRULES  183
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  364

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
       0,   141,   141,   142,   145,   146,   147,   150,   156,   155,
     162,   161,   168,   167,   175,   191,   174,   204,   206,   212,
     213,   219,   220,   224,   225,   227,   229,   235,   238,   241,
     245,   251,   259,   259,   262,   263,   264,   265,   266,   267,
     268,   269,   270,   271,   272,   273,   274,   275,   277,   305,
     304,   312,   311,   318,   319,   318,   324,   325,   329,   331,
     333,   341,   345,   349,   350,   351,   352,   353,   354,   355,
     357,   359,   361,   364,   372,   379,   383,   390,   399,   400,
     403,   405,   410,   429,   433,   444,   452,   466,   469,   483,
     491,   501,   514,   519,   524,   525,   529,   533,   538,   542,
     543,   550,   555,   559,   563,   571,   576,   582,   602,   628,
     652,   653,   657,   658,   675,   679,   692,   697,   708,   721,
     733,   750,   758,   769,   783,   800,   802,   811,   825,   827,
     831,   835,   836,   837,   838,   839,   840,   841,   847,   851,
     858,   860,   895,   900,   905,   909,   957,   964,   987,   990,
     993,   996,  1001,  1008,  1014,  1019,  1024,  1031,  1033,  1033,
    1035,  1039,  1047,  1066,  1067,  1071,  1076,  1084,  1093,  1112,
    1135,  1142,  1143,  1146,  1152,  1165,  1178,  1190,  1192,  1207,
    1209,  1216,  1225,  1231
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
  "NEXTFILE", "RETURN", "FUNCTION", "$accept", "program", "program_block",
  "PA_block", "$@1", "$@2", "$@3", "$@4", "$@5", "block",
  "block_or_separator", "statement_list", "statement", "separator", "expr",
  "$@6", "$@7", "$@8", "$@9", "cat_expr", "p_expr", "lvalue", "arglist",
  "args", "builtin", "string_comma", "mark", "pmark", "printf_args",
  "pr_args", "arg2", "pr_direction", "if_front", "else", "do",
  "while_front", "for1", "for2", "for3", "array_loop_front", "field",
  "split_front", "split_back", "re_arg", "return_statement", "getline",
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

#define YYPACT_NINF -241

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-241)))

#define YYTABLE_NINF -119

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-119)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     362,  -241,   545,  -241,   906,   906,   906,    49,   514,  -241,
     937,  -241,  -241,  -241,   371,  -241,  -241,   -42,   -19,    -4,
    -241,  -241,  -241,  -241,  -241,   -32,   305,  -241,  -241,  -241,
    1215,   906,   149,   357,  -241,   413,     7,   123,   906,    -2,
    -241,    47,    25,    47,    19,  -241,  -241,  -241,  -241,  -241,
      46,    96,    98,    98,   101,    64,   689,    98,    98,   689,
    -241,   468,  -241,  -241,  1167,   622,   622,   622,   720,   622,
    -241,   937,    93,   -30,    55,   -30,   -30,    30,   141,  -241,
    -241,   141,  -241,    10,    12,   285,  -241,   153,   124,   127,
     591,   937,   937,   146,    47,    47,  -241,  -241,  -241,  -241,
    -241,  -241,  -241,  -241,   129,   937,   937,   937,   937,   937,
     937,   937,   140,   149,   906,   906,   906,   906,   906,   162,
     906,   937,   937,   937,   937,   937,   937,   937,   937,   937,
     937,   937,   937,   937,   937,  -241,   937,  -241,  -241,  -241,
    -241,  -241,   155,    76,   937,  -241,   145,  -241,  -241,  -241,
     968,   999,   937,   751,  -241,  -241,   937,    98,  -241,  1167,
    -241,  -241,  -241,  1167,    98,  -241,  -241,  -241,   135,   148,
    -241,  -241,  1179,   782,  -241,   681,   202,   169,   207,   209,
     937,  -241,   937,   203,  -241,   937,   181,  -241,  1030,   937,
    -241,    69,  1074,  1236,  1257,   813,  -241,  -241,   937,   937,
     937,   937,  -241,   687,  -241,  -241,  -241,  -241,  -241,  -241,
    -241,  -241,  -241,   183,   183,   -30,   -30,   -30,    49,   188,
    1281,  1281,  1281,  1281,  1281,  1281,  1281,  1281,  1281,  1281,
    1281,  1281,  1281,  1281,  1086,  -241,  1281,   228,  -241,   194,
     232,   844,  1281,  -241,   233,   235,   875,   234,   937,   235,
    1101,  -241,   428,  1194,  1113,  -241,   244,  -241,  -241,  -241,
     622,   211,  -241,  -241,  1128,   622,   937,   937,   937,  1281,
    1281,   204,   144,  -241,   219,   246,  -241,   230,  -241,  -241,
     227,   937,  -241,    31,   937,  1281,  1269,   467,   454,  -241,
    -241,   937,  -241,   231,  -241,    41,   937,   937,    98,   937,
    -241,   233,   235,    98,  -241,   236,  -241,  -241,   937,  -241,
     937,  -241,  -241,   156,   166,   168,  -241,   445,  -241,  -241,
    -241,  -241,  -241,  -241,   237,  -241,    52,   140,  -241,   297,
    -241,   203,  1281,  1281,  -241,   238,    98,  -241,   239,   179,
    1140,   215,  -241,  -241,  -241,  -241,  -241,  -241,   937,    49,
    -241,  -241,   235,  -241,  -241,    98,    98,  1281,   242,    98,
    -241,  -241,  -241,  -241
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   175,     0,   157,     0,     0,     0,     0,     0,   125,
       0,    58,    59,    62,    60,    87,    87,   142,     0,     0,
     163,   164,    87,     8,    10,     0,     0,     2,     4,     7,
      12,    34,    56,     0,    72,   130,     0,   152,     0,     0,
       5,     0,     0,     0,     0,    32,    33,    92,    92,   105,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      23,     0,    21,    25,     0,     0,     0,     0,     0,     0,
      29,     0,    60,    70,   130,    71,    69,     0,    77,    74,
      76,   126,   128,     0,     0,   130,    73,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   169,   170,     1,     3,
      14,    53,    49,    51,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    57,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    75,     0,   140,   138,   160,
     158,   159,   153,   154,     0,   167,   171,     6,    18,    26,
      78,    78,     0,     0,    27,    28,     0,    87,   148,     0,
      30,    31,   150,     0,     0,    17,    22,    24,   102,     0,
     108,   112,     0,     0,   124,     0,     0,     0,     0,     0,
       0,    61,     0,     0,   129,     0,   179,   176,     0,    78,
     143,    60,     0,     0,     0,     0,     9,    11,     0,     0,
       0,     0,   116,    48,    42,    43,    44,    45,    46,    47,
      19,    13,    20,    63,    64,    65,    66,    67,   155,    68,
      35,    36,    37,    38,    39,    40,    41,   131,   132,   133,
     134,   135,   136,   137,     0,   161,   147,     0,   173,     0,
     172,     0,    80,    94,    79,    99,     0,    59,     0,    99,
       0,   110,    60,     0,     0,   122,     0,   149,   151,   103,
       0,     0,   113,   114,     0,     0,     0,     0,     0,    97,
      98,     0,     0,   177,    60,     0,   178,     0,   145,   144,
       0,     0,    83,     0,     0,    15,     0,    50,    52,   156,
     141,     0,   168,     0,    96,     0,     0,     0,     0,     0,
      86,    93,    99,     0,   107,     0,   111,   101,     0,   104,
       0,   115,   109,     0,     0,     0,   117,   119,   181,   183,
     180,   182,    82,   139,     0,    85,     0,     0,    54,     0,
     174,    95,    81,   100,    88,     0,     0,    89,     0,     0,
       0,   119,   118,   127,   120,   146,    84,    16,     0,     0,
     165,   162,    99,    90,   123,     0,     0,    55,     0,     0,
     121,   106,   166,    91
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -241,  -241,   254,  -241,  -241,  -241,  -241,  -241,  -241,     3,
     -45,  -241,   -50,   150,     0,  -241,  -241,  -241,  -241,  -241,
     134,    -6,   103,   -44,  -241,  -189,    -8,   245,    16,   160,
     306,  -240,  -241,  -241,  -241,  -241,  -241,  -241,  -241,  -241,
      43,  -241,  -241,    14,  -241,  -241,  -214,  -241,  -241,  -241,
    -241,  -241,  -241,  -241,  -241,  -241,  -241,  -241,  -241
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    26,    27,    28,    94,    95,   112,   198,   327,    60,
     211,    61,    62,    63,   242,   200,   201,   199,   348,    31,
      32,    33,   243,   244,    34,   248,    87,   150,   302,   245,
     295,   298,    65,   260,    66,    67,    68,   173,   265,    69,
      35,    36,   138,   237,    70,    37,   142,    38,    39,   351,
      40,    41,    42,   239,   240,    43,   187,   188,   276
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      30,    79,    64,    29,   289,    90,   284,    88,    89,   303,
      83,   166,   119,   120,    93,   168,   169,   170,   136,   174,
      96,   180,    97,   182,    45,    46,    30,   148,    91,    29,
     101,   140,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   296,    92,   145,   144,   147,    74,    74,    74,
      80,    74,   182,    85,     2,   137,   159,   299,   181,   163,
     183,    64,   336,   296,   176,    64,    64,    64,   172,    64,
     178,   175,   146,   179,    74,     8,     9,    77,   -87,   325,
     141,    74,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   331,
     192,   193,   194,   152,     8,     9,    77,   196,   197,   135,
     346,    78,   -87,    45,    46,   203,   204,   205,   206,   207,
     208,   209,   359,    86,    85,   210,   157,   278,  -119,   120,
     177,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   358,   234,    86,    73,    75,
      76,   272,    82,   153,   236,    45,    46,     2,   156,   256,
     -87,   283,   250,   253,   317,   296,   254,    74,    74,    74,
      74,    74,   185,    74,   139,   113,   341,   296,     8,     9,
      77,   186,   143,   264,   189,    78,   342,   296,   343,   296,
     269,   202,   270,   114,   115,   116,   117,   118,   275,   355,
     296,   119,   120,   195,   149,   218,   235,   238,   285,   286,
     287,   288,   154,   155,   301,   259,   158,   160,   161,   162,
     309,   266,   140,   261,   167,   312,   267,   184,   268,   116,
     117,   118,   313,   314,   315,   119,   120,   271,   -87,   273,
     318,   120,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   291,
     326,    83,   292,   293,   296,   300,    83,   297,   213,   214,
     215,   216,   217,   308,   219,   301,   316,   320,   310,   344,
      64,   141,   212,    86,   339,    64,   101,   319,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   322,   323,
      99,   236,   347,   330,    85,   345,   352,   354,   338,    85,
     362,   329,   277,   151,   321,   324,   332,   333,   128,   129,
     130,   131,   132,   133,   134,    98,     1,   255,   349,   257,
     340,   249,     2,   258,   149,   335,    84,   101,     0,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   135,
     210,     0,     0,   184,     0,     0,     0,     0,     3,     4,
       5,     0,     0,   140,     6,   350,     0,     0,   357,     7,
       8,     9,    10,     0,    11,    12,    13,    14,     0,    15,
      16,    17,     0,     1,    18,    19,    20,    21,    22,     2,
     121,   122,   123,   124,   125,   126,   127,    23,    24,     0,
     -87,     0,     0,    25,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,     0,   141,     0,     0,     3,     4,     5,     0,     0,
       0,     6,     0,     0,     0,     0,     7,     8,     9,    10,
       0,    11,    12,    13,    14,    86,    15,    16,    17,     0,
       0,    18,    19,    20,    21,    22,   128,   129,   130,   131,
     132,   133,   134,     0,    23,    24,     0,   -87,     0,     0,
      25,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   334,     0,
       0,     0,   305,   337,     0,     0,     0,   135,  -118,  -118,
    -118,  -118,  -118,  -118,  -118,     0,     0,     0,     0,   164,
       0,     0,    86,    45,    46,     2,   165,   212,   104,   105,
     106,   107,   108,   109,   110,   111,   353,     0,     0,   344,
     103,   104,   105,   106,   107,   108,   109,   110,   111,     0,
       0,     3,     4,     5,     0,   360,   361,     6,     0,   363,
       0,     0,     7,     8,     9,    10,     0,    11,    12,    13,
      14,     0,    15,    16,    17,    47,    48,    18,    19,    20,
      21,    22,    49,    50,    51,    52,    53,    54,     0,    55,
       0,     0,    56,    57,    58,    59,    44,     3,     4,     5,
      45,    46,     2,     6,     0,     0,     0,     0,     7,     8,
       9,    71,     0,    11,    12,    13,    72,    81,    15,    16,
      17,     0,     0,    18,    19,    20,    21,    22,     3,     4,
       5,     0,     0,     0,     6,     0,     0,     0,     0,     7,
       8,     9,    10,     0,    11,    12,    13,    14,     0,    15,
      16,    17,    47,    48,    18,    19,    20,    21,    22,    49,
      50,    51,    52,    53,    54,     0,    55,     0,     0,    56,
      57,    58,    59,   164,     3,     4,     5,    45,    46,     2,
       6,     0,     0,     0,     0,     7,     8,     9,    10,   190,
      11,    12,    13,   191,     0,    15,    16,    17,     0,     0,
      18,    19,    20,    21,    22,     3,     4,     5,     0,     0,
       0,     6,     0,     0,     0,     0,     7,     8,     9,    10,
       0,    11,    12,    13,    14,     0,    15,    16,    17,    47,
      48,    18,    19,    20,    21,    22,    49,    50,    51,    52,
      53,    54,     0,    55,    45,    46,    56,    57,    58,    59,
       0,   101,     0,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   106,   107,   108,   109,   110,   111,     0,
       0,     0,     3,     4,     5,     0,   171,     0,     6,   181,
       0,     0,     0,     7,     8,     9,    10,     0,    11,    12,
      13,    14,     0,    15,    16,    17,     0,     0,    18,    19,
      20,    21,    22,     3,     4,     5,     0,   251,     0,     6,
       0,     0,     0,     0,     7,     8,     9,    10,     0,    11,
      12,    13,    14,     0,    15,    16,    17,     0,     0,    18,
      19,    20,    21,    22,     3,     4,     5,     0,     0,     0,
       6,     0,     0,     0,     0,     7,     8,     9,    10,     0,
      11,    12,    13,   252,     0,    15,    16,    17,     0,     0,
      18,    19,    20,    21,    22,     3,     4,     5,     0,     0,
       0,     6,     0,     0,     0,     0,     7,     8,     9,    10,
     263,    11,    12,    13,    14,     0,    15,    16,    17,     0,
       0,    18,    19,    20,    21,    22,     3,     4,     5,     0,
       0,     0,     6,     0,     0,     0,     0,     7,     8,     9,
      10,   282,    11,   247,    13,    14,     0,    15,    16,    17,
       0,     0,    18,    19,    20,    21,    22,     3,     4,     5,
       0,     0,     0,     6,     0,     0,     0,     0,     7,     8,
       9,    10,   294,    11,    12,    13,    14,     0,    15,    16,
      17,     0,     0,    18,    19,    20,    21,    22,     3,     4,
       5,     0,     0,     0,     6,     0,     0,     0,     0,     7,
       8,     9,    10,   294,    11,   247,    13,    14,     0,    15,
      16,    17,     0,     0,    18,    19,    20,    21,    22,     3,
       4,     5,     0,     0,     0,     6,     0,     0,     0,     0,
       7,     8,     9,    71,     0,    11,    12,    13,    72,     0,
      15,    16,    17,     0,     0,    18,    19,    20,    21,    22,
       3,     4,     5,     0,     0,     0,     6,     0,     0,     0,
       0,     7,     8,     9,    10,     0,    11,    12,    13,    14,
       0,    15,    16,    17,     0,     0,    18,    19,    20,    21,
      22,     3,     4,     5,     0,     0,     0,     6,     0,     0,
       0,     0,     7,     8,     9,   241,     0,    11,    12,    13,
      14,     0,    15,    16,    17,     0,     0,    18,    19,    20,
      21,    22,     3,     4,     5,     0,     0,     0,     6,     0,
       0,     0,     0,     7,     8,     9,   246,     0,    11,   247,
      13,    14,     0,    15,    16,    17,     0,     0,    18,    19,
      20,    21,    22,     3,     4,     5,     0,     0,     0,     6,
       0,     0,     0,     0,     7,     8,     9,    10,     0,    11,
      12,    13,   274,     0,    15,    16,    17,     0,     0,    18,
      19,    20,    21,    22,   101,     0,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   101,     0,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,     0,     0,
       0,   101,   279,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   101,   290,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,     0,     0,     0,   101,   304,
     102,   103,   104,   105,   106,   107,   108,   109,   110,   111,
     101,   307,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,    45,    46,     0,     0,   311,     0,     0,     0,
       0,     0,     0,     0,     0,   262,     0,   101,   356,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   101,
     306,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,     0,     0,     0,   101,     0,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   100,     0,     0,     0,
       0,     0,     0,     0,     0,   101,     0,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   280,     0,     0,
       0,     0,     0,     0,     0,     0,   101,     0,   102,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   281,     0,
       0,     0,     0,     0,     0,     0,     0,   101,     0,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   101,
     328,   102,   103,   104,   105,   106,   107,   108,   109,   110,
     111,   101,     0,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111
};

static const yytype_int16 yycheck[] =
{
       0,     7,     2,     0,   218,    47,   195,    15,    16,   249,
      10,    61,    42,    43,    22,    65,    66,    67,    11,    69,
      52,    11,    54,    11,     5,     6,    26,     8,    47,    26,
      20,    37,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    11,    47,    41,    47,    43,     4,     5,     6,
       7,     8,    11,    10,     7,    48,    56,   246,    48,    59,
      48,    61,   302,    11,    72,    65,    66,    67,    68,    69,
      78,    71,    47,    81,    31,    45,    46,    47,     9,    48,
      37,    38,    13,    14,    15,    16,    17,    18,    19,    48,
      90,    91,    92,    47,    45,    46,    47,    94,    95,    44,
      48,    52,     9,     5,     6,   105,   106,   107,   108,   109,
     110,   111,   352,    44,    71,   112,    52,    48,    42,    43,
      77,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   349,   136,    44,     4,     5,
       6,   185,     8,    47,   144,     5,     6,     7,    47,   157,
       9,   195,   152,   153,    10,    11,   156,   114,   115,   116,
     117,   118,     9,   120,    41,    31,    10,    11,    45,    46,
      47,    47,    38,   173,    47,    52,    10,    11,    10,    11,
     180,    52,   182,    34,    35,    36,    37,    38,   188,    10,
      11,    42,    43,    47,    44,    33,    41,    52,   198,   199,
     200,   201,    52,    53,   248,    70,    56,    57,    58,    59,
     260,     9,   218,    65,    64,   265,     9,    48,     9,    36,
      37,    38,   266,   267,   268,    42,    43,    24,     9,    48,
      11,    43,    13,    14,    15,    16,    17,    18,    19,    11,
     284,   241,    48,    11,    11,    11,   246,    12,   114,   115,
     116,   117,   118,     9,   120,   299,    52,    11,    47,    44,
     260,   218,   112,    44,   308,   265,    20,    48,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    48,    52,
      26,   281,   327,    52,   241,    48,    48,    48,    52,   246,
      48,   291,   189,    48,    48,   281,   296,   297,    13,    14,
      15,    16,    17,    18,    19,     0,     1,   157,    11,   159,
     310,   151,     7,   163,   164,   299,    10,    20,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    44,
     327,    -1,    -1,    48,    -1,    -1,    -1,    -1,    33,    34,
      35,    -1,    -1,   349,    39,    48,    -1,    -1,   348,    44,
      45,    46,    47,    -1,    49,    50,    51,    52,    -1,    54,
      55,    56,    -1,     1,    59,    60,    61,    62,    63,     7,
      13,    14,    15,    16,    17,    18,    19,    72,    73,    -1,
       9,    -1,    -1,    78,    13,    14,    15,    16,    17,    18,
      19,    -1,   349,    -1,    -1,    33,    34,    35,    -1,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      -1,    49,    50,    51,    52,    44,    54,    55,    56,    -1,
      -1,    59,    60,    61,    62,    63,    13,    14,    15,    16,
      17,    18,    19,    -1,    72,    73,    -1,     9,    -1,    -1,
      78,    13,    14,    15,    16,    17,    18,    19,   298,    -1,
      -1,    -1,    24,   303,    -1,    -1,    -1,    44,    13,    14,
      15,    16,    17,    18,    19,    -1,    -1,    -1,    -1,     1,
      -1,    -1,    44,     5,     6,     7,     8,   327,    24,    25,
      26,    27,    28,    29,    30,    31,   336,    -1,    -1,    44,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    -1,
      -1,    33,    34,    35,    -1,   355,   356,    39,    -1,   359,
      -1,    -1,    44,    45,    46,    47,    -1,    49,    50,    51,
      52,    -1,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    -1,    71,
      -1,    -1,    74,    75,    76,    77,     1,    33,    34,    35,
       5,     6,     7,    39,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    -1,    -1,    59,    60,    61,    62,    63,    33,    34,
      35,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    -1,    49,    50,    51,    52,    -1,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    71,    -1,    -1,    74,
      75,    76,    77,     1,    33,    34,    35,     5,     6,     7,
      39,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    -1,    54,    55,    56,    -1,    -1,
      59,    60,    61,    62,    63,    33,    34,    35,    -1,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      -1,    49,    50,    51,    52,    -1,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    -1,    71,     5,     6,    74,    75,    76,    77,
      -1,    20,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    26,    27,    28,    29,    30,    31,    -1,
      -1,    -1,    33,    34,    35,    -1,     6,    -1,    39,    48,
      -1,    -1,    -1,    44,    45,    46,    47,    -1,    49,    50,
      51,    52,    -1,    54,    55,    56,    -1,    -1,    59,    60,
      61,    62,    63,    33,    34,    35,    -1,     6,    -1,    39,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    -1,    49,
      50,    51,    52,    -1,    54,    55,    56,    -1,    -1,    59,
      60,    61,    62,    63,    33,    34,    35,    -1,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    44,    45,    46,    47,    -1,
      49,    50,    51,    52,    -1,    54,    55,    56,    -1,    -1,
      59,    60,    61,    62,    63,    33,    34,    35,    -1,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    -1,    54,    55,    56,    -1,
      -1,    59,    60,    61,    62,    63,    33,    34,    35,    -1,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    -1,    54,    55,    56,
      -1,    -1,    59,    60,    61,    62,    63,    33,    34,    35,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    -1,    54,    55,
      56,    -1,    -1,    59,    60,    61,    62,    63,    33,    34,
      35,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    -1,    54,
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
      62,    63,    33,    34,    35,    -1,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    44,    45,    46,    47,    -1,    49,    50,
      51,    52,    -1,    54,    55,    56,    -1,    -1,    59,    60,
      61,    62,    63,    33,    34,    35,    -1,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    -1,    49,
      50,    51,    52,    -1,    54,    55,    56,    -1,    -1,    59,
      60,    61,    62,    63,    20,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    20,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    -1,    -1,
      -1,    20,    48,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    20,    48,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    -1,    -1,    -1,    20,    48,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      20,    48,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,     5,     6,    -1,    -1,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     6,    -1,    20,    48,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    20,
       6,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    -1,    -1,    -1,    20,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    11,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    -1,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    11,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    20,    -1,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     7,    33,    34,    35,    39,    44,    45,    46,
      47,    49,    50,    51,    52,    54,    55,    56,    59,    60,
      61,    62,    63,    72,    73,    78,    80,    81,    82,    88,
      93,    98,    99,   100,   103,   119,   120,   124,   126,   127,
     129,   130,   131,   134,     1,     5,     6,    57,    58,    64,
      65,    66,    67,    68,    69,    71,    74,    75,    76,    77,
      88,    90,    91,    92,    93,   111,   113,   114,   115,   118,
     123,    47,    52,    99,   119,    99,    99,    47,    52,   100,
     119,    53,    99,    93,   109,   119,    44,   105,   105,   105,
      47,    47,    47,   105,    83,    84,    52,    54,     0,    81,
      11,    20,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    85,    99,    34,    35,    36,    37,    38,    42,
      43,    13,    14,    15,    16,    17,    18,    19,    13,    14,
      15,    16,    17,    18,    19,    44,    11,    48,   121,    41,
     100,   119,   125,    99,    47,    88,    47,    88,     8,    92,
     106,   106,    47,    47,    92,    92,    47,    52,    92,    93,
      92,    92,    92,    93,     1,     8,    91,    92,    91,    91,
      91,     6,    93,   116,    91,    93,   105,   119,   105,   105,
      11,    48,    11,    48,    48,     9,    47,   135,   136,    47,
      48,    52,    93,    93,    93,    47,    88,    88,    86,    96,
      94,    95,    52,    93,    93,    93,    93,    93,    93,    93,
      88,    89,    92,    99,    99,    99,    99,    99,    33,    99,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    41,    93,   122,    52,   132,
     133,    47,    93,   101,   102,   108,    47,    50,   104,   108,
      93,     6,    52,    93,    93,    92,   105,    92,    92,    70,
     112,    65,     6,    48,    93,   117,     9,     9,     9,    93,
      93,    24,   102,    48,    52,    93,   137,   101,    48,    48,
      11,    11,    48,   102,   104,    93,    93,    93,    93,   125,
      48,    11,    48,    11,    48,   109,    11,    12,   110,   104,
      11,   102,   107,   110,    48,    24,     6,    48,     9,    91,
      47,    48,    91,   102,   102,   102,    52,    10,    11,    48,
      11,    48,    48,    52,   122,    48,   102,    87,    21,    93,
      52,    48,    93,    93,    92,   107,   110,    92,    52,   102,
      93,    10,    10,    10,    44,    48,    48,    89,    97,    11,
      48,   128,    48,    92,    48,    10,    48,    93,   125,   110,
      92,    92,    48,    92
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    79,    80,    80,    81,    81,    81,    82,    83,    82,
      84,    82,    85,    82,    86,    87,    82,    88,    88,    89,
      89,    90,    90,    91,    91,    91,    91,    91,    91,    91,
      91,    91,    92,    92,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    94,
      93,    95,    93,    96,    97,    93,    98,    98,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,    99,    99,    99,   100,   101,   101,
     102,   102,   103,   103,   103,   103,   104,   105,    91,    91,
      91,    91,   106,   107,   108,   108,   108,   109,   109,   110,
     110,   111,    91,   112,    91,   113,    91,   114,    91,    91,
     115,   115,   116,   116,   117,   117,    93,    93,   100,    99,
      99,    91,    91,   118,    91,   119,   119,   119,   119,   119,
      99,    93,    93,    93,    93,    93,    93,    93,    99,   120,
     121,   121,    99,    99,    99,    99,    99,   122,    91,    91,
     123,   123,    99,    99,    99,    99,    99,   124,   125,   125,
     126,   126,    99,   127,   127,   128,   128,   129,   130,   131,
     131,   132,   132,   133,   133,   134,    99,   135,   135,   136,
     136,   136,   137,   137
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     2,     1,     0,     3,
       0,     3,     0,     3,     0,     0,     6,     3,     3,     1,
       1,     1,     2,     1,     2,     1,     2,     2,     2,     1,
       2,     2,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     0,
       4,     0,     4,     0,     0,     7,     1,     2,     1,     1,
       1,     3,     1,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     1,     2,     2,     2,     2,     1,     0,     1,
       1,     3,     5,     4,     6,     5,     2,     0,     5,     5,
       6,     8,     0,     1,     1,     3,     2,     3,     3,     0,
       2,     4,     2,     1,     4,     1,     7,     4,     2,     4,
       3,     4,     1,     2,     1,     2,     3,     5,     5,     5,
       6,     7,     3,     6,     2,     1,     2,     6,     2,     3,
       1,     3,     3,     3,     3,     3,     3,     3,     2,     5,
       1,     3,     1,     3,     4,     4,     6,     1,     2,     3,
       2,     3,     1,     2,     2,     3,     4,     1,     1,     1,
       2,     3,     6,     1,     1,     1,     3,     2,     4,     2,
       2,     0,     1,     1,     3,     1,     3,     2,     2,     1,
       3,     3,     2,     2
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




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
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
      yychar = yylex ();
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
        case 7:
#line 151 "parse.y" /* yacc.c:1667  */
    { /* this do nothing action removes a vacuous warning
                  from Bison */
             }
#line 1879 "y.tab.c" /* yacc.c:1667  */
    break;

  case 8:
#line 156 "parse.y" /* yacc.c:1667  */
    { be_setup(scope = SCOPE_BEGIN) ; }
#line 1885 "y.tab.c" /* yacc.c:1667  */
    break;

  case 9:
#line 159 "parse.y" /* yacc.c:1667  */
    { switch_code_to_main() ; }
#line 1891 "y.tab.c" /* yacc.c:1667  */
    break;

  case 10:
#line 162 "parse.y" /* yacc.c:1667  */
    { be_setup(scope = SCOPE_END) ; }
#line 1897 "y.tab.c" /* yacc.c:1667  */
    break;

  case 11:
#line 165 "parse.y" /* yacc.c:1667  */
    { switch_code_to_main() ; }
#line 1903 "y.tab.c" /* yacc.c:1667  */
    break;

  case 12:
#line 168 "parse.y" /* yacc.c:1667  */
    { code_jmp(_JZ, (INST*)0) ; }
#line 1909 "y.tab.c" /* yacc.c:1667  */
    break;

  case 13:
#line 171 "parse.y" /* yacc.c:1667  */
    { patch_jmp( code_ptr ) ; }
#line 1915 "y.tab.c" /* yacc.c:1667  */
    break;

  case 14:
#line 175 "parse.y" /* yacc.c:1667  */
    {
	       INST *p1 = CDP((yyvsp[-1].start)) ;
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
#line 1935 "y.tab.c" /* yacc.c:1667  */
    break;

  case 15:
#line 191 "parse.y" /* yacc.c:1667  */
    { code1(_STOP) ; }
#line 1941 "y.tab.c" /* yacc.c:1667  */
    break;

  case 16:
#line 194 "parse.y" /* yacc.c:1667  */
    {
	       INST *p1 = CDP((yyvsp[-5].start)) ;

	       p1[3].op = CDP((yyvsp[0].start)) - (p1+1) ;
               p1[4].op = code_ptr - (p1+1) ;
             }
#line 1952 "y.tab.c" /* yacc.c:1667  */
    break;

  case 17:
#line 205 "parse.y" /* yacc.c:1667  */
    { (yyval.start) = (yyvsp[-1].start) ; }
#line 1958 "y.tab.c" /* yacc.c:1667  */
    break;

  case 18:
#line 207 "parse.y" /* yacc.c:1667  */
    { (yyval.start) = code_offset ; /* does nothing won't be executed */
              print_flag = getline_flag = paren_cnt = 0 ;
              yyerrok ; }
#line 1966 "y.tab.c" /* yacc.c:1667  */
    break;

  case 20:
#line 214 "parse.y" /* yacc.c:1667  */
    { (yyval.start) = code_offset ;
                       code1(_PUSHINT) ; code1(0) ;
                       code2(_PRINT, bi_print) ;
                     }
#line 1975 "y.tab.c" /* yacc.c:1667  */
    break;

  case 24:
#line 226 "parse.y" /* yacc.c:1667  */
    { code1(_POP) ; }
#line 1981 "y.tab.c" /* yacc.c:1667  */
    break;

  case 25:
#line 228 "parse.y" /* yacc.c:1667  */
    { (yyval.start) = code_offset ; }
#line 1987 "y.tab.c" /* yacc.c:1667  */
    break;

  case 26:
#line 230 "parse.y" /* yacc.c:1667  */
    { (yyval.start) = code_offset ;
                print_flag = getline_flag = 0 ;
                paren_cnt = 0 ;
                yyerrok ;
              }
#line 1997 "y.tab.c" /* yacc.c:1667  */
    break;

  case 27:
#line 236 "parse.y" /* yacc.c:1667  */
    { (yyval.start) = code_offset ; BC_insert('B', code_ptr+1) ;
               code2(_JMP, 0) /* don't use code_jmp ! */ ; }
#line 2004 "y.tab.c" /* yacc.c:1667  */
    break;

  case 28:
#line 239 "parse.y" /* yacc.c:1667  */
    { (yyval.start) = code_offset ; BC_insert('C', code_ptr+1) ;
               code2(_JMP, 0) ; }
#line 2011 "y.tab.c" /* yacc.c:1667  */
    break;

  case 29:
#line 242 "parse.y" /* yacc.c:1667  */
    { if ( scope != SCOPE_FUNCT )
                     compile_error("return outside function body") ;
             }
#line 2019 "y.tab.c" /* yacc.c:1667  */
    break;

  case 30:
#line 246 "parse.y" /* yacc.c:1667  */
    { if ( scope != SCOPE_MAIN )
                   compile_error( "improper use of next" ) ;
                (yyval.start) = code_offset ;
                code1(_NEXT) ;
              }
#line 2029 "y.tab.c" /* yacc.c:1667  */
    break;

  case 31:
#line 252 "parse.y" /* yacc.c:1667  */
    { if ( scope != SCOPE_MAIN )
                   compile_error( "improper use of nextfile" ) ;
                (yyval.start) = code_offset ;
                code1(_NEXTFILE) ;
              }
#line 2039 "y.tab.c" /* yacc.c:1667  */
    break;

  case 35:
#line 263 "parse.y" /* yacc.c:1667  */
    { code1(_ASSIGN) ; }
#line 2045 "y.tab.c" /* yacc.c:1667  */
    break;

  case 36:
#line 264 "parse.y" /* yacc.c:1667  */
    { code1(_ADD_ASG) ; }
#line 2051 "y.tab.c" /* yacc.c:1667  */
    break;

  case 37:
#line 265 "parse.y" /* yacc.c:1667  */
    { code1(_SUB_ASG) ; }
#line 2057 "y.tab.c" /* yacc.c:1667  */
    break;

  case 38:
#line 266 "parse.y" /* yacc.c:1667  */
    { code1(_MUL_ASG) ; }
#line 2063 "y.tab.c" /* yacc.c:1667  */
    break;

  case 39:
#line 267 "parse.y" /* yacc.c:1667  */
    { code1(_DIV_ASG) ; }
#line 2069 "y.tab.c" /* yacc.c:1667  */
    break;

  case 40:
#line 268 "parse.y" /* yacc.c:1667  */
    { code1(_MOD_ASG) ; }
#line 2075 "y.tab.c" /* yacc.c:1667  */
    break;

  case 41:
#line 269 "parse.y" /* yacc.c:1667  */
    { code1(_POW_ASG) ; }
#line 2081 "y.tab.c" /* yacc.c:1667  */
    break;

  case 42:
#line 270 "parse.y" /* yacc.c:1667  */
    { code1(_EQ) ; }
#line 2087 "y.tab.c" /* yacc.c:1667  */
    break;

  case 43:
#line 271 "parse.y" /* yacc.c:1667  */
    { code1(_NEQ) ; }
#line 2093 "y.tab.c" /* yacc.c:1667  */
    break;

  case 44:
#line 272 "parse.y" /* yacc.c:1667  */
    { code1(_LT) ; }
#line 2099 "y.tab.c" /* yacc.c:1667  */
    break;

  case 45:
#line 273 "parse.y" /* yacc.c:1667  */
    { code1(_LTE) ; }
#line 2105 "y.tab.c" /* yacc.c:1667  */
    break;

  case 46:
#line 274 "parse.y" /* yacc.c:1667  */
    { code1(_GT) ; }
#line 2111 "y.tab.c" /* yacc.c:1667  */
    break;

  case 47:
#line 275 "parse.y" /* yacc.c:1667  */
    { code1(_GTE) ; }
#line 2117 "y.tab.c" /* yacc.c:1667  */
    break;

  case 48:
#line 278 "parse.y" /* yacc.c:1667  */
    {
	    INST *p3 = CDP((yyvsp[0].start)) ;

            if ( p3 == code_ptr - 2 )
            {
               if ( p3->op == _MATCH0 )  p3->op = _MATCH1 ;

               else /* check for string */
               if ( p3->op == _PUSHS )
               { CELL *cp = ZMALLOC(CELL) ;

                 cp->type = C_STRING ;
                 cp->ptr = p3[1].ptr ;
                 cast_to_RE(cp) ;
                 code_ptr -= 2 ;
                 code2(_MATCH1, cp->ptr) ;
                 ZFREE(cp) ;
               }
               else  code1(_MATCH2) ;
            }
            else code1(_MATCH2) ;

            if ( !(yyvsp[-1].ival) ) code1(_NOT) ;
          }
#line 2146 "y.tab.c" /* yacc.c:1667  */
    break;

  case 49:
#line 305 "parse.y" /* yacc.c:1667  */
    { code1(_TEST) ;
                code_jmp(_LJNZ, (INST*)0) ;
              }
#line 2154 "y.tab.c" /* yacc.c:1667  */
    break;

  case 50:
#line 309 "parse.y" /* yacc.c:1667  */
    { code1(_TEST) ; patch_jmp(code_ptr) ; }
#line 2160 "y.tab.c" /* yacc.c:1667  */
    break;

  case 51:
#line 312 "parse.y" /* yacc.c:1667  */
    { code1(_TEST) ;
		code_jmp(_LJZ, (INST*)0) ;
	      }
#line 2168 "y.tab.c" /* yacc.c:1667  */
    break;

  case 52:
#line 316 "parse.y" /* yacc.c:1667  */
    { code1(_TEST) ; patch_jmp(code_ptr) ; }
#line 2174 "y.tab.c" /* yacc.c:1667  */
    break;

  case 53:
#line 318 "parse.y" /* yacc.c:1667  */
    { code_jmp(_JZ, (INST*)0) ; }
#line 2180 "y.tab.c" /* yacc.c:1667  */
    break;

  case 54:
#line 319 "parse.y" /* yacc.c:1667  */
    { code_jmp(_JMP, (INST*)0) ; }
#line 2186 "y.tab.c" /* yacc.c:1667  */
    break;

  case 55:
#line 321 "parse.y" /* yacc.c:1667  */
    { patch_jmp(code_ptr) ; patch_jmp(CDP((yyvsp[0].start))) ; }
#line 2192 "y.tab.c" /* yacc.c:1667  */
    break;

  case 57:
#line 326 "parse.y" /* yacc.c:1667  */
    { code1(_CAT) ; }
#line 2198 "y.tab.c" /* yacc.c:1667  */
    break;

  case 58:
#line 330 "parse.y" /* yacc.c:1667  */
    {  (yyval.start) = code_offset ; code2(_PUSHD, (yyvsp[0].ptr)) ; }
#line 2204 "y.tab.c" /* yacc.c:1667  */
    break;

  case 59:
#line 332 "parse.y" /* yacc.c:1667  */
    { (yyval.start) = code_offset ; code2(_PUSHS, (yyvsp[0].ptr)) ; }
#line 2210 "y.tab.c" /* yacc.c:1667  */
    break;

  case 60:
#line 334 "parse.y" /* yacc.c:1667  */
    { check_var((yyvsp[0].stp)) ;
            (yyval.start) = code_offset ;
            if ( is_local((yyvsp[0].stp)) )
            { code2op(L_PUSHI, (yyvsp[0].stp)->offset) ; }
            else code2(_PUSHI, (yyvsp[0].stp)->stval.cp) ;
          }
#line 2221 "y.tab.c" /* yacc.c:1667  */
    break;

  case 61:
#line 342 "parse.y" /* yacc.c:1667  */
    { (yyval.start) = (yyvsp[-1].start) ; }
#line 2227 "y.tab.c" /* yacc.c:1667  */
    break;

  case 62:
#line 346 "parse.y" /* yacc.c:1667  */
    { (yyval.start) = code_offset ; code2(_MATCH0, (yyvsp[0].ptr)) ; }
#line 2233 "y.tab.c" /* yacc.c:1667  */
    break;

  case 63:
#line 349 "parse.y" /* yacc.c:1667  */
    { code1(_ADD) ; }
#line 2239 "y.tab.c" /* yacc.c:1667  */
    break;

  case 64:
#line 350 "parse.y" /* yacc.c:1667  */
    { code1(_SUB) ; }
#line 2245 "y.tab.c" /* yacc.c:1667  */
    break;

  case 65:
#line 351 "parse.y" /* yacc.c:1667  */
    { code1(_MUL) ; }
#line 2251 "y.tab.c" /* yacc.c:1667  */
    break;

  case 66:
#line 352 "parse.y" /* yacc.c:1667  */
    { code1(_DIV) ; }
#line 2257 "y.tab.c" /* yacc.c:1667  */
    break;

  case 67:
#line 353 "parse.y" /* yacc.c:1667  */
    { code1(_MOD) ; }
#line 2263 "y.tab.c" /* yacc.c:1667  */
    break;

  case 68:
#line 354 "parse.y" /* yacc.c:1667  */
    { code1(_POW) ; }
#line 2269 "y.tab.c" /* yacc.c:1667  */
    break;

  case 69:
#line 356 "parse.y" /* yacc.c:1667  */
    { (yyval.start) = (yyvsp[0].start) ; code1(_NOT) ; }
#line 2275 "y.tab.c" /* yacc.c:1667  */
    break;

  case 70:
#line 358 "parse.y" /* yacc.c:1667  */
    { (yyval.start) = (yyvsp[0].start) ; code1(_UPLUS) ; }
#line 2281 "y.tab.c" /* yacc.c:1667  */
    break;

  case 71:
#line 360 "parse.y" /* yacc.c:1667  */
    { (yyval.start) = (yyvsp[0].start) ; code1(_UMINUS) ; }
#line 2287 "y.tab.c" /* yacc.c:1667  */
    break;

  case 73:
#line 365 "parse.y" /* yacc.c:1667  */
    { check_var((yyvsp[-1].stp)) ;
             (yyval.start) = code_offset ;
             code_address((yyvsp[-1].stp)) ;

             if ( (yyvsp[0].ival) == '+' )  code1(_POST_INC) ;
             else  code1(_POST_DEC) ;
           }
#line 2299 "y.tab.c" /* yacc.c:1667  */
    break;

  case 74:
#line 373 "parse.y" /* yacc.c:1667  */
    { (yyval.start) = (yyvsp[0].start) ;
              if ( (yyvsp[-1].ival) == '+' ) code1(_PRE_INC) ;
              else  code1(_PRE_DEC) ;
            }
#line 2308 "y.tab.c" /* yacc.c:1667  */
    break;

  case 75:
#line 380 "parse.y" /* yacc.c:1667  */
    { if ((yyvsp[0].ival) == '+' ) code1(F_POST_INC ) ;
             else  code1(F_POST_DEC) ;
           }
#line 2316 "y.tab.c" /* yacc.c:1667  */
    break;

  case 76:
#line 384 "parse.y" /* yacc.c:1667  */
    { (yyval.start) = (yyvsp[0].start) ;
             if ( (yyvsp[-1].ival) == '+' ) code1(F_PRE_INC) ;
             else  code1( F_PRE_DEC) ;
           }
#line 2325 "y.tab.c" /* yacc.c:1667  */
    break;

  case 77:
#line 391 "parse.y" /* yacc.c:1667  */
    { (yyval.start) = code_offset ;
          check_var((yyvsp[0].stp)) ;
          code_address((yyvsp[0].stp)) ;
        }
#line 2334 "y.tab.c" /* yacc.c:1667  */
    break;

  case 78:
#line 399 "parse.y" /* yacc.c:1667  */
    { (yyval.ival) = 0 ; }
#line 2340 "y.tab.c" /* yacc.c:1667  */
    break;

  case 80:
#line 404 "parse.y" /* yacc.c:1667  */
    { (yyval.ival) = 1 ; }
#line 2346 "y.tab.c" /* yacc.c:1667  */
    break;

  case 81:
#line 406 "parse.y" /* yacc.c:1667  */
    { (yyval.ival) = (yyvsp[-2].ival) + 1 ; }
#line 2352 "y.tab.c" /* yacc.c:1667  */
    break;

  case 82:
#line 411 "parse.y" /* yacc.c:1667  */
    { BI_REC *p = (yyvsp[-4].bip) ;
          (yyval.start) = (yyvsp[-3].start) ;
          if ( (int)p->min_args > (yyvsp[-1].ival) || (int)p->max_args < (yyvsp[-1].ival) )
            compile_error(
            "wrong number of arguments in call to %s" ,
            p->name ) ;
          if ( p->min_args != p->max_args ) /* variable args */
              { code1(_PUSHINT) ;  code1((yyvsp[-1].ival)) ; }
          code2(_BUILTIN , p->fp) ;
        }
#line 2367 "y.tab.c" /* yacc.c:1667  */
    break;

  case 83:
#line 430 "parse.y" /* yacc.c:1667  */
    {   (yyval.start) = (yyvsp[-2].start) ;
	      compile_error("no argments in call to sprintf()") ;
	  }
#line 2375 "y.tab.c" /* yacc.c:1667  */
    break;

  case 84:
#line 434 "parse.y" /* yacc.c:1667  */
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
#line 2390 "y.tab.c" /* yacc.c:1667  */
    break;

  case 85:
#line 445 "parse.y" /* yacc.c:1667  */
    {
	      (yyval.start) = (yyvsp[-3].start) ;
	      code2op(_PUSHINT, (yyvsp[-1].ival)) ;
	      code2(_BUILTIN, bi_sprintf1) ;
	  }
#line 2400 "y.tab.c" /* yacc.c:1667  */
    break;

  case 86:
#line 453 "parse.y" /* yacc.c:1667  */
    {
	           STRING* str = (STRING*) (yyvsp[-1].ptr) ;
		   const Form* form = parse_form(str) ;
		   free_STRING(str) ;
		   (yyval.ptr) = (PTR) form ;
		   code2(PUSHFM, form) ;
		}
#line 2412 "y.tab.c" /* yacc.c:1667  */
    break;

  case 87:
#line 466 "parse.y" /* yacc.c:1667  */
    { (yyval.start) = code_offset ; }
#line 2418 "y.tab.c" /* yacc.c:1667  */
    break;

  case 88:
#line 470 "parse.y" /* yacc.c:1667  */
    { code2(_PRINT, bi_print) ;
              print_flag = 0 ;
              (yyval.start) = (yyvsp[-3].start) ;
            }
#line 2427 "y.tab.c" /* yacc.c:1667  */
    break;

  case 89:
#line 484 "parse.y" /* yacc.c:1667  */
    { code2(_PRINT, bi_printf1) ;
              print_flag = 0 ;
              (yyval.start) = (yyvsp[-3].start) ;
	      if ((yyvsp[-2].ival) == 0) {
	          compile_error("no arguments in call to printf") ;
	      }
	    }
#line 2439 "y.tab.c" /* yacc.c:1667  */
    break;

  case 90:
#line 492 "parse.y" /* yacc.c:1667  */
    {  const Form* form = (Form*) (yyvsp[-3].ptr) ;
	        if (form && form->num_args != (yyvsp[-2].ival)) {
   compile_error("wrong number of arguments to printf, needs %d, has %d",
                    form->num_args+1, (yyvsp[-2].ival)+1) ;
		}
	        code2(_PRINT, bi_printf) ;
	        print_flag = 0 ;
		(yyval.start) = (yyvsp[-4].start) ;
	     }
#line 2453 "y.tab.c" /* yacc.c:1667  */
    break;

  case 91:
#line 502 "parse.y" /* yacc.c:1667  */
    {  const Form* form = (Form*) (yyvsp[-4].ptr) ;
	        if (form && form->num_args != (yyvsp[-3].ival)) {
   compile_error("wrong number of arguments to printf, needs %d, has %d",
                    form->num_args+1, (yyvsp[-3].ival)+1) ;
		}
	        code2(_PRINT, bi_printf) ;
	        print_flag = 0 ;
		(yyval.start) = (yyvsp[-6].start) ;
	     }
#line 2467 "y.tab.c" /* yacc.c:1667  */
    break;

  case 92:
#line 514 "parse.y" /* yacc.c:1667  */
    { (yyval.start) = code_offset ;
	     print_flag = 1 ;
	   }
#line 2475 "y.tab.c" /* yacc.c:1667  */
    break;

  case 93:
#line 520 "parse.y" /* yacc.c:1667  */
    { code2op(_PUSHINT, (yyvsp[0].ival) + 1) ;
	   }
#line 2482 "y.tab.c" /* yacc.c:1667  */
    break;

  case 94:
#line 524 "parse.y" /* yacc.c:1667  */
    { code2op(_PUSHINT, (yyvsp[0].ival)) ; }
#line 2488 "y.tab.c" /* yacc.c:1667  */
    break;

  case 95:
#line 526 "parse.y" /* yacc.c:1667  */
    { (yyval.ival) = (yyvsp[-1].arg2p)->cnt ; zfree((yyvsp[-1].arg2p),sizeof(ARG2_REC)) ;
             code2op(_PUSHINT, (yyval.ival)) ;
           }
#line 2496 "y.tab.c" /* yacc.c:1667  */
    break;

  case 96:
#line 530 "parse.y" /* yacc.c:1667  */
    { (yyval.ival)=0 ; code2op(_PUSHINT, 0) ; }
#line 2502 "y.tab.c" /* yacc.c:1667  */
    break;

  case 97:
#line 534 "parse.y" /* yacc.c:1667  */
    { (yyval.arg2p) = (ARG2_REC*) zmalloc(sizeof(ARG2_REC)) ;
             (yyval.arg2p)->start = (yyvsp[-2].start) ;
             (yyval.arg2p)->cnt = 2 ;
           }
#line 2511 "y.tab.c" /* yacc.c:1667  */
    break;

  case 98:
#line 539 "parse.y" /* yacc.c:1667  */
    { (yyval.arg2p) = (yyvsp[-2].arg2p) ; (yyval.arg2p)->cnt++ ; }
#line 2517 "y.tab.c" /* yacc.c:1667  */
    break;

  case 100:
#line 544 "parse.y" /* yacc.c:1667  */
    { code2op(_PUSHINT, (yyvsp[-1].ival)) ; }
#line 2523 "y.tab.c" /* yacc.c:1667  */
    break;

  case 101:
#line 551 "parse.y" /* yacc.c:1667  */
    {  (yyval.start) = (yyvsp[-1].start) ; eat_nl() ; code_jmp(_JZ, (INST*)0) ; }
#line 2529 "y.tab.c" /* yacc.c:1667  */
    break;

  case 102:
#line 556 "parse.y" /* yacc.c:1667  */
    { patch_jmp( code_ptr ) ;  }
#line 2535 "y.tab.c" /* yacc.c:1667  */
    break;

  case 103:
#line 559 "parse.y" /* yacc.c:1667  */
    { eat_nl() ; code_jmp(_JMP, (INST*)0) ; }
#line 2541 "y.tab.c" /* yacc.c:1667  */
    break;

  case 104:
#line 564 "parse.y" /* yacc.c:1667  */
    { patch_jmp(code_ptr) ;
		  patch_jmp(CDP((yyvsp[0].start))) ;
		}
#line 2549 "y.tab.c" /* yacc.c:1667  */
    break;

  case 105:
#line 572 "parse.y" /* yacc.c:1667  */
    { eat_nl() ; BC_new() ; }
#line 2555 "y.tab.c" /* yacc.c:1667  */
    break;

  case 106:
#line 577 "parse.y" /* yacc.c:1667  */
    { (yyval.start) = (yyvsp[-5].start) ;
          code_jmp(_JNZ, CDP((yyvsp[-5].start))) ;
          BC_clear(code_ptr, CDP((yyvsp[-2].start))) ; }
#line 2563 "y.tab.c" /* yacc.c:1667  */
    break;

  case 107:
#line 583 "parse.y" /* yacc.c:1667  */
    { eat_nl() ; BC_new() ;
                  (yyval.start) = (yyvsp[-1].start) ;

                  /* check if const expression */
                  if ( code_ptr - 2 == CDP((yyvsp[-1].start)) &&
                       code_ptr[-2].op == _PUSHD &&
                       *(double*)code_ptr[-1].ptr != 0.0
                     )
                     code_ptr -= 2 ;
                  else
		  { INST *p3 = CDP((yyvsp[-1].start)) ;
		    code_push(p3, code_ptr-p3, scope, active_funct) ;
		    code_ptr = p3 ;
                    code2(_JMP, (INST*)0) ; /* code2() not code_jmp() */
		  }
                }
#line 2584 "y.tab.c" /* yacc.c:1667  */
    break;

  case 108:
#line 603 "parse.y" /* yacc.c:1667  */
    {
		  int  saved_offset ;
		  int len ;
		  INST *p1 = CDP((yyvsp[-1].start)) ;
		  INST *p2 = CDP((yyvsp[0].start)) ;

                  if ( p1 != p2 )  /* real test in loop */
		  {
		    p1[1].op = code_ptr-(p1+1) ;
		    saved_offset = code_offset ;
		    len = code_pop(code_ptr) ;
		    code_ptr += len ;
		    code_jmp(_JNZ, CDP((yyvsp[0].start))) ;
		    BC_clear(code_ptr, CDP(saved_offset)) ;
		  }
		  else /* while(1) */
		  {
		    code_jmp(_JMP, p1) ;
		    BC_clear(code_ptr, CDP((yyvsp[0].start))) ;
		  }
                }
#line 2610 "y.tab.c" /* yacc.c:1667  */
    break;

  case 109:
#line 629 "parse.y" /* yacc.c:1667  */
    {
		  int cont_offset = code_offset ;
                  unsigned len = code_pop(code_ptr) ;
		  INST *p2 = CDP((yyvsp[-2].start)) ;
		  INST *p4 = CDP((yyvsp[0].start)) ;

                  code_ptr += len ;

		  if ( p2 != p4 )  /* real test in for2 */
		  {
                    p4[-1].op = code_ptr - p4 + 1 ;
		    len = code_pop(code_ptr) ;
		    code_ptr += len ;
                    code_jmp(_JNZ, CDP((yyvsp[0].start))) ;
		  }
		  else /*  for(;;) */
		  code_jmp(_JMP, p4) ;

		  BC_clear(code_ptr, CDP(cont_offset)) ;

                }
#line 2636 "y.tab.c" /* yacc.c:1667  */
    break;

  case 110:
#line 652 "parse.y" /* yacc.c:1667  */
    { (yyval.start) = code_offset ; }
#line 2642 "y.tab.c" /* yacc.c:1667  */
    break;

  case 111:
#line 654 "parse.y" /* yacc.c:1667  */
    { (yyval.start) = (yyvsp[-1].start) ; code1(_POP) ; }
#line 2648 "y.tab.c" /* yacc.c:1667  */
    break;

  case 112:
#line 657 "parse.y" /* yacc.c:1667  */
    { (yyval.start) = code_offset ; }
#line 2654 "y.tab.c" /* yacc.c:1667  */
    break;

  case 113:
#line 659 "parse.y" /* yacc.c:1667  */
    {
             if ( code_ptr - 2 == CDP((yyvsp[-1].start)) &&
                  code_ptr[-2].op == _PUSHD &&
                  * (double*) code_ptr[-1].ptr != 0.0
                )
                    code_ptr -= 2 ;
             else
	     {
	       INST *p1 = CDP((yyvsp[-1].start)) ;
	       code_push(p1, code_ptr-p1, scope, active_funct) ;
	       code_ptr = p1 ;
	       code2(_JMP, (INST*)0) ;
	     }
           }
#line 2673 "y.tab.c" /* yacc.c:1667  */
    break;

  case 114:
#line 676 "parse.y" /* yacc.c:1667  */
    { eat_nl() ; BC_new() ;
	     code_push((INST*)0,0, scope, active_funct) ;
	   }
#line 2681 "y.tab.c" /* yacc.c:1667  */
    break;

  case 115:
#line 680 "parse.y" /* yacc.c:1667  */
    { INST *p1 = CDP((yyvsp[-1].start)) ;

	     eat_nl() ; BC_new() ;
             code1(_POP) ;
             code_push(p1, code_ptr - p1, scope, active_funct) ;
             code_ptr -= code_ptr - p1 ;
           }
#line 2693 "y.tab.c" /* yacc.c:1667  */
    break;

  case 116:
#line 693 "parse.y" /* yacc.c:1667  */
    { check_array((yyvsp[0].stp)) ;
             code_array((yyvsp[0].stp)) ;
             code1(A_TEST) ;
            }
#line 2702 "y.tab.c" /* yacc.c:1667  */
    break;

  case 117:
#line 698 "parse.y" /* yacc.c:1667  */
    { (yyval.start) = (yyvsp[-3].arg2p)->start ;
             code2op(A_CAT, (yyvsp[-3].arg2p)->cnt) ;
             zfree((yyvsp[-3].arg2p), sizeof(ARG2_REC)) ;

             check_array((yyvsp[0].stp)) ;
             code_array((yyvsp[0].stp)) ;
             code1(A_TEST) ;
           }
#line 2715 "y.tab.c" /* yacc.c:1667  */
    break;

  case 118:
#line 709 "parse.y" /* yacc.c:1667  */
    {
             if ( (yyvsp[-1].ival) > 1 )
             { code2op(A_CAT, (yyvsp[-1].ival)) ; }

             check_array((yyvsp[-4].stp)) ;
             if( is_local((yyvsp[-4].stp)) )
             { code2op(LAE_PUSHA, (yyvsp[-4].stp)->offset) ; }
             else code2(AE_PUSHA, (yyvsp[-4].stp)->stval.array) ;
             (yyval.start) = (yyvsp[-3].start) ;
           }
#line 2730 "y.tab.c" /* yacc.c:1667  */
    break;

  case 119:
#line 722 "parse.y" /* yacc.c:1667  */
    {
             if ( (yyvsp[-1].ival) > 1 )
             { code2op(A_CAT, (yyvsp[-1].ival)) ; }

             check_array((yyvsp[-4].stp)) ;
             if( is_local((yyvsp[-4].stp)) )
             { code2op(LAE_PUSHI, (yyvsp[-4].stp)->offset) ; }
             else code2(AE_PUSHI, (yyvsp[-4].stp)->stval.array) ;
             (yyval.start) = (yyvsp[-3].start) ;
           }
#line 2745 "y.tab.c" /* yacc.c:1667  */
    break;

  case 120:
#line 734 "parse.y" /* yacc.c:1667  */
    {
             if ( (yyvsp[-2].ival) > 1 )
             { code2op(A_CAT,(yyvsp[-2].ival)) ; }

             check_array((yyvsp[-5].stp)) ;
             if( is_local((yyvsp[-5].stp)) )
             { code2op(LAE_PUSHA, (yyvsp[-5].stp)->offset) ; }
             else code2(AE_PUSHA, (yyvsp[-5].stp)->stval.array) ;
             if ( (yyvsp[0].ival) == '+' )  code1(_POST_INC) ;
             else  code1(_POST_DEC) ;

             (yyval.start) = (yyvsp[-4].start) ;
           }
#line 2763 "y.tab.c" /* yacc.c:1667  */
    break;

  case 121:
#line 751 "parse.y" /* yacc.c:1667  */
    {
               (yyval.start) = (yyvsp[-4].start) ;
               if ( (yyvsp[-2].ival) > 1 ) { code2op(A_CAT, (yyvsp[-2].ival)) ; }
               check_array((yyvsp[-5].stp)) ;
               code_array((yyvsp[-5].stp)) ;
               code1(A_DEL) ;
             }
#line 2775 "y.tab.c" /* yacc.c:1667  */
    break;

  case 122:
#line 759 "parse.y" /* yacc.c:1667  */
    {
		(yyval.start) = code_offset ;
		check_array((yyvsp[-1].stp)) ;
		code_array((yyvsp[-1].stp)) ;
		code1(DEL_A) ;
	     }
#line 2786 "y.tab.c" /* yacc.c:1667  */
    break;

  case 123:
#line 770 "parse.y" /* yacc.c:1667  */
    { eat_nl() ; BC_new() ;
                      (yyval.start) = code_offset ;

                      check_var((yyvsp[-3].stp)) ;
                      code_address((yyvsp[-3].stp)) ;
                      check_array((yyvsp[-1].stp)) ;
                      code_array((yyvsp[-1].stp)) ;

                      code2(SET_ALOOP, (INST*)0) ;
                    }
#line 2801 "y.tab.c" /* yacc.c:1667  */
    break;

  case 124:
#line 784 "parse.y" /* yacc.c:1667  */
    {
		INST *p2 = CDP((yyvsp[0].start)) ;

	        p2[-1].op = code_ptr - p2 + 1 ;
                BC_clear( code_ptr+2 , code_ptr) ;
		code_jmp(ALOOP, p2) ;
		code1(POP_AL) ;
              }
#line 2814 "y.tab.c" /* yacc.c:1667  */
    break;

  case 125:
#line 801 "parse.y" /* yacc.c:1667  */
    { (yyval.start) = code_offset ; code2(F_PUSHA, (yyvsp[0].cp)) ; }
#line 2820 "y.tab.c" /* yacc.c:1667  */
    break;

  case 126:
#line 803 "parse.y" /* yacc.c:1667  */
    { check_var((yyvsp[0].stp)) ;
             (yyval.start) = code_offset ;
             if ( is_local((yyvsp[0].stp)) )
             { code2op(L_PUSHI, (yyvsp[0].stp)->offset) ; }
             else code2(_PUSHI, (yyvsp[0].stp)->stval.cp) ;

	     CODE_FE_PUSHA() ;
           }
#line 2833 "y.tab.c" /* yacc.c:1667  */
    break;

  case 127:
#line 812 "parse.y" /* yacc.c:1667  */
    {
             if ( (yyvsp[-1].ival) > 1 )
             { code2op(A_CAT, (yyvsp[-1].ival)) ; }

             check_array((yyvsp[-4].stp)) ;
             if( is_local((yyvsp[-4].stp)) )
             { code2op(LAE_PUSHI, (yyvsp[-4].stp)->offset) ; }
             else code2(AE_PUSHI, (yyvsp[-4].stp)->stval.array) ;

	     CODE_FE_PUSHA()  ;

             (yyval.start) = (yyvsp[-3].start) ;
           }
#line 2851 "y.tab.c" /* yacc.c:1667  */
    break;

  case 128:
#line 826 "parse.y" /* yacc.c:1667  */
    { (yyval.start) = (yyvsp[0].start) ;  CODE_FE_PUSHA() ; }
#line 2857 "y.tab.c" /* yacc.c:1667  */
    break;

  case 129:
#line 828 "parse.y" /* yacc.c:1667  */
    { (yyval.start) = (yyvsp[-1].start) ; }
#line 2863 "y.tab.c" /* yacc.c:1667  */
    break;

  case 130:
#line 832 "parse.y" /* yacc.c:1667  */
    { field_A2I() ; }
#line 2869 "y.tab.c" /* yacc.c:1667  */
    break;

  case 131:
#line 835 "parse.y" /* yacc.c:1667  */
    { code1(F_ASSIGN) ; }
#line 2875 "y.tab.c" /* yacc.c:1667  */
    break;

  case 132:
#line 836 "parse.y" /* yacc.c:1667  */
    { code1(F_ADD_ASG) ; }
#line 2881 "y.tab.c" /* yacc.c:1667  */
    break;

  case 133:
#line 837 "parse.y" /* yacc.c:1667  */
    { code1(F_SUB_ASG) ; }
#line 2887 "y.tab.c" /* yacc.c:1667  */
    break;

  case 134:
#line 838 "parse.y" /* yacc.c:1667  */
    { code1(F_MUL_ASG) ; }
#line 2893 "y.tab.c" /* yacc.c:1667  */
    break;

  case 135:
#line 839 "parse.y" /* yacc.c:1667  */
    { code1(F_DIV_ASG) ; }
#line 2899 "y.tab.c" /* yacc.c:1667  */
    break;

  case 136:
#line 840 "parse.y" /* yacc.c:1667  */
    { code1(F_MOD_ASG) ; }
#line 2905 "y.tab.c" /* yacc.c:1667  */
    break;

  case 137:
#line 841 "parse.y" /* yacc.c:1667  */
    { code1(F_POW_ASG) ; }
#line 2911 "y.tab.c" /* yacc.c:1667  */
    break;

  case 138:
#line 848 "parse.y" /* yacc.c:1667  */
    { code2(_BUILTIN, bi_split) ; }
#line 2917 "y.tab.c" /* yacc.c:1667  */
    break;

  case 139:
#line 852 "parse.y" /* yacc.c:1667  */
    { (yyval.start) = (yyvsp[-2].start) ;
              check_array((yyvsp[0].stp)) ;
              code_array((yyvsp[0].stp))  ;
            }
#line 2926 "y.tab.c" /* yacc.c:1667  */
    break;

  case 140:
#line 859 "parse.y" /* yacc.c:1667  */
    { code2(_PUSHI, &fs_shadow) ; }
#line 2932 "y.tab.c" /* yacc.c:1667  */
    break;

  case 141:
#line 861 "parse.y" /* yacc.c:1667  */
    {
                  if ( CDP((yyvsp[-1].start)) == code_ptr - 2 )
                  {
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
                    else
                    if ( code_ptr[-2].op == _PUSHS )
                    { CELL *cp = ZMALLOC(CELL) ;

                      cp->type = C_STRING ;
                      cp->ptr = code_ptr[-1].ptr ;
                      cast_for_split(cp) ;
                      code_ptr[-2].op = _PUSHC ;
                      code_ptr[-1].ptr = (PTR) cp ;
                    }
                  }
                }
#line 2963 "y.tab.c" /* yacc.c:1667  */
    break;

  case 142:
#line 896 "parse.y" /* yacc.c:1667  */
    { (yyval.start) = code_offset ;
	    code2(_PUSHI,field) ;
            code2(_BUILTIN,bi_length) ;
	  }
#line 2972 "y.tab.c" /* yacc.c:1667  */
    break;

  case 143:
#line 901 "parse.y" /* yacc.c:1667  */
    { (yyval.start) = code_offset ;
	    code2(_PUSHI,field) ;
            code2(_BUILTIN,bi_length) ;
	  }
#line 2981 "y.tab.c" /* yacc.c:1667  */
    break;

  case 144:
#line 906 "parse.y" /* yacc.c:1667  */
    { (yyval.start) = (yyvsp[-1].start) ;
            code2(_BUILTIN,bi_length) ;
	  }
#line 2989 "y.tab.c" /* yacc.c:1667  */
    break;

  case 145:
#line 910 "parse.y" /* yacc.c:1667  */
    {
	      SYMTAB* stp = (yyvsp[-1].stp) ;
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
#line 3035 "y.tab.c" /* yacc.c:1667  */
    break;

  case 146:
#line 958 "parse.y" /* yacc.c:1667  */
    { (yyval.start) = (yyvsp[-3].start) ;
          code2(_BUILTIN, bi_match) ;
        }
#line 3043 "y.tab.c" /* yacc.c:1667  */
    break;

  case 147:
#line 965 "parse.y" /* yacc.c:1667  */
    {
	       INST *p1 = CDP((yyvsp[0].start)) ;

               if ( p1 == code_ptr - 2 )
               {
                 if ( p1->op == _MATCH0 ) RE_as_arg() ;
                 else
                 if ( p1->op == _PUSHS )
                 { CELL *cp = ZMALLOC(CELL) ;

                   cp->type = C_STRING ;
                   cp->ptr = p1[1].ptr ;
                   cast_to_RE(cp) ;
                   p1->op = _PUSHC ;
                   p1[1].ptr = (PTR) cp ;
                 }
               }
             }
#line 3066 "y.tab.c" /* yacc.c:1667  */
    break;

  case 148:
#line 988 "parse.y" /* yacc.c:1667  */
    { (yyval.start) = code_offset ;
                      code1(_EXIT0) ; }
#line 3073 "y.tab.c" /* yacc.c:1667  */
    break;

  case 149:
#line 991 "parse.y" /* yacc.c:1667  */
    { (yyval.start) = (yyvsp[-1].start) ; code1(_EXIT) ; }
#line 3079 "y.tab.c" /* yacc.c:1667  */
    break;

  case 150:
#line 994 "parse.y" /* yacc.c:1667  */
    { (yyval.start) = code_offset ;
                      code1(_RET0) ; }
#line 3086 "y.tab.c" /* yacc.c:1667  */
    break;

  case 151:
#line 997 "parse.y" /* yacc.c:1667  */
    { (yyval.start) = (yyvsp[-1].start) ; code1(_RET) ; }
#line 3092 "y.tab.c" /* yacc.c:1667  */
    break;

  case 152:
#line 1002 "parse.y" /* yacc.c:1667  */
    { (yyval.start) = code_offset ;
            code2(F_PUSHA, &field[0]) ;
            code1(_PUSHINT) ; code1(0) ;
            code2(_BUILTIN, bi_getline) ;
            getline_flag = 0 ;
          }
#line 3103 "y.tab.c" /* yacc.c:1667  */
    break;

  case 153:
#line 1009 "parse.y" /* yacc.c:1667  */
    { (yyval.start) = (yyvsp[0].start) ;
            code1(_PUSHINT) ; code1(0) ;
            code2(_BUILTIN, bi_getline) ;
            getline_flag = 0 ;
          }
#line 3113 "y.tab.c" /* yacc.c:1667  */
    break;

  case 154:
#line 1015 "parse.y" /* yacc.c:1667  */
    { code1(_PUSHINT) ; code1(F_IN) ;
            code2(_BUILTIN, bi_getline) ;
            /* getline_flag already off in yylex() */
          }
#line 3122 "y.tab.c" /* yacc.c:1667  */
    break;

  case 155:
#line 1020 "parse.y" /* yacc.c:1667  */
    { code2(F_PUSHA, &field[0]) ;
            code1(_PUSHINT) ; code1(PIPE_IN) ;
            code2(_BUILTIN, bi_getline) ;
          }
#line 3131 "y.tab.c" /* yacc.c:1667  */
    break;

  case 156:
#line 1025 "parse.y" /* yacc.c:1667  */
    {
            code1(_PUSHINT) ; code1(PIPE_IN) ;
            code2(_BUILTIN, bi_getline) ;
          }
#line 3140 "y.tab.c" /* yacc.c:1667  */
    break;

  case 157:
#line 1031 "parse.y" /* yacc.c:1667  */
    { getline_flag = 1 ; }
#line 3146 "y.tab.c" /* yacc.c:1667  */
    break;

  case 160:
#line 1036 "parse.y" /* yacc.c:1667  */
    { (yyval.start) = code_offset ;
                   code2(F_PUSHA, field+0) ;
                 }
#line 3154 "y.tab.c" /* yacc.c:1667  */
    break;

  case 161:
#line 1040 "parse.y" /* yacc.c:1667  */
    { (yyval.start) = (yyvsp[-1].start) ; }
#line 3160 "y.tab.c" /* yacc.c:1667  */
    break;

  case 162:
#line 1048 "parse.y" /* yacc.c:1667  */
    {
	     INST *p5 = CDP((yyvsp[-1].start)) ;
	     INST *p6 = CDP((yyvsp[0].start)) ;

             if ( p6 - p5 == 2 && p5->op == _PUSHS  )
             { /* cast from STRING to REPL at compile time */
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
#line 3181 "y.tab.c" /* yacc.c:1667  */
    break;

  case 163:
#line 1066 "parse.y" /* yacc.c:1667  */
    { (yyval.fp) = bi_sub ; }
#line 3187 "y.tab.c" /* yacc.c:1667  */
    break;

  case 164:
#line 1067 "parse.y" /* yacc.c:1667  */
    { (yyval.fp) = bi_gsub ; }
#line 3193 "y.tab.c" /* yacc.c:1667  */
    break;

  case 165:
#line 1072 "parse.y" /* yacc.c:1667  */
    { (yyval.start) = code_offset ;
                  code2(F_PUSHA, &field[0]) ;
                }
#line 3201 "y.tab.c" /* yacc.c:1667  */
    break;

  case 166:
#line 1077 "parse.y" /* yacc.c:1667  */
    { (yyval.start) = (yyvsp[-1].start) ; }
#line 3207 "y.tab.c" /* yacc.c:1667  */
    break;

  case 167:
#line 1085 "parse.y" /* yacc.c:1667  */
    {
		   resize_fblock((yyvsp[-1].fbp)) ;
                   restore_ids() ;
		   switch_code_to_main() ;
                 }
#line 3217 "y.tab.c" /* yacc.c:1667  */
    break;

  case 168:
#line 1094 "parse.y" /* yacc.c:1667  */
    { eat_nl() ;
                   scope = SCOPE_FUNCT ;
                   active_funct = (yyvsp[-3].fbp) ;
                   *main_code_p = active_code ;

		   (yyvsp[-3].fbp)->nargs = (yyvsp[-1].ival) ;
                   if ( (yyvsp[-1].ival) )
                        (yyvsp[-3].fbp)->typev = (char *)
			    memset( zmalloc((yyvsp[-1].ival)), ST_LOCAL_NONE, (yyvsp[-1].ival)) ;
                   else (yyvsp[-3].fbp)->typev = (char *) 0 ;

		   code_ptr = code_base =
                       (INST *) zmalloc(INST_BYTES(PAGESZ));
		   code_limit = code_base + PAGESZ ;
		   code_warn = code_limit - CODEWARN ;
                 }
#line 3238 "y.tab.c" /* yacc.c:1667  */
    break;

  case 169:
#line 1113 "parse.y" /* yacc.c:1667  */
    { FBLOCK  *fbp ;

                   if ( (yyvsp[0].stp)->type == ST_NONE )
                   {
                         (yyvsp[0].stp)->type = ST_FUNCT ;
                         fbp = (yyvsp[0].stp)->stval.fbp =
                             (FBLOCK *) zmalloc(sizeof(FBLOCK)) ;
                         fbp->name = (yyvsp[0].stp)->name ;
			 fbp->code = (INST*) 0 ;
                   }
                   else
                   {
                         type_error( (yyvsp[0].stp) ) ;

                         /* this FBLOCK will not be put in
                            the symbol table */
                         fbp = (FBLOCK*) zmalloc(sizeof(FBLOCK)) ;
                         fbp->name = "" ;
                   }
                   (yyval.fbp) = fbp ;
                 }
#line 3264 "y.tab.c" /* yacc.c:1667  */
    break;

  case 170:
#line 1136 "parse.y" /* yacc.c:1667  */
    { (yyval.fbp) = (yyvsp[0].fbp) ;
                   if ( (yyvsp[0].fbp)->code )
                       compile_error("redefinition of %s" , (yyvsp[0].fbp)->name) ;
                 }
#line 3273 "y.tab.c" /* yacc.c:1667  */
    break;

  case 171:
#line 1142 "parse.y" /* yacc.c:1667  */
    { (yyval.ival) = 0 ; }
#line 3279 "y.tab.c" /* yacc.c:1667  */
    break;

  case 173:
#line 1147 "parse.y" /* yacc.c:1667  */
    { (yyvsp[0].stp) = save_id((yyvsp[0].stp)->name) ;
                (yyvsp[0].stp)->type = ST_LOCAL_NONE ;
                (yyvsp[0].stp)->offset = 0 ;
                (yyval.ival) = 1 ;
              }
#line 3289 "y.tab.c" /* yacc.c:1667  */
    break;

  case 174:
#line 1153 "parse.y" /* yacc.c:1667  */
    { if ( is_local((yyvsp[0].stp)) )
                  compile_error("%s is duplicated in argument list",
                    (yyvsp[0].stp)->name) ;
                else
                { (yyvsp[0].stp) = save_id((yyvsp[0].stp)->name) ;
                  (yyvsp[0].stp)->type = ST_LOCAL_NONE ;
                  (yyvsp[0].stp)->offset = (yyvsp[-2].ival) ;
                  (yyval.ival) = (yyvsp[-2].ival) + 1 ;
                }
              }
#line 3304 "y.tab.c" /* yacc.c:1667  */
    break;

  case 175:
#line 1166 "parse.y" /* yacc.c:1667  */
    {  /* we may have to recover from a bungled function
		       definition */
		   /* can have local ids, before code scope
		      changes  */
		    restore_ids() ;

		    switch_code_to_main() ;
		 }
#line 3317 "y.tab.c" /* yacc.c:1667  */
    break;

  case 176:
#line 1179 "parse.y" /* yacc.c:1667  */
    { (yyval.start) = (yyvsp[-1].start) ;
             code2(_CALL, (yyvsp[-2].fbp)) ;

             if ( (yyvsp[0].ca_p) )  code1((yyvsp[0].ca_p)->arg_num+1) ;
             else  code1(0) ;

	     check_fcall((yyvsp[-2].fbp), scope, code_move_level, active_funct,
			 (yyvsp[0].ca_p), token_lineno) ;
           }
#line 3331 "y.tab.c" /* yacc.c:1667  */
    break;

  case 177:
#line 1191 "parse.y" /* yacc.c:1667  */
    { (yyval.ca_p) = (CA_REC *) 0 ; }
#line 3337 "y.tab.c" /* yacc.c:1667  */
    break;

  case 178:
#line 1193 "parse.y" /* yacc.c:1667  */
    { (yyval.ca_p) = (yyvsp[0].ca_p) ;
                 (yyval.ca_p)->link = (yyvsp[-1].ca_p) ;
                 (yyval.ca_p)->arg_num = (yyvsp[-1].ca_p) ? (yyvsp[-1].ca_p)->arg_num+1 : 0 ;
               }
#line 3346 "y.tab.c" /* yacc.c:1667  */
    break;

  case 179:
#line 1208 "parse.y" /* yacc.c:1667  */
    { (yyval.ca_p) = (CA_REC *) 0 ; }
#line 3352 "y.tab.c" /* yacc.c:1667  */
    break;

  case 180:
#line 1210 "parse.y" /* yacc.c:1667  */
    { (yyval.ca_p) = ZMALLOC(CA_REC) ;
                (yyval.ca_p)->link = (yyvsp[-2].ca_p) ;
                (yyval.ca_p)->type = CA_EXPR  ;
                (yyval.ca_p)->arg_num = (yyvsp[-2].ca_p) ? (yyvsp[-2].ca_p)->arg_num+1 : 0 ;
		(yyval.ca_p)->call_offset = code_offset ;
              }
#line 3363 "y.tab.c" /* yacc.c:1667  */
    break;

  case 181:
#line 1217 "parse.y" /* yacc.c:1667  */
    { (yyval.ca_p) = ZMALLOC(CA_REC) ;
                (yyval.ca_p)->link = (yyvsp[-2].ca_p) ;
                (yyval.ca_p)->arg_num = (yyvsp[-2].ca_p) ? (yyvsp[-2].ca_p)->arg_num+1 : 0 ;

                code_call_id((yyval.ca_p), (yyvsp[-1].stp)) ;
              }
#line 3374 "y.tab.c" /* yacc.c:1667  */
    break;

  case 182:
#line 1226 "parse.y" /* yacc.c:1667  */
    { (yyval.ca_p) = ZMALLOC(CA_REC) ;
                (yyval.ca_p)->type = CA_EXPR ;
		(yyval.ca_p)->call_offset = code_offset ;
              }
#line 3383 "y.tab.c" /* yacc.c:1667  */
    break;

  case 183:
#line 1232 "parse.y" /* yacc.c:1667  */
    { (yyval.ca_p) = ZMALLOC(CA_REC) ;
                code_call_id((yyval.ca_p), (yyvsp[-1].stp)) ;
              }
#line 3391 "y.tab.c" /* yacc.c:1667  */
    break;


#line 3395 "y.tab.c" /* yacc.c:1667  */
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
#line 1240 "parse.y" /* yacc.c:1918  */


/* resize the code for a user function */

static void  resize_fblock( FBLOCK * fbp )
{
  CODEBLOCK *p = ZMALLOC(CODEBLOCK) ;
  unsigned dummy ;

  code2op(_RET0, _HALT) ;
	/* make sure there is always a return */

  *p = active_code ;
  fbp->code = code_shrink(p, &dummy) ;
      /* code_shrink() zfrees p */

  if ( dump_code_flag ) add_to_fdump_list(fbp) ;
}


/* convert FE_PUSHA  to  FE_PUSHI
   or F_PUSH to F_PUSHI
*/

static void  field_A2I(void)
{ CELL *cp ;

  if ( code_ptr[-1].op == FE_PUSHA &&
       code_ptr[-1].ptr == (PTR) 0)
  /* On most architectures, the two tests are the same; a good
     compiler might eliminate one.  On LM_DOS, and possibly other
     segmented architectures, they are not */
  { code_ptr[-1].op = FE_PUSHI ; }
  else
  {
    cp = (CELL *) code_ptr[-1].ptr ;

    if ( cp == field  || (cp > NF && cp <= LAST_PFIELD) )
    {
         code_ptr[-2].op = _PUSHI  ;
    }
    else if ( cp == NF )
    { code_ptr[-2].op = NF_PUSHI ; code_ptr-- ; }

    else
    {
      code_ptr[-2].op = F_PUSHI ;
      code_ptr -> op = field_addr_to_index( (CELL *)code_ptr[-1].ptr ) ;
      code_ptr++ ;
    }
  }
}

/* we've seen an ID in a context where it should be a VAR,
   check that's consistent with previous usage */

static void check_var(SYMTAB * p )
{
      switch(p->type)
      {
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
        case ST_LOCAL_VAR :  break ;

        default :
            type_error(p) ;
            break ;
      }
}

/* we've seen an ID in a context where it should be an ARRAY,
   check that's consistent with previous usage */
static  void  check_array(SYMTAB *p)
{
      switch(p->type)
      {
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

        default : type_error(p) ; break ;
      }
}

static void code_array(SYMTAB* p)
{
  if ( is_local(p) ) code2op(LA_PUSHA, p->offset) ;
  else  code2(A_PUSHA, p->stval.array) ;
}


/* we've seen an ID as an argument to a user defined function */

static void  code_call_id(CA_REC * p, SYMTAB * ip )
{ static CELL dummy ;

  p->call_offset = code_offset ;
     /* This always get set now.  So that fcall:relocate_arglist
	works. */

  switch( ip->type )
  {
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

    /* not enough info to code it now; it will have to
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


#ifdef   DEBUG
    default :
            bozo("code_call_id") ;
#endif

  }
}

/* an RE by itself was coded as _MATCH0 , change to
   push as an expression */

static void RE_as_arg(void)
{ CELL *cp = ZMALLOC(CELL) ;

  code_ptr -= 2 ;
  cp->type = C_RE ;
  cp->ptr = code_ptr[1].ptr ;
  code2(_PUSHC, cp) ;
}

/* reset the active_code back to the MAIN block */
static void
switch_code_to_main(void)
{
   switch(scope)
   {
     case SCOPE_BEGIN :
	*begin_code_p = active_code ;
	active_code = *main_code_p ;
	break ;

     case SCOPE_END :
	*end_code_p = active_code ;
	active_code = *main_code_p ;
	break ;

     case SCOPE_FUNCT :
	active_code = *main_code_p ;
	break ;

     case SCOPE_MAIN :
	break ;
   }
   active_funct = (FBLOCK*) 0 ;
   scope = SCOPE_MAIN ;
}


void
parse(void)
{
   if ( yyparse() || compile_error_count != 0 ) mawk_exit(2) ;

   scan_cleanup() ;
   set_code() ;
   /* code must be set before call to resolve_fcalls() */
   if ( resolve_list )  resolve_fcalls() ;

   if ( compile_error_count != 0 ) mawk_exit(2) ;
   if ( dump_code_flag ) { dump_code() ; mawk_exit(0) ; }
}

