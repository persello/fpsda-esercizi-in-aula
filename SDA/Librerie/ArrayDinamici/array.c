#include "array.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


vettore_dinamico crea_vettore_dinamico(int n) {
    vettore_dinamico v;
    // non ha senso creare vettori di dimensione negativa
    assert(n >= 0);
    if (n > 0) {
        // alloca lo spazio per i dati, memorizzandone il puntatore nel descrittore
        v.dati = (float*)malloc(2 * n * sizeof(float));
        // verifica che l'allocazione abbia avuto buon esito
        assert(v.dati != NULL);
    }
    else
        v.dati = NULL;
    v.dimensione = n;
    v.capacita = 2 * n;
    return v;
}

void ridimensiona_vettore_dinamico(vettore_dinamico *v, int n) {
    // non ha senso creare vettori di dimensione negativa
    assert(n >= 0);
    if (n >= v->capacita) { // raddoppia
        v->dati = (float*)realloc(v->dati, 2 * n * sizeof(float));
        // verifica che la riallocazione abbia avuto buon esito
        assert(v->dati != NULL);
        v->capacita = 2 * n;
    } else if (v->capacita > 1 && n <= v->capacita / 4) { // dimezza
        v->dati = (float*)realloc(v->dati, 2 * n * sizeof(float));
        assert(v->dati != NULL);
        v->capacita = 2 * n;
        //
    } else if (v->capacita == 0 && n > 0) { // passa da zero a una dimensione diversa da zero
        v->dati = (float*)malloc(2 * n * sizeof(float));
        assert(v->dati != NULL);
        v->capacita = 2 * n;
    }
    v->dimensione = n;
}

void elimina_vettore_dinamico(vettore_dinamico *v) {
    // elimina dati
    free(v->dati);
    v->dimensione = 0;
    v->capacita = 0;
}

void stampa_vettore_dinamico(vettore_dinamico v) {
    int i;
    for (i = 0; i < v.dimensione; i++)
        printf("%g ", v.dati[i]);
    if (v.dimensione > 0)
        printf("\n");
}

void stampa_vettore(float v[], int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("%g ", v[i]);
    if (n > 0)
        printf("\n");
}


