#include "assembler.h"
#include "Primitivas.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void generarASM(SExpression *ast, t_cola *colaSimbolos)
{
    FILE *pArchivo;

    crearArchivo(&pArchivo);

    escribirCabecera(pArchivo);

    escribirVariables(pArchivo, colaSimbolos);

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
}
/*
void imprimirArbolPosOrden(SExpression *arbol)
{
    if (arbol)
    {
        imprimirArbolInOrden(arbol->left);

        imprimirArbolInOrden(arbol->right);
    }*/