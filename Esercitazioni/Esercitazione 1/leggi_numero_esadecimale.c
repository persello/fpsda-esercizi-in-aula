#include <stdlib.h>
#include <stdio.h>

int main()
{
    /* Dichiarazione delle variabili */
    char input;
    int totale = 0;

    printf("Inserisci un numero esadecimale: ");

    /* Leggi fino a quando non c'è un carattere di line feed */
    while ((input = getchar()) != '\n')
    {

        /* Cifra 0 - 9 */
        if (input <= '9' && input >= '0')
        {
            totale *= 16;
            totale += input - '0';
        }
        /* Cifra a - f */
        else if (input <= 'f' && input >= 'a')
        {
            totale *= 16;
            totale += input + 10 - 'a';
        }
        /* Cifra A - F */
        else if (input <= 'F' && input >= 'A')
        {
            totale *= 16;
            totale += input + 10 - 'A';
        }
        else
        {
            printf("La cifra \'%c\' non è valida. Il programma verrà terminato.\n", input);
            exit(EXIT_FAILURE);
        }
    }

    /* Stampo il risultato */
    printf("Valore esadecimale letto: %x, valore decimale = %d.\n", totale, totale);

    ò EXIT_SUCCESS;
}