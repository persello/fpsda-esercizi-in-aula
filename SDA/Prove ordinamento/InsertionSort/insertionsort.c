#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "insertionsort.h"

// Colori printf
#define PRINT_RED_B "\033[1;31m"
#define PRINT_GREEN_B "\033[1;32m"
#define PRINT_YELLOW_B "\033[1;33m"
#define PRINT_BLUE_B "\033[1;34m"
#define PRINT_WHITE "\033[0;0m"

// Funzioni private
void _scambia(float *a, float *b);
void _stampa_vettore(float *a, int sinistra, int destra, int finali, int swap1, int swap2);

void insertionSort(float v[], int n)
{
    printf("\nVettore iniziale:\n");
    _stampa_vettore(v, 0, n, -1, -1, -1);

    for (int i = 1; i < n; i++)
    {
        float prossimo = v[i];
        int j = i;
        while (j > 0 && v[j - 1] > prossimo)
        {
            printf("\nSposto avanti:\n");
            _stampa_vettore(v, 0, n, i, j - 1, -1);
            v[j] = v[j - 1];
            _stampa_vettore(v, 0, n, i, j, j - 1);
            j = j - 1;
        }

        printf("\nCopio valore \"prossimo\" alla locazione raggiunta:\n");
        _stampa_vettore(v, 0, n, -1, -1, -1);
        v[j] = prossimo;
        _stampa_vettore(v, 0, n, j, -1, -1);
    }

    printf("Risultato:\n");
    _stampa_vettore(v, 0, n, -1, -1, -1);
}

void _scambia(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}

void _stampa_vettore(float *a, int sinistra, int destra, int indice, int swap1, int swap2)
{
    for (int i = sinistra; i < destra; i++)
    {
        if (swap1 == i || swap2 == i)
            printf(PRINT_BLUE_B);
        else if (i == indice)
            printf(PRINT_YELLOW_B);

        printf(" %3.1f ", a[i]);
        printf(PRINT_WHITE);
    }
    printf("\n");
}
