#include "assembler.h"
#include "Primitivas.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int contadorAux = 0;
int contadorIf = 0;
int contadorWhile = 0;
int ifLayer = 0;
t_pila pilaIdDecisiones;
t_pila pilaIdMientras;
StackItem item;

void generarASM(SExpression *ast, t_cola *colaSimbolos)
{
    FILE *pArchivo;

    crearPila(&pilaIdDecisiones);
    crearPila(&pilaIdMientras);

    crearArchivo(&pArchivo);

    escribirCabecera(pArchivo);

    escribirVariables(pArchivo, colaSimbolos);

    escribirCodigo(pArchivo, ast);

    escribirFinal(pArchivo);

    fclose(pArchivo);

    printf("\n///////////// Archivo de assembler generado. /////////////\n");
}

void crearArchivo(FILE **pArchivo)
{
    *pArchivo = fopen("Final.asm", "wb");

    if (*pArchivo == NULL)
    {
        printf("\nNo se pudo crear el archivo de assembler.\n");
        exit(1);
    }
}

void escribirCabecera(FILE *pArchivo)
{
    //fprintf(pArchivo, "include macros2.asm\n");
    //fprintf(pArchivo, "include numbers.asm\n\n");
    fprintf(pArchivo, ".MODEL LARGE\n.386\n.STACK 200h\n\n.DATA\n\n");
}

void escribirVariables(FILE *pArchivo, t_cola *colaSimbolos)
{
    QueueItem itemSimbolo;

    while (!colaVacia(colaSimbolos))
    {
        desacolar(colaSimbolos, &itemSimbolo);
        //printf("ESTE ES EL VALOR PADRE: %s\n", itemSimbolo.nombre);
        fprintf(pArchivo, "%-30s\tdd", itemSimbolo.nombre);

        if (strlen(itemSimbolo.valor) > 0)
            fprintf(pArchivo, "\t%s\n", itemSimbolo.valor);
        else
            fprintf(pArchivo, "\t%s", "?\n");
    }

    fprintf(pArchivo, "\n\n");
}

void escribirFinal(FILE *pArchivo)
{
    fprintf(pArchivo, "\n\nFINAL:\n");
    fprintf(pArchivo, "\tmov ah, 1 ; pausa, espera que oprima una tecla:\n");
    fprintf(pArchivo, "\tint 21h ; AH=1 es el servicio de lectura\n");
    fprintf(pArchivo, "\tMOV AX, 4C00h ; Sale del Dos\n");
    fprintf(pArchivo, "\tINT 21h ; Enviamos la interripcion 21h\n");
    fprintf(pArchivo, "END ; final del archivo.\n");
}

