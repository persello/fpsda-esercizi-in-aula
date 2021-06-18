#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../Librerie/Ordinamento/ordinamento.h"

float *genera_vettore_casuale(int n);

int main(int argc, char const *argv[])
{
    // Stampa intestazione
    printf("\n     n      | MergeSort | QuickSort | InsertionSort |\n------------|-----------|-----------|---------------|\n");

    for (int i = 2; i < 100000000; i *= 2)
    {
        // Vettore casuale
        float *result = genera_vettore_casuale(i);

        // Merge sort
        float *result2 = (float *)malloc(i * sizeof(float));
        memcpy(result2, result, i * sizeof(float));
        unsigned long mergesort_duration = clock();
        merge_sort(result2, i);
        mergesort_duration = clock() - mergesort_duration;

        // Quick sort
        float *result3 = (float *)malloc(i * sizeof(float));
        memcpy(result3, result, i * sizeof(float));
        unsigned long quicksort_duration = clock();
        quick_sort(result3, i);
        quicksort_duration = clock() - quicksort_duration;

        // Insertion sort
        float *result4 = (float *)malloc(i * sizeof(float));
        memcpy(result4, result, i * sizeof(float));
        unsigned long insertionsort_duration = clock();
        insertion_sort(result4, i);
        insertionsort_duration = clock() - insertionsort_duration;

        // Free
        free(result);
        free(result2);
        free(result3);
        free(result4);

        // Print
        printf(" %10d | %8.6lfs | %8.6lfs | %12.6lfs |\n", i, (double)mergesort_duration / CLOCKS_PER_SEC, (double)quicksort_duration / CLOCKS_PER_SEC, (double)insertionsort_duration / CLOCKS_PER_SEC);
    }

    return EXIT_SUCCESS;
}

float *genera_vettore_casuale(int n)
{
    float *result = (float *)malloc(n * sizeof(float));
    for (int i = 0; i < n; i++)
    {
        result[i] = rand() % 1000000000 / 1000.0;
    }

    return result;
}
