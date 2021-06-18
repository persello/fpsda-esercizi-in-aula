#include <stdlib.h>
#include <stdio.h>

#include "libdate.h"

int data_valida(int giorno, int mese, int anno)
{
    if (anno < 1582)
        return 0;

    if (!(mese >= 1 && mese <= 12))
        return 0;

    if (!(giorno >= 1 && giorno <= giorni_del_mese(mese, anno)))
        return 0;

    return 1;
}

int giorni_del_mese(int m, int a)
{
    switch (m)
    {
    case 11:
    case 4:
    case 6:
    case 9:
        return 30;
        break;

    case 2:
        if (bisestile(a))
            return 29;
        else
            return 28;
        break;

    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
        break;

    default:
        printf("LIBDATE - GIORNI_DEL_MESE: Numero mese non valido: %d.\n", m);
        exit(EXIT_FAILURE);
        break;
    }
}

int bisestile(int anno)
{
    return ((anno % 4 == 0) && (anno % 100 != 0) || (anno % 400 == 0));
}

int giorni_fra_date(int g1, int m1, int a1, int g2, int m2, int a2)
{
    int giorno_corrente, mese_corrente, anno_corrente,
        giorno_arrivo, mese_arrivo, anno_arrivo;

    int contatore_giorni;

    /* Trovo quale delle due è antecedente */
    if (confronta_date(g1, m1, a1, g2, m2, a2) < 0)
    {
        /* La data di partenza è la prima */
        giorno_corrente = g1;
        mese_corrente = m1;
        anno_corrente = a1;

        /* La data di arrivo è la seconda */
        giorno_arrivo = g2;
        mese_arrivo = m2;
        anno_arrivo = a2;
    }
    else
    {
        /* La data di partenza è la seconda */
        giorno_corrente = g2;
        mese_corrente = m2;
        anno_corrente = a2;

        /* La data di arrivo è la prima */
        giorno_arrivo = g1;
        mese_arrivo = m1;
        anno_arrivo = a1;
    }

    contatore_giorni = 0;

    /* Finché non arriviamo alla data finale */
    while (confronta_date(giorno_corrente, mese_corrente, anno_corrente, giorno_arrivo, mese_arrivo, anno_arrivo) < 0)
    {
        /* Passa al giorno successivo */
        giorno_successivo(&giorno_corrente, &mese_corrente, &anno_corrente);

        /* Incrementa il contatore */
        contatore_giorni++;
    }

    return contatore_giorni;
}

int confronta_date(int g1, int m1, int a1, int g2, int m2, int a2)
{
    if (a1 == a2)
    {
        /* Anni uguali, confronto mesi */
        if (m1 == m2)
        {
            /* Mesi uguali, differenza giorni */
            return g1 - g2;
        }
        else
        {
            /* Mesi differenti, differenza mesi */
            return m1 - m2;
        }
    }
    else
    {
        /* Anni differenti, differenza anni */
        return a1 - a2;
    }
}

void giorno_successivo(int *pg, int *pm, int *pa)
{
    /* Incremento il giorno */
    (*pg)++;

    /* Siamo oltre l'ultimo giorno del mese? */
    if (*pg > giorni_del_mese(*pm, *pa))
    {
        /* Incremento il mese e giorno = 1 */
        (*pm)++;
        *pg = 1;

        /* Siamo oltre l'ultimo mese dell'anno? */
        if (*pm > 12)
        {
            /* Incremento l'anno e mese = 1 */
            (*pa)++;
            *pm = 1;
        }
    }

    return;
}

void leggi_data(int *pg, int *pm, int *pa)
{
    /* Leggi la data */
    printf("Inserisci data (GG MM AAAA): ");
    scanf("%d %d %d", pg, pm, pa);

    /* Finché non è corretta */
    while (!data_valida(*pg, *pm, *pa))
    {
        /* Segnala errore e leggi di nuovo */
        printf("Data non valida. Inserisci nuova data (GG MM AAAA): ");
        scanf("%d %d %d", pg, pm, pa);
    }

    return;
}