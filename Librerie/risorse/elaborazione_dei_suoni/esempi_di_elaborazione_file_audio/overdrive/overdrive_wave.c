
/*****************************************************************

 Copyright 2013   PIER LUCA MONTESSORO

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
#include <math.h>
#include "wav.h"

#define MAXVALUE (1<<15)
#define GAIN  3

void overdrive (WAVE w);


int main (int argc, char *argv[])
{
   FILE *fpin, *fpout;
   WAVE wave;
   char filename[128];

   if (argc != 2)
   {
      printf ("USAGE: overdrive_wave <wave>\n");
      exit (EXIT_FAILURE);
   }

   strcpy (filename, argv[1]);
   strcat (filename, ".wav");
   
   if ((fpin = fopen (filename, "rb")) == NULL)
   {
      printf ("Error opening input file\n");
      exit (EXIT_FAILURE);
   }

   strcpy (filename, argv[1]);
   strcat (filename, "_overdrive.wav");
   
   if ((fpout = fopen (filename, "wb")) == NULL)
   {
      printf ("Error opening output file\n");
      exit (EXIT_FAILURE);
   }


   /* read the wave */
   wave = ReadWave (fpin);
   fclose (fpin);

   overdrive (wave);

   /* write the file */
   WriteWave (wave, fpout);
   fclose (fpout);

   ReleaseWaveData (&wave);

   return EXIT_SUCCESS;
}


void overdrive (WAVE w)
{
   int i;
   double sample, overdriven_sample;

   /* x < 0: y = -(1-e^(-3*abs(x)))
   /* x >= 0: y = (1-e^(-3*abs(x*3)))/3 */
   for (i = 0; i < w.numofstereosamples; i++)
   {
      /* left */
      sample = GAIN * SAMPLE(w, LEFT, i) / (double) MAXVALUE;
      if (sample < 0)
         overdriven_sample = - (1 - (exp(-3*fabs(sample)))); 
      else
         overdriven_sample = (1 - (exp(-3*fabs(sample*3))))/3; 
      SAMPLE(w, LEFT, i) = overdriven_sample * MAXVALUE;
      
      /* right */      
      sample = GAIN * SAMPLE(w, RIGHT, i) / (double) MAXVALUE;
      if (sample < 0)
         overdriven_sample = - (1 - (exp(-3*fabs(sample)))); 
      else
         overdriven_sample = (1 - (exp(-3*fabs(sample*3))))/3; 
      SAMPLE(w, RIGHT, i) = overdriven_sample * MAXVALUE;
   }

   return;
}
