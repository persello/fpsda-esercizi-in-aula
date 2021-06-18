#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct articolo
{
    char nome[32];
    int q;
};

int leggi_file(FILE *fp_magazzino, struct articolo *magazzino, int max);
int differenza_liste(struct articolo *lista, struct articolo *magazzino, struct articolo *mancanti, int n_articoli_lista, int n_articoli_magazzino);

int main()
{
    struct articolo articoli_magazzino[100], articoli_lista[100], articoli_mancanti[100];
    int n_articoli_magazzino, n_articoli_lista, n_articoli_mancanti = 0;
    char nome_file_magazzino[64], nome_file_lista[64];
    FILE *fp_magazzino, *fp_lista;

    /* Apertura file */
    printf("Inserire nome del file magazzino: ");
    scanf("%s", nome_file_magazzino);

    if ((fp_magazzino = fopen(nome_file_magazzino, "r")) == NULL)
    {
        printf("Errore durante l'apertura del file \"%s\".\n", nome_file_magazzino);
        exit(EXIT_FAILURE);
    }

    printf("Inserire nome del file della lista: ");
    scanf("%s", nome_file_lista);

    if ((fp_lista = fopen(nome_file_lista, "r")) == NULL)
    {
        printf("Errore durante l'apertura del file \"%s\".\n", nome_file_lista);
        exit(EXIT_FAILURE);
    }

    /* Parsing */
    n_articoli_magazzino = leggi_file(fp_magazzino, articoli_magazzino, 100);
    n_articoli_lista = leggi_file(fp_lista, articoli_lista, 100);

    /* Cerca articoli mancanti */
    n_articoli_mancanti = differenza_liste(articoli_lista, articoli_magazzino, articoli_mancanti, n_articoli_lista, n_articoli_magazzino);

    /* Stampa articoli mancanti */
    printf("ARTICOLI MANCANTI:\n");
    for (int i = 0; i < n_articoli_mancanti; i++)
    {
        printf("%s: %d\n", articoli_mancanti[i].nome, articoli_mancanti[i].q);
    }

    return EXIT_SUCCESS;
}

int differenza_liste(struct articolo *lista, struct articolo *magazzino, struct articolo *mancanti, int n_articoli_lista, int n_articoli_magazzino)
{
    int indice_articoli_mancanti = 0;
    for (int i = 0; i < n_articoli_lista; i++)
    {
        int trovato = 0;
        for (int j = 0; j < n_articoli_magazzino; j++)
        {
            /* Se trovo con lo stesso nome */
            if (strcmp(lista[i].nome, magazzino[j].nome) == 0)
            {
                /* Attivo il flag trovato */
                trovato = 1;

                /* Controllo le quantità */
                if (lista[i].q > magazzino[j].q)
                {
                    /* Non bastano, aggiungo agli articoli mancanti */
                    strcpy(mancanti[indice_articoli_mancanti].nome, lista[i].nome);
                    mancanti[indice_articoli_mancanti].q = lista[i].q - magazzino[j].q;
                    indice_articoli_mancanti++;
                }
            }
        }

        /* Se non ho proprio trovato l'articolo */
        if (!trovato)
        {
            mancanti[indice_articoli_mancanti] = lista[i];
            indice_articoli_mancanti++;
        }
    }
    return indice_articoli_mancanti;
}

int leggi_file(FILE *fp_magazzino, struct articolo *magazzino, int max)
{
    int indice_articolo_corrente = 0;
    char riga[100];

    while (fgets(riga, 100, fp_magazzino) != NULL && indice_articolo_corrente < max)
    {
        /* Leggi nome */
        int i = 0, j = 0;

        /* Salto spazi iniziali */
        while (riga[i] == ' ')
            i++;

        /* Copio nome */
        while (riga[i] != ':')
        {
            magazzino[indice_articolo_corrente].nome[j] = riga[i];
            j++;
            i++;
        }

        /* Salta due punti */
        i++;

        /* Leggi quantità */
        sscanf(riga + i, "%d", &(magazzino[indice_articolo_corrente].q));

        /* Incrementa indice */
        indice_articolo_corrente++;
    }

    return indice_articolo_corrente;
}