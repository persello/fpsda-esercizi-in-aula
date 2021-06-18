#include <stdio.h>
#include <stdlib.h>

#include "../../Librerie/libstring/libstring.h"

int main()
{
    char frase[200] = {};

    /* Richiedi inserimento parola. */
    printf("Inserisci frase: ");
    gets(frase);
    if (frase_palindroma(frase))
    {
        printf("%s è palindroma.\n", frase);
    } else {
        printf("%s non è palindroma.\n", frase);
    }

    return EXIT_SUCCESS;
}
