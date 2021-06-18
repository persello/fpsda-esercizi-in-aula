#include <stdio.h>
#include <stdlib.h>

#include "../../Librerie/wavlib/wav.h"

FILE *fpin;
FILE *fpout;
WAVE wave;

void swap(signed short int *a, signed short int *b);
void reverse(WAVE *wave);

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        printf("USAGE: reverse <input> <output>\n");
        exit(EXIT_FAILURE);
    }
    else
    {

        // Input file
        if ((fpin = fopen(argv[1], "rb")) == NULL)
        {
            printf("Error while opening input file.\n");
            exit(EXIT_FAILURE);
        }

        // Output file
        if ((fpout = fopen(argv[2], "wb")) == NULL)
        {
            printf("Error while creating output file.\n");
            exit(EXIT_FAILURE);
        }

        // Wave read
        wave = ReadWave(fpin);

        // Reverse
        reverse(&wave);

        // Save
        WriteWave(wave, fpout);

        // Free
        ReleaseWaveData(&wave);
        free(fpin);
        free(fpout);
    }
    return EXIT_SUCCESS;
}

void reverse(WAVE *wave)
{
    for (unsigned long i = 0; i < wave->numofstereosamples / 2; i++)
    {
        swap(&(SAMPLE(*wave, LEFT, i)), &(SAMPLE(*wave, LEFT, wave->numofstereosamples - i)));
        swap(&(SAMPLE(*wave, RIGHT, i)), &(SAMPLE(*wave, RIGHT, wave->numofstereosamples - i)));
    }
}

void swap(signed short int *a, signed short int *b)
{
    signed short int temp = *a;
    *a = *b;
    *b = temp;
}