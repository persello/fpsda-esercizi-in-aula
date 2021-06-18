#include <stdio.h>
#include <stdlib.h>

#include "../Librerie/Alberi/alberi.h"
#include "funzioni_abr.h"

int main()
{
    printf("Inizio test funzione valore massimo delle chiavi.\n");

    for (int i = 0; i < 100; i++)
    {
        int numero_nodi = rand() % 1000;
        printf("Avvio test %d. Dimensione albero: %d. ", i, numero_nodi);

        int chiave_massima = 0;
        albero_binario_ricerca albero = crea_abr();

        // Creazione albero
        for (int i = 0; i < numero_nodi; i++)
        {
            int chiave_corrente = rand() % numero_nodi;
            chiave_massima = chiave_massima >= chiave_corrente ? chiave_massima : chiave_corrente;
            inserisci_abr(&albero, chiave_corrente, 0.0);
        }

        printf("Albero generato. Chiave massima inserita = %d. Avvio test. ", chiave_massima);

        // Test
        int risultato = massimo_chiave_abr(albero);
        if (risultato == chiave_massima)
        {
            printf("Test superato. Risultato = %d.\n", risultato);
        }
        else
        {
            printf("Test fallito. Risultato = %d.\n", risultato);
            elimina_abr(&albero);
            exit(EXIT_FAILURE);
        }

        // Libera memoria
        elimina_abr(&albero);
    }

    printf("Inizio test stampa valori minori.\n");

    printf("Tutti i test superati.\n");
    return EXIT_SUCCESS;
}
