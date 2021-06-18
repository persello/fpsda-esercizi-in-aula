#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ConvertiData(char data1[], char data2[]);
void estrai_data_dal_formato_1(char data1[], int *p_g, int *p_m, int *p_a);
void genera_formato_2(int g, int m, int a, char data2[]);
void converti_mese_in_lettere(int numero_mese, char nome_mese[]);


int main()
{
    char data1[64], data2[64];
    int g, m, a;

    printf("Inserisci la data nel formato aaaa-mm-gg: ");
    scanf("%c", &data1);

#ifdef DEBUG
    estrai_data_dal_formato_1(data1, &g, &m ,&a);
    printf("La data letta è %d %d %d", g, m, a);
#endif
    

    ConvertiData(data1, data2);

    return EXIT_SUCCESS;
}

void ConvertiData(char data1[], char data2[])
{
    int g, m, a;

    /* Estrai la data in forma numerica (tre interi: g, m, a) dalla data con formato 1. */
    estrai_data_dal_formato_1(data1, &g, &m, &a);

    /* Genera la stringa che rappresenta la data nel formato 2. */
    genera_formato_2(g, m, a, data2);

    return;
}

void estrai_data_dal_formato_1(char data1[], int *p_g, int *p_m, int *p_a)
{
    char t[16];
    int i, j;

    /* Estrai dalla stringa data1 l'anno e scrivilo dentro una stringa temporanea. */
    i = 0;
    j = 0;

    /* Copio data1 in t fino al carattere '-'. */
    while (data1[i] != '-')
    {
        t[j] = data1[i];
        i++;
        j++;
    }

    /* Termino t con NUL. */
    t[j] = '\0';

    /* Converti il contenuto della stringa temporanea in un intero mediante atoi. */
    *p_a = atoi(t);

    /* Incremento i perché ora punta al carattere '-'. */
    i++;

    /* Estrai dalla stringa data1 il mese e scrivilo dentro una stringa temporanea. */
    j = 0;

    /* Copio data1 in t fino al carattere '-'. */
    while (data1[i] != '-')
    {
        t[j] = data1[i];
        i++;
        j++;
    }

    /* Termino t con NUL. */
    t[j] = '\0';

    /* Converti il contenuto della stringa temporanea in un intero mediante atoi. */
    *p_m = atoi(t);

    /* Incremento i perché ora i punta al carattere '-'. */
    i++;

    /* Estrai dalla stringa data1 il giorno e scrivilo dentro una stringa temporanea. */
    j = 0;

    /* Copio data1 in t fino al terminatore. */
    while (data1[i] != '\0')
    {
        t[j] = data1[i];
        i++;
        j++;
    }

    /* Termino t con NUL. */
    t[j] = '\0';

    /* Converti il contenuto della stringa temporanea in un intero mediante atoi. */
    *p_m = atoi(t);

    return;
}

void genera_formato_2(int g, int m, int a, char data2[])
{
    char nome_del_mese[16];
    /* Converti il numero del mese nel nome corrispondente e scrivilo dentro la stringa
    nome del mese */
    converti_mese_in_lettere(m, nome_del_mese);

    /* Scrivi la stringa nel formato data2 usando la funzione sprintf*/
    sprintf(data2, "%d %s dell'anno %d", g, nome_del_mese, a);

    return;
}

void converti_mese_in_lettere(int numero_mese, char nome_mese[])
{

    /* Char nomi dei mesi[13][16] = {{'\0', ...}, {g, e, n, ...}, ... } */
    char nomi_dei_mesi[13][16] = { "",
                                  "gennaio",
                                  "febbraio", 
                                  "marzo",
                                  "aprile",
                                  "maggio",
                                  "giugno",
                                  "luglio",
                                  "agosto",
                                  "settembre",
                                  "ottobre",
                                  "novembre",
                                  "dicembre"};

    if(numero_mese < 1 || numero_mese > 12)
    {
        printf("Il numero %d del mese non è valido\n", numero_mese);
        strcpy(nome_mese, "NUMERO MESE NON VALIDO");
        return;
    }

    #if 0
    /* Versione intuitiva */
    switch (numero_mese)
    {
    case 1:
        strcpy(nome_mese, "gennaio");
        break;
    case 2:
        strcpy(nome_mese, "febbraio");
        break;
    case 3:
        strcpy(nome_mese, "marzo");
        break;
    case 4:
        strcpy(nome_mese, "aprile");
        break;
    case 5:
        strcpy(nome_mese, "maggio");
        break;
    case 6:
        strcpy(nome_mese, "giugno");
        break;
    case 7:
        strcpy(nome_mese, "luglio");
        break;
    case 8:
        strcpy(nome_mese, "agosto");
        break;
    case 9:
        strcpy(nome_mese, "settembre");
        break;
    case 10:
        strcpy(nome_mese, "ottobre");
        break;
    case 11:
        strcpy(nome_mese, "novembre");
        break;
    case 12:
        strcpy(nome_mese, "dicembre");
        break;

    }
    #endif


}
