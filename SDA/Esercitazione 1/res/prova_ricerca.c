#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "../../Librerie/ArrayDinamici/array.h"

bool ricerca(vettore_dinamico v, float e, int i); // da fare

int main() {
    float valori_prova[10] = {1.0, -2.3, 3.1, 0.9, 6.2, 2.1, 5.2, 2.1, 3.4, 11.2};
    int i;
    vettore_dinamico v = crea_vettore_dinamico(10);
    for (i = 0; i < 10; i++)
        v.dati[i] = valori_prova[i];
    
    if (ricerca(v, 2.1, 0))
        printf("Trovato\n");
    else
        printf("Non trovato\n");
    
    return EXIT_SUCCESS;
}