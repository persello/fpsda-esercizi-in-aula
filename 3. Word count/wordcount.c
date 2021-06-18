/* Implementazione del comando UNIX wc */

#include <stdio.h>
#include <stdlib.h>

#define FALSO 0
#define VERO 1

int main()
{

   /* Dichiaro le variabili */
   int contatore_caratteri, contatore_parole, contatore_righe;
   char ch;
   int dentro_parola;

   /* Inizializzo le variabili */
   contatore_caratteri = 0;
   contatore_parole = 0;
   contatore_righe = 0;
   dentro_parola = FALSO;

   /* Finche' non trovo EOF */
   while ((ch = getchar()) != EOF)
   {
      /* Elaboro */

      /* Conto i caratteri */
      contatore_caratteri++;

      /* Conta le parole */
      if (ch == ' ' || ch == '\n')
      {
         /* Sono in un separatore */
         dentro_parola = FALSO;
      }
      else
      {
         /* Sono in una parola */

         /* Se vengo da fuori della parola */
         if (dentro_parola == FALSO)
         {
            /* Abbiamo una nuova parola */
            contatore_parole++;
            dentro_parola = VERO;
         }
      }

      /* Conta le righe */
      if (ch == '\n')
      {
         contatore_righe++;
      }
   }

   /* Stampo i risultati */
   printf("Caratteri: %d, parole: %d, righe: %d.\n", contatore_caratteri, contatore_parole, contatore_righe);

   return EXIT_SUCCESS;
}