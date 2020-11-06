%{
  #include "expression.h"
  #include "Primitivas.h"
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "y.tab.h"
  

  int yystopparser = 0;
  FILE *yyin;

  char *yytext;

  int yyerror();
  int yylex();

  SExpression* pFactor;
  SExpression* pExpresion;
  SExpression* pTermino;
  SExpression* pTipos;
  SExpression* pImpresion;
  SExpression* pDeclaracion;
  SExpression* pLectura;
  SExpression* pAsignacion;
  SExpression* pCondicion;
  SExpression* pCondiciones;
  SExpression* pMientras;
  SExpression* pDecision;
  SExpression* pVariables;
  SExpression* pSentencia;
  SExpression* pPrograma;
  SExpression* pAux;

  EOperationType condicional;

  char nameID[30];
  char stringFormateado[33];
%}

%parse-param { SExpression **expression }

%token LETRA
%token DIGITO

%token FNMAX

%token <value> ID
%token COMA
%token PYC
%token ASIG

%token DECVAR
%token DEFTIPO
%token IMPR
%token LEER
%token <value> INTEGER
%token <value> FLOAT

%token <value> CONSCAD
%token <value> CONSENT
%token <value> CONSREAL
%token <value> CONSHEXA
%token <value> CONSBIN

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
%token IG

%token Y
%token O

%union {
  char* value;
  SExpression *expression;
}

%type <expression> factor
%type <expression> expresion
%type <expression> termino
%type <expression> tipo
%type <expression> tipos
%type <expression> impresion
%type <expression> declaracion
%type <expression> lectura
%type <expression> asignacion
%type <expression> condicion
%type <expression> condiciones
%type <expression> mientras
%type <expression> decision
%type <expression> variable
%type <expression> variables
%type <expression> sentencia
%type <expression> programa


%%
programaPrima:
  programa {
            printf("COMPILACIÓN EXITOSA!!\n");
            //SExpression *prueba;
             *expression = pPrograma;
           };

programa: 
  sentencia { pPrograma = pSentencia; $$ = pPrograma; printf("\t{sentencia} es programa\n"); } 
  | programa sentencia { pPrograma = crearNodo(ePROGRAMA, $1, pSentencia);$$ = pPrograma; printf("\t{programa sentencia} es programa\n");};

sentencia:
  impresion { pSentencia = pImpresion; $$ = pSentencia; printf("\t{impresion} es sentencia\n"); } |
  declaracion { pSentencia = pDeclaracion; $$ = pSentencia; printf("\t{declaracion} es sentencia\n"); } |
  lectura { pSentencia = pLectura; $$ = pSentencia; printf("\t{lectura} es sentencia\n"); } |
  asignacion { pSentencia = pAsignacion; $$ = pSentencia; printf("\t{asignacion} es sentencia\n"); } |
  mientras { pSentencia = pMientras; $$ = pSentencia; printf("\t{mientras} es sentencia\n"); } |
  decision {pSentencia = pDecision; $$ = pSentencia; printf("\t{decision} es sentencia\n"); };
  
declaracion:
  DECVAR CORCA variables CORCC DEFTIPO CORCA tipos CORCC { printf("\t{DECVAR CORCA variables CORCC DEFTIPO CORCA tipos CORCC} es declaracion\n"); };

variables:
  variables COMA variable { printf("\t{variables COMA variable} es variables\n"); }|
  variable { printf("\t{variable} es variables\n"); };

variable:
  ID { $$ = crearHoja(yytext); printf("\t{ID} es variable\n"); };

tipos:
  tipos COMA tipo { printf("\t{tipos COMA tipo} es tipos\n"); }|
  tipo { printf("\t{tipo} es tipos\n"); };

tipo:
  INTEGER { $$ = crearHoja(yytext); printf("\t{INTEGER} es tipo\n"); } |
  FLOAT { $$ = crearHoja(yytext); printf("\t{FLOAT} es tipo\n"); };

impresion:
  IMPR CONSCAD {formatearString(yytext, stringFormateado);} PYC { pImpresion = crearNodo(eESCRIBIR, crearHoja(stringFormateado), NULL); $$=pImpresion; printf("\t{IMPR CONSCAD PYC} es impresion\n"); };
  //| IMPR expresion PYC { $$ = crearNodo(eESCRIBIR, crearNodo($2), NULL); printf("\t{IMPR expresion PYC} es impresion\n"); };

