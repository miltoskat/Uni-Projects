%option noyywrap
%{
#define YYSTYPE double
#include <stdlib.h>
#include <stdio.h>
#include "y.tab.h"
%}
%%
[ \t]
[0-9]+(\.[0-9]+)?           { yylval = atof(yytext); return DOUBLE; }
"("                         { return LPAREN; }
")"                         { return RPAREN; }
"+"                         { return PLUS; }
"-"                         { return MINUS; }
"*"                         { return MUL; }
"/"                         { return DIV; }
"^"                         { return POW; }
"quit"                      { yyterminate(); }
\n                          { return EOL; }
.       { printf("Άγνωστο γνώρισμα: %s!\n", yytext); yyterminate(); }
%%
