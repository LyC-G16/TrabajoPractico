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
CONSOCT   
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
LETRA     {print("LETRA: %s\n", yytext);}
DIGITO      {print("DIGITO: %s\n", yytext);}

ID      {print("ID: %s\n", yytext);}
COMA      {print("COMA: %s\n", yytext);}
PYC     {print("PYC: %s\n", yytext);}
ASIG      {print("ASIG: %s\n", yytext);}

DECVAR      {print("DECVAR: %s\n", yytext);}
DEFTIPO     {print("DEFTIPO: %s\n", yytext);}
IMPR      {print("IMPR: %s\n", yytext);}
LEER      {print("LEER: %s\n", yytext);}
INTEGER     {print("INTEGER: %s\n", yytext);}
FLOAT     {print("FLOAT: %s\n", yytext);}

CONSCAD     {print("CONSCAD: %s\n", yytext);}
CONSENT     {print("CONSENT: %s\n", yytext);}
CONSREAL      {print("CONSREAL: %s\n", yytext);}
CONSHEXA      {print("CONSHEXA: %s\n", yytext);}
CONSOCT     {print("CONSOCT: %s\n", yytext);}
CONSBIN     {print("CONSBIN: %s\n", yytext);}
FN      {print("FN: %s\n", yytext);}

SUMA      {print("SUMA: %s\n", yytext);}
MENOS     {print("MENOS: %s\n", yytext);}
DIV     {print("DIV: %s\n", yytext);}
MULT      {print("MULT: %s\n", yytext);}

WHILE     {print("WHILE: %s\n", yytext);}
SI      {print("SI: %s\n", yytext);}
SINO      {print("SINO: %s\n", yytext);}

PARA      {print("PARA: %s\n", yytext);}
PARC      {print("PARC: %s\n", yytext);}
LLAVA     {print("LLAVA: %s\n", yytext);}
LLAVC     {print("LLAVC: %s\n", yytext);}
CORCA     {print("CORCA: %s\n", yytext);}
CORCC     {print("CORCC: %s\n", yytext);}

DIST      {print("DIST: %s\n", yytext);}
MENIG     {print("MENIG: %s\n", yytext);}
MAYIG     {print("MAYIG: %s\n", yytext);}
NO_IG     {print("NO_IG: %s\n", yytext);}
IG      {print("IG: %s\n", yytext);}

Y     {print("Y: %s\n", yytext);}
O     {print("O: %s\n", yytext);}

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