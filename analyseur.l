%{
#include "analyseur.h"
#define debug true

%}
%option noyywrap
%option yylineno

%%
[0-9]+  {if(debug) printf("ENTIER(%s)\n",yytext);}

"+"|"-"|"*"|"/" {if(debug) printf("OPERATION(%s)\n",yytext);}
"type"|"package"|"SPARK_Mode"|"with"|"WITH"|"use"|"is"|"procedure"|"begin"|"end"|"loop"|"put"|"put_line"|"if"|"else"|"new"|"Natural"|"in"|"out"|"return"|"private" {printf("KEY_WORD(%s)\n",yytext);}
"String"|"Integer"|"character"|"float"  {if(debug) printf("TYPE_VAR(%s)\n",yytext);}

"." {if(debug) printf("POINT(%s)\n",yytext);}
":" {if(debug) printf("DEF_TYPE_VAR(%s)\n",yytext);}
";" {if(debug) printf("POINT_VIRGULE(%s)\n",yytext);}
"," {if(debug) printf("VIRGULE(%s)\t  pour double déclaration \n",yytext);}
"'" {if(debug) printf("APPOSTROPHE(%s)\n",yytext);}
":=" {if(debug) printf("AFFECTATION(%s)\n",yytext);}
"_" {if(debug) printf("TABULATION(%s)\n",yytext);}
"(" {if(debug) printf("OPEN_BRACKET(%s)\n",yytext);}
")" {if(debug) printf("CLOSED_BRACKET(%s)\n",yytext);}
"<" {printf("INFERIEUR(%s)",yytext);}
">" {printf("SUPERIEUR(%s)",yytext);}

[a-zA-Z]([a-zA-Z0-9]*)  {if(debug) printf("IDF(%s)\n",yytext);}

" "*|[\n\t]*  //rien

.   {printf("a non iditified token\n",yytext);}
%%