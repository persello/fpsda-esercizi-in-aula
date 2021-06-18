#include <stdio.h>
#include <stdlib.h>

#include "../../Librerie/libvect/libvect.h"
#include "../../Librerie/libutil/libutil.h"

#define DIMENSIONE 10

int main()
{
    int v[DIMENSIONE];

    int indice_inizio, indice_fine, valore_cercato, indice_trovato, dimensione_vettore;

    /* Leggo il vettore da tastiera. */
    dimensione_vettore = leggi_vettore(v, DIMENSIONE);

    /* Leggo un indice di inizio valido. */
    printf("Indice di inizio: ");
    indice_inizio = leggi_valore_valido(0, dimensione_vettore - 1);

    /* Leggo un indice di fine valido. */
    printf("Indice di fine: ");
    indice_fine = leggi_valore_valido(indice_inizio + 1, dimensione_vettore - 1);

    /* Leggo un valore di ricerca. */
    printf("Valore da cercare: ");
    scanf("%d", &valore_cercato);

    indice_trovato = cerca_in_sottovettore(v, indice_inizio, indice_fine, valore_cercato);

    if (indice_trovato == -1)
    {
        printf("Valore non trovato nell'array.\n");
    }
    else
    {
        printf("Elemento trovato all'indice %d.\n", indice_trovato);
    }

    return EXIT_SUCCESS;
}