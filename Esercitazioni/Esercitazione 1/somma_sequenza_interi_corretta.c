/* Somma di una sequenza di interi */

#include <stdio.h>
#include <stdlib.h>

int main()
{
   int contatore, n, dato, somma;

   printf("quanti numeri? ");
   scanf("%d", &n);

   contatore = 0;
   somma = 0;

   while (contatore < n)
   {
      printf("DEBUG: Inizio ciclo while, contatore = %d, somma = %d.\n", contatore, somma);
      printf("numero: ");
      scanf("%d", &dato);
      somma = somma + dato;
      contatore = contatore + 1;
   }

   printf("la somma e` %d\n", somma);

   return EXIT_SUCCESS;
}
