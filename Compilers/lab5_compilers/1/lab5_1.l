%option noyywrap
%{
  #include <stdio.h>
	#include <stdlib.h>
  int tab=0, everything = 0;
  FILE* fp;
%}

%%
("is"|"am"|"are"|"were"|"was"|"be"|"being"|"been"|"do"|"does"|"did"|"should"|"can"|"could"|"has"|"have"|"had"|"go") {printf("\n%s: is a verb\n", yytext); }
[a-zA-Z]+ {printf("\n%s: is not a verb\n", yytext);}
[\f\n\r\t ]+ {ECHO;}
. {printf("%s", yytext);}
%%
  int main(int argc, char const *argv[]) {
    if(argc<2){
      printf("\nError no file name specified please use keyboard to insert characters\n");
			yylex();
			exit(1);
    }else
    fp=fopen(argv[1],"r");
    if(!fp){
      printf("\nFile couldn't be opened");
    }
    yyrestart(fp);
    yylex();
    return 0;
  }
