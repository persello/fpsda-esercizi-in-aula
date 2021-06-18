#include "libchart.h"

#include <stdio.h>
#include <stdlib.h>

#include "../libvect/libvect.h"

void calcola_distribuzione(int sequenza[], int lunghezza_sequenza, int contatori[], int lunghezza_contatori)
{
    int i = 0;
    int elemento_corrente;

    while (i < lunghezza_sequenza)
    {
        elemento_corrente = sequenza[i];
        if (elemento_corrente < lunghezza_contatori && elemento_corrente >= 0)
        {
            contatori[elemento_corrente]++;
        }

        i++;
    }

    return;
}

void istogramma_orizzontale(int v[], int dimensione)
{
    for (int i = 0; i < dimensione; i++)
    {
        if (v[i] > 0)
        {
            printf("%3d ", i);
            for (int j = 0; j < v[i]; j++)
            {
                printf("*");
            }

            printf("\n");
        }
    }

    return;
}

void istogramma_verticale(int v[], int dimensione)
{
    /* Trovo il valore massimo */
    int massimo = massimo_in_sottovettore(v, 0, dimensione - 1);

    /* Per ogni riga */
    for (int i = massimo; i > 0; i--)
    {
        /* Per ogni colonna */
        for (int j = 0; j < dimensione; j++)
        {
            if (v[j] > 0)
            {
                /* Considero la colonna */
                if (v[j] >= i)
                {
                    /* Stampo un blocco pieno */
                    printf("** ");
                }
                else
                {
                    /* Stampo un blocco vuoto */
                    printf("   ");
                }
            }
        }
        printf("\n");
    }

    /* Stampa etichette */
    for (int i = 0; i < dimensione; i++)
    {
        if (v[i] > 0)
        {
            printf("%2d ", i);
        }
    }

    printf("\n");

    return;
}

void istogramma_verticale_ascii(int v[], int dimensione)
{
    /* Trovo il valore massimo */
    int massimo = massimo_in_sottovettore(v, 0, dimensione - 1);

    /* Per ogni riga */
    for (int i = massimo; i > 0; i--)
    {
        /* Per ogni colonna */
        for (int j = 0; j < dimensione; j++)
        {
            if (v[j] >= i)
            {
                /* Stampo un blocco pieno */
                printf("*");
            }
            else
            {
                /* Stampo un blocco vuoto */
                printf(" ");
            }
        }
        printf("\n");
    }

    /* Stampa etichette */
    for (int i = 0; i < dimensione; i++)
    {
        printf("%c", i + 'a');
    }

    printf("\n");

    return;
}
