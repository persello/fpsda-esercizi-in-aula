#include "coda.h"
#include "lista.h"
#include "array.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

coda crea_coda() {
    return crea_lista();
}

void elimina_coda(coda* q) {
    elimina_lista(q);
}

void enqueue(coda* q, float dato) {
    aggiungi_in_coda(q, dato);
}

void dequeue(coda* q) {
    assert(q->testa != NULL);
    elimina_in_testa(q);
}

float first(coda q) {
    assert(q.testa != NULL);
    return q.testa->dato;
}

bool coda_vuota(coda q) {
    return q.testa == NULL;
}

void stampa_coda(coda q) {
    stampa_lista(q);
}

coda_v crea_coda_v() {
    coda_v q;
    q.dati = (float*)malloc(10 * sizeof(float)); // alloca un vettore con almeno 10 elementi
    assert(q.dati != NULL);
    q.testa = 0;
    q.fondo = 0;
    q.elementi = 0;
    q.capacita = 10;
    return q;
}

void elimina_coda_v(coda_v* q) {
    free(q->dati);
    q->capacita = q->elementi = q->testa = q->fondo = 0;
}

void enqueue_v(coda_v* q, float dato) {
    // qualora la capacità del vettore sia esaurita
    // oltre a ridimensionarlo, ripristiniamo la situazione in cui testa sia 0
    if (q->elementi + 1 >= q->capacita) {
        float* tmp = (float*)malloc(2 * q->capacita * sizeof(float));
        assert(tmp != NULL);
        int i, j = 0;
        i = q->testa;
        do {
            tmp[j] = q->dati[i];
            i = (i + 1) % q->capacita;
            j++;
        } while (i != q->fondo);
        free(q->dati);
        q->dati = tmp;
        q->testa = 0;
        q->fondo = j;
        q->capacita = q->capacita * 2;
    }
    q->dati[q->fondo] = dato;
    q->fondo = (q->fondo + 1) % q->capacita;
    q->elementi++;
}

void dequeue_v(coda_v* q) {
    assert(q->elementi > 0);
    q->elementi--;
    q->testa = (q->testa + 1) % q->capacita;
    
    if (q->elementi <= q->capacita / 4) {
        int i, j = 0;
        float* tmp = (float*)malloc(q->capacita / 2 * sizeof(float));
        assert(tmp != NULL);
        i = q->testa;
        do {
            tmp[j] = q->dati[i];
            i = (i + 1) % q->capacita;
            j++;
        } while (i != q->fondo);
        q->testa = 0;
        q->fondo = j;
        q->capacita = q->capacita / 2;
        free(q->dati);
        q->dati = tmp;
    }
}

float first_v(coda_v q) {
    assert(q.elementi > 0);
    return q.dati[q.testa];
}

bool coda_v_vuota(coda_v q) {
    return q.elementi == 0;
}

void stampa_coda_v(coda_v q) {
    int i = q.testa;
    if (q.elementi == 0)
        return;
    do {
        printf("%g ", q.dati[i]);
        i = (i + 1) % q.capacita;
    } while (i != q.fondo);
    printf("\n");
}

