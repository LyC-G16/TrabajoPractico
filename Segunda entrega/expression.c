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
  printf("\nHojaCreada: %s:\n", value);
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

char *formatearString(char *string)
{
  char *cadenaFormateada;
  cadenaFormateada = replaceWord(string, "\"", "\\\"");

  return cadenaFormateada;
}

char *replaceWord(const char *s, const char *oldW,
                  const char *newW)
{
  char *result;
  int i, cnt = 0;
  int newWlen = strlen(newW);
  int oldWlen = strlen(oldW);

  // Counting the number of times old word
  // occur in the string
  for (i = 0; s[i] != '\0'; i++)
  {
    if (strstr(&s[i], oldW) == &s[i])
    {
      cnt++;

      // Jumping to index after the old word.
      i += oldWlen - 1;
    }
  }

  // Making new string of enough length
  result = (char *)malloc(i + cnt * (newWlen - oldWlen) + 1);

  i = 0;
  while (*s)
  {
    // compare the substring with the result
    if (strstr(s, oldW) == s)
    {
      strcpy(&result[i], newW);
      i += newWlen;
      s += oldWlen;
    }
    else
      result[i++] = *s++;
  }

  result[i] = '\0';
  return result;
}