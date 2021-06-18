#include <stdlib.h>
#include <stdio.h>

#define MINIMO -50
#define MASSIMO 50

int main()
{

    /* Dichiarazione variabili */
    int n, contatore, totale, input;
    double media;

    /* Inizializzazione */
    contatore = 0;
    totale = 0;

    /* Leggo il numero di input da leggere */
    printf("Quanti numeri devo leggere? ");
    scanf("%d", &n);

    /* Leggo tutti n numeri e ne calcolo la media */
    while (contatore < n)
    {

        /* Leggo un numero e non esco fino a che non rientra nei limiti */
        do
        {
            printf("Inserisci %d^ valore: ", contatore + 1);
            scanf("%d", &input);
            if (input < MINIMO || input > MASSIMO)
            {
                printf("Valore fuori dai limiti. ");
            }
        } while (input < MINIMO || input > MASSIMO);

        /* Aggiungo il valore letto al totale */
        totale += input;

        /* Incremento il contatore */
        contatore++;
    }

    /* Calcolo la media e stampo il risultato */
    media = totale / (double)n;
    printf("La media calcolata su %d valori è %.3f.\n", n, media);

    return EXIT_SUCCESS;
}