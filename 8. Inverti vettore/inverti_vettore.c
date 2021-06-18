#include <stdio.h>
#include <stdlib.h>

#include "libvect/libvect.h"

#define N 10

int main()
{
    int v[N];
    int dim;

    dim = leggi_vettore(v, N);
    stampa_vettore(v, dim);
    stampa_vettore_al_contrario(v, dim);

    printf("Inverto il vettore.\n");

    inverti_vettore(v, dim);
    stampa_vettore(v, dim);
}