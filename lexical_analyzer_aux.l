%{
#include "analyseur.h"
#define debug true

%}
%option noyywrap
%option yylineno

%%
[0-9]+  {return NUM;}
    // operations
"+" {return PLUS;}
"-" {return MINUS;}
"*" {return MULT;}
"/" {return DIV;}
    // KEY_WORDS
"type" {return TYPE;}
"package" {return PACK;}
"SPARK_Mode" {return SPARK_Mode;}
"with"|"WITH" {return WITH;}
"use" {return USE;}
"IS" {return IS;}
"procedure" {return PROC;}
"begin" {return BEGIN;}
"end" {return END;}
"loop" {return LOOP;}
    // normalement pas des outputs en Spark !!
"put" {return PUT;}
"get" {return GET;}
"put_line" {return PUT_LINE;}
"get_line" {return GET_LINE;}
    ////////////////////////////////////////////
    // Again KEY_WORDS
"if" {return IF;}
"else" {return ELSE;}
"record" {return RECORD;}
"while" {return WHILE;}
"for" {return FOR;}
"Natural" {return NATURAL;}
"in" {return IN;}
"out" {return OUT;}
"new" {return NEW;}
"return" {return RETURN;}
"private" {return PRIVATE;}
    // the key word constant used in types
"constant" {return CONST;}
    ////////////
    // TYPES
"String" {return STRING;}
"Character" {return CHAR;}
"float" {return FLOAT;}
"Integer" {return INTEGER;}

"." {return POINT;}
":" {return DEF_TYPE_VAR;}
";" {return PT_COMMA;}
"," {return COMMA;}
"'" {return APPOST;}
":=" {return AFFECT;}
"_" {return TAB;}
"(" {return POPEN;}
")" {return PCLOSE;}
"<" {return SUP;}
">" {return INF;}

[a-zA-Z]([a-zA-Z0-9]*)  {return IDF;}

" "*|[\n\t]*  //will not treat it at all

.   {printf("%s is not defined as a token at line %d\n",yytext,yylineno);}
%%
