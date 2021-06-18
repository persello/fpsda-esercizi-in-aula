#include <stdlib.h>
#include <stdio.h>

#include "../../Librerie/bmp_lib/bmp.h"

BITMAP creaBarre(COLORTRIPLE colori[8], int larghezzaBarra, int altezza);

int main(int argc, char **argv)
{
    FILE *fpout;
    BITMAP output;
    unsigned int height = 0;
    unsigned int barWidth = 0;

    // Nero, rosso, verde, blu, magenta, azzurro, giallo, bianco
    COLORTRIPLE barre[8] = {{0, 0, 0}, {0, 0, 255}, {0, 255, 0}, {255, 0, 0}, {255, 0, 255}, {255, 255, 0}, {0, 255, 255}, {255, 255, 255}};

    // Aiuto
    if (argc != 4)
    {
        printf("USAGE: barre <height> <bar width> <output>\n");
        exit(EXIT_FAILURE);
    }
    // Interpretazione input ed elaborazione
    else
    {
        height = atoi(argv[1]);
        barWidth = atoi(argv[2]);

        if (height == 0 || barWidth == 0)
        {
            printf("Image size should be greater than zero.\n");
            exit(EXIT_FAILURE);
        }

        fpout = fopen(argv[3], "wb");
        if (fpout == NULL)
        {
            printf("Error while opening output file.\n");
            exit(EXIT_FAILURE);
        }

        WriteBitmap(creaBarre(barre, barWidth, height), fpout);
    }
    return EXIT_SUCCESS;
}

BITMAP creaBarre(COLORTRIPLE colori[8], int larghezzaBarra, int altezza)
{
    if (larghezzaBarra == 0 || altezza == 0)
    {
        printf("Size must be grater than zero.\n");
        exit(EXIT_FAILURE);
    }

    int larghezza = larghezzaBarra * 8;

    BITMAP result = CreateEmptyBitmap(altezza, larghezza);

    for (int i = 0; i < larghezza; i++)
    {
        for (int j = 0; j < altezza; j++)
        {
            PIXEL(result, j, i) = colori[i / larghezzaBarra];
        }
    }

    return result;
}