#include <stdio.h>
#include <stdlib.h>

int main()
{

   char c;
   int valore = 0;

   /* Se ci sono caratteri disponibili */
   c = getchar();

   /* Finche' non raggiungo un '\n' */
   while (c != '\n')
   {

      /* Moltiplico il contenuto per 10 e sommo l'ultima cifra letta */
      valore = valore + c - '0';

      /* Leggo la prossima cifra */
      c = getchar();
   }

   /* Dopo aver premuto invio */
   printf("Valore letto: DEC = %d, HEX = %x.\n", valore, valore);

   return EXIT_SUCCESS;
}