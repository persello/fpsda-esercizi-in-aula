#include <stdlib.h>
#include "lista_multipla.h"

/* Crea un vettore di m liste inizialmente vuote e imposta eventuali altre informazioni nel descrittore. */
lista_multipla crea_lista_multipla(int m)
{
    lista_multipla lm;
    int i;

    lm.liste = (lista *)malloc(m * sizeof(lista));
    lm.pesi = (int *)mallic(m * sizeof(int));
    lm.m = m;

    for (i = 0; i < m; i++)
    {
        lm.liste[i] = crea_lista();
        lm.pesi[i] = 0;
    }

    return lm;
}

/* Funzione privata che restituisce l'indice della lista con peso minore di tutta la lista multipla. */
int trova_lista_peso_minore(lista_multipla *lm)
{
    int i;
    int min_indice;
    int min_peso = lm->pesi[0];

    for (i = 1; i < lm->m; i++)
    {
        if (lm->pesi[i] < min_peso)
        {
            min_indice = i;
            min_peso = lm->pesi[i];
        }
    }
    return i;
}

/* Inserisce il dato d nella lista, facente parete della lista multipla lm, avente peso minore. */
void inserisci_lista_multipla(lista_multipla *lm, float d)
{
    int indice = trova_lista_peso_minore(lm);
    aggiungi_in_coda(&(lm->liste[indice]), d);
    lm->pesi[indice] += d;
}

/* Rimuove tutte le occorrenze del dato d dalle liste facenti parte della lista multipla lm. */
void rimuovi_lista_multipla(lista_multipla *lm, float d)
{
    int i, j;
    for (i = 0; i < lm->m; i++)
    {
        nodo_lista *nodo = lm->liste[i].testa;

        /* Per i nodi iniziali, va cambiata la testa. */
        while (nodo->dato == d)
        {
            lm->liste[i].testa = nodo->succ;
            nodo_lista *nodo_da_eliminare = nodo;
            nodo = nodo->succ;
            elimina_nodo(nodo_da_eliminare);
        }

        /* Dopo devo cambiare il puntatore del nodo precedente. */
        while (nodo != NULL)
        {
            if (nodo->succ->dato == d)
            {
                nodo_lista *nodo_da_eliminare = nodo->succ;
                
                if (nodo->succ != NULL)
                    nodo->succ = nodo->succ->succ;
                else
                    nodo->succ = NULL;

                elimina_nodo(nodo_da_eliminare);
            }
        }
    }
}

/* Elimina la lista multipla deallocando tutti i dati allocati dinamicamente. */
void elimina_lista_multipla(lista_multipla *lm)
{
    int i;
    for (i = 0; i < lm->m; i++)
    {
        elimina_lista(&(lm->liste[i]));
    }

    lm->m = 0;
    free(lm->liste);
}