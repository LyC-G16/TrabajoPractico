%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "y.tab.h"

  int yystopparser = 0;
  FILE *yyin;

  int yyerror();
  int yylex();
%}

%token LETRA
%token DIGITO

%token ID
%token COMA
%token PYC
%token ASIG

%token DECVAR
%token DEFTIPO
%token IMPR
%token LEER
%token INTEGER
%token FLOAT

%token CONSCAD
%token CONSENT
%token CONSREAL
%token CONSHEXA
%token CONSBIN

%token SUMA
%token MENOS
%token DIV
%token MULT

%token WHILE
%token SI
%token SINO

%token PARA
%token PARC
%token LLAVA
%token LLAVC
%token CORCA
%token CORCC

%token DIST
%token MENIG
%token MAYIG
%token NO_IG
%token IG

%token Y
%token O

%%
declaracion:
  DECVAR CORCA variables CORCC DEFTIPO CORCA tipos CORCC { printf("\t{DECVAR CORCA variables CORCC DEFTIPO CORCA tipos CORCC} es declaracion\n"); };
variables:
  variables COMA ID { printf("\t{variables COMA ID} es variables\n"); } |
  ID { printf("\t{ID} es variables\n"); };
tipos:
  tipos COMA INTEGER { printf("\t{tipos COMA INTEGER} es tipos\n"); } |
  tipos COMA FLOAT { printf("\t{tipos COMA FLOAT} es tipos\n"); } |
  INTEGER { printf("\t{INTEGER} es tipos\n"); } |
  FLOAT { printf("\t{FLOAT} es tipos\n"); };

%%

int main(int argc, char *argv[])
{
  if(( yyin = fopen(argv[1], "rt")) == NULL)
  {
    printf("\nNo se puede abrir el archivo de prueba: %s\n", argv[1]);
  }
  else
  {
    yyparse();
  }

  fclose(yyin);
  return 0;
}

int yyerror(void)
{
  printf("Error sintáctico\n");
  exit(1);
}