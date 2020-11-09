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

%token FNMAX

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
programaPrima:
  programa {printf("COMPILACIÓN EXITOSA!!\n"); };

programa: 
  sentencia {printf("\t{sentencia} es programa\n"); } |
  programa sentencia {printf("\t{programa sentencia} es programa\n");};

sentencia:
  impresion {printf("\t{impresion} es sentencia\n"); } |
  declaracion {printf("\t{declaracion} es sentencia\n"); } |
  lectura {printf("\t{lectura} es sentencia\n"); } |
  asignacion {printf("\t{asignacion} es sentencia\n"); } |
  mientras {printf("\t{mientras} es sentencia\n"); } |
  decision {printf("\t{decision} es sentencia\n"); };
  
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

impresion:
  IMPR CONSCAD PYC { printf("\t{IMPR CONSCAD PYC} es impresion\n"); }|
  IMPR expresion PYC { printf("\t{IMPR expresion PYC} es impresion\n"); };

lectura:
  LEER ID PYC { printf("\t{IMPR CONSCAD PYC} es impresion\n"); };

asignacion:
  ID ASIG expresion PYC{ printf("\t{ID ASIG expresion} es asignacion\n"); };

expresion:
  expresion SUMA termino { printf("\t{expresion SUMA termino} es expresion\n"); } |
  expresion MENOS termino { printf("\t{expresion MENOS termino} es expresion\n"); } |
  termino { printf("\t{termino} es expresion\n"); };

termino:
  termino MULT factor { printf("\t{termino MULT factor} es termino\n"); } |
  termino DIV factor { printf("\t{termino DIV factor} es termino\n"); } |
  factor { printf("\t{factor} es termino\n"); };

factor:
  PARA expresion PARC { printf("\t{PARA expresion PARC} es factor\n"); } |
  ID { printf("\t{ID} es factor\n"); } |
  CONSENT { printf("\t{CONSENT} es factor\n"); } |
  CONSREAL { printf("\t{CONSREAL} es factor\n"); } |
  CONSHEXA { printf("\t{CONSHEXA} es factor\n"); } |
  CONSBIN { printf("\t{CONSBIN} es factor\n"); } |
  maximo { printf("\t{maximo} es factor\n"); };

mientras:
  WHILE PARA condiciones PARC LLAVA programa LLAVC { printf("\t{WHILE PARA condicion PARC LLAVA programa LLAVC} es mientras\n"); };

condiciones:
  condiciones Y condicion { printf("\t{condiciones Y condicion} es condiciones\n"); }|
  condiciones O condicion { printf("\t{condiciones O condicion} es condiciones\n"); }|
  condicion { printf("\t{condicion} es condiciones\n"); };

condicion:
  expresion condicional expresion { printf("\t{expresion condicional expresion} es condicion\n"); }|
  expresion { printf("\t{expresion} es condicion\n"); };

condicional:
  CORCA { printf("\t{CORCA} es condicional\n"); }|
  CORCC { printf("\t{CORCC} es condicional\n"); }|
  DIST { printf("\t{DIST} es condicional\n"); }|
  MENIG { printf("\t{MENIG} es condicional\n"); }|
  MAYIG { printf("\t{MAYIG} es condicional\n"); }|
  NO_IG { printf("\t{NO_IG} es condicional\n"); }|
  IG { printf("\t{IG} es condicional\n"); };

maximo:
  FNMAX PARA parametros PARC { printf("\t{FNMAX PARA parametros PARC} es maximo\n"); };

parametros:
  parametros COMA expresion { printf("\t{parametros COMA expresion} es parametros\n"); } |
  expresion { printf("\t{expresion} es parametros\n"); };

decision:
  SI PARA condiciones PARC sentencia { printf("\t{SI PARA condiciones PARC sentencia} es decision\n"); } |
  SI PARA condiciones PARC LLAVA programa LLAVC { printf("\t{SI PARA condiciones PARC LLAVA programa LLAVC} es decision\n"); } |
  SI PARA condiciones PARC LLAVA programa LLAVC SINO LLAVA programa LLAVC{ printf("\t{SI PARA condiciones PARC LLAVA programa LLAVC SINO LLAVA programa LLAVC} es decision\n"); } ;

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