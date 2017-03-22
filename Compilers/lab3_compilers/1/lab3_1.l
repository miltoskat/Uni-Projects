%option noyywrap
%{
#include <stdio.h>
%}
%%
(username) {printf("%s",getlogin());}
%%
int main(void)
{
yylex();
return 0;
}
