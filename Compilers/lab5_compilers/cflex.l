%option noyywrap
%{
  #include <stdio.h>
	#include <stdlib.h>
  int tab=0, everything = 0;
  FILE* fp;
%}
%%
("printf"|"main"|"int"|"char"|"double"|"float"|"#"|"define"|"return"|"scanf"|"fopen"|"fclose"|"fseek"|"exit") {printf("\n%s: Is a C keyword\n", yytext); }
("exitC")	{return 0;}
[a-zA-Z]+ {printf("\n%s: is not a C bound keyword\n", yytext);}
("+"|"-"|"*"|"/") {printf("\n%s: is a bound Operator please use it only for operations", yytext);}
[\f\n\r\t ]+ {ECHO;}
. {printf("%s", yytext);}
%%
int main(int argc, char const *argv[]) {
	if(argc<2){
		printf("\nError no file name specified please use keyboard to insert characters\n\n");
		yylex();
		return 0;
	}else
	fp=fopen(argv[1],"r");
	if(!fp){
		printf("\nFile couldn't be opened");
	}
	yyrestart(fp);
	yylex();
	return 0;
}
