#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_LAVORI 100
#define MAX_STUDENTI MAX_LAVORI * 5

/* Nuovi tipi di dati */

typedef struct
{
   char nome[32];
   char cognome[32];
   double voto;
} studente;

typedef struct
{
   char id[8];
   char tipo[16];
   char giudizio[16];
   int numero_partecipanti;
   studente *partecipanti[5];
} lavoro_di_gruppo;

/* Prototipi */

/*
    Legge i nomi degli studenti ed i loro voti dell'anno scolastico da file_voti
    e li inserisce nel vettore di struct studenti, di cui viene passato il
    puntatore al primo elemento. Restituisce il numero di studenti/voti letti.
*/
int leggi_voti(FILE *file_voti, studente *studenti);

/*
    Legge le proprietà dei lavori di gruppo da file_lavori e li inserisce nel
    vettore di struct dei lavori di gruppo. Successivamente effettua una ricerca
    tra gli studenti trovati per ottenere i puntatori alle struct degli studenti
    che hanno lavorato in ciascun gruppo e li inserisce nella proprietà
    partecipanti. Restituisce il numero di lavori di gruppo letti.
*/
int leggi_lavori(FILE *file_lavori, lavoro_di_gruppo *lavori,
                 studente *studenti, int numero_studenti);

/*
    Aggiorna i voti di ciascuno studente in base alla valutazione ed alla
    tipologia di lavoro a cui hanno partecipato in gruppo. Si suppone che ogni
    studente abbia partecipato ad un solo lavoro di gruppo.
*/
void aggiorna_voti(lavoro_di_gruppo *lavori, int numero_lavori);

/*
    Legge nome, cognome e voto di ogni studente e lo interpreta (per distinguere
    un dieci da un dieci e lode), l'output viene indirizzato ad un file ASCII in
    cui ogni riga ha cognome, nome e voto di ogni studente nello stesso ordine
    del file dei voti iniziale.
*/
void crea_pagelle(FILE *file_output, studente *studenti, int numero_studenti);

int main(int argc, char *argv[])
{
   /* File I/O */
   FILE *file_voti;
   FILE *file_lavori;
   FILE *file_output;

   /* Vettori di dati */
   studente studenti[MAX_STUDENTI];
   lavoro_di_gruppo lavori[MAX_LAVORI];

   /* Numero effettivo di lavori e studenti */
   int n_studenti;
   int n_lavori;

   /* Controllo del numero di argomenti */
   if (argc != 4)
   {
      printf("Uso: voti <file voti> <file lavori di gruppo> <file output>\n");
      exit(EXIT_FAILURE);
   }

   /* Apertura dei file */
   if ((file_voti = fopen(argv[1], "r")) == NULL)
   {
      printf("File voti %s inesistente.\n", argv[1]);
      exit(EXIT_FAILURE);
   }

   if ((file_lavori = fopen(argv[2], "r")) == NULL)
   {
      printf("File lavori di gruppo %s inesistente.\n", argv[2]);
      exit(EXIT_FAILURE);
   }

   if ((file_output = fopen(argv[3], "w")) == NULL)
   {
      printf("Errore durante la creazione del file pagelle %s.\n", argv[3]);
      exit(EXIT_FAILURE);
   }

   /* Lettura ed elaborazione dei file */
   n_studenti = leggi_voti(file_voti, studenti);
   n_lavori = leggi_lavori(file_lavori, lavori, studenti, n_studenti);
   aggiorna_voti(lavori, n_lavori);

   /* Output pagelle */
   crea_pagelle(file_output, studenti, n_studenti);

   /* Conclusione */
   fclose(file_voti);
   fclose(file_lavori);
   fclose(file_output);

   return EXIT_SUCCESS;
}



int leggi_voti(FILE *file_voti, studente *studenti)
{
   /* Indice dello studente in lettura al momento */
   int i_studente = 0;

   /* Ultima riga letta dal file */
   char riga[200] = {0};

   /* Leggi tutte le righe del file */
   while (fgets(riga, sizeof(riga), file_voti) != NULL)
   {

#ifdef DEBUG
      printf("DEBUG: leggi_voti: Riga letta: %s\n", riga);
#endif

      /* Se la riga contiene nome e cognome, e non un voto... */
      if (strlen(riga) > 3)
      {

         char c;

         /* Indice della lettera della riga corrente */
         int i_lettera = 0;

         /* Indice della lettera del campo
               (nome/cognome) dello studente corrente */
         int i_campo = 0;

         /* 0 = Nome, 1 = Cognome */
         int campo_corrente = 0;

         /* Ogni carattere fino a fine riga */
         while ((c = riga[i_lettera]) != '\n')
         {

            /* Nome */
            if (campo_corrente == 0)
            {
               if (c == ';')
                  /* Aggiungo terminatore di stringa
                           al passaggio tra campi */
                  studenti[i_studente].nome[i_campo] = '\0';
               else
                  /* Copio il carattere nel campo nome */
                  studenti[i_studente].nome[i_campo] = c;
            }
            /* Cognome */
            else if (campo_corrente == 1)
            {
               if (c == ';')
                  /* Aggiungo terminatore di stringa
                           al passaggio tra campi */
                  studenti[i_studente].cognome[i_campo] = '\0';
               else
                  /* Copio il carattere nel campo cognome */
                  studenti[i_studente].cognome[i_campo] = c;
            }

            /* Incremento indici */
            i_lettera++;
            i_campo++;

            /* Se ho trovato un divisore passo al campo successivo
                   e reimposto l'indice del campo */
            if (c == ';')
            {
               campo_corrente++;
               i_campo = 0;

               /* Saltiamo lo spazio dopo il ; se siamo al cognome */
               if (campo_corrente == 1)
                  i_lettera++;
            }
         }
      }
      /* Se stiamo leggendo un voto */
      else if (strlen(riga) >= 1 && strlen(riga) <= 3)
      {
         studenti[i_studente].voto = atoi(riga);

#ifdef DEBUG
         printf("DEBUG: leggi_voti: Studente letto: %s %s %lf.\n",
                studenti[i_studente].nome,
                studenti[i_studente].cognome,
                studenti[i_studente].voto);
#endif

         /* Passaggio al prossimo studente */
         i_studente++;
      }
      else
      {
         printf("Riga non valida nel file voti.\n");
         exit(EXIT_FAILURE);
      }
   }

   return i_studente;
}



