#include "assembler.h"
#include "Primitivas.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int contadorAux = 0;

void generarASM(SExpression *ast, t_cola *colaSimbolos)
{
    FILE *pArchivo;

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
        printf("\nNo se puedo crear el archivo de assembler.\n");
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
    if (ast == NULL)
        return;

    escribirCodigo(pArchivo, ast->left);
    escribirCodigo(pArchivo, ast->right);

    if (esHoja(ast->left) || esHoja(ast->right))
    {
        switch (ast->type)
        {
        case eMULTIPLICACION:
            fprintf(pArchivo, ";MULTIPLICACION\n");
            fprintf(pArchivo, "FLD _%s\n", ast->left->value);
            fprintf(pArchivo, "FLD _%s\n", ast->right->value);
            fprintf(pArchivo, "FMUL \n");
            fprintf(pArchivo, "FSTP @aux%d\n", contadorAux);
            fprintf(pArchivo, "ffree\n");
            sprintf(ast->value, "@aux%d", contadorAux);
            ast->left = NULL;
            ast->right = NULL;
            contadorAux++;
            break;
        case eSUMA:
            fprintf(pArchivo, ";SUMA\n");
            fprintf(pArchivo, "FLD _%s\n", ast->left->value);
            fprintf(pArchivo, "FLD _%s\n", ast->right->value);
            fprintf(pArchivo, "FADD \n");
            fprintf(pArchivo, "FSTP @aux%d\n", contadorAux);
            fprintf(pArchivo, "ffree\n");
            sprintf(ast->value, "@aux%d", contadorAux);
            ast->left = NULL;
            ast->right = NULL;
            contadorAux++;
            break;
        case eDIVISION:
            fprintf(pArchivo, ";DIVISION\n");
            fprintf(pArchivo, "FLD _%s\n", ast->left->value);
            fprintf(pArchivo, "FLD _%s\n", ast->right->value);
            fprintf(pArchivo, "FDIV \n");
            fprintf(pArchivo, "FSTP @aux%d\n", contadorAux);
            fprintf(pArchivo, "ffree\n");
            sprintf(ast->value, "@aux%d", contadorAux);
            ast->left = NULL;
            ast->right = NULL;
            contadorAux++;
            break;
        case eMENOS:
            fprintf(pArchivo, ";RESTA\n");
            fprintf(pArchivo, "FLD _%s\n", ast->left->value);
            fprintf(pArchivo, "FLD _%s\n", ast->right->value);
            fprintf(pArchivo, "FSUB \n");
            fprintf(pArchivo, "FSTP @aux%d\n", contadorAux);
            fprintf(pArchivo, "ffree\n");
            sprintf(ast->value, "@aux%d", contadorAux);
            ast->left = NULL;
            ast->right = NULL;
            contadorAux++;
            break;
        case eASIGNACION:
            fprintf(pArchivo, ";ASIGNACION\n");
            fprintf(pArchivo, "FLD _%s\n", ast->right->value);
            fprintf(pArchivo, "FSTP _%s\n", ast->left->value);
            fprintf(pArchivo, "ffree\n");
            break;
        case eLEER:
            fprintf(pArchivo, ";LEER\n");
            fprintf(pArchivo, "getString %s\n", ast->left->value);
            break;
        case eESCRIBIR:
            fprintf(pArchivo, ";ESCRIBIR\n");
            fprintf(pArchivo, "displayString %s\n", ast->left->value);
            break;
        }
    }
}
