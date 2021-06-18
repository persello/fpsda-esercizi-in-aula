#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "insertionsort.h"

#define N 12

int main(int argc, char const *argv[])
{
    float *v = (float *)malloc(N * sizeof(float));
    srand(time(NULL));
    for (int i = 0; i < N; i++)
    {
        v[i] = (rand() % 1000) / 10.0;
    }

    insertionSort(v, N);

    return EXIT_SUCCESS;
}
