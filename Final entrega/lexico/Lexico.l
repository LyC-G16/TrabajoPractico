%{
  #include "expression.h"
  #include "Primitivas.h"
  #include <stdio.h>
  #include <stdlib.h>
  #include "y.tab.h"
  #include <string.h>

  FILE *yyin; // funcion que hace el analisis.
  int yylvan; //Variable reservada que interactua con el analizador lexico
  char* yyltext; //varible que devuelve flex

  float auxFloat;
  int auxInt;
  char aux[100];
  int yyerror();
%}

%option noyywrap
%option yylineno

LETRA [a-zA-Z]
DIGITO [0-9]

FNMAX     "maximo"

ID        {LETRA}({LETRA}|{DIGITO})*
COMA      ","
PYC       ";"
ASIG      ":"

DECVAR    "DIM"
DEFTIPO   "AS"
IMPR      "PUT"
LEER      "GET"
INTEGER   "Integer"
FLOAT     "Float"

CONSCAD   ["].*["]
CONSENT   [-]?[0-9]+
CONSREAL  [-]?({DIGITO}+[.]{DIGITO}*)|({DIGITO}*[.]{DIGITO}+)
CONSHEXA  0[xX][0-9a-fA-F]{1,4}
CONSBIN   0[bB][0-1]{1,16}

SUMA      "+"
MENOS     "-"
DIV       "/"
MULT      "*"

WHILE     "while"
SI        "if"
SINO      "else"

PARA      "("
PARC      ")"
LLAVA     "{"
LLAVC     "}"
CORCA     "<"
CORCC     ">"

DIST      "<>"
MENIG     "<="
MAYIG     ">="
IG        "=="

Y         "and"
O         "or"
NOT       "not"

%%


{FNMAX}       {printf("FNMAX: %s\n", yytext); return FNMAX;}

{DECVAR}      {printf("DECVAR: %s\n", yytext); return DECVAR;}
{DEFTIPO}     {printf("DEFTIPO: %s\n", yytext); return DEFTIPO;}
{IMPR}        {printf("IMPR: %s\n", yytext); return IMPR;}
{LEER}        {printf("LEER: %s\n", yytext); return LEER;}
{INTEGER}     {printf("INTEGER: %s\n", yytext); return INTEGER;}
{FLOAT}       {printf("FLOAT: %s\n", yytext); return FLOAT;}

{WHILE}       {printf("WHILE: %s\n", yytext); return WHILE;}
{SI}          {printf("SI: %s\n", yytext); return SI;}
{SINO}        {printf("SINO: %s\n", yytext); return SINO;}

{Y}           {printf("Y: %s\n", yytext); return Y;}
{O}           {printf("O: %s\n", yytext); return O;}
{NOT}         {printf("NOT: %s\n", yytext); return NOT;}

{ID}          {printf("ID: %s\n", yytext); return ID;}
{COMA}        {printf("COMA: %s\n", yytext); return COMA;}
{PYC}         {printf("PYC: %s\n", yytext); return PYC;}
{ASIG}        {printf("ASIG: %s\n", yytext); return ASIG;}

{CONSCAD}     { printf("CONSCAD: %s\n", yytext); strcpy(aux, yytext);if(strlen(aux) > 32){ printf("La cadena supera el limite.\n"); yyerror();} return CONSCAD;}
{CONSENT}     {printf("CONSENT: %s\n", yytext); auxInt = atoi(yytext); if(auxInt > 32767 || auxInt < -32768){ printf("El numero entero supera los limites.\n"); yyerror(); } return CONSENT;}
{CONSREAL}    {printf("CONSREAL: %s\n", yytext); auxFloat = atof(yytext);if(auxFloat > +3.4E+38 || auxFloat < -3.4E+38){ printf("El numero real supera los limites.\n"); yyerror();} return CONSREAL;}
{CONSHEXA}    {printf("CONSHEXA: %s\n", yytext); return CONSHEXA;}
{CONSBIN}     {printf("CONSBIN: %s\n", yytext); return CONSBIN;}

{SUMA}        {printf("SUMA: %s\n", yytext); return SUMA;}
{MENOS}       {printf("MENOS: %s\n", yytext); return MENOS;}
{DIV}         {printf("DIV: %s\n", yytext); return DIV;}
{MULT}        {printf("MULT: %s\n", yytext); return MULT;}

{PARA}        {printf("PARA: %s\n", yytext); return PARA;}
{PARC}        {printf("PARC: %s\n", yytext); return PARC;}
{LLAVA}       {printf("LLAVA: %s\n", yytext); return LLAVA;}
{LLAVC}       {printf("LLAVC: %s\n", yytext); return LLAVC;}
{CORCA}       {printf("CORCA: %s\n", yytext); return CORCA;}
{CORCC}       {printf("CORCC: %s\n", yytext); return CORCC;}

{DIST}        {printf("DIST: %s\n", yytext); return DIST;}
{MENIG}       {printf("MENIG: %s\n", yytext); return MENIG;}
{MAYIG}       {printf("MAYIG: %s\n", yytext); return MAYIG;}
{IG}          {printf("IG: %s\n", yytext); return IG;}

"\t"
"\n"
"\n\t"
"\r\n"
" "
.   yyerror("No se reconoce token.");
%%

