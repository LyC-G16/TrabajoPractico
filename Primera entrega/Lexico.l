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

LETRA [a-zA-z]
DIGITO [0-9]

WRITE "write"
WHILE "while"
DECVAR "DECVAR"
END "ENDDEC"
ELSE "else"
FLOAT "Float"
INTEGER "Integer"
IF "if"
ENTERO ["-"]?{DIGITO}*
N_FLOTANTE ["-"]?{DIGITO}+["."]{DIGITO}+
OP_AS ":"
COMA ","
PYC ";"
ID {LETRA}({LETRA}|{DIGITO})*
STRING ["].*["]
PAR_A "("
PAR_C ")"
LLA_A "{"
LLA_C "}"
OP_SUM "+"
DIV "/"
MULT "*"
LEQ "<""="
HIGHER ">"
LESS "<"
HEQ ">="
NOT_EQ "!="
COMP "=="

%%
{WRITE} {printf("WRITE: %s\n", yytext);}
{FLOAT} {printf("FLOAT: %s\n", yytext);}
{N_FLOTANTE} {printf("N_FLOTANTE: %s\n", yytext);}
{INTEGER} {printf("INTEGER: %s\n", yytext);}
{IF} {printf("IF: %s\n", yytext);}
{DECVAR} {printf("DECVAR: %s\n", yytext);}
{END} {printf("END: %s\n", yytext);}
{WHILE} {printf("WHILE: %s\n", yytext);}
{ID} {printf("ID: %s\n", yytext);}
{COMA} {printf("COMA: %s\n", yytext);}
{PYC} {printf("PYC: %s\n", yytext);}
{OP_AS} {printf("OP_AS: %s\n", yytext);}
{OP_SUM} {printf("OP_SUM: %s\n", yytext);}
{PAR_A} {printf("PAR_A: %s\n", yytext);}
{PAR_C} {printf("PAR_C: %s\n", yytext);}
{OP_AS} {printf("OP_AS: %s\n", yytext);}
{LLA_A} {printf("LLA_A: %s\n", yytext);}
{LLA_C} {printf("LLA_C: %s\n", yytext);}
{DIV} {printf("DIV: %s\n", yytext);}
{MULT} {printf("MULT: %s\n", yytext);}
{LEQ} {printf("LEQ: %s\n", yytext);}
{HIGHER} {printf("HIGHER: %s\n", yytext);}
{HEQ} {printf("HEQ: %s\n", yytext);}
{NOT_EQ} {printf("NOT_EQ: %s\n", yytext);}
{COMP} {printf("COMP: %s\n", yytext);}
{ELSE} {printf("ELSE: %s\n", yytext);}
{ENTERO} {printf("ENTERO: %s\n", yytext);}
{N_FLOTANTE} {printf("N_FLOTANTE: %s\n", yytext);}
{LESS} {printf("LESS: %s\n", yytext);}
{STRING} {printf("STRING: %s\n", yytext);}

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