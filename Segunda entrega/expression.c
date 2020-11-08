/*
 * expression.c
 * Implementation of functions used to build the syntax tree.
 */

#include "expression.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * @brief Allocates space for expression
 * @return The expression or NULL if not enough memory
 */
static SExpression *allocateExpression()
{
  SExpression *b = (SExpression *)malloc(sizeof(SExpression));
  if (b == NULL)
    return NULL;
  b->type = eVALUE;
  b->left = NULL;
  b->right = NULL;
  return b;
}

SExpression *crearHoja(char *value)
{
  printf("(hoja creada: %s)", value);
  SExpression *b = allocateExpression();
  if (b == NULL)
    return NULL;
  b->type = eVALUE;
  strcpy(b->value, value);

  return b;
}

SExpression *crearNodo(EOperationType type,
                       SExpression *left, SExpression *right)
{
  SExpression *b = allocateExpression();
  if (b == NULL)
    return NULL;
  b->type = type;
  b->left = left;
  b->right = right;
  return b;
}

void deleteExpression(SExpression *b)
{
  if (b == NULL)
    return;
  deleteExpression(b->left);
  deleteExpression(b->right);
  free(b);
}

EOperationType convertirLexemaEnOperacion(char *lexema)
{
  if (!strcmp("<", lexema))
    return eMENOR;

  if (!strcmp(">", lexema))
    return eMAYOR;

  if (!strcmp("==", lexema))
    return eIGUAL;

  if (!strcmp("<>", lexema))
    return eDISTINTO;

  if (!strcmp(">=", lexema))
    return eMAYORIGUAL;

  if (!strcmp("<=", lexema))
    return eMENORIGUAL;
}

void formatearString(char *string, char result[])
{
  /*
  int indice = 1;

  result[0] = '\\';
  result[1] = '\"';

  while (string[indice] != '\"')
  {
    result[indice + 1] = string[indice];
    indice++;
  }

  result[indice++] = '\\';
  result[indice++] = '\"';
  result[indice] = '\0';*/

  strcpy(result, "cadena");
}
