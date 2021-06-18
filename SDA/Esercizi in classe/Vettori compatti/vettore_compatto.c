#include "vettore_compatto.h"

#include <stdlib.h>

vettore_compatto crea_vettore_compatto()
{
    vettore_compatto v;
    v.n = 0;
    v.testa = NULL;
    v.coda = NULL;

    return v;
}

void aggiungi_in_coda(vettore_compatto *v, int dato)
{
    /* Caso vettore vuoto */
    if (v->n == 0)
    {
        /* Creo nuovo elemento */
        elemento_compatto e;
        e.dato = dato;
        e.molteplicita = 1;
        e.succ = NULL;

        /* Aggiungo alla struttura */
        v->testa = &e;
        v->coda = &e;
    }
    /* Caso vettore con elementi */
    else
    {
        /* Caso dato differente da ultimo */
        if (dato != v->coda->dato)
        {
            /* Creo nuovo elemento */
            elemento_compatto e;
            e.dato = dato;
            e.molteplicita = 1;
            e.succ = NULL;

            /* Aggiungo alla struttura */
            v->coda->succ = &e;
            v->coda = &e;
        }
        /* Caso valore uguale all'ultimo */
        else
        {
            /* Incremento la molteplicità della coda */
            (v->coda->molteplicita)++;
        }
    }

    /* In ogni caso ho aggiunto un elemento */
    (v->n)++;
}

int cerca_prima_posizione(vettore_compatto v, int dato)
{
    /* Condizioni */
    assert(v.n > 0 && v.testa != NULL && v.coda != NULL);

    int indice_corrente = 0;
    elemento_compatto *e = v.testa;

    do
    {
        /* Confronto */
        if (e->dato == dato)
            return indice_corrente;

        /* Passo al successivo */
        indice_corrente += (e->molteplicita);
        e = e->succ;
    } while (e != NULL);

    /* Non trovato */
    return -1;
}

int valore_di_indice(vettore_compatto v, int indice)
{
    assert(indice <= (v.n - 1));

    int indice_corrente;
    elemento_compatto *e = v.testa;

    do
    {
        /* Incremento indice corrente totale */
        indice_corrente += e->molteplicita;

        /* Controllo superamento */
        if (indice < indice_corrente)
            return e->dato;

        /* Iterazione successiva */
        e = e->succ;
    } while (e != NULL);

    /* Questo punto non dovrà mai essere raggiunto */
    exit(EXIT_SUCCESS);
}

void elimina_vettore_compatto(vettore_compatto *v)
{
    /* Elimino gli elementi */
    elemento_compatto *e = v->testa;
    do
    {
        elemento_compatto *da_eliminare = e;
        e = e->succ;
        free(da_eliminare);
    } while (e != NULL);

    /* Elimino la struttura */
    free(v);
}