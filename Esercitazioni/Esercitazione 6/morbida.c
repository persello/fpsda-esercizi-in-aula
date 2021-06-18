#include <stdlib.h>
#include <stdio.h>

#include "../../Librerie/bmp_lib/bmp.h"
BITMAP morbida(BITMAP input, double peso_pixel, double peso_intorno);

int main(int argc, char **argv)
{
    FILE *fpout;
    FILE *fpin;
    BITMAP input;
    BITMAP output;

    double p_pixel = 0;
    double p_intorno = 0;

    // Aiuto
    if (argc != 5)
    {
        printf("USAGE: morbida <input> <output> <peso pixel> <peso intorno>\n");
        exit(EXIT_FAILURE);
    }
    // Interpretazione input ed elaborazione
    else
    {
        // Input
        if ((fpin = fopen(argv[1], "rb")) == NULL)
        {
            printf("Error while opening input file.\n");
            exit(EXIT_FAILURE);
        }

        // Output
        if ((fpout = fopen(argv[2], "wb")) == NULL)
        {
            printf("Error while creating output file.\n");
            exit(EXIT_FAILURE);
        }

        // Parametri
        p_pixel = atof(argv[3]);
        p_intorno = atof(argv[4]);

        // Elaborazione
        input = ReadBitmap(fpin);
        output = morbida(input, p_pixel, p_intorno);

        // Output
        WriteBitmap(output, fpout);

        // Free
        ReleaseBitmapData(&input);
        ReleaseBitmapData(&output);
    }
    return EXIT_SUCCESS;
}

BITMAP morbida(BITMAP input, double peso_pixel, double peso_intorno)
{
    BITMAP result = CreateEmptyBitmap(input.height, input.width);

    printf("Height: %d, width: %d", result.height, result.width);

    for (int i = 0; i < result.height; i++)
    {
        for (int j = 0; j < result.width; j++)
        {
            COLORTRIPLE sopra = PIXEL(input, j, i + 1 >= result.height ? i : i + 1);
            COLORTRIPLE sotto = PIXEL(input, j, i - 1 < 0 ? 0 : i - 1);
            COLORTRIPLE destra = PIXEL(input, j + 1 >= result.width ? j : j + 1, i);
            COLORTRIPLE sinistra = PIXEL(input, j - 1 < 0 ? 0 : j - 1, i);

            PIXEL(result, j, i).blue = peso_pixel * PIXEL(input, j, i).blue + ((sopra.blue / 4.0) + (sotto.blue / 4.0) + (destra.blue / 4.0) + (sinistra.blue / 4.0)) * peso_intorno;
            PIXEL(result, j, i).green = peso_pixel * PIXEL(input, j, i).green + ((sopra.green / 4.0) + (sotto.green / 4.0) + (destra.green / 4.0) + (sinistra.green / 4.0)) * peso_intorno;
            PIXEL(result, j, i).red = peso_pixel * PIXEL(input, j, i).red + ((sopra.red / 4.0) + (sotto.red / 4.0) + (destra.red / 4.0) + (sinistra.red / 4.0)) * peso_intorno;
        }
    }

    return result;
}