void escribirCodigo(FILE *pArchivo, SExpression *ast)
{
    int nroIf = 0;
    
    if (ast == NULL || esHoja(ast))
        return;

    escribirCodigo(pArchivo, ast -> left);

    switch (ast -> type)
    {
    case eMULTIPLICACION:
        fprintf(pArchivo, "; MULTIPLICACION\n");
        fprintf(pArchivo, "FLD _%s\n", ast -> left -> value);
        fprintf(pArchivo, "FLD _%s\n", ast -> right -> value);
        fprintf(pArchivo, "FMUL \n");
        fprintf(pArchivo, "FSTP @aux%d\n", contadorAux);
        fprintf(pArchivo, "ffree\n");
        sprintf(ast -> value, "@aux%d", contadorAux);
        ast -> left = NULL;
        ast -> right = NULL;
        contadorAux++;
        break;
    case eSUMA:
        if (ast -> right -> type != eVALUE)
            escribirCodigo(pArchivo, ast -> right);
        fprintf(pArchivo, "; SUMA\n");
        fprintf(pArchivo, "FLD _%s\n", ast -> left -> value);
        fprintf(pArchivo, "FLD _%s\n", ast -> right -> value);
        fprintf(pArchivo, "FADD \n");
        fprintf(pArchivo, "FSTP @aux%d\n", contadorAux);
        fprintf(pArchivo, "ffree\n");
        sprintf(ast -> value, "@aux%d", contadorAux);
        ast -> left = NULL;
        ast -> right = NULL;
        contadorAux++;
        break;
    case eDIVISION:
        fprintf(pArchivo, "; DIVISION\n");
        fprintf(pArchivo, "FLD _%s\n", ast -> left -> value);
        fprintf(pArchivo, "FLD _%s\n", ast -> right -> value);
        fprintf(pArchivo, "FDIV \n");
        fprintf(pArchivo, "FSTP @aux%d\n", contadorAux);
        fprintf(pArchivo, "ffree\n");
        sprintf(ast -> value, "@aux%d", contadorAux);
        ast -> left = NULL;
        ast -> right = NULL;
        contadorAux++;
        break;
    case eMENOS:
        if (ast -> right -> type != eVALUE)
            escribirCodigo(pArchivo, ast -> right);
        fprintf(pArchivo, "; RESTA\n");
        fprintf(pArchivo, "FLD _%s\n", ast -> left -> value);
        fprintf(pArchivo, "FLD _%s\n", ast -> right -> value);
        fprintf(pArchivo, "FSUB \n");
        fprintf(pArchivo, "FSTP @aux%d\n", contadorAux);
        fprintf(pArchivo, "ffree\n");
        sprintf(ast -> value, "@aux%d", contadorAux);
        ast -> left = NULL;
        ast -> right = NULL;
        contadorAux++;
        break;
    case eASIGNACION:
        if (ast -> right -> type != eVALUE)
            escribirCodigo(pArchivo, ast -> right);
        fprintf(pArchivo, "; ASIGNACION\n");
        fprintf(pArchivo, "FLD _%s\n", ast -> right -> value);
        fprintf(pArchivo, "FSTP _%s\n", ast -> left -> value);
        fprintf(pArchivo, "ffree\n");
        ast -> left = NULL;
        ast -> right = NULL;
        break;
    case eLEER:
        fprintf(pArchivo, "; LEER\n");
        fprintf(pArchivo, "getString %s\n", ast -> left -> value);
        ast -> left = NULL;
        //ast = NULL;
        break;
    case eESCRIBIR:
        fprintf(pArchivo, "; ESCRIBIR\n");
        fprintf(pArchivo, "displayString %s\n", ast -> left -> value);
        ast -> left = NULL;
        //ast = NULL;
        break;
    case eMENOR:
        fprintf(pArchivo, "; MENOR\n");
        fprintf(pArchivo, "FLD _%s\n", ast -> right -> value);
        fprintf(pArchivo, "FCOMP _%s\n", ast -> left -> value);
        fprintf(pArchivo, "FSTSW ax\n");
        fprintf(pArchivo, "SAHF\n");
        fprintf(pArchivo, "JNA\t");
        break;
    case eMAYOR:
        fprintf(pArchivo, "; MAYOR\n");
        fprintf(pArchivo, "FLD _%s\n", ast -> left -> value);
        fprintf(pArchivo, "FCOMP _%s\n", ast -> right -> value);
        fprintf(pArchivo, "FSTSW ax\n");
        fprintf(pArchivo, "SAHF\n");
        fprintf(pArchivo, "JNA\t");
        break;
    case eMENORIGUAL:
        fprintf(pArchivo, "; MENORIGUAL\n");
        fprintf(pArchivo, "FLD _%s\n", ast -> right -> value);
        fprintf(pArchivo, "FCOMP _%s\n", ast -> left -> value);
        fprintf(pArchivo, "FSTSW ax\n");
        fprintf(pArchivo, "SAHF\n");
        fprintf(pArchivo, "JNAE\t");
        break;
    case eMAYORIGUAL:
        fprintf(pArchivo, "; MAYORIGUAL\n");
        fprintf(pArchivo, "FLD _%s\n", ast -> right -> value);
        fprintf(pArchivo, "FCOMP _%s\n", ast -> left -> value);
        fprintf(pArchivo, "FSTSW ax\n");
        fprintf(pArchivo, "SAHF\n");
        fprintf(pArchivo, "JNAE\t");
        break;
    case eO:
        fprintf(pArchivo, "; OR\n");
        fprintf(pArchivo, "o_siguiente_condicion\n");
        fprintf(pArchivo, "jmp bloque_verdadero\n");
        fprintf(pArchivo, "o_siguiente_condicion:\n");
        break;
    case eY:
        fprintf(pArchivo, "; AND\n");
        fprintf(pArchivo, "bloque_falso\n");
        break;
    case eDECISION:
        printf("<<< ARRANCA EDECISION Nro %d >>>\n", nroIf);

        if (ast -> right -> type == eDECISIONCUERPO)
        {
            fprintf(pArchivo, "bloque_falso%d\n", nroIf);
        }
        else
        {
            fprintf(pArchivo, "endif%d\n", nroIf);
        }

        if (ast -> right -> type == eDECISIONCUERPO)
        {
            escribirCodigo(pArchivo, ast -> right);
            ast -> right = NULL;
        }
        else
        {
            escribirCodigo(pArchivo, ast -> right);
            ast -> right = NULL;
            fprintf(pArchivo, "endif%d:\n", nroIf);
        }
        printf("<<< TERMINA EDECISION Nro %d >>>\n", nroIf);
        break;
    case eDECISIONCUERPO:
        printf("<<< ARRANCA EDECISIONCUERPO Nro %d >>>\n", nroIf);

        fprintf(pArchivo, "; DECISIONCUERPO\n");
        escribirCodigo(pArchivo, ast -> left);
        ast -> left = NULL;
        fprintf(pArchivo, "jmp endif%d\n", nroIf);

        fprintf(pArchivo, "bloque_falso%d:\n", nroIf);
        escribirCodigo(pArchivo, ast -> right);
        ast -> right = NULL;
        fprintf(pArchivo, "endif%d:\n", nroIf);

        printf("<<< TERMINA EDECISIONCUERPO Nro %d >>>\n", nroIf);
        break;
    case eMIENTRAS:
        fprintf(pArchivo, "; MIENTRAS\n");
        fprintf(pArchivo, "mientras_inicio:\n");
        escribirCodigo(pArchivo, ast -> left);
        ast -> left = NULL;
        fprintf(pArchivo, "bloque_falso\n");
        escribirCodigo(pArchivo, ast -> right);
        ast -> right = NULL;
        escribirCodigo(pArchivo, ast -> left);
        ast -> left = NULL;
        fprintf(pArchivo, "jmp mientras_inicio\n");
        fprintf(pArchivo, "bloque_falso:\n");
        break;
    }

    escribirCodigo(pArchivo, ast -> right);
}
