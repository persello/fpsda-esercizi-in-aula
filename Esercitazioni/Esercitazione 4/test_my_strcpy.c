#include <stdio.h>
#include <stdlib.h>

#include "../../Librerie/libstring/libstring.h"

int main() {

    char a[100];
    char b[100];

    printf("Inserire stringa da copiare: ");
    gets(a);

    my_strcpy(b, a);

    printf("Stringa iniziale: %s, stringa copiata: %s\n", a, b);

    return EXIT_SUCCESS;
}