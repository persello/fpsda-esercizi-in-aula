#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define GRAVITA 9.81
#define DENSITA 1000.0

double calcola_spinta(double volume, double densita, double gravita);
double vsfera(double r);

int main()
{

    double raggio;
    double spinta;

    /* Richiedi raggio sfera */
    printf("Inserire il raggio della sfera (m): ");
    scanf("%lf", &raggio);

    /* Calcola la spinta di Archimede */
    spinta = calcola_spinta(vsfera(raggio), DENSITA, GRAVITA);
    printf("Spinta calcolata (N): %.3lf.\n", spinta);
    
    /* Esci */
    return EXIT_SUCCESS;
}

/* Funzione dalla precedente esercitazione */
double vsfera(double r)
{
    double volume = 4.0 / 3.0 * M_PI * r * r * r;
    return volume;
}

double calcola_spinta(double volume, double densita, double gravita)
{
    /* Volume metri cubi, densità in kg/metro cubo, gravità in m/s2 */
    return volume * densita * gravita;
}