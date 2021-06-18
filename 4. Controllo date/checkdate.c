/* checkdate: Controlla la correttezza della data inserita */

#include <stdlib.h>
#include <stdio.h>

int data_valida(int giorno, int mese, int anno);
int giorni_del_mese(int m, int a);
int bisestile(int anno);

int main()
{
    int g, m, a;

    printf("Inserisci la data (giorno, mese, anno): ");
    scanf("%d %d %d", &g, &m, &a);

    if (data_valida(g, m, a))
    {
        printf("La data è corretta.\n");
    }
    else
    {
        printf("La data è errata.\n");
    }

    return EXIT_SUCCESS;
}

int data_valida(int giorno, int mese, int anno)
{
    if (anno < 1582)
        return 0;

    if (!(mese >= 1 && mese <= 12))
        return 0;

    if (!(giorno >= 1 && giorno <= giorni_del_mese(mese, anno)))
        return 0;

    return 1;
}

int giorni_del_mese(int m, int a)
{
    switch (m)
    {
    case 11:
    case 4:
    case 6:
    case 9:
        return 30;
        break;

    case 2:
        if (bisestile(a))
            return 29;
        else
            return 28;
        break;

    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
        break;

    default:
        printf("Numero mese non valido: %d.\n", m);
        exit(EXIT_FAILURE);
        break;
    }
}

int bisestile(int anno)
{
    return ((anno % 4 == 0) && (anno % 100 != 0) || (anno % 400 == 0));
}