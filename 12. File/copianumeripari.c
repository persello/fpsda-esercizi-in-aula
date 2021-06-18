#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fpin, *fpout;
    int valore_corrente;
    char nome_file_in[64], nome_file_out[64];

    /* Costruisci i nomi dei file */
    printf("Inserisci il nome del file di input(senza estensione): ");
    scanf("%s", nome_file_in);
    strcat(nome_file_in, ".dat");

    printf("Inserisci il nome del file di output(senza estensione): ");
    scanf("%s", nome_file_out);
    strcat(nome_file_out, ".dat");

    /* Apri file input */
    if ((fpin = fopen(nome_file_in, "r")) == NULL)
    {
        printf("Errore di apertura del file di input \"%s\".\n", nome_file_in);
        exit(EXIT_FAILURE);
    }

    /* Crea file output */
    if ((fpout = fopen(nome_file_out, "w")) == NULL)
    {
        printf("Errore durante la creazione del file di output \"%s\".\n", nome_file_out);
        exit(EXIT_FAILURE);
    }

    /* Filtra numeri pari */
    while (fscanf(fpin, "%d", &valore_corrente) != EOF)
    {
        if (valore_corrente % 2 == 0)
        {
            /* Scrivo nel file di output */
            fprintf(fpout, "%d\n", valore_corrente);
        }
    }

    /* Chiudi file */
    fclose(fpin);
    fclose(fpout);
}