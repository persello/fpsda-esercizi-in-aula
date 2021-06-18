#include <stdio.h>
#include <stdlib.h>

int main()
{

   char c;
   int valore = 0;

   /* VARIANTE: Finche' non raggiungo un '\n' */
   while ((c = getchar()) != '\n')
   {

      /* Moltiplico il contenuto per 10 e sommo l'ultima cifra letta */
      valore = (valore * 10) + c - '0';
   }

   /* Dopo aver premuto invio */
   printf("Valore letto: DEC = %d, HEX = %x.\n", valore, valore);

   return EXIT_SUCCESS;
}