lectura:
  LEER ID {strcpy(nameID, yytext);} PYC { pLectura = crearNodo(eLEER, crearHoja(nameID), NULL); $$ = pLectura; printf("\t{IMPR CONSCAD PYC} es impresion\n"); };

asignacion:
  ID {strcpy(nameID, yytext);} ASIG expresion PYC{ pAsignacion = crearNodo(eASIGNACION, crearHoja(nameID), pExpresion);$$=pAsignacion; printf("\t{ID ASIG expresion} es asignacion\n"); };

expresion:
  expresion SUMA termino { pExpresion = crearNodo(eSUMA, pExpresion, pTermino); $$=pExpresion; printf("\t{expresion SUMA termino} es expresion\n"); } |
  expresion MENOS termino { pExpresion = crearNodo(eMENOS, pExpresion, pTermino); $$=pExpresion; printf("\t{expresion MENOS termino} es expresion\n"); } |
  termino { pExpresion = pTermino; $$ = $1; printf("\t{termino} es expresion\n"); };

termino:
  termino MULT factor { pTermino = crearNodo(eMULTIPLICACION, pTermino, pFactor); $$=pTermino; printf("\t{termino MULT factor} es termino\n"); } |
  termino DIV factor { pTermino = crearNodo(eDIVISION, pTermino, pFactor); $$=pTermino; printf("\t{termino DIV factor} es termino\n"); } |
  factor { pTermino = pFactor; $$ = $1; printf("\t{factor} es termino\n"); };

factor:
  PARA expresion PARC { pFactor = pExpresion;$$ = $2; printf("\t{PARA expresion PARC} es factor\n"); } |
  ID { printf("\t{ID} es factor\n"); pFactor = crearHoja(yytext);$$ =pFactor;printf("\n//////////VALOR:%s\n", yytext); } |
  CONSENT { printf("\t{CONSENT} es factor\n"); pFactor = crearHoja(yytext);$$ =pFactor;printf("\n//////////VALOR:%s\n", yytext);} |
  CONSREAL { printf("\t{CONSREAL} es factor\n"); pFactor = crearHoja(yytext);$$ =pFactor;printf("\n//////////VALOR:%s\n", yytext);} |
  CONSHEXA { printf("\t{CONSHEXA} es factor\n"); pFactor = crearHoja(yytext);$$ =pFactor;printf("\n//////////VALOR:%s\n", yytext);} |
  CONSBIN { printf("\t{CONSBIN} es factor\n"); pFactor = crearHoja(yytext);$$ =pFactor;printf("\n//////////VALOR:%s\n", yytext);} |
  maximo { printf("\t{maximo} es factor\n");};

mientras:
  WHILE PARA condiciones PARC LLAVA programa LLAVC { pMientras = crearNodo(eMIENTRAS, pCondiciones, pPrograma);printf("\t{WHILE PARA condicion PARC LLAVA programa LLAVC} es mientras\n"); };

condiciones:
  condiciones Y condicion { printf("\t{condiciones Y condicion} es condiciones\n"); }|
  condiciones O condicion { printf("\t{condiciones O condicion} es condiciones\n"); }|
  condicion {pCondiciones = pCondicion; $$ = pCondiciones; printf("\t{condicion} es condiciones\n"); };

condicion:
  expresion {pAux =  pExpresion;} condicional {condicional = convertirLexemaEnOperacion(yytext);} expresion {pCondicion = crearNodo(condicional, pAux, pExpresion); $$=pCondicion; printf("\t{expresion condicional expresion} es condicion\n"); }|
  expresion { pCondicion = pExpresion; $$=pCondicion; printf("\t{expresion} es condicion\n"); };

condicional:
  CORCA { printf("\t{CORCA} es condicional\n"); }|
  CORCC { printf("\t{CORCC} es condicional\n"); }|
  DIST { printf("\t{DIST} es condicional\n"); }|
  MENIG { printf("\t{MENIG} es condicional\n"); }|
  MAYIG { printf("\t{MAYIG} es condicional\n"); }|
  IG { printf("\t{IG} es condicional\n"); };

maximo:
  FNMAX PARA parametros PARC { printf("\t{FNMAX PARA parametros PARC} es maximo\n"); };

parametros:
  parametros COMA expresion { printf("\t{parametros COMA expresion} es parametros\n"); } |
  expresion { printf("\t{expresion} es parametros\n"); };

