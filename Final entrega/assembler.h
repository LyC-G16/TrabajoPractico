/*
 * assembler.h
 
 */
#ifndef __ASSEMBLER_H__
#define __ASSEMBLER_H__

#include "expression.h"
#include "Primitivas.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void generarASM(SExpression *ast, t_cola *colaSimbolos);
void crearArchivo(FILE **pArchivo);
void escribirCabecera(FILE *pArchivo);
void escribirVariables(FILE *pArchivo, t_cola *colaSimbolos);
//void imprimirArbolInOrden(SExpression *ast);

#endif // __ASSEMBLER_H__