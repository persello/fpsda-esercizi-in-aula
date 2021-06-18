/* Esempi di utilizzo di printf e scanf */

#include <stdio.h>
#include <stdlib.h>

int main()  
{
   int a, b, c, d;

   printf ("inserire due numeri interi: ");
   scanf ("%d", &a);
   scanf ("%d", &b);
   printf ("ho letto %d e %d\n", a, b);

   printf ("inserire tre numeri interi: ");
   scanf ("%d %d %d", &a, &b, &c);
   printf ("ho letto %d, %d e %d\n", a, b, c);

   do
   {
      printf ("inserire un numero intero "
              "(-1 per terminare): ");
      scanf ("%d", &d);
      printf ("ho letto %d\n", d);
   } while (d != -1);

   return EXIT_SUCCESS;
}
