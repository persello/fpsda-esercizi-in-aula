#include <stdio.h>
#include <stdlib.h>

#define QUADRATO 'Q'
#define LINEA 'L'
#define TRIANGOLO 'T'

void disegna_linea(int lunghezza);
void disegna_quadrato(int lato);
void disegna_triangolo(int lato);

int main()
{

    char figura;
    int dimensione;

    while (1)
    {
        /* Leggi prossima coppia figura-dimensione */
        scanf("%c%d", &figura, &dimensione);

        // printf("MAIN: Carattere figura richiesta: %c, dimensione: %d\n", figura, dimensione);

        /* Controllo dimensione */
        if (dimensione > 9 || dimensione < 1)
        {
            printf("Dimensione %d non valida.\n", dimensione);
            exit(EXIT_FAILURE);
        }

        /* Chiama la funzione appropriata */
        switch (figura)
        {
        case QUADRATO:
            // printf("MAIN: Disegno un quadrato di lato %d.\n", dimensione);
            disegna_quadrato(dimensione);
            break;

        case LINEA:
            // printf("MAIN: Disegno una linea di lunghezza %d.\n", dimensione);
            disegna_linea(dimensione);
            break;

        case TRIANGOLO:
            // printf("MAIN: Disegno un triangolo di cateto %d.\n", dimensione);
            disegna_triangolo(dimensione);
            break;

        default:
            printf("Figura %c non riconosciuta.\n", figura);
            exit(EXIT_FAILURE);
            break;
        }

        /* Lascio una riga vuota dopo la figura */
        putchar('\n');
    }

    /* Esci dal programma */
    return EXIT_SUCCESS;
}

void disegna_linea(int lunghezza)
{
    /* Metto in linea 'lunghezza' volte degli asterischi */
    for (int i = 0; i < lunghezza; i++)
    {
        putchar('*');
    }

    /* Alla fine della riga vado a capo */
    putchar('\n');
}

void disegna_quadrato(int lato)
{
    /* Disegna 'lato' righe lunghe 'lato' */
    for (int i = 0; i < lato; i++)
    {
        disegna_linea(lato);
    }
}

void disegna_triangolo(int lato)
{
    /* Disegna 'lato' righe di lunghezza crescente */
    for (int i = 0; i < lato; i++)
    {
        /* Prima volta lunghezza 1, non 0 */
        disegna_linea(i + 1);
    }
}