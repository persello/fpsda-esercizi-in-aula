#include <stdio.h>
#include <stdlib.h>

#define MASSIMO 100.0
#define MINIMO -100.0

double ottieni_valore_valido();
int valore_nei_limiti(double valore, double minimo, double massimo);

int main()
{

    int numero_valori;
    int contatore = 0;
    double totale = 0;

    /* Ottieni conteggio valori */
    printf("Inserire numero valori: ");
    scanf("%d", &numero_valori);

    /* Leggi n valori */
    while (contatore < numero_valori)
    {
        totale += ottieni_valore_valido();
        contatore++;
    }

    /* Stampa media ed esci */
    printf("La media di %d valori è %f.\n", numero_valori, totale / numero_valori);
    return EXIT_SUCCESS;
}

double ottieni_valore_valido()
{
    double valore;

    /* Cicla fino a quando il valore non rientra nel range */
    do
    {
        printf("Inserire un nuovo valore: ");
        scanf("%lf", &valore);

        /* Stampa messaggio di errore */
        if (!valore_nei_limiti(valore, MINIMO, MASSIMO))
        {
            printf("Valore fuori dai limiti. ");
        }
    } while (!valore_nei_limiti(valore, MINIMO, MASSIMO));

    /* Restituisci un risultato valido */
    return valore;
}

int valore_nei_limiti(double valore, double minimo, double massimo)
{
    return (valore <= massimo) && (valore >= minimo);
}