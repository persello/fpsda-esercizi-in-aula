#include <stdio.h>
#include <stdlib.h>

#include "../../Librerie/libstring/libstring.h"

int main() {

    char a[100];
    char b[100];

    printf("Inserire stringa iniziale: ");
    gets(a);

    printf("Inserire stringa da aggiungere all'inizio: ");
    gets(b);

    my_strinsert(a, b);

    printf("Stringa concatenata: %s\n", a);

    return EXIT_SUCCESS;
}