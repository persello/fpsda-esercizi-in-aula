#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SFERA 's'
#define CUBO 'c'
#define PARALLELEPIPEDO 'p'

double vsfera(double raggio);
double vcubo(double lato);
double vparallbt(double bt, double at, double ap);
double area_triangolo(double base, double altezza);


int main()
{
    /* Dichiarazione variabili */
    double raggio, lato, baset, altezzat, altezzap, volume_totale;
    char tipo_solido;
    int numero_solidi_da_inserire, contatore_solidi_inseriti;

    volume_totale = 0;

    /* Input numero solidi da inserire */
    printf("Numero di solidi da inserire: ");
    scanf("%d", &numero_solidi_da_inserire);

    contatore_solidi_inseriti = 0;

    while (contatore_solidi_inseriti < numero_solidi_da_inserire)
    {
        /* Svuota buffer tastiera */
        while(getchar() != '\n');

        /* Inserimento del solido */
        printf("Inserisci tipo di solido (s, c, p): ");
        scanf("%c", &tipo_solido);

        /* Elaborazione */
        switch (tipo_solido)
        {
        case SFERA:
            printf("Inserisci il raggio: ");
            scanf("%lf", &raggio);
            volume_totale += vsfera(raggio);
            contatore_solidi_inseriti++;
            break;
        case CUBO:
            printf("Inserisci il lato: ");
            scanf("%lf", &lato);
            volume_totale += vcubo(lato);
            contatore_solidi_inseriti++;
            break;
        case PARALLELEPIPEDO:
            printf("Inserisci primo lato del triangolo di base: ");
            scanf("%lf", &baset);
            printf("Inserisci secondo lato del triangolo di base: ");
            scanf("%lf", &altezzat);
            printf("Inserisci altezza: ");
            scanf("%lf", &altezzap);
            volume_totale += vparallbt(baset, altezzat, altezzap);
            contatore_solidi_inseriti++;
            break;
        default:
            printf("Tipo solido non valido.\n");
            break;
        }
    }

    /* Stampa risultati */
    printf("Volume totale : %lf\n", volume_totale);

    return EXIT_SUCCESS;
}

double vsfera(double r)
{
    double volume = 4.0 / 3.0 * M_PI * r * r * r;
    return volume;
}

double vcubo(double l)
{
    return l * l * l;
}

double vparallbt(double bt, double at, double ap)
{
    double area_base = area_triangolo(bt, at);
    return area_base * ap;
}

double area_triangolo(double base, double altezza)
{
    return base * altezza / 2.0;
}
