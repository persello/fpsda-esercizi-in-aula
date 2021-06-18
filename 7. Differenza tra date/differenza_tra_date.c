#include <stdio.h>
#include <stdlib.h>
#include "libdate/libdate.h"

int to_julian_days(int dd, int mm, int yy);

int main()
{
    int g1, m1, a1,
        g2, m2, a2;

    /* Leggi le due date */
    leggi_data(&g1, &m1, &a1);
    leggi_data(&g2, &m2, &a2);

    printf("%d", to_julian_days(1, 1, 0));

    /* Calcola la differenza */
    printf("Giorni tra le due date: %d.\n", giorni_fra_date(g1, m1, a1, g2, m2, a2));

    return EXIT_SUCCESS;
}

int to_julian_days(int dd, int mm, int yy)
{
    mm = (mm + 9) % 12;
    yy = yy - mm / 10;
    int days = 365 * yy + yy / 4 - yy / 100 + yy / 400 + (mm * 306 + 5) / 10 + (dd - 1);
    return days;
}