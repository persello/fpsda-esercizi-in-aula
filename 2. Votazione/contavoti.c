#include <stdlib.h>
#include <stdio.h>

int main()
{

    /* Dichiaro le variabili */
    int favorevoli, contrari, astenuti;
    char voto;

    /* Inizializzo i contatori */
    favorevoli = 0;
    contrari = 0;
    astenuti = 0;

    /* Input voto */
    voto = getchar();

    /* Pulisco il buffer della tastiera fino a '\n' */
    while (getchar() != '\n')
        ;

    /* Finche' il voto inserito e' diverso da 'X' */
    while (voto != 'X' && voto != 'x')
    {
        /* Elaborazione */
        switch (voto)
        {
        case 'f':
        case 'F':
        case 's':
        case 'S':
        case 'y':
        case 'Y': /* Incrementa contatore favorevoli */
            favorevoli++;
            break;
        case 'c':
        case 'C':
        case 'n':
        case 'N': /* Incrementa contatore contrari */
            contrari++;
            break;
        case 'a':
        case 'A':
        case '-': /* Incrementa contatore astenuti */
            astenuti++;
            break;
        default:
            printf("Voto non valido.\n");
        }

        /* Input voto */
        voto = getchar();

        /* Pulisco il buffer della tastiera fino a '\n' */
        while (getchar() != '\n')
            ;
    }

    /* Stampa i risultati */
    printf("Favorevoli: %d, contrari: %d, astenuti: %d\n", favorevoli, contrari, astenuti);

    return EXIT_SUCCESS;
}