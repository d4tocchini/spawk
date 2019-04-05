
/********************************************
code.h
copyright 1991,2014-2016 Michael D. Brennan

This is a source file for mawk, an implementation of
the AWK programming language.

Mawk is distributed without warranty under the terms of
the GNU General Public License, version 3, 2007.

If you import elements of this code into another product,
you agree to not name that product mawk.
********************************************/


/*  code.h  */

#ifndef  CODE_H
#define  CODE_H

#include "types_string.h"

/* --------------------- jmp.h --------------------- BEGIN */
void     BC_new( void );
void     BC_insert( int, INST * );
void     BC_clear( INST *, INST * );
void     code_push( INST *, unsigned, int, FBLOCK * );
unsigned code_pop( INST * );
void     code_jmp( int, INST * );
void     patch_jmp( INST * );
extern int  code_move_level;
/*          used to as one part of unique identification of context when
            moving code.  Global for communication with parser.
*/
/* --------------------- jmp.h --------------------- END */

#define  CODEWARN       16

/* number of code instructions allocated at one time */
#define  PAGESZ	        512

/* coding scope */
#define   SCOPE_MAIN    0
#define   SCOPE_BEGIN   1
#define   SCOPE_END     2
#define   SCOPE_FUNCT   3

typedef struct {
    INST *base,
    *limit,
    *warn,
    *ptr ;
} CODEBLOCK ;

extern CODEBLOCK   active_code   ;
extern CODEBLOCK * main_code_p  ;
extern CODEBLOCK * begin_code_p ;
extern CODEBLOCK * end_code_p   ;

extern INST *   main_start;
extern INST *   begin_start;
extern INST *   end_start;
extern INST *   execution_start;
extern INST *   next_label;  /* next statements jump to here */
extern unsigned main_size ;
extern unsigned begin_size;
extern int      dump_code_flag;
extern int      exit_code;
extern CELL     eval_stack[] ;

#define code_ptr    active_code.ptr
#define code_base   active_code.base
#define code_warn   active_code.warn
#define code_limit  active_code.limit
#define code_offset (code_ptr - code_base)
#define code1(x)    code_ptr++ -> op = (x)
#define code2(x,p)  xcode2(x,(PTR)(p))

#define INST_BYTES(x) (sizeof(INST)*(unsigned)(x))

void   xcode2(int, PTR) ;
void   code2op(int, int) ;
INST * code_shrink(CODEBLOCK*, unsigned*) ;
void   code_grow(void) ;
void   set_code(void) ;
// void   code_open_BEGIN(void) ;
// void   code_open_END(void) ;
// void   code_close_active(void) ;
void   dump_code(void) ;
CODEBLOCK * code_create_block( void ) ;

/*  the machine opcodes  */
/* to avoid confusion with a ptr FE_PUSHA must have op code 0 */

enum {
    FE_PUSHA   =   0,
    FE_PUSHI,
    F_PUSHA,
    F_PUSHI,
    NF_PUSHI,
    _HALT,
    _STOP,
    _PUSHC,
    _PUSHD,
    _PUSHS,
    _PUSHINT,
    _PUSHA,
    _PUSHI,
    PUSHFM, 
    L_PUSHA,
    L_PUSHI,
    AE_PUSHA,
    AE_PUSHI,
    A_PUSHA,
    LAE_PUSHA,
    LAE_PUSHI,
    LA_PUSHA,
    _POP,
    _ADD,
    _SUB,
    _MUL,
    _DIV,
    _MOD,
    _POW,
    _NOT,
    _TEST,
    A_TEST,
    A_DEL,
    ALOOP,
    A_CAT,
    _UMINUS,
    _UPLUS,
    _ASSIGN,
    _ADD_ASG,
    _SUB_ASG,
    _MUL_ASG,
    _DIV_ASG,
    _MOD_ASG,
    _POW_ASG,
    F_ASSIGN,
    F_ADD_ASG,
    F_SUB_ASG,
    F_MUL_ASG,
    F_DIV_ASG,
    F_MOD_ASG,
    F_POW_ASG,
    _CAT,
    _BUILTIN,
    _PRINT,
    _POST_INC,
    _POST_DEC,
    _PRE_INC,
    _PRE_DEC,
    F_POST_INC,
    F_POST_DEC,
    F_PRE_INC,
    F_PRE_DEC,
    _JMP,
    _JNZ,
    _JZ,
    _LJZ,
    _LJNZ,
    _EQ,
    _NEQ,
    _LT,
    _LTE,
    _GT,
    _GTE,
    _MATCH0,
    _MATCH1,
    _MATCH2,
    _EXIT,
    _EXIT0,
    _NEXT,
    _NEXTFILE,
    _RANGE,
    _CALL,
    _RET,
    _RET0,
    SET_ALOOP,
    POP_AL,
    OL_GL,
    OL_GL_NR,
    _OMAIN,
    _JMAIN,
    DEL_A,
    PI_LOAD,
    LPI_LOAD
} ;

#endif  /* CODE_H */
