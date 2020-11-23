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

  SExpression* pMaximo;
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
  char distinctVariableName[30];
  char stringFormateado[33];

  t_pila pilaTipos;
  t_pila pilaVariables;
  t_pila pilaParametros[10];

  t_cola colaSimbolos;
  QueueItem itemSimbolo;

  int indicePilaParametros = -1;
  int cantCadenas = 0;

  StackItem itemTipo;
  StackItem itemVar;
  StackItem itemParametro;

  void write_graphviz(SExpression*);
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
%right NOT

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
             *expression = pPrograma;
             write_graphviz(pPrograma);
             generarASM(pPrograma, &colaSimbolos);
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
  DECVAR CORCA variables CORCC DEFTIPO CORCA tipos CORCC {
    sacarDePila(&pilaTipos, &itemTipo);
    sacarDePila(&pilaVariables, &itemVar);

    pDeclaracion = crearNodo(eDECLARACION, crearHoja(itemVar.value), crearHoja(itemTipo.value));
    cargarItemSimboloVariable(&itemSimbolo, itemVar.value, itemTipo.value);
    acolar(&colaSimbolos, &itemSimbolo);

    while(!esPilaVacia(&pilaTipos))
    {

      pAux = pDeclaracion;

      sacarDePila(&pilaTipos, &itemTipo);
      sacarDePila(&pilaVariables, &itemVar);

      pDeclaracion = crearNodo(eDECLARACION, crearHoja(itemVar.value), crearHoja(itemTipo.value));
      
      pDeclaracion = crearNodo(ePROGRAMA, pAux, pDeclaracion);

      cargarItemSimboloVariable(&itemSimbolo, itemVar.value, itemTipo.value);
      acolar(&colaSimbolos, &itemSimbolo);
    }
    
    printf("\t{DECVAR CORCA variables CORCC DEFTIPO CORCA tipos CORCC} es declaracion\n"); 
  };

variables:
  variables COMA variable { strcpy(itemVar.value, yytext); meterEnPila(&pilaVariables, &itemVar); printf("\t{variables COMA variable} es variables\n"); }|
  variable { crearPila(&pilaVariables); strcpy(itemVar.value, yytext); meterEnPila(&pilaVariables, &itemVar); printf("\t{variable} es variables\n"); };

variable:
  ID { 
    printf("\t{ID} es variable\n");

  };

tipos:
  tipos COMA tipo { strcpy(itemTipo.value, yytext); meterEnPila(&pilaTipos, &itemTipo); printf("\t{tipos COMA tipo} es tipos\n"); }|
  tipo { crearPila(&pilaTipos); strcpy(itemTipo.value, yytext); meterEnPila(&pilaTipos, &itemTipo); printf("\t{tipo} es tipos\n"); };

tipo:
  INTEGER { printf("\t{INTEGER} es tipo\n"); } |
  FLOAT { printf("\t{FLOAT} es tipo\n"); };

impresion:
  IMPR CONSCAD {
    formatearString(yytext, stringFormateado);

    cargarItemSimboloCadena(&itemSimbolo, yytext, &cantCadenas);
    acolar(&colaSimbolos, &itemSimbolo);
  } PYC { 
    pImpresion = crearNodo(eESCRIBIR, crearHoja(stringFormateado), NULL);
    $$ = pImpresion;
    printf("\t{IMPR CONSCAD PYC} es impresion\n");
  } |
  IMPR ID {strcpy(nameID, yytext);} PYC { pImpresion = crearNodo(eESCRIBIR, crearHoja(nameID), NULL); $$=pImpresion; printf("\t{IMPR ID PYC} es impresion\n"); };

lectura:
  LEER ID {strcpy(nameID, yytext);} PYC { pLectura = crearNodo(eLEER, crearHoja(nameID), NULL); $$ = pLectura; printf("\t{IMPR ID PYC} es impresion\n"); };

asignacion:
  ID {strcpy(nameID, yytext);} ASIG expresion PYC{ pAsignacion = crearNodo(eASIGNACION, crearHoja(nameID), pExpresion);$$=pAsignacion; printf("\t{ID ASIG expresion} es asignacion\n"); };

