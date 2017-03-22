%option noyywrap
%{
#include <stdio.h>
%}
DIGIT [0-9]
LETTER [a-z]
%%
[+-]?{DIGIT}+ {printf("ο ακέραιος:%d",atoi(yytext));}
[+-]?{DIGIT}+("."{DIGIT})?	{printf("ο πραγματικός:%5.2f",atof(yytext));}
(if|then|begin|end|procedure|function) {printf("Λέξη κλειδί: %s",yytext);}
{LETTER}({DIGIT}|{LETTER})* {printf("Ένα αναγνωριστικό: %s",yytext);}
. {printf("Άγνωστος χαρακτήρας");}
%%
int main(void)
{
yylex();
return 0;
}
