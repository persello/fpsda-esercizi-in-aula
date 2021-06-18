#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "../../Librerie/wavlib/wav.h"

#define FREQUENZA_LA 440.0

int accordoMaggiore[3] = {0, 4, 7};

WAVE generaAccordo(double frequenzaBase, int tipoAccordo[3], double durata);
double frequenzaDaNota(double frequenzaBase, int semitoni);
signed short int sintetizza(unsigned long sample, double frequenza, short int ampiezza);

int main(int argc, char const *argv[])
{
    FILE *fpout = fopen("lamaggiore.wav", "wb");
    WriteWave(generaAccordo(FREQUENZA_LA, accordoMaggiore, 3), fpout);
    return EXIT_SUCCESS;
}

WAVE generaAccordo(double frequenzaBase, int tipoAccordo[3], double durata)
{
    WAVE result = CreateEmptyCDaudioWave((int)(durata * 44100));
    for (unsigned long i = 0; i < result.numofstereosamples; i++)
    {
        SAMPLE(result, LEFT, i) = sintetizza(i, frequenzaDaNota(frequenzaBase, tipoAccordo[0]), 5000) + sintetizza(i, frequenzaDaNota(frequenzaBase, tipoAccordo[1]), 5000) + sintetizza(i, frequenzaDaNota(frequenzaBase, tipoAccordo[2]), 5000);
    }

    return result;
}

double frequenzaDaNota(double frequenzaBase, int semitoni)
{
    return frequenzaBase * pow(2, semitoni / 12.0);
}

signed short int sintetizza(unsigned long sample, double frequenza, short int ampiezza)
{
    double pi = acos(-1);
    return ampiezza * cos((sample / 44100.0) * frequenza * 2 * pi);
}
