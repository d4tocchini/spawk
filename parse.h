/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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
#line 158 "parse.y" /* yacc.c:1927  */

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

#line 227 "y.tab.h" /* yacc.c:1927  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif



int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
