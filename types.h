
/********************************************
types.h
copyright 1991,2014-2016 Michael D. Brennan

This is a source file for mawk, an implementation of
the AWK programming language.

Mawk is distributed without warranty under the terms of
the GNU General Public License, version 3, 2007.

If you import elements of this code into another product,
you agree to not name that product mawk.
********************************************/

/*  types.h  */

#ifndef MAWK_TYPES_H
#define MAWK_TYPES_H

// #include "sizes.h"

//                          CELL
typedef struct cell         {
    int     type;
    PTR     ptr;
    double  dval;
                            }
CELL;
typedef                     CELL * ( *PF_CP )( CELL * )
//                              all builtins are passed the evaluation stack
//                              ptr & return its new value, here is the type
;
//                          INST
typedef union               {   // an element of code (instruction)
    int     op;
    PTR     ptr;
                            }
INST;
//                          CELLtypes

#define         C_NOINIT             0
#define         C_DOUBLE             1
#define         C_STRING             2
#define         C_STRNUM             3
#define         C_MBSTRN             4   // could be STRNUM, hasnt been checked
#define         C_RE                 5
#define         C_SPACE              6   // split on space
#define         C_SNULL              7   // split on the empty string
#define         C_REPL               8   // a replacement string '\&' changedto &
#define         C_REPLV              9   // a vector replacement -- broken on &
#define         NUM_CELL_TYPES      10

//                              these defines are used to check types for two
//                              CELLs which are adjacent in memory
#define         TWO_NOINITS         ( ( 1 << (C_NOINIT + 1) ) )
#define         TWO_DOUBLES         ( ( 1 << (C_DOUBLE + 1) ) )
#define         TWO_STRINGS         ( ( 1 << (C_STRING + 1) ) )
#define         TWO_STRNUMS         ( ( 1 << (C_STRNUM + 1) ) )
#define         TWO_MBSTRNS         ( ( 1 << (C_MBSTRN + 1) ) )
#define         NOINIT_AND_DOUBLE   ( ( 1 << C_NOINIT ) + ( 1 << C_DOUBLE ) )
#define         NOINIT_AND_STRING   ( ( 1 << C_NOINIT ) + ( 1 << C_STRING ) )
#define         NOINIT_AND_STRNUM   ( ( 1 << C_NOINIT ) + ( 1 << C_STRNUM ) )
#define         DOUBLE_AND_STRING   ( ( 1 << C_DOUBLE ) + ( 1 << C_STRING ) )
#define         DOUBLE_AND_STRNUM   ( ( 1 << C_STRNUM ) + ( 1 << C_DOUBLE ) )
#define         STRING_AND_STRNUM   ( ( 1 << C_STRING ) + ( 1 << C_STRNUM ) )
#define         NOINIT_AND_MBSTRN   ( ( 1 << C_NOINIT ) + ( 1 << C_MBSTRN ) )
#define         DOUBLE_AND_MBSTRN   ( ( 1 << C_DOUBLE ) + ( 1 << C_MBSTRN ) )
#define         STRING_AND_MBSTRN   ( ( 1 << C_STRING ) + ( 1 << C_MBSTRN ) )
#define         STRNUM_AND_MBSTRN   ( ( 1 << C_STRNUM ) + ( 1 << C_MBSTRN ) )

#define         CELL_PAIR_TYPE(cp)  ( ( 1 << ( cp )->type ) + ( 1 << ( ( cp ) + 1 )->type ) )



//                          STRING
typedef struct              {
    size_t   len;
    unsigned ref_cnt;
    char     str[4];
                            }
STRING;

//                          num bytes for a STRING of length
#define                     STRING_SIZE( len )                  \
                            (   ( len ) <= 3                    \
                                ? sizeof( STRING )              \
                                : sizeof( STRING ) + (len)-3    \
                            )
//                          compare two strings ==
#define                     STRING_eq( s1, s2 )                             \
                            (   ( s1 )->len == ( s2 )->len                  \
                                && memcmp(                                  \
                                    ( s1 )->str, ( s2 )->str, ( s1 )->len   \
                                ) == 0                                      \
                            )
//                          copy a STRING
#define                     STRING_dup( s )                     \
                            (   ( (STRING *)( s ) )->ref_cnt++, \
                                ( STRING *)( s )                \
                            )
//                          like strcmp()
int                         STRING_cmp( const STRING *, const STRING * );



#endif /* MAWK_TYPES_H */
