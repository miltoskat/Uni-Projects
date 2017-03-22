%option noyywrap
%{
#include <stdio.h>
%}
ID [a-zA-Z][a-zA-Z"_"]*
DIGIT [0-9]
INTEGER {DIGIT}+
REAL INTEGER("."{DIGIT})?
OPERATOR [+-*/]
