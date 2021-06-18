#include <stdio.h>
#include <stddef.h>

#include "libutil.h"

void swap_int(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;

    return;
}

int leggi_valore_valido(int min, int max)
{
    int valore;
    scanf("%d", &valore);

    while (valore > max || valore < min)
    {
        printf("Valore fuori dai limiti. Minimo: %d, massimo: %d. Riprova: ", min, max);
        scanf("%d", &valore);
    }

    return valore;
}