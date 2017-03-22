%option noyywrap
%{
#include <stdio.h>
#include <stdlib.h>
int charn,tabn,numn,i;
FILE* fp;
%}
%%
0|[1-9][0-9]* { numn++; }
[ \f\n\r\t]+ { tabn++; }
. { charn++; }
%%
int main(int argc, char *argv[])
{
 if (argc<2) {
      printf("\nNo filename defined\n");
      exit(1);
      }
  for (i=1;i<argc;i++){
  fp = fopen(argv[i],"r");
  if (!fp) {
      printf("\nFile #%d <%s> couldn't be opened\n",i,argv[i]);
      continue;
      }
	yyrestart(fp);
	yylex();
  }
printf("\nChar number read: %d \nTab number: %d \nNumbers read: %d\n",charn,tabn,numn);

return 0;
}
