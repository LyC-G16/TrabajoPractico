#include "Primitivas.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////////////
///PRIMITIVAS
//////////////////////////////////////////////////////////////////////////////////
void crearPila(t_pila *pp)
{
    *pp = NULL;
}
//////////////////////////////////////////////////////////////////////////////////
int meterEnPila(t_pila *pp, StackItem *pi)
{
    t_nodo_pila *pn = (t_nodo_pila *)malloc(sizeof(t_nodo_pila));
    if (!pn)
        return 0;
    pn->dato = *pi;
    pn->psig = *pp;
    *pp = pn;
    return 1;
}
//////////////////////////////////////////////////////////////////////////////////
int sacarDePila(t_pila *pp, StackItem *pi)
{
    t_nodo_pila *pn;
    if (!*pp)
        return 0;
    pn = *pp;
    *pi = (*pp)->dato; //Para que guarda este dato si lo va a sacar?//Es para mostrar en un printf "se saco este dato"??
    *pp = (*pp)->psig;
    free(pn);
    return 1;
}
//////////////////////////////////////////////////////////////////////////////////
int esPilaVacia(const t_pila *pp)
{
    return *pp == NULL;
}
//////////////////////////////////////////////////////////////////////////////////
int esPilaLlena(const t_pila *pp)
{
    t_nodo_pila *pn = (t_nodo_pila *)malloc(sizeof(t_nodo_pila)); //Crea un nodo, el cual hace que sea apuntado por pn.
    free(pn);                                                     //Si hay memoria, el puntero pn va a existir, por ende libera la memoria para no desperdiciarla.
    return pn == NULL;                                            //Pregunta si el puntero pn se creo.
}
//////////////////////////////////////////////////////////////////////////////////
int tope_de_pila(const t_pila *pp, StackItem *pi)
{
    if (!*pp)
        return 0;
    *pi = (*pp)->dato;
    return 0;
}

void vaciarPila(t_pila *pp)
{
    t_nodo_pila *pn;
    while (*pp)
    {
        pn = *pp;
        *pp = (*pp)->psig;
        printf("\n%s\n", pn->dato.value);
        free(pn);
    }
}

////////////////////////////////////////////////////////////
void crearCola(t_cola *pc)
{
    pc->pri = NULL;
    pc->ult = NULL;
}

int acolar(t_cola *pc, const QueueItem *pd)
{
    t_nodo *nue = (t_nodo *)malloc(sizeof(t_nodo));

    if (!nue)
        return SIN_MEMORIA;

    nue->dato = *pd;
    nue->sig = NULL;

    if (!pc->pri)
        pc->pri = nue;
    else
        pc->ult->sig = nue;

    pc->ult = nue;

    return 1;
}

int desacolar(t_cola *pc, QueueItem *pd)
{
    t_nodo *aux;

    if (!pc->pri)
        return COLA_VACIA;

    aux = pc->pri;
    *pd = aux->dato;
    pc->pri = aux->sig;

    if (!aux->sig)
        pc->ult = NULL;

    free(aux);

    return 1;
}

int colaLlena(const t_cola *pc)
{
    void *aux = malloc(sizeof(QueueItem));

    free(aux);

    return aux == NULL;
}

int colaVacia(const t_cola *pc)
{
    return pc->pri == NULL;
}

int verPrimero(const t_cola *pc, QueueItem *pd)
{
    if (!pc->pri)
        return COLA_VACIA;

    *pd = pc->pri->dato;
    return 1;
}
void vaciarCola(t_cola *pc)
{
    t_nodo *aux;

    while (!pc->pri)
    {
        aux = pc->pri;
        pc->pri = aux->sig;
        free(aux);
    }

    if (!pc->pri)
        pc->ult = NULL;
}

void cargarItemSimbolo(QueueItem *item, char *tipoDato, char *value)
{
    char* cadenaAuxiliar;

    sprintf(cadenaAuxiliar, "_%s", value);

    if (strcmp(tipoDato, "real") == 0) {
        cadenaAuxiliar = replace_char(cadenaAuxiliar);
    }

    strcpy(item->nombre, cadenaAuxiliar);
    strcpy(item->tipo, tipoDato);
    strcpy(item->valor, value);

    item->longitud = 0;
}

void cargarItemSimboloCadena(QueueItem *item, char *value, int *contador)
{
    char cadenaAuxiliar[33];

    item->longitud = strlen(value);

    sprintf(cadenaAuxiliar, "_cad%d", *contador);
    strcpy(item->nombre, cadenaAuxiliar);
    strcpy(item->tipo, "cadena");
    strcpy(item->valor, value);

    (*contador)++;
}

void cargarItemSimboloVariable(QueueItem *item, char *nombre, char *tipo)
{
    char* cadenaAuxiliar;

    sprintf(cadenaAuxiliar, "_%s", nombre);

    item->longitud = 0;
    strcpy(item->nombre, cadenaAuxiliar);
    strcpy(item->tipo, tipo);
    strcpy(item->valor, "\0");
}

char* replace_char(char* str) {
    char find = '.';
    char replace = 'p';

    char *current_pos = strchr(str, find);
    *current_pos = replace;

    printf("STRING RESULTADO: %s", str);
    return str;
}