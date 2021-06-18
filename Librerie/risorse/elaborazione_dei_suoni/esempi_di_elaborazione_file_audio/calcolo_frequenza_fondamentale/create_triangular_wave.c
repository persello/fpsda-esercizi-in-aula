#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "wav.h"

WAVE triangular_wave (int freq, int amplitude_percentage, int lenght_s);


int main(int argc, char *argv[])
{
   FILE *fpout;
   WAVE w;
   
   if(argc < 5)
   {
      printf("usage: <outfile.wav> <freq[Hz]> <amplitude[%%]> <lenght[s]>");
      exit(EXIT_FAILURE);
   }

   w = triangular_wave (atoi (argv[2]), atoi (argv[3]), atoi (argv[4]));
   
   if((fpout = fopen(argv[1], "wb")) == NULL)
   {
      printf("errore nell'apertura del file\n");
      exit(EXIT_FAILURE);
   }

   WriteWave(w, fpout);
   ReleaseWaveData(&w);
   fclose(fpout);

   return EXIT_SUCCESS;
}


WAVE triangular_wave (int freq, int amplitude_percentage, int lenght_s)
{
   WAVE w;
   double period, ampl, len, step, inc;
   int i;

   period = 1 / (double) freq;
   ampl = ((1 << 15) - 1) * amplitude_percentage / 100.0;
   len = lenght_s * SAMPLINGRATE;   
   
   w = CreateEmptyCDaudioWave (len);

   step = 2 * ampl / (period / 2.0 * SAMPLINGRATE);
   inc = -ampl;

   SAMPLE(w, RIGHT, 0) = SAMPLE(w, LEFT, 0) = inc;

   inc += step;
      
   for (i = 1; i < w.numofstereosamples; i++)
   {
      SAMPLE(w, RIGHT, i) = SAMPLE(w, LEFT, i) = inc;

      if((i % (int)(period * 44100 / 2)) == 0)
      {
         step = -step;
      }   
      inc += step;      
   }

   return w;
}

   

