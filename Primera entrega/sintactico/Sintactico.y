%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <y.tab.h>

  int yystopparser = 0;
  FILE *yyin;

  int error();
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

//Aca van las reglas
declaracion:
  DECVAR CORCA variables CORCC DEFTIPO CORCA tipos CORCC;

variables:
  variables COMA ID |
  ID;

tipos:
  tipos COMA INTEGER |
  tipos COMA FLOAT |
  INTEGER |
  FLOAT;

%%

int main(int argc, char *argv[])
{
  if(( yyin = fopen(argv[1], "rt")) == NULL)
    printf("\nNo se puede abrir el archivo de prueba: %s\n", argv[1]);
  else
    yyparse();

  fclose(yyin);
  return 0;
  fclose(yyin);
  return 0;
}  