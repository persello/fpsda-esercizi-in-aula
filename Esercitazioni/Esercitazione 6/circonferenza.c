#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "../../Librerie/bmp_lib/bmp.h"

void creaCirconferenza(COLORTRIPLE coloreSfondo, COLORTRIPLE colorePrincipale, BITMAP bitmap);
double distanza(int x1, int x2, int y1, int y2);

int main(int argc, char **argv)
{
    FILE *fpout;
    BITMAP output;
    unsigned int size = 0;

    COLORTRIPLE azzurro = {255, 255, 0};
    COLORTRIPLE rosso = {0, 0, 255};

    // Aiuto
    if (argc != 3)
    {
        printf("USAGE: circonferenza <size> <output>\n");
        exit(EXIT_FAILURE);
    }
    // Interpretazione input ed elaborazione
    else
    {
        size = atoi(argv[1]);

        if (size == 0)
        {
            printf("Image size should be greater than zero.\n");
            exit(EXIT_FAILURE);
        }

        fpout = fopen(argv[2], "wb");
        if (fpout == NULL)
        {
            printf("Error while opening output file.\n");
            exit(EXIT_FAILURE);
        }

        output = CreateEmptyBitmap(size, size);
        creaCirconferenza(azzurro, rosso, output);
        WriteBitmap(output, fpout);
    }
    return EXIT_SUCCESS;
}

double distanza(int x1, int x2, int y1, int y2)
{
    double deltax = (double)abs(x1 - x2);
    double deltay = (double)abs(y1 - y2);

    return sqrt(deltax * deltax + deltay * deltay);
}

void creaCirconferenza(COLORTRIPLE coloreSfondo, COLORTRIPLE colorePrincipale, BITMAP bitmap)
{
    // Dimensioni
    int larghezza = bitmap.bmpheader.ImageWidth;
    int altezza = bitmap.bmpheader.ImageHeight;

    printf("Altezza = %d, larghezza = %d\n", altezza, larghezza);

    // Calcolo spessore
    double raggioEsterno = larghezza < altezza ? (double)larghezza / 2 : (double)altezza / 2;
    double raggioInterno = raggioEsterno * 0.9;

    printf("Raggio esterno = %lf, interno = %lf\n", raggioEsterno, raggioInterno);

    // Riempimento
    for (int i = 0; i < larghezza; i++)
    {
        for (int j = 0; j < altezza; j++)
        {
            double distanzaAttuale = distanza(i, larghezza / 2, j, altezza / 2);
            if (distanzaAttuale <= raggioEsterno && distanzaAttuale >= raggioInterno)
            {
                PIXEL(bitmap, i, j) = colorePrincipale;
            }
            else
            {
                PIXEL(bitmap, i, j) = coloreSfondo;
            }
        }
    }
}