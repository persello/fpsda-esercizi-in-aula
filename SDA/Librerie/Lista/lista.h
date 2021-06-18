#ifndef _LISTA_H
#define _LISTA_H

#include <stdbool.h>

/**
 \defgroup lista
 
 Struttura dati **Lista**.
 
 La struttura può essere manipolata attraverso le funzioni di creazione della lista, ridimensionamento e deallocazione.
 */

/**
 Nodo di una lista (semplice):  è costituito da un puntatore al successore e da una variabile che contiene il dato.
 \ingroup lista
 */
typedef struct _nodo_lista {
  float dato;  /**< dato contenuto nel nodo corrente */
  struct _nodo_lista *succ; /**< successore del nodo corrente */
} nodo_lista;

/**
 Descrittore della lista semplice:  è costituito dal puntatore al primo elemento della lista (testa), dal puntatore all'ultimo elemento della lista (coda) e dalla numero di elementi contenuti.
 \ingroup lista
 */
typedef struct {
  nodo_lista *testa;
  nodo_lista *coda;
  int lunghezza;
} lista;

/* Liste Semplici */

/* Manipolazione generica */
lista crea_lista(void);
void elimina_lista(lista *l);
void aggiungi_in_coda(lista *l, float dato);
void elimina_in_coda(lista *l);
void aggiungi_in_testa(lista *l, float dato);
void elimina_in_testa(lista *l);

/* Verifica proprietà */
int lunghezza(lista l);
bool lista_vuota(lista l);
/* Stampa */
void stampa_lista(lista l);

/* Manipolazione nodi della lista */
nodo_lista *crea_nodo(float dato);
void elimina_nodo(nodo_lista *n);

nodo_lista *inserisci_nodo_dopo(nodo_lista *t, nodo_lista *p, nodo_lista *n);
nodo_lista *elimina_nodo_dopo(nodo_lista *t, nodo_lista *p, nodo_lista *n);
nodo_lista *trova_dato(nodo_lista *t, float dato);
nodo_lista *trova_predecessore(nodo_lista *t, nodo_lista *n);

/* Liste Doppie */

/**
 Nodo di una lista (doppia):  è costituito da un puntatore al successore e da una variabile che contiene il dato.
 \ingroup lista
 */
typedef struct _nodo_lista_doppia {
  float dato;  /**< dato contenuto nel nodo corrente */
  struct _nodo_lista_doppia* succ; /**< successore del nodo corrente */
  struct _nodo_lista_doppia* pred; /**< predecessore del nodo corrente */
} nodo_lista_doppia;


typedef struct {
  nodo_lista_doppia* testa;
  nodo_lista_doppia* coda;
  int lunghezza;
} lista_doppia;

/* Manipolazione generica */
lista_doppia crea_lista_d(void);
void elimina_lista_d(lista_doppia *l);
void aggiungi_in_coda_d(lista_doppia *l, float dato);
void elimina_in_coda_d(lista_doppia *l);
void aggiungi_in_testa_d(lista_doppia *l, float dato);
void elimina_in_testa_d(lista_doppia *l);

/* Verifica proprietà */
int lunghezza_d(lista_doppia l);
bool lista_vuota_d(lista_doppia l);
void stampa_lista_d(lista_doppia l);

/* Manipolazione nodi della lista */
nodo_lista_doppia *crea_nodo_d(float dato);
void elimina_nodo_d(nodo_lista_doppia *n);

nodo_lista_doppia *inserisci_nodo_dopo_d(nodo_lista_doppia *t, nodo_lista_doppia *p, nodo_lista_doppia *n);
nodo_lista_doppia *elimina_nodo_dopo_d(nodo_lista_doppia *t, nodo_lista_doppia *p, nodo_lista_doppia *n);
nodo_lista_doppia *trova_dato_d(nodo_lista_doppia *t, float dato);
nodo_lista_doppia *trova_predecessore_d(nodo_lista_doppia *t, nodo_lista_doppia *n);

#endif