decision:
  SI PARA condiciones PARC sentencia {pDecision = crearNodo(eDECISION, pCondiciones, pSentencia); $$ = pDecision; printf("\t{SI PARA condiciones PARC sentencia} es decision\n"); } |
  SI PARA condiciones PARC LLAVA programa LLAVC {pDecision = crearNodo(eDECISION, pCondiciones, pPrograma); $$ = pDecision; printf("\t{SI PARA condiciones PARC LLAVA programa LLAVC} es decision\n"); } |
  SI PARA condiciones PARC LLAVA programa LLAVC SINO LLAVA programa LLAVC{ pDecision = crearNodo(eDECISION, pCondiciones, crearNodo(eDECISIONCUERPO, $6, $10)); $$ = pDecision; printf("\t{SI PARA condiciones PARC LLAVA programa LLAVC SINO LLAVA programa LLAVC} es decision\n"); } ;

%%

////////// funciones GRAPHVIZ
char* node_name(SExpression *e){
  /* return char* description of parse tree node, e.g. '+', '-', '3', etc */
  char* name = (char *)malloc(16);  /* up to 15 char descriptive node name */
  switch (e->type){
  case eVALUE:
    sprintf(name, "%s", e->value);
    return name;
  case eMULTIPLICACION:
    sprintf(name, "*");
    return name;
  case eSUMA:
    sprintf(name, "+");
    return name;
  case eDIVISION:
    sprintf(name, "/");
    return name;
  case eMENOS:
    sprintf(name, "-");
    return name;
  case eASIGNACION:
    sprintf(name, "=");
    return name;
  case eMAYOR:
    sprintf(name, ">");
    return name;
  case eMENOR:
    sprintf(name, "<");
    return name;
  case eIGUAL:
    sprintf(name, "==");
    return name;
  case eDISTINTO:
    sprintf(name, "<>");
    return name;
  case eMAYORIGUAL:
    sprintf(name, ">=");
    return name;
  case eMENORIGUAL:
    sprintf(name, "<=");
    return name;
  case eMIENTRAS:
    sprintf(name, "WHILE");
    return name;
  case eDECISION:
    sprintf(name, "IF");
    return name;
  case eDECISIONCUERPO:
    sprintf(name, "CUERPO");
    return name;
  case eESCRIBIR:
    sprintf(name, "PUT");
    return name;
  case eLEER:
    sprintf(name, "GET");
    return name;
  case ePROGRAMA:
    sprintf(name, "PROGRAMA");
    return name;
  default:  // shouldn't get here
    sprintf(name, "???");
    return name;
  }
}

/* We need to declare this before write_node so
   that the recursive mutual calls compile properly. */
void write_tree(SExpression *e, FILE *dotfile, int node);

void write_node(SExpression *e, FILE *dotfile, int node, int parent){
  fprintf(dotfile, " %i -> %i;\n", parent, node);
  write_tree(e, dotfile, node);
}

void write_tree(SExpression *e, FILE *dotfile, int node){
  fprintf(dotfile, " %i [label=\"%s\"];\n", node, node_name(e));
  if (e->left != NULL) write_node(e->left, dotfile, 2*node, node);
  if (e->right != NULL) write_node(e->right, dotfile, 2*node+1, node);
}

void write_graphviz(SExpression *e){
  if(e == NULL)
  {
    printf("ERROR: No se puede imprimir árbol nulo.");
    exit(1);
  }

  FILE *dotfile = fopen("tree.dot", "w");
  fprintf(dotfile, "digraph tree {\n");
  write_tree(e, dotfile, 1);
  fprintf(dotfile, "}\n");
  fclose(dotfile);
}
//////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
  if (( yyin = fopen(argv[1], "rt")) == NULL)
  {
    printf("\nNo se puede abrir el archivo de prueba: %s\n", argv[1]);
  }
  else
  {
    SExpression *expression;
    yyparse(&expression);

    write_graphviz(expression);
  }

  t_pila pila;
  crearPila(&pila);
  StackItem item1;
  StackItem item2;

  strcpy(item1.value, "token1");
  strcpy(item2.value, "token2");

  meterEnPila(&pila, &item1);
  meterEnPila(&pila, &item2);

  StackItem aux;
  sacarDePila(&pila, &aux);
  printf("\n%s\n");
  sacarDePila(&pila, &aux);
  printf("\n%s\n");


  fclose(yyin);
  return 0;
}


int yyerror(void)
{
  printf("Error sintáctico\n");
  exit(1);
}