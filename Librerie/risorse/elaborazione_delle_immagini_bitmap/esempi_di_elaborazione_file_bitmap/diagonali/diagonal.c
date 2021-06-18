
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

BITMAP diagonali (int size);

int main (int argc, char *argv[])
{
   FILE *fpout;
   BITMAP bmpout;

   if (argc != 3)
   {
      printf ("USAGE: diagonal <bmp destination file> <size>\n");
      exit (EXIT_FAILURE);
   }

   if ((fpout = fopen (argv[1], "wb")) == NULL)
   {
      printf ("Error opening output file\n");
      exit (EXIT_FAILURE);
   }

   bmpout = diagonali (atoi (argv[2]));

   WriteBitmap (bmpout, fpout);
   ReleaseBitmapData (&bmpout);
   fclose (fpout);

   return EXIT_SUCCESS;
}

BITMAP diagonali (int size)
{
   BITMAP bmp;
   COLORTRIPLE blackpixel = {0, 0, 0};
   COLORTRIPLE whitepixel = {255, 255, 255};
   int i, j;

   /* create an empty bitmap data structure */
   bmp = CreateEmptyBitmap (size, size);

   /* color the pixels */
   for (i = 0; i < bmp.height; i++)   /* rows */
      for (j = 0; j < bmp.width; j++)   /* columns */
         if ((i + j) %2)
            PIXEL(bmp, i, j) = blackpixel;
         else
            PIXEL(bmp, i, j) = whitepixel;

   return bmp;
}
