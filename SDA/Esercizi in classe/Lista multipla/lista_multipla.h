#include "../../Librerie/Lista/lista.h"

typedef struct
{
    lista *liste;
    int *pesi;
    int m;
} lista_multipla;

/* Crea un vettore di m liste inizialmente vuote e imposta eventuali altre informazioni nel descrittore. */
lista_multipla crea_lista_multipla(int m);

/* Inserisce il dato d nella lista, facente parete della lista multipla lm, avente peso minore. */
void inserisci_lista_multipla(lista_multipla *lm, float d);

/* Rimuove tutte le occorrenze del dato d dalle liste facenti parte della lista multipla lm. */
void rimuovi_lista_multipla(lista_multipla *lm, float d);

/* Elimina la lista multipla deallocando tutti i dati allocati dinamicamente. */
void elimina_lista_multipla(lista_multipla *lm);