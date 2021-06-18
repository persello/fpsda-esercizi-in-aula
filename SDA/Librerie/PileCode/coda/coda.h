#ifndef _CODA_H
#define _CODA_H

#include "lista.h"
#include "array.h"
#include <stdbool.h>

typedef lista coda;

coda crea_coda(void);
void elimina_coda(coda* q);
void enqueue(coda* q, float dato);
void dequeue(coda* q);
float first(coda q);
bool coda_vuota(coda q);
void stampa_coda(coda q);



// descrittore coda implementata con array dinamici

typedef struct {
    int testa;
    int fondo;
    int elementi;
    int capacita;
    float* dati;
} coda_v;

coda_v crea_coda_v(void);
void elimina_coda_v(coda_v* q);
void enqueue_v(coda_v* q, float dato);
void dequeue_v(coda_v* q);
float first_v(coda_v q);
bool coda_v_vuota(coda_v q);
void stampa_coda_v(coda_v q);

#endif
