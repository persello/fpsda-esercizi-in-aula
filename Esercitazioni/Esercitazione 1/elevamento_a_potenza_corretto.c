/* Elevamento a potenza mediante
   moltiplicazioni successive */

#include <stdio.h>
#include <stdlib.h>

int main()
{
   int base, esponente, potenza;

   printf ("base: ");
   scanf ("%d", &base);
   printf ("esponente: ");
   scanf ("%d", &esponente);

   potenza = 1;

   while (esponente > 0)
   {
      printf("DEBUG: Inizio del ciclo, potenza = %d, esponente  =%d.\n", potenza, esponente);
      potenza = potenza * base;
      esponente--;
   }

   printf ("il risultato e` %d\n", potenza);

   return EXIT_SUCCESS;
}
