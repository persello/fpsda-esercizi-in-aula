
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
#include "bmp.h"


void inserisci_reticolo (BITMAP bmp, int n);
                   
int main (int argc, char *argv[])
{
   FILE *fpin, *fpout;
   BITMAP bmp;

   if (argc != 4)
   {
      printf ("USO: reticolo <input file> <output file> <N>\n");
      exit (EXIT_FAILURE);
   }

   if ((fpin = fopen (argv[1], "rb")) == NULL)
   {
      printf ("Error opening input file\n");
      exit (EXIT_FAILURE);
   }

   if ((fpout = fopen (argv[2], "wb")) == NULL)
   {
      printf ("Error opening output file\n");
      exit (EXIT_FAILURE);
   }

   bmp = ReadBitmap (fpin);

   inserisci_reticolo (bmp, atoi (argv[3]));

   WriteBitmap (bmp, fpout);
   ReleaseBitmapData (&bmp);
   fclose (fpin);
   fclose (fpout);

   return EXIT_SUCCESS;
}


void inserisci_reticolo (BITMAP bmp, int n)
{
   int vcnt, hcnt, i, j;
   COLORTRIPLE white = { 255, 255, 255 };

   vcnt = hcnt = 0;
   for (i = 0; i < bmp.height; i++)
   {
      if (vcnt % n == 0)
      {
         for (j = 0; j < bmp.width; j++)
            PIXEL(bmp, i, j) = white;
      }
      else
      {
         for (j = 0; j < bmp.width; j++)
         {
            if (hcnt % n == 0)
            {
               PIXEL(bmp, i, j) = white;
            }
            hcnt++;
         }
      }
      vcnt++;
      hcnt = 0;
   }

   return;
}



