
/********************************************
table_kw.c
copyright 1991,2014-2016 Michael D. Brennan

This is a source file for mawk, an implementation of
the AWK programming language.

Mawk is distributed without warranty under the terms of
the GNU General Public License, version 3, 2007.

If you import elements of this code into another product,
you agree to not name that product mawk.
********************************************/

/* table_kw.c */

#include "mawk.h"
#include "table.h"
#include "parse.h"
#include "init.h"

const static struct kw {
    const char * text;
    short        kw;
} keywords[] = {
    { "BEGIN"       ,   BEGIN },
    { "break"       ,   BREAK },
    { "continue"    ,   CONTINUE },
    { "do"          ,   DO },
    { "delete"      ,   DELETE },
    { "else"        ,   ELSE },
    { "exit"        ,   EXIT },
    { "END"         ,   END },
    { "for"         ,   FOR },
    { "function"    ,   FUNCTION },
    { "getline"     ,   GETLINE },
    { "gsub"        ,   GSUB },
    { "if"          ,   IF },
    { "in"          ,   IN },
    { "length"      ,   LENGTH },
    { "match"       ,   MATCH_FUNC },
    { "next"        ,   NEXT },
    { "nextfile"    ,   NEXTFILE },
    { "print"       ,   PRINT },
    { "printf"      ,   PRINTF },
    { "return"      ,   RETURN },
    { "split"       ,   SPLIT },
    { "sprintf"     ,   SPRINTF },
    { "sub"         ,   SUB },
    { "while"       ,   WHILE },
    { 0, 0 }
};

/* put keywords in the symbol table */
void
kw_init( void )
{
    register const struct kw * p = keywords;
    register SYMTAB *          q;
    while ( p->text ) {
        q           = insert( p->text );
        q->type     = ST_KEYWORD;
        q->stval.kw = p++->kw;
    }
}

/* find a keyword to emit an error message */
const char *
find_kw_str( int kw_token )
{
    const struct kw * p;
    for ( p = keywords; p->text; p++ )
        if ( p->kw == kw_token )
            return p->text;
    /* search failed */
    return (char *)0;
}
