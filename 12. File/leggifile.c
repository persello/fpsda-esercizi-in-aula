#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    int valore_corrente, somma;
    char nome_file[64];

    /* Costruisci il nome del file */
    printf("Inserisci il nome del file (senza estensione): ");
    scanf("%s", nome_file);
    strcat(nome_file, ".dat");

    /* Apri file */
    if ((fp = fopen(nome_file, "r")) == NULL)
    {
        printf("Errore di apertura del file \"%s\".\n", nome_file);
        exit(EXIT_FAILURE);
    }

    /* Per ogni numero leggi e somma */
    somma = 0;

    while (fscanf(fp, "%d", &valore_corrente) != EOF)
    {
        somma += valore_corrente;
    }

    /* Stampo il risultato */
    printf("La somma è %d\n", somma);

    /* Chiudi file */
    fclose(fp);
}