expresion:
  expresion SUMA termino { pExpresion = crearNodo(eSUMA, $1, pTermino); $$ = pExpresion; printf("\t{expresion SUMA termino} es expresion\n"); } |
  expresion MENOS termino { pExpresion = crearNodo(eMENOS, $1, pTermino); $$ = pExpresion; printf("\t{expresion MENOS termino} es expresion\n"); } |
  termino { pExpresion = pTermino; $$ = pExpresion; printf("\t{termino} es expresion\n"); };

termino:
  termino MULT factor { pTermino = crearNodo(eMULTIPLICACION, $1, pFactor); $$=pTermino; printf("\t{termino MULT factor} es termino\n"); } |
  termino DIV factor { pTermino = crearNodo(eDIVISION, $1, pFactor); $$=pTermino; printf("\t{termino DIV factor} es termino\n"); } |
  factor { pTermino = pFactor; $$ = $1; printf("\t{factor} es termino\n"); };

factor:
  PARA expresion PARC { pFactor = pExpresion;$$ = $2; printf("\t{PARA expresion PARC} es factor\n"); } |
  ID { printf("\t{ID} es factor\n"); pFactor = crearHoja(yytext); $$ = pFactor; } |
  CONSENT { 
    printf("\t{CONSENT} es factor\n");
    pFactor = crearHoja(yytext);
    $$ = pFactor;
    
    cargarItemSimbolo(&itemSimbolo, "entero", yytext);
    acolar(&colaSimbolos, &itemSimbolo);
  } |
  CONSREAL { 
    printf("\t{CONSREAL} es factor\n"); 
    pFactor = crearHoja(yytext); 
    $$ = pFactor;

    cargarItemSimbolo(&itemSimbolo, "real", yytext);
    acolar(&colaSimbolos, &itemSimbolo);
  } |
  CONSHEXA { 
    printf("\t{CONSHEXA} es factor\n");
    pFactor = crearHoja(yytext);
    $$ = pFactor;
    
    cargarItemSimbolo(&itemSimbolo, "hexadecimal", yytext);
    acolar(&colaSimbolos, &itemSimbolo);
  } |
  CONSBIN {
    printf("\t{CONSBIN} es factor\n");
    pFactor = crearHoja(yytext);
    $$ = pFactor;
    
    cargarItemSimbolo(&itemSimbolo, "binario", yytext);
    acolar(&colaSimbolos, &itemSimbolo);
  } |
  maximo {pFactor = pMaximo; $$= pFactor; printf("\t{maximo} es factor\n");};

mientras:
  WHILE PARA condiciones PARC LLAVA programa LLAVC { pMientras = crearNodo(eMIENTRAS, pCondiciones, pPrograma);printf("\t{WHILE PARA condicion PARC LLAVA programa LLAVC} es mientras\n"); };

condiciones:
  condiciones Y condicion { pCondiciones = crearNodo(eY, pCondiciones, pCondicion); $$ = pCondiciones; printf("\t{condiciones Y condicion} es condiciones\n"); }|
  condiciones O condicion { pCondiciones = crearNodo(eO, pCondiciones, pCondicion); $$ = pCondiciones; printf("\t{condiciones O condicion} es condiciones\n"); }|
  NOT condicion { pCondiciones = crearNodo(eNOT, $2, NULL); $$ = pCondiciones; printf("\t{NOT condicion} es condiciones\n"); } |
  //NOT PARA condiciones PARC { pCondiciones = crearNodo(eNOT, $3, NULL); $$ = pCondiciones; printf("\t{NOT PARA condiciones PARC} es condiciones\n"); } |
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
  FNMAX PARA parametros PARC { 
    sacarDePila(&pilaParametros[indicePilaParametros], &itemParametro);

    strcpy(distinctVariableName, "@max");
    sprintf(stringFormateado, "%d",indicePilaParametros);
    strcat(distinctVariableName, stringFormateado);
    
    cargarItemSimboloVariable(&itemSimbolo, distinctVariableName, "real");
    acolar(&colaSimbolos, &itemSimbolo);

    pMaximo = crearNodo(eDECLARACION, crearHoja(distinctVariableName), crearHoja("EXPRESION"));
    pAux = crearNodo(ePROGRAMA, pMaximo, crearNodo(eASIGNACION, crearHoja(distinctVariableName), itemParametro.estructura));
    
    while(!esPilaVacia(&pilaParametros[indicePilaParametros]))
    {
      sacarDePila(&pilaParametros[indicePilaParametros], &itemParametro);
      pAux = crearNodo(ePROGRAMA, pAux, crearNodo(eDECISION, crearNodo(eMENOR, crearHoja(distinctVariableName), itemParametro.estructura), crearNodo(eASIGNACION, crearHoja(nameID), itemParametro.estructura)));

    }

    pMaximo=pAux;
    indicePilaParametros--;
    printf("\t{FNMAX PARA parametros PARC} es maximo\n"); 
  };

