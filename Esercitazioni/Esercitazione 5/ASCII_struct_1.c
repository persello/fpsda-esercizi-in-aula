#include <stdio.h>
#include <stdlib.h>

struct articolo
{
    char nome[32];
    int q;
};

int leggi_file(FILE *fp_magazzino, struct articolo *magazzino, int max);

int main()
{
    struct articolo articoli[100];
    int n_articoli;
    char nome_file_magazzino[64];
    FILE *fp_magazzino;

    /* Apertura file */
    printf("Inserire nome del file magazzino: ");
    scanf("%s", nome_file_magazzino);

    if ((fp_magazzino = fopen(nome_file_magazzino, "r")) == NULL)
    {
        printf("Errore durante l'apertura del file \"%s\".\n", nome_file_magazzino);
        exit(EXIT_FAILURE);
    }

    /* Parsing */
    n_articoli = leggi_file(fp_magazzino, articoli, 100);

    /* Stampa risultati */
    for (int i = 0; i < n_articoli; i++)
    {
        printf("%s: %d\n", articoli[i].nome, articoli[i].q);
    }

    return EXIT_SUCCESS;
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