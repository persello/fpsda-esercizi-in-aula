#include <stdio.h>
#include <stdlib.h>

#include "../../Librerie/libvect/libvect.h"

#define NUMERO_VALORI 8

void componi_importo(int importo, int n_valori, int valori[], int numero_monete[]);

int main()
{
    /* Valori delle monete in centesimi. */
    int valori[NUMERO_VALORI] = {1, 2, 5, 10, 20, 50, 100, 200};

    /* Numero delle monete di ogni valore (inizializzato a 0). */
    int numero_monete[NUMERO_VALORI] = {};

    int importo;

    /* Richiedi importo del resto. */
    printf("Inserisci l'importo del resto in centesimi: ");
    scanf("%d", &importo);

    if(importo < 0) {
        printf("L'importo deve essere maggiore di zero.\n");
        exit(EXIT_FAILURE);
    }

    /* Componi il resto. */
    componi_importo(importo, NUMERO_VALORI, valori, numero_monete);

    /* Stampa il risultato. */
    printf("Per comporre %.2f€ occorrono le monete elencate di seguito:\n", importo / 100.0);
    for (int i = 0; i < NUMERO_VALORI; i++)
    {
        if (numero_monete[i] != 0)
            printf("%d monete da %.2f€\n", numero_monete[i], valori[i] / 100.0);
    }

    return EXIT_SUCCESS;
}

void componi_importo(int importo, int n_valori, int valori[], int numero_monete[])
{
    int indice_valore_corrente = n_valori - 1;

    /* Finché l'importo rimanente non è nullo. */
    while (importo > 0)
    {

        /* Se l'importo è maggiore o uguale del valore della moneta corrente. */
        if (importo >= valori[indice_valore_corrente])
        {
            /* Sottraggo all'importo il valore della moneta. */
            importo -= valori[indice_valore_corrente];

            /* Conto la moneta usata. */
            (numero_monete[indice_valore_corrente])++;
        }
        else
        {
            /* Scendo di un valore. */
            indice_valore_corrente--;
        }
    }

    return;
}