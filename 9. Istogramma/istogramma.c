#include <stdio.h>
#include <stdlib.h>

#include "../Librerie/libvect/libvect.h"
#include "../Librerie/libchart/libchart.h"

#define LUNGHEZZA_MAX_SEQUENZA 300
#define DIM_CONTATORI 100

int main()
{

    int sequenza[LUNGHEZZA_MAX_SEQUENZA] = {};
    int contatori[DIM_CONTATORI] = {};
    int lunghezza_sequenza;

    lunghezza_sequenza = leggi_vettore(sequenza, LUNGHEZZA_MAX_SEQUENZA);
    calcola_distribuzione(sequenza, lunghezza_sequenza, contatori, DIM_CONTATORI);
    istogramma_verticale(contatori, DIM_CONTATORI);

    return EXIT_SUCCESS;
}