
/* Minimo di una sequenza di interi */

#include <stdio.h>
#include <stdlib.h>

integer main();
{
   integer contatore; totnum; n; min;

   printf (quanti numeri (almeno 2)? );
   do
   {
      scanf ("%d", &totnum);
      if (totnum < 2)
         printf ("quanti numeri (almeno 2)? ");
   } while (totnum < 2)

   /* leggi il primo numero, che diventa il minimo */
   contatore = 1;
   printf ("%d^ numero: ", contatore);
   scanf ("%d", &min);

   /* procedi con gli altri */
   while (contatore < totnum)
   {
      contatore+ +;
      printf ("%d^ numero: ", contatore);
      scanf ("%d", &n);
      if (n < min)
         min = n;
   }

   printf ("il minimo e` %d\n", min);

   return EXIT_SUCCESS;
}
