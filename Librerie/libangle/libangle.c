#include <stdio.h>
#include <stdlib.h>

#include "libangle.h"

struct angolo leggi_angolo(void)
{
    struct angolo alpha;

    printf("Inserisci angolo (gradi primi secondi): ");
    scanf("%d %d %lf", &alpha.gradi, &alpha.primi, &alpha.secondi);

    return alpha;
}

void stampa_angolo(struct angolo alpha)
{
    printf("%d gradi, %d primi, %lf secondi\n", alpha.gradi, alpha.primi, alpha.secondi);
    return;
}

struct angolo somma_angoli(struct angolo alpha, struct angolo beta)
{
    struct angolo gamma;

    /* Somma i secondi */
    gamma.secondi = alpha.secondi + beta.secondi;

    /* Somma i primi */
    gamma.primi = alpha.primi + beta.primi;

    /* Somma i gradi */
    gamma.gradi = alpha.gradi + beta.gradi;

    return gamma;
}

struct angolo normalizza_angolo(struct angolo alpha)
{
    /* I secondi sono double */
    while (alpha.secondi >= 60)
    {
        alpha.secondi -= 60;
        alpha.primi++;
    }

    alpha.gradi += alpha.primi / 60;
    alpha.primi = alpha.primi % 60;

    // alpha.gradi = alpha.gradi % 360;

    return alpha;
}