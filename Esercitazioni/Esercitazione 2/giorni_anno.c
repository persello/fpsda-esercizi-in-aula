#include <stdio.h>
#include <stdlib.h>

#include "libdate/libdate.h"

/* Restituisce il numero del giorno specificato dall'inizio dell'anno. Controlla la validità della data. */
int numero_da_inizio_anno(int giorno, int mese, int anno);

int main()
{
    int giorno, mese, anno, giorno_num;

    /* Ottieni dati in ingresso */
    printf("Inserire una data (GG MM AAAA): ");
    scanf("%d %d %d", &giorno, &mese, &anno);

    /* Calcola giorno */
    giorno_num = numero_da_inizio_anno(giorno, mese, anno);

    /* Stampa ed esci */
    printf("Il %d/%d è il %d^ giorno dell'anno %d.\n", giorno, mese, giorno_num, anno);
    return EXIT_SUCCESS;
}

int numero_da_inizio_anno(int giorno, int mese, int anno)
{

    int risultato_giorni = 0;
    int mese_corrente = 1;

    /* Notifica date non valide */
    if (!data_valida(giorno, mese, anno))
    {
        printf("LIBDATE - NUMERO_DA_INIZIO_ANNO: Data non valida!\n");
        exit(EXIT_FAILURE);
    }

    /* Sommo i mesi precedenti */
    while(mese_corrente < mese) {
        risultato_giorni += giorni_del_mese(mese_corrente, anno);
        mese_corrente++;
    }

    /* Sommo i giorni di questo mese */
    risultato_giorni += giorno;

    return risultato_giorni;
}