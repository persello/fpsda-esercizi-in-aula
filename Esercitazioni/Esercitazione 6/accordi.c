#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "../../Librerie/wavlib/wav.h"

#define FREQUENZA_LA 440.0

int accordoMaggiore[3] = {0, 4, 7};
int note[7] = {-9, -7, -5, -4, -2, 0, 2}; // Do Re Mi Fa Sol La Si (rispetto al La)

WAVE generaAccordi(double frequenzaBase, int tipoAccordo[3], double durata);
double frequenzaDaNota(double frequenzaBase, int semitoni);
signed short int sintetizza(unsigned long sample, double frequenza, short int ampiezza);

int main(int argc, char const *argv[])
{
    FILE *fpout = fopen("accordiMaggiori.wav", "wb");

    WriteWave(generaAccordi(FREQUENZA_LA, accordoMaggiore, 0.6), fpout);
    return EXIT_SUCCESS;
}

WAVE generaAccordi(double frequenzaBase, int tipoAccordo[3], double durata)
{
    WAVE result = CreateEmptyCDaudioWave((int)(durata * 44100) * 12);
    for (int nota = 0; nota < 12; nota++)
    {
        double frequenza_nota_corrente = frequenzaDaNota(FREQUENZA_LA, nota);
        for (unsigned long i = nota * result.numofstereosamples / 12; i < (nota + 1) * result.numofstereosamples / 12; i++)
        {
            SAMPLE(result, LEFT, i) = sintetizza(i, frequenzaDaNota(frequenza_nota_corrente, tipoAccordo[0]), 5000) + sintetizza(i, frequenzaDaNota(frequenza_nota_corrente, tipoAccordo[1]), 5000) + sintetizza(i, frequenzaDaNota(frequenza_nota_corrente, tipoAccordo[2]), 5000);
        }
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
