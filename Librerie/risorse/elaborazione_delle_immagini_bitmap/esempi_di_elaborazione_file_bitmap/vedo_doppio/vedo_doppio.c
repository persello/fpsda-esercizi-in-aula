
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

BITMAP double_image (BITMAP bmpL, BITMAP bmpR);


int main (int argc, char *argv[])
{
   FILE *fpL, *fpR, *fpout;
   BITMAP bmpL, bmpR, bmpout;
   char filename[64];

   if (argc != 2)
   {
      printf ("USAGE: vedo_doppio <immagine>\n");
      exit (EXIT_FAILURE);
   }

   strcpy (filename, argv[1]);
   strcat (filename, "_LEFT.bmp");
   
   if ((fpL = fopen (filename, "rb")) == NULL)
   {
      printf ("Error opening input file\n");
      exit (EXIT_FAILURE);
   }

   strcpy (filename, argv[1]);
   strcat (filename, "_RIGHT.bmp");
   
   if ((fpR = fopen (filename, "rb")) == NULL)
   {
      printf ("Error opening input file\n");
      exit (EXIT_FAILURE);
   }

   strcpy (filename, argv[1]);
   strcat (filename, ".bmp");
   
   if ((fpout = fopen (filename, "wb")) == NULL)
   {
      printf ("Error opening output file\n");
      exit (EXIT_FAILURE);
   }

   bmpL = ReadBitmap (fpL);
   bmpR = ReadBitmap (fpR);

   bmpout = double_image (bmpL, bmpR);   

   WriteBitmap (bmpout, fpout);

   ReleaseBitmapData (&bmpL);
   ReleaseBitmapData (&bmpR);
   ReleaseBitmapData (&bmpout);

   fclose (fpL);
   fclose (fpR);
   fclose (fpout);

   return EXIT_SUCCESS;
}


BITMAP double_image (BITMAP bmpL, BITMAP bmpR)
{
   BITMAP bmpout;
   int i, j;
   
   if (bmpL.width != bmpR.width || bmpL.height != bmpR.height) 
   {
      printf ("Immagini di dimensioni differenti!\n");
      exit (EXIT_FAILURE);
   }

   bmpout = CreateEmptyBitmap (bmpL.height, bmpL.width);

   for (i = 0; i < bmpL.height; i++)
   {
      for (j = 0; j < bmpL.width / 2; j++)
         PIXEL(bmpout,i,j) = PIXEL(bmpL,i,j);
      for ( ; j < bmpL.width; j++)
         PIXEL(bmpout,i,j) = PIXEL(bmpR,i,j);
   }
   
   return bmpout;
}

