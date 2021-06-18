#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

#include "quicksort.h"

// Colori printf
#define PRINT_RED_B "\033[1;31m"
#define PRINT_GREEN_B "\033[1;32m"
#define PRINT_YELLOW_B "\033[1;33m"
#define PRINT_BLUE_B "\033[1;34m"
#define PRINT_WHITE "\033[0;0m"

// Funzioni private
void _quickSort_ric(float v[], int sinistra, int destra);
int _distribuzione(float v[], int sinistra, int pivot, int destra);
void _scambia(float *a, float *b);
void _stampa_vettore(float *a, int n, int pivot, int swap1, int swap2);

void quickSort(float v[], int n)
{
    printf("Vettore iniziale:\n");
    _stampa_vettore(v, n, -1, -1, -1);
    _quickSort_ric(v, 0, n - 1);
    printf("Risultato:\n");
    _stampa_vettore(v, n, -1, -1, -1);
}

void _quickSort_ric(float v[], int sinistra, int destra)
{
    if (sinistra < destra)
    {
        printf("\nEseguo quicksort con sinistra = %d e destra = %d. Il pezzo di vettore in uso è il seguente:\n", sinistra, destra);
        _stampa_vettore(&v[sinistra], destra - sinistra + 1, -1, -1, -1);

        int pivot = destra;
        int rango = _distribuzione(v, sinistra, pivot, destra);

        // Eseguo il quicksort nelle due zone divise dal rango
        _quickSort_ric(v, sinistra, rango - 1);
        _quickSort_ric(v, rango + 1, destra);
    }
}

int _distribuzione(float v[], int sinistra, int pivot, int destra)
{
    // Metto il pivot a destra
    if (pivot != destra)
    {
        printf("\nSposto pivot (%d) a destra:\n", pivot);
        _stampa_vettore(&v[sinistra], destra - sinistra + 1, pivot - sinistra, destra - sinistra, -1);
        printf("diventa\n");
        _scambia(&v[pivot], &v[destra]);
        _stampa_vettore(&v[sinistra], destra - sinistra + 1, destra - sinistra, pivot - sinistra, -1);
    }

    // Conto tutti gli elementi minori e maggiori del pivot
    int i = sinistra;
    int j = destra - 1;
    while (i <= j)
    {
        // Elemento minore del pivot
        while ((i <= j) && v[i] <= v[destra])
            i++;

        // Elemento maggiore del pivot
        while ((i <= j) && v[j] >= v[destra])
            j--;

        // Quando sono passati entrambi i cicli precedenti vuol dire che siamo giunti ad un punto in cui vanno scambiati due elementi
        // Mettiamo un elemento piccolo nella prima parte (verso l'inizio) e uno grande nella seconda (verso la fine)
        if (i < j)
        {
            printf("\nScambio due elementi, v[%d] con v[%d]:\n", i, j);
            _stampa_vettore(&v[sinistra], destra - sinistra + 1, destra - sinistra, i - sinistra, j - sinistra);
            printf("diventa\n");
            _scambia(&v[i], &v[j]);
            _stampa_vettore(&v[sinistra], destra - sinistra + 1, destra - sinistra, i - sinistra, j - sinistra);
        }
    }

    // Alla fine, sappiamo che il pivot avrà i elementi più piccoli e l'elemento i sarà più grande del pivot
    // Scambiamo v[i] con v[destra] (pivot)
    printf("\nSposto il pivot al suo rango (%d):\n", i);
    _stampa_vettore(&v[sinistra], destra - sinistra + 1, destra - sinistra, i - sinistra, -1);
    printf("diventa\n");
    _scambia(&v[i], &v[destra]);
    _stampa_vettore(&v[sinistra], destra - sinistra + 1, i - sinistra, destra - sinistra, -1);

    return i;
}

void _scambia(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;
}

void _stampa_vettore(float *a, int n, int pivot, int swap1, int swap2)
{
    for (int i = 0; i < n; i++)
    {
        if (pivot == i)
            printf(PRINT_YELLOW_B);
        else if (swap1 == i || swap2 == i)
            printf(PRINT_RED_B);

        printf(" %3.1f ", a[i]);
        printf(PRINT_WHITE);
    }
    printf("\n");
}