int leggi_lavori(FILE *file_lavori, lavoro_di_gruppo *lavori,
                 studente *studenti, int numero_studenti)
{
   int i_lavoro = 0;
   char riga[200] = {0};

   /* Ottieni prima riga */
   while (fgets(riga, sizeof(riga), file_lavori) != NULL)
   {

#ifdef DEBUG
      printf("DEBUG: leggi_lavori: Intestazione lavoro di gruppo: %s\n", riga);
#endif

      /* Ottieni dati formattati della prima riga */
      sscanf(riga, "%s %d %s %s",
             lavori[i_lavoro].id,
             &(lavori[i_lavoro].numero_partecipanti),
             lavori[i_lavoro].tipo,
             lavori[i_lavoro].giudizio);

      /* Per ogni partecipante */
      for (int i_partecipante = 0;
           i_partecipante < lavori[i_lavoro].numero_partecipanti;
           i_partecipante++)
      {
         /* Estrai nome e cognome corrente come riga formattata */
         char nome_cognome[200] = {0};
         if (fgets(nome_cognome, 200, file_lavori) == NULL)
         {
            printf("Errore durante la lettura del file lavori.\n");
            exit(EXIT_FAILURE);
         }
         /* Se la lettura è riuscita, ricerca il puntatore
               alla struct corrispondente */
         else
         {
            /* Indice dello studente in riferimento al vettore
                   di tutti gli studenti */
            int studente_confronto = 0;
            char nome_cognome_confronto[200] = {0};

            do
            {
               /* Stampa su stringa il nome ed il cognome dello studente
                       corrente nello stesso formato del file */
               sprintf(nome_cognome_confronto, "%s; %s;",
                       studenti[studente_confronto].nome,
                       studenti[studente_confronto].cognome);

               studente_confronto++;

#ifdef DEBUG
               printf("DEBUG: leggi_lavori: Confronto %s con %s (size: %zu).\n",
                      nome_cognome_confronto,
                      nome_cognome,
                      strlen(nome_cognome_confronto));
#endif

            } while (studente_confronto < numero_studenti &&
                     strncmp(nome_cognome,
                             nome_cognome_confronto,
                             strlen(nome_cognome_confronto)));

            studente_confronto--;

            /* Il ciclo termina quando lo studente è stato trovato
                   o non esiste (ignora eventuali \n su nome_cognome) */

            /* Studente inesistente */
            if (studente_confronto == numero_studenti)
            {
               printf("Lo studente %s non è stato trovato.\n", nome_cognome);
               exit(EXIT_FAILURE);
            }
            /* Studente trovato */
            else
            {
               lavori[i_lavoro].partecipanti[i_partecipante] =
                   &(studenti[studente_confronto]);
            }
         }
      }
      i_lavoro++;
   }

   return i_lavoro;
}



void aggiorna_voti(lavoro_di_gruppo *lavori, int numero_lavori)
{
   for (int i_lavoro = 0; i_lavoro < numero_lavori; i_lavoro++)
   {
      double valore_giudizio = 0;

      /* Interpreta giudizio testuale */
      if (!strcmp("insufficiente", lavori[i_lavoro].giudizio))
         valore_giudizio = 4;
      else if (!strcmp("sufficiente", lavori[i_lavoro].giudizio))
         valore_giudizio = 6;
      else if (!strcmp("discreto", lavori[i_lavoro].giudizio))
         valore_giudizio = 7;
      else if (!strcmp("buono", lavori[i_lavoro].giudizio))
         valore_giudizio = 8;
      else if (!strcmp("ottimo", lavori[i_lavoro].giudizio))
         valore_giudizio = 10;
      else
      {
         printf("Giudizio %s non valido.\n", lavori[i_lavoro].giudizio);
         exit(EXIT_FAILURE);
      }

      /* Interpreta tipologia di lavoro */
      if (!strcmp("sperimentale", lavori[i_lavoro].tipo))
         valore_giudizio *= 1.2;
      else if (!strcmp("compilativo", lavori[i_lavoro].tipo))
         valore_giudizio *= 0.8;
      else
      {
         printf("Tipo %s non valido.\n", lavori[i_lavoro].tipo);
         exit(EXIT_FAILURE);
      }

      /* Aggiorna i voti di ogni partecipante */
      for (int i_partecipante = 0;
           i_partecipante < lavori[i_lavoro].numero_partecipanti;
           i_partecipante++)

         lavori[i_lavoro].partecipanti[i_partecipante]->voto +=
             0.1 * valore_giudizio;
   }
}



void crea_pagelle(FILE *file_output, studente *studenti, int numero_studenti)
{
   for (int i = 0; i < numero_studenti; i++)
   {
      if (studenti[i].voto <= 10.0)
         fprintf(file_output, "%s %s %.2lf\n",
                 studenti[i].cognome,
                 studenti[i].nome,
                 studenti[i].voto);
      else
         fprintf(file_output, "%s %s 10 e lode\n",
                 studenti[i].cognome,
                 studenti[i].nome);
   }
}
