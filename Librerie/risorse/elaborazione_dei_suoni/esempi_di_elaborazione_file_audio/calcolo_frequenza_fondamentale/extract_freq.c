
/*****************************************************************

 Copyright 2001   PIER LUCA MONTESSORO

 University of Udine
 ITALY

 montessoro@uniud.it
 www.montessoro.it

 This file is part of a freeware open source software package.
 It can be freely used (as it is or modified) as long as this
 copyright note is not removed.

******************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wav.h"


double frequenza_fondamentale (WAVE w);


int main (int argc, char *argv[])
{
   FILE *fpin;
   WAVE wave;

   if (argc != 2)
   {                                                         
      printf ("USO: extract_freq <file WAVE>\n");
      exit (EXIT_FAILURE);
   }

   if ((fpin = fopen (argv[1], "rb")) == NULL)
   {
      printf ("Errore di apertura del file\n");
      exit (EXIT_FAILURE);
   }

   wave = ReadWave (fpin);
   fclose (fpin);

   printf ("frequenza = %g\n", frequenza_fondamentale (wave));

   ReleaseWaveData (&wave);

   return EXIT_SUCCESS;
}


double frequenza_fondamentale (WAVE wave)
{
   int i, t1, t2, n_peaks;

   n_peaks = 0;

   /* cerca la prima rampa crescente */
   i = 0;
   while (i < wave.numofstereosamples - 1 &&
          SAMPLE(wave, RIGHT, i) >= SAMPLE(wave, RIGHT, i+1))
      i++;

   /* ora cerca il primo massimo */
   while (i < wave.numofstereosamples - 1 &&
          SAMPLE(wave, RIGHT, i) < SAMPLE(wave, RIGHT, i+1))
      i++;
   t1 = i;
   n_peaks++;

   /* cerca l'ultimo picco */
   while (i < wave.numofstereosamples)
   {
      /* cerca la successiva rampa crescente */
      while (i < wave.numofstereosamples - 1 &&
             SAMPLE(wave, RIGHT, i) >= SAMPLE(wave, RIGHT, i+1))
         i++;

      /* ora cerca il massimo */
      while (i < wave.numofstereosamples - 1 &&
             SAMPLE(wave, RIGHT, i) < SAMPLE(wave, RIGHT, i+1))
         i++;
      if (i < wave.numofstereosamples)
      {
         t2 = i;
         n_peaks++;
      }

      i++;
   }

   /* calcola la frequenza */
   if (n_peaks >= 2)
      return 44100.0 * (n_peaks - 1) / (t2-t1);
   else
      return 0;
}
