%{
#include <stdio.h>
#include <stdlib.h>

FILE *yyin; // funcion que hace el analisis.
int yylvan; //Variable reservada que interactua con el analizador lexico
char* yyltext; //varible que devuelve flex

int yyerror(void);
%}

%option noyywrap
%option yylineno

LETRA [a-zA-Z]
DIGITO [0-9]

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

CONSCAD   ["].{30}["]
CONSENT   [-]?[0-9]+
CONSREAL  [-]?{DIGITO}*[.]{DIGITO}*
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
NO_IG     "!="
IG        "=="

Y         "and"
O         "or"

%%

{DECVAR}      {printf("DECVAR: %s\n", yytext);}
{DEFTIPO}     {printf("DEFTIPO: %s\n", yytext);}
{IMPR}      {printf("IMPR: %s\n", yytext);}
{LEER}      {printf("LEER: %s\n", yytext);}
{INTEGER}     {printf("INTEGER: %s\n", yytext);}
{FLOAT}     {printf("FLOAT: %s\n", yytext);}

{WHILE}     {printf("WHILE: %s\n", yytext);}
{SI}      {printf("SI: %s\n", yytext);}
{SINO}      {printf("SINO: %s\n", yytext);}

{Y}     {printf("Y: %s\n", yytext);}
{O}     {printf("O: %s\n", yytext);}

{ID}      {printf("ID: %s\n", yytext);}
{COMA}      {printf("COMA: %s\n", yytext);}
{PYC}     {printf("PYC: %s\n", yytext);}
{ASIG}      {printf("ASIG: %s\n", yytext);}

{CONSCAD}     {printf("CONSCAD: %s\n", yytext);}
{CONSENT}     {printf("CONSENT: %s\n", yytext);}
{CONSREAL}      {printf("CONSREAL: %s\n", yytext);}
{CONSHEXA}      {printf("CONSHEXA: %s\n", yytext);}
{CONSBIN}     {printf("CONSBIN: %s\n", yytext);}

{SUMA}      {printf("SUMA: %s\n", yytext);}
{MENOS}     {printf("MENOS: %s\n", yytext);}
{DIV}     {printf("DIV: %s\n", yytext);}
{MULT}      {printf("MULT: %s\n", yytext);}

{PARA}      {printf("PARA: %s\n", yytext);}
{PARC}      {printf("PARC: %s\n", yytext);}
{LLAVA}     {printf("LLAVA: %s\n", yytext);}
{LLAVC}     {printf("LLAVC: %s\n", yytext);}
{CORCA}     {printf("CORCA: %s\n", yytext);}
{CORCC}     {printf("CORCC: %s\n", yytext);}

{DIST}      {printf("DIST: %s\n", yytext);}
{MENIG}     {printf("MENIG: %s\n", yytext);}
{MAYIG}     {printf("MAYIG: %s\n", yytext);}
{NO_IG}     {printf("NO_IG: %s\n", yytext);}
{IG}      {printf("IG: %s\n", yytext);}

"\t"
"\n"
"\n\t"
"\r\n"
" "
.   yyerror();
%%

int main(int argc, char* argv[])
{
    if((yyin = fopen(argv[1], "rt")) == NULL){
        printf("\nNo se logro abrir el archivo: %s\n", argv[1]);
        return 1;
    }
    yylex();
    fclose(yyin);
}

int yyerror(void){
   printf("Caracter no valido: %s\n", yytext);
}