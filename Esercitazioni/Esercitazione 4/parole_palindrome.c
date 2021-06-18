#include <stdio.h>
#include <stdlib.h>

#include "../../Librerie/libstring/libstring.h"

int main()
{
    char parola[40] = {};

    /* Richiedi inserimento parola. */
    printf("Inserisci parola: ");
    scanf("%s", parola);
    if (palindroma(parola))
    {
        printf("%s è palindroma.\n", parola);
    } else {
        printf("%s non è palindroma.\n", parola);
    }

    return EXIT_SUCCESS;
}
