#include <stdio.h>
#include <stdlib.h>

#include "../../Librerie/libvect/libvect.h"

#define DIMENSIONE 10

int main()
{
    int v[DIMENSIONE];
    int dimensione_vettore;

    /* Leggo il vettore e ne salvo la dimensione utilizzata. */
    dimensione_vettore = leggi_vettore(v, DIMENSIONE);

    /* Stampo il vettore originale. */
    printf("Vettore prima dello scorrimento:\n");
    stampa_vettore(v, dimensione_vettore);

    /* Chiamo la funzione di scorrimento. */
    scorrimento_circolare(v, dimensione_vettore);

    /* Stampo il vettore dopo la chiamata. */
    printf("Vettore dopo scorrimento:\n");
    stampa_vettore(v, dimensione_vettore);

    return EXIT_SUCCESS;
}