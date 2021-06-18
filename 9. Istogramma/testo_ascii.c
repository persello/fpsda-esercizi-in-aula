#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "../Librerie/libutil/libutil.h"
#include "../Librerie/libchart/libchart.h"
#include "../Librerie/libvect/libvect.h"

#define DIMENSIONE  'z' - 'a' + 1

void calcola_distribuzione_ascii(int contatori[]);

int main()
{
    int distribuzione[DIMENSIONE] = {};

    calcola_distribuzione_ascii(distribuzione);
    // stampa_vettore(distribuzione, dimensione);
    istogramma_verticale_ascii(distribuzione, DIMENSIONE);

    return EXIT_SUCCESS;
}

void calcola_distribuzione_ascii(int contatori[])
{
    char ch;
    while ((ch = getchar()) != EOF)
    {
        /* Converto in minuscola */
        ch = tolower(ch);

        if (ch >= 'a' && ch <= 'z')
        {
            contatori[ch - 'a']++;
        }
    }

    return;
}