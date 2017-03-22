%option noyywrap
%{
#include <stdio.h>
#include <stdlib.h>
int noOfChars = 0;
%}
IDENTIFIER [a-zA-Z][a-zA-Z"_"]*
INTEGER 0|[1-9][0-9]*
REAL {INTEGER}"."?{INTEGER}*
OP [+-*/]
%%
{IDENTIFIER}"="({INTEGER}|{REAL}){OP}({INTEGER}|{REAL}) { printf("Βρήκα την πράξη: %s", yytext); }
%%

int main(int argc, char *argv[]) {
	yylex();
	return 0;
}
