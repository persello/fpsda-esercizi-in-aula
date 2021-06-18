#include "pila.h"
#include "lista.h"
#include "array.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

pila crea_pila() {
    return crea_lista();
}

void elimina_pila(pila *p) {
    elimina_lista(p);
}

void push(pila *p, float dato) {
    return aggiungi_in_testa(p, dato);
}

void pop(pila *p) {
    assert(!empty(*p));
    elimina_in_testa(p);
}

float top(pila p) {
    assert(!empty(p));
    return p.testa->dato;
}

bool empty(pila p) {
    return (p.testa == NULL);
}

void stampa_pila(pila p) {
    stampa_lista(p);
}

pila_v crea_pila_v() {
    return crea_vettore_dinamico(0);
}

void elimina_pila_v(pila_v *p) {
    elimina_vettore_dinamico(p);
}

void push_v(pila_v *p, float dato) {
    // la cima della pila è rappresentata da p->dimensione - 1
    ridimensiona_vettore_dinamico(p, p->dimensione + 1);
    p->dati[p->dimensione - 1] = dato;
}

void pop_v(pila_v *p) {
    assert(!empty_v(*p));
    ridimensiona_vettore_dinamico(p, p->dimensione - 1);
}

float top_v(pila_v p) {
    assert(!empty_v(p));
    return p.dati[p.dimensione - 1];
}

bool empty_v(pila_v p) {
    return p.dimensione == 0;
}

void stampa_pila_v(pila_v p) {
    stampa_vettore_dinamico(p);
}
