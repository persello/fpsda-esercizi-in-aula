#include <stdio.h>
#include <stdlib.h>

#include "libvect.h"
#include "../libutil/libutil.h"

int leggi_vettore(int v[], int dim_max)
{
    int contatore, numero_elementi_da_inserire;

    printf("Quanti elementi vuoi inserire? ");
    scanf("%d", &numero_elementi_da_inserire);

    if (numero_elementi_da_inserire > dim_max)
    {
        printf("Attenzione: il numero è troppo grande. Saranno letti solo %d valori.\n", dim_max);
    }

    contatore = 0;

    while (contatore < numero_elementi_da_inserire && contatore < dim_max)
    {
        printf("Inserire valore di v[%d]: ", contatore);
        scanf("%d", &v[contatore]);

        contatore++;
    }

    printf("\n");

    return contatore;
}

void inverti_vettore(int v[], int dimensione)
{
    int i, j;
    i = 0;
    j = dimensione - 1;

    while (i < j)
    {
        swap_int(&v[i], &v[j]);
        i++;
        j--;
    }

    return;
}

void stampa_vettore(int v[], int dim)
{
    int i;

    for (i = 0; i < dim; i++)
    {
        printf("v[%d] = %d\n", i, v[i]);
    }

    printf("\n");
    return;
}

void stampa_vettore_al_contrario(int v[], int dim)
{
    int i;

    for (i = dim - 1; i >= 0; i--)
    {
        printf("v[%d] = %d\n", i, v[i]);
    }

    printf("\n");
    return;
}

int cerca_in_sottovettore(int v[], int inizio, int fine, int valore_cercato)
{
    for (int i = inizio; i <= fine; i++)
    {
        if (v[i] == valore_cercato)
            return i;
    }

    return -1;
}

void scorrimento_circolare(int v[], int dim)
{
    /* Salvo l'ultimo elemento. */
    int temp = v[dim - 1];

    /* Faccio scorrere tutti gli elementi in avanti (tranne l'ultimo). */
    for (int i = dim - 2; i >= 0; i--)
    {
        v[i + 1] = v[i];
    }

    /* Copio l'ultimo valore nel primo indice. */
    v[0] = temp;

    return;
}

int massimo_in_sottovettore(int v[], int inizio, int fine)
{
    /* Non valido */
    if (inizio >= fine)
        return 0;

    int massimo_temp = v[0];
    for (int i = inizio + 1; i <= fine; i++)
    {
        if (v[i] > massimo_temp)
        {
            massimo_temp = v[i];
        }
    }

    return massimo_temp;
}