parametros:
  parametros COMA expresion { itemParametro.estructura = pExpresion; meterEnPila(&pilaParametros[indicePilaParametros], &itemParametro); printf("\t{parametros COMA expresion} es parametros\n"); } |
  expresion { indicePilaParametros++; crearPila(&pilaParametros[indicePilaParametros]); itemParametro.estructura = pExpresion; meterEnPila(&pilaParametros[indicePilaParametros], &itemParametro); printf("\t{expresion} es parametros\n"); };

decision:
  SI PARA condiciones PARC sentencia {pDecision = crearNodo(eDECISION, $3, pSentencia); $$ = pDecision; printf("\t{SI PARA condiciones PARC sentencia} es decision\n"); } |
  SI PARA condiciones PARC LLAVA programa LLAVC {pDecision = crearNodo(eDECISION, $3, pPrograma); $$ = pDecision; printf("\t{SI PARA condiciones PARC LLAVA programa LLAVC} es decision\n"); } |
  SI PARA condiciones PARC LLAVA programa LLAVC SINO LLAVA programa LLAVC{ pDecision = crearNodo(eDECISION, $3, crearNodo(eDECISIONCUERPO, $6, $10)); $$ = pDecision; printf("\t{SI PARA condiciones PARC LLAVA programa LLAVC SINO LLAVA programa LLAVC} es decision\n"); } ;

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
  case eNOT:
    sprintf(name, "NOT");
    return name;
  case eY:
    sprintf(name, "Y");
    return name;
  case eO:
    sprintf(name, "O");
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
  case eDECLARACION:
    sprintf(name, "DECLARACION");
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
////////// escribir tablas simbolos
void escribirTablaSimbolos() {
  FILE* arch;
  int i;
  if((arch = fopen("ts.txt","wb")) == NULL) {
    printf("\nNo se puedo crear la tabla de simbolos.\n");
    return;
  }

  fprintf(arch, "%-30s|%-15s|%-30s|%-10s\n\n", "NOMBRE", "TIPO DE DATO", "VALOR", "LONGITUD");

  while (!colaVacia(&colaSimbolos)) {
    desacolar(&colaSimbolos, &itemSimbolo);
    //printf("ESTE ES EL VALOR PADRE: %s\n", itemSimbolo.nombre);
    fprintf(arch, "%-30s|%-15s|%-30s|%-10d\n", itemSimbolo.nombre, itemSimbolo.tipo, itemSimbolo.valor, itemSimbolo.longitud);
  }

  fclose(arch);
}
//////////////////////////////////////////////////////

int main(int argc, char *argv[])
{
  crearCola(&colaSimbolos);

  if (( yyin = fopen(argv[1], "rt")) == NULL)
  {
    printf("\nNo se puede abrir el archivo de prueba: %s\n", argv[1]);
  }
  else
  {
    SExpression *expression;
    yyparse(&expression);

    //write_graphviz(expression);
  }

  escribirTablaSimbolos();

  fclose(yyin);
  return 0;
}

int yyerror(char *mensaje)
{
  printf("%s", mensaje);
  exit(1);
}