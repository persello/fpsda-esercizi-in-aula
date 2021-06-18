#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIMENSIONE_CAMPO 15

int lunghezze_navi[4] = {};

int converti_sequenza(char *pseq, int dimensione_campo, char *ptipo_nave, int *px, int *py, char *po);
int controlla_collisioni(int x, int y, int lunghezza, char direzione, char campo[DIMENSIONE_CAMPO][DIMENSIONE_CAMPO]);
void disegna_nave(int x, int y, int lunghezza, char direzione, char campo[DIMENSIONE_CAMPO][DIMENSIONE_CAMPO]);
void stampa_campo(char campo[DIMENSIONE_CAMPO][DIMENSIONE_CAMPO]);

char campo[DIMENSIONE_CAMPO][DIMENSIONE_CAMPO] = {};
char prossima_sequenza[20] = "";
char tipo_nave_corrente, orientamento_nave_corrente;
int x_nave_corrente, y_nave_corrente;

int main()
{
    /* Inizializzazione */
    x_nave_corrente = 0;
    y_nave_corrente = 0;

    /* Aggiungo elementi a lunghezze_navi. */
    lunghezze_navi['p'] = 5; /* Portaerei */
    lunghezze_navi['c'] = 4; /* Cacciatorpediniere */
    lunghezze_navi['i'] = 3; /* Incrociatore */
    lunghezze_navi['r'] = 2; /* Ricognitore */

    /* Finché ci sono dati disponibili. */
    do
    {
        /* Leggi dato in ingresso. */
        gets(prossima_sequenza);

        /* Converti e controlla correttezza. */
        if (converti_sequenza(prossima_sequenza, DIMENSIONE_CAMPO,
                              &tipo_nave_corrente, &x_nave_corrente,
                              &y_nave_corrente, &orientamento_nave_corrente))
        {
            /* La sequenza è corretta */

            /* Controlla collisioni con altre navi. */
            if (controlla_collisioni(x_nave_corrente, y_nave_corrente,
                                     lunghezze_navi[tipo_nave_corrente],
                                     orientamento_nave_corrente, campo))
            {
                /* Non ci sono collisioni */

                /* Aggiungi a matrice. */
                disegna_nave(x_nave_corrente, y_nave_corrente,
                             lunghezze_navi[tipo_nave_corrente],
                             orientamento_nave_corrente, campo);
            }
        }

#ifdef DEBUG
        printf("Ricevuta nave di tipo '%c', con lunghezza %d, orientamento '%c' e posizione (%d, %d).\n", tipo_nave_corrente, lunghezze_navi[tipo_nave_corrente], orientamento_nave_corrente, x_nave_corrente, y_nave_corrente);
#endif

    } while (strlen(prossima_sequenza) > 0);

    /* Stampa matrice. */
    stampa_campo(campo);

    return EXIT_SUCCESS;
}

int converti_sequenza(char *pseq, int dimensione_campo, char *ptipo_nave, int *px, int *py, char *po)
{
    sscanf(pseq, "%c %d %d %c", ptipo_nave, px, py, po);

    /* Controlliamo che il primo parametro sia valido, ovvero che una nave di tipo tipo_nave sia più lunga di 1. */
    if (lunghezze_navi[*ptipo_nave] < 2)
    {
        printf("Tipo nave '%c' non riconosciuto.\n", *ptipo_nave);
        return 0;
    }

    /* Controlliamo le coordinate. */
    if (*px < 0 || *py < 0)
    {
        printf("Coordinate (%d, %d) non valide.\n", *px, *py);
        return 0;
    }

    /* Controlla confini e validità orientamento. */
    if (*po == 'O')
    {
        if (*px + lunghezze_navi[*ptipo_nave] > dimensione_campo)
        {
            printf("Coordinate (%d, %d) non valide per questo tipo di nave.\n", *px, *py);
            return 0;
        }
    }
    else if (*po == 'V')
    {
        if (*py + lunghezze_navi[*ptipo_nave] > dimensione_campo)
        {
            printf("Coordinate (%d, %d) non valide per questo tipo di nave.\n", *px, *py);
            return 0;
        }
    }
    else
    {
        return 0;
    }

    return 1;
}

int controlla_collisioni(int x, int y, int lunghezza, char direzione, char campo[DIMENSIONE_CAMPO][DIMENSIONE_CAMPO])
{
    for (int i = 0; i < lunghezza; i++)
    {
        /* Controlla */
        if (campo[x][y] == '*')
        {
            return 0;
        }

        /* Incrementa nella direzione scelta */
        if (direzione == 'O')
        {
            x++;
        }
        else if (direzione == 'V')
        {
            y++;
        }
    }

    return 1;
}

void disegna_nave(int x, int y, int lunghezza, char direzione, char campo[DIMENSIONE_CAMPO][DIMENSIONE_CAMPO])
{
    for (int i = 0; i < lunghezza; i++)
    {
        /* Disegna */
        campo[x][y] = '*';

        /* Incrementa nella direzione scelta */
        if (direzione == 'O')
        {
            x++;
        }
        else if (direzione == 'V')
        {
            y++;
        }
    }

    return;
}

void stampa_campo(char campo[DIMENSIONE_CAMPO][DIMENSIONE_CAMPO])
{
    /* Righe */
    for (int y = DIMENSIONE_CAMPO; y > 0; y--)
    {

        /* Stampa indice ordinate */
        printf("%2d\t", y);

        /* Colonne */
        for (int x = 0; x < DIMENSIONE_CAMPO; x++)
        {
            if (campo[x][y] == '*')
                printf(" * ");
            else
                printf("   ");
        }

        /* A capo */
        printf("\n");
    }

    /* Stampa indice ascisse */
    printf("  \t");
    for (int i = 0; i < DIMENSIONE_CAMPO; i++)
        printf("%2d ", i);

    printf("\n\n");

    return;
}