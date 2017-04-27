%{
#define YYSTYPE double
#include <stdio.h>
#include <math.h>
void yyerror(const char*);
%}
%token DOUBLE LPAREN RPAREN
%left PLUS MINUS
%left MUL DIV
%right POW
%token EOL
%%
input:
      /* empty */
      | input line
      ;
line:
        EOL
      | expr EOL    { printf("%g\n", $1); }
      ;
expr:
      DOUBLE        { $$ = $1; }
| expr PLUS expr    { $$ = $1 + $3; }
| expr MINUS expr   { $$ = $1 - $3; }
| expr MUL expr     { $$ = $1 * $3; }
| expr DIV expr     { $$ = $1 / $3; }
| expr POW expr     { $$ = pow($1, $3); }
| LPAREN expr RPAREN  { $$ = $2; } 
;
%%
void yyerror(const char *str)
{
  fprintf(stderr," error: %s\n",str);
}
main()
{
  yyparse();
}
