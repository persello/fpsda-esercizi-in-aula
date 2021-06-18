#include <stdio.h>
#include <stdlib.h>

#include "../Librerie/libangle/libangle.h"

int main()
{
    struct angolo a, b, c;

    printf("Lettura angolo a\n");
    a = leggi_angolo();

    printf("Lettura angolo b\n");
    b = leggi_angolo();

    printf("\nAngolo a: ");
    stampa_angolo(a);

    printf("Angolo b: ");
    stampa_angolo(b);

    printf("\nSomma a + b: ");
    c = somma_angoli(a, b);
    c = normalizza_angolo(c);
    stampa_angolo(c);

    return EXIT_SUCCESS;
}