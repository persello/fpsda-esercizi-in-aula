#include "coda_priorita.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

coda_priorita crea_coda_priorita(void) {
    coda_priorita q;
    // Alloca lo spazio fisico per 2 almeno
    q.dati = (elemento_coda_priorita*)malloc(2 * sizeof(elemento_coda_priorita));
    q.capacita = 2;
    q.elementi = 0;
    return q;
}

void elimina_coda_priorita(coda_priorita* q) {
    if (q->dati) {
        free(q->dati);
        q->capacita = 0;
        q->elementi = 0;
    }
}

// Funzioni di utilità per determinare, in uno heap tree,
// l'indice dell'elemento padre dato il figlio e dell'elemento figlio sinistro dato il padre

int _pq_padre(int i) {
    return (i - 1) / 2;
}

int _pq_sinistro(int i) {
    return 2 * i + 1;
}

// Funzione di utilità che determina il più grande fra il padre (i, passato come parametro) e i suoi due figli

int _pq_migliore_padre_figli(elemento_coda_priorita* dati, int n, int i) {
    int j, k;
    j = k = _pq_sinistro(i);
    // verifica se esiste un figlio destro, in tal caso k è il figlio destro
    if (k + 1 < n)
        k = k + 1;
    // confronta i due figli
    if (dati[k].priorita > dati[j].priorita)
        j = k;
    if (dati[i].priorita > dati[j].priorita)
        j = i;
    return j;
}

void _pq_scambia_elemento_coda_priorita(elemento_coda_priorita* p_a, elemento_coda_priorita* p_b) {
    elemento_coda_priorita t = *p_a;
    *p_a = *p_b;
    *p_b = t;
}

// funzione di utilità che riorganizza lo heap tree a seguito di un aggiornamento di priorità

void _pq_riorganizza_heap(elemento_coda_priorita* dati, int n, int i) {
    // verifica se l'elemento deve salire nell'albero
    while (i > 0 && dati[i].priorita > dati[_pq_padre(i)].priorita) {
        _pq_scambia_elemento_coda_priorita(&dati[i], &dati[_pq_padre(i)]);
        i = _pq_padre(i);
    }
    // verifica se l'elemento deve scendere nell'albero
    while (_pq_sinistro(i) < n && i != _pq_migliore_padre_figli(dati, n, i)) {
        int figlio_migliore = _pq_migliore_padre_figli(dati, n, i);
        _pq_scambia_elemento_coda_priorita(&dati[i], &dati[figlio_migliore]);
        i = figlio_migliore;
    }
}

void enqueue_priorita(coda_priorita* q, float dato, int priorita) {
    int i;
    // verifica che ci sia capacità sufficiente
    if (q->elementi >= q->capacita) {
        q->dati = (elemento_coda_priorita*)realloc(q->dati, 2 * q->elementi);
        q->capacita = 2 * q->elementi;
    }
    q->dati[q->elementi].dato = dato;
    q->dati[q->elementi].priorita = priorita;
    q->elementi++;
    // garantisco che la heap property sia soddisfatta
    i = q->elementi - 1;
    while (i > 0 && q->dati[i].priorita > q->dati[_pq_padre(i)].priorita) {
        _pq_scambia_elemento_coda_priorita(&q->dati[i], &q->dati[_pq_padre(i)]);
        i = _pq_padre(i);
    }
}

void dequeue_priorita(coda_priorita* q) {
    int i;
    assert(q->elementi > 0);
    q->dati[0] = q->dati[q->elementi - 1];
    q->elementi--;
    i = 0;
           /* non sei su una foglia */
    while (_pq_sinistro(i) < q->elementi && i != _pq_migliore_padre_figli(q->dati, q->elementi, i)) {
        int indice_figlio_migliore = _pq_migliore_padre_figli(q->dati, q->elementi, i);
        _pq_scambia_elemento_coda_priorita(&q->dati[i], &q->dati[indice_figlio_migliore]);
        i = indice_figlio_migliore;
    }
    // verifica di ridimensionamento
    if (q->elementi <= q->capacita / 4) {
        q->dati = (elemento_coda_priorita*)realloc(q->dati, 2 * q->elementi);
        q->capacita = 2 * q->elementi;
    }
}

elemento_coda_priorita first_priorita(coda_priorita q) {
    assert(q.elementi > 0);
    return q.dati[0];
}

void aggiorna_priorita(coda_priorita* q, float dato, int nuova_priorita) {
    int i;
    for (i = 0; i < q->elementi; i++)
        if (q->dati[i].dato == dato)
            break;
    if (i >= q->elementi)
        return; // l'elemento con il dato passato non è stato trovato, non fare nulla
    q->dati[i].priorita = nuova_priorita;
    // La heap va riorganizzata solo in questo caso
    if (q->dati[_pq_padre(i)].priorita < nuova_priorita)
        _pq_riorganizza_heap(q->dati, q->elementi, i);
}

bool empty_priorita(coda_priorita q) {
    return q.elementi == 0;
}

void stampa_coda_priorita(coda_priorita q) {
    int i;
    if (q.elementi == 0)
        return;
    for (i = 0; i < q.elementi; i++)
        printf("%g (p: %d) ", q.dati[i].dato, q.dati[i].priorita);
    printf("\n");
}


                                        

