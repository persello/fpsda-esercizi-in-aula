#include <stdio.h>
#include <stdlib.h>

#include "../../Librerie/libstring/libstring.h"

int main() {

    char a[100];
    char b[100];
    int lunghezza_confronto;
    int stringhe_uguali;

    printf("Inserire stringa a: ");
    gets(a);

    printf("Inserire stringa b: ");
    gets(b);

    printf("Inserire lunghezza confronto: ");
    scanf("%d", &lunghezza_confronto);

    stringhe_uguali = my_strncmp(a, b, lunghezza_confronto);

    if(stringhe_uguali) {
        printf("I primi %d caratteri delle due stringhe sono uguali.\n", lunghezza_confronto);
    } else {
        printf("I primi %d caratteri delle due stringhe non sono uguali.\n", lunghezza_confronto);
    }

    return EXIT_SUCCESS;
}