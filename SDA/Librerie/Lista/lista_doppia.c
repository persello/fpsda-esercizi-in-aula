#include "lista.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

/* Crea una lista_doppia doppia vuota */

lista_doppia crea_lista_d() {
    lista_doppia l;
    l.testa = NULL;
    l.coda = NULL;
    l.lunghezza = 0;
    return l;
}

/* Elimina una lista_doppia */

void elimina_lista_d(lista_doppia *l) {
    nodo_lista_doppia *n = l->testa;
    while (n != NULL) {
        nodo_lista_doppia *s = n->succ;
        elimina_nodo_d(n);
        n = s;
    }
    l->testa = NULL;
    l->coda = NULL;
    l->lunghezza = 0;
}

/* Crea il nodo di una lista_doppia */
nodo_lista_doppia *crea_nodo_d(float dato) {
    nodo_lista_doppia *n = (nodo_lista_doppia*)malloc(sizeof(nodo_lista_doppia));
    n->dato = dato;
    n->succ = NULL;
    n->pred = NULL;
    return n;
}

void aggiungi_in_coda_d(lista_doppia *l, float dato) {
    nodo_lista_doppia *n = crea_nodo_d(dato);
    if (l->lunghezza > 0) {
        l->coda->succ = n;
        n->pred = l->coda;
    } else {
        l->testa = n;
    }
    l->coda = n;
    l->lunghezza++;
}

void elimina_in_coda_d(lista_doppia *l) {
    nodo_lista_doppia *n = l->coda; // n è il nodo da eliminare
    if (l->lunghezza == 0)
        return;
    l->coda = l->coda->pred;
    l->coda->succ = NULL;
    l->lunghezza--;
    elimina_nodo_d(n);
}

void aggiungi_in_testa_d(lista_doppia *l, float dato) {
    nodo_lista_doppia *n = crea_nodo_d(dato);
    if (l->lunghezza == 0)
        l->coda = n;
    if (l->lunghezza > 0)
        l->testa->pred = n;
    n->succ = l->testa;
    l->testa = n;
    l->lunghezza++;
}

void elimina_in_testa_d(lista_doppia *l) {
    nodo_lista_doppia *n = l->testa;
    if (l->lunghezza == 0)
        return;
    l->testa = l->testa->succ;
    l->lunghezza--;
    elimina_nodo_d(n);
}

int lunghezza_d(lista_doppia l) {
    return l.lunghezza;
}

bool lista_doppia_vuota_d(lista_doppia l) {
    return l.lunghezza == 0;
}

void stampa_lista_doppia_d(lista_doppia l) {
    nodo_lista_doppia *n = l.testa;
    while (n != NULL) {
        printf("%g ", n->dato);
        n = n->succ;
    }
    if (l.lunghezza > 0)
        printf("\n");
}

/* Elimina il nodo di una lista_doppia */

void elimina_nodo_d(nodo_lista_doppia *n) {
    free(n);
    n = NULL;
}
