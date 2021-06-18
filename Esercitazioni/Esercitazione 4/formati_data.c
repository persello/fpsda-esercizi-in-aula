#include <stdio.h>
#include <stdlib.h>

#include "../../Librerie/libdate/libdate.h"

void scorriStringaFino(char **stringa, char carattere);
void convertiData(char data1[], char data2[]);
char *nomeMese(int mese);

int main()
{
    char input[20] = {};
    char output[100] = {};

    /* Ottengo la data nel formato 1 sotto forma di stringa. */
    printf("Inserisci data nel formato Anno-Mese-Giorno: ");
    scanf("%s", input);

    convertiData(input, output);

    /* Stampo il risultato nel formato 2. */
    printf("Risultato: %s\n", output);
    return EXIT_SUCCESS;
}

void convertiData(char data1[], char data2[])
{
    int giorno, mese, anno;
    giorno = 0;
    mese = 0;
    anno = 0;

    anno = atoi(data1);
    scorriStringaFino(&data1, '-');
    mese = atoi(data1);
    scorriStringaFino(&data1, '-');
    giorno = atoi(data1);

    if (!data_valida(giorno, mese, anno))
    {
        printf("Data non valida!\n");
        exit(EXIT_FAILURE);
    }

    sprintf(data2, "%d %s dell'anno %d", giorno, nomeMese(mese), anno);

    return;
}

void scorriStringaFino(char **stringa, char carattere)
{
    while ((**stringa) != carattere && (**stringa) != '\0')
    {
        (*stringa)++;
    }

    (*stringa)++;
    return;
}

char *nomeMese(int mese)
{
    switch (mese)
    {
    case 1:
        return "Gennaio";
    case 2:
        return "Febbraio";
    case 3:
        return "Marzo";
    case 4:
        return "Aprile";
    case 5:
        return "Maggio";
    case 6:
        return "Giugno";
    case 7:
        return "Luglio";
    case 8:
        return "Agosto";
    case 9:
        return "Settembre";
    case 10:
        return "Ottobre";
    case 11:
        return "Novembre";
    case 12:
        return "Dicembre";
    default:
        printf("Mese non valido!");
        exit(EXIT_FAILURE);
        break;
    }
}