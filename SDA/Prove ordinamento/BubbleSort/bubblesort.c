#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "bubblesort.h"

// Colori printf
#define PRINT_RED_B "\033[1;31m"
#define PRINT_GREEN_B "\033[1;32m"
#define PRINT_YELLOW_B "\033[1;33m"
#define PRINT_BLUE_B "\033[1;34m"
#define PRINT_WHITE "\033[0;0m"

// Funzioni private
void _scambia(float *a, float *b);
void _stampa_vettore(float *a, int sinistra, int destra, int finali, int swap1, int swap2);

void bubbleSort(float v[], int n)
{
    printf("\nVettore iniziale:\n");
    _stampa_vettore(v, 0, n, -1, -1, -1);
    bool scambiato;
    int fine = n - 1;
    do
    {
        scambiato = false;
        for (int i = 0; i < fine; i++)
        {
            if (v[i] > v[i + 1])
            {
                printf("\nScambio due elementi:\n");
                _stampa_vettore(v, 0, n, fine, i + 1, i);
                printf("diventa\n");
                _scambia(&v[i], &v[i + 1]);
                _stampa_vettore(v, 0, n, fine, i, i + 1);
                scambiato = true;
            }
        }
        fine--;
    } while (scambiato);

    printf("Risultato:\n");
    _stampa_vettore(v, 0, n, -1, -1, -1);
}

void _scambia(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}

void _stampa_vettore(float *a, int sinistra, int destra, int finali, int swap1, int swap2)
{
    for (int i = sinistra; i < destra; i++)
    {
        if (i > finali)
            printf(PRINT_YELLOW_B);
        else if (swap1 == i)
            printf(PRINT_RED_B);
        else if (swap2 == i)
            printf(PRINT_BLUE_B);

        printf(" %3.1f ", a[i]);
        printf(PRINT_WHITE);
    }
    printf("\n");
}
