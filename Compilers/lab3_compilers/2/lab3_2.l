%option noyywrap
%{
#include <stdio.h>
%}
DIGIT [0-9]
%%
[+-]?{DIGIT} {printf("ο δεκαπλάσιος ακέραιος:%d",atoi(yytext)*10);}
[+-]?{DIGIT}*("."{DIGIT})?	{printf("ο δεκαπλάσιος πραγματικός:%5.2f",atof(yytext)*10);}
%%
int main(void)
{
yylex();
return 0;
}
