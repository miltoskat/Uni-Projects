%option noyywrap
%{
#include <stdio.h>
int tab=0, everything = 0;
FILE* fp;
%}
%%
[[:upper:]]+ {printf("Found an uppercase word: %s\n", yytext);}
[[:lower:]]+ {printf("Found an lowercase word: %s\n", yytext);}
[[:xdigit:][:upper:]][[:xdigit:][:upper:]][[:xdigit:][:upper:]]+ {printf("Found a hex number: %s\n", yytext);}
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
