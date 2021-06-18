#include "lista.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

/* Crea una lista vuota */

lista crea_lista() {
    lista l;
    l.testa = NULL;
    l.coda = NULL;
    l.lunghezza = 0;
    return l;
}

/* Elimina una lista */

void elimina_lista(lista *l) {
    nodo_lista *n = l->testa;
    while (n != NULL) {
        nodo_lista *s = n->succ;
        elimina_nodo(n);
        n = s;
    }
    l->testa = NULL;
    l->coda = NULL;
    l->lunghezza = 0;
}

/* Crea il nodo di una lista */
nodo_lista *crea_nodo(float dato) {
    nodo_lista *n = (nodo_lista*)malloc(sizeof(nodo_lista));
    n->dato = dato;
    n->succ = NULL;
    return n;
}

void aggiungi_in_coda(lista *l, float dato) {
    nodo_lista *n = crea_nodo(dato);
    if (l->lunghezza > 0) {
        l->coda->succ = n;
    } else {
        l->testa = n;
    }
    l->coda = n;
    l->lunghezza++;
}

void elimina_in_coda(lista *l) {
    nodo_lista *c = l->testa, *n = l->coda; // n è il nodo da eliminare
    if (l->lunghezza == 0)
        return;
    while (c->succ != n)
        c = c->succ;
    l->coda = c;
    l->coda->succ = NULL;
    l->lunghezza--;
    elimina_nodo(n);
}

void aggiungi_in_testa(lista *l, float dato) {
    nodo_lista *n = crea_nodo(dato);
    if (l->lunghezza == 0)
        l->coda = n;
    n->succ = l->testa;
    l->testa = n;
    l->lunghezza++;
}

void elimina_in_testa(lista *l) {
    nodo_lista *n = l->testa;
    if (l->lunghezza == 0)
        return;
    l->testa = l->testa->succ;
    l->lunghezza--;
    elimina_nodo(n);
}

int lunghezza(lista l) {
    return l.lunghezza;
}

bool lista_vuota(lista l) {
    return l.lunghezza == 0;
}

void stampa_lista(lista l) {
    nodo_lista *n = l.testa;
    while (n != NULL) {
        printf("%g ", n->dato);
        n = n->succ;
    }
    if (l.lunghezza > 0)
        printf("\n");
}

/* Elimina il nodo di una lista */

void elimina_nodo(nodo_lista *n) {
    free(n);
    n = NULL;
}


