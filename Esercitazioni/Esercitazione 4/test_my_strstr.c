#include <stdio.h>
#include <stdlib.h>

#include "../../Librerie/libstring/libstring.h"

int main() {

    char a[100];
    char b[100];
    int indice_risultato;

    printf("Inserire stringa a: ");
    gets(a);

    printf("Inserire stringa b: ");
    gets(b);

    indice_risultato = my_strstr(a, b);

    if(indice_risultato == -1) {
        printf("Non trovato.\n");
    } else {
        printf("Trovato all'indice %d.\n", indice_risultato);
    }

    return EXIT_SUCCESS;
}