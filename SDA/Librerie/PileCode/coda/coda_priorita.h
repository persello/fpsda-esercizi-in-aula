#ifndef CODA_PRIORITA_H
#define CODA_PRIORITA_H

#include <stdbool.h>

typedef struct {
    float dato;
    int priorita;
} elemento_coda_priorita;

typedef struct {
    elemento_coda_priorita* dati;
    int capacita;
    int elementi;
} coda_priorita;

coda_priorita crea_coda_priorita(void);
void elimina_coda_priorita(coda_priorita* q);
void enqueue_priorita(coda_priorita* q, float dato, int priorita);
void dequeue_priorita(coda_priorita* q);
elemento_coda_priorita first_priorita(coda_priorita q);
bool empty_priorita(coda_priorita q);
void stampa_coda_priorita(coda_priorita q);
void aggiorna_priorita(coda_priorita* q, float dato, int npriorita);

#endif /* CODA_PRIORITA_H */
