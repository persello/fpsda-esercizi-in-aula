
/*****************************************************************

 Copyright 2008   PIER LUCA MONTESSORO

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

#define NOTE_DURATION 0.25

double freq (char note[]);


int main (int argc, char *argv[])
{
   FILE *fpout;
   WAVE wave;
   int i;
   double f;
   long int sample, start;

   if (argc < 3)
   {
      printf ("make_melody outputfile notes...\n");
      exit (EXIT_FAILURE);
   }

   if ((fpout = fopen (argv[1], "wb")) == NULL)
   {
      printf ("Error opening output file\n");
      exit (EXIT_FAILURE);
   }

   wave = CreateEmptyCDaudioWave ((argc - 2) * NOTE_DURATION * SAMPLINGRATE);

   i = 0;
   start = 0;
   for (i = 2; i < argc; i++)
   {
      f = freq (argv[i]);

      for (sample = 0; sample < NOTE_DURATION * SAMPLINGRATE; sample++)
      {
         SAMPLE(wave, RIGHT, start + sample) = 
            25000 * sin (sample / 44100.0 * 2 * M_PI * f);
         SAMPLE(wave, LEFT, start + sample) = 
            25000 * sin (sample / 44100.0 * 2 * M_PI * f);
      }
      start += sample;
   }

   /* write the file */
   WriteWave (wave, fpout);
   fclose (fpout);

   ReleaseWaveData (&wave);

   return EXIT_SUCCESS;
}

struct basic_note
{
   char name[3];
   int index;
};


double freq (char note[])
{
   struct basic_note notes[17] = { {"A", 0}, {"A#", 1}, {"Bb", 1}, {"B", 2}, 
                                   {"C", -9}, {"C#", -8}, {"Db", -8}, {"D", -7}, 
                                   {"D#", -6}, {"Eb", -6}, {"E", -5}, 
                                   {"F", -4}, {"F#", -3}, {"Gb", -3}, {"G", -2}, 
                                   {"G#", -1}, {"Ab", -1} };
   int note_name_len, i, octave;

   note_name_len = strlen (note) - 1;
   for (i = 0; i < 17; i++)
   {
      if ((note_name_len == 1 && note[0] == notes[i].name[0]
              && notes[i].name[1] == '\0') ||
          (note_name_len == 2 && note[0] == notes[i].name[0]
              && note[1] == notes[i].name[1]))
      {
         octave = atoi(note + note_name_len);
         return 55 * pow (2, (12 * (octave - 1) + notes[i].index) / 12.0);
      }
   }

   printf ("note %s not found!\n", note);
   exit (EXIT_FAILURE);
}





