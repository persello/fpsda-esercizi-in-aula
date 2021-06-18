#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../Librerie/wavlib/wav.h"

FILE *fpin, *fpout;
WAVE input;
WAVE output;
double delaySec = 0;
double volume = 0;

WAVE delay(double delay, double repeatVolume, WAVE input);

int main(int argc, char const *argv[])
{
    if (argc != 5)
    {
        printf("USAGE: delay <input> <output> <delay in seconds> <volume>\n");
        exit(EXIT_FAILURE);
    }
    else
    {

        // Open files
        fpin = fopen(argv[1], "rb");
        fpout = fopen(argv[2], "wb");
        if (fpin == NULL || fpout == NULL)
        {
            printf("Error while opening input/output files.\n");
            exit(EXIT_FAILURE);
        }

        // Read wave
        input = ReadWave(fpin);

        // Read values
        delaySec = atof(argv[3]);
        volume = atof(argv[4]);

        // Apply effect
        output = delay(delaySec, volume, input);

        // Output
        WriteWave(output, fpout);

        ReleaseWaveData(&input);
        ReleaseWaveData(&output);

        free(fpin);
        free(fpout);
    }
    return EXIT_SUCCESS;
}

WAVE delay(double delay, double repeatVolume, WAVE input)
{
    // Calculate samples
    unsigned long delaySampleStart = (int)ceil(delay * input.fmtheader.SampleRate);
    unsigned long finalSampleCount = input.numofstereosamples + delaySampleStart;

    printf("Campioni stereo input: %ld, Campioni stereo per %g secondi: %ld, Campioni stereo output: %ld.\n", input.numofstereosamples, delaySec, delaySampleStart, finalSampleCount);

    // Create output file
    WAVE result = CreateEmptyCDaudioWave(finalSampleCount);
    for (unsigned long i = 0; i < finalSampleCount; i++)
    {
        if (i < delaySampleStart)
        {
            // Only input
            SAMPLE(result, LEFT, i) = SAMPLE(input, LEFT, i);
            SAMPLE(result, RIGHT, i) = SAMPLE(input, RIGHT, i);
        }
        else if (i < input.numofstereosamples)
        {
            // Sum the waves
            SAMPLE(result, LEFT, i) = SAMPLE(input, LEFT, i) + SAMPLE(input, LEFT, i - delaySampleStart) * repeatVolume;
            SAMPLE(result, RIGHT, i) = SAMPLE(input, RIGHT, i) + SAMPLE(input, RIGHT, i - delaySampleStart) * repeatVolume;
        }
        else
        {
            // Only repeat
            SAMPLE(result, LEFT, i) = SAMPLE(input, LEFT, i - delaySampleStart) * repeatVolume;
            SAMPLE(result, RIGHT, i) = SAMPLE(input, RIGHT, i - delaySampleStart) * repeatVolume;
        }
    }

    return result;
}