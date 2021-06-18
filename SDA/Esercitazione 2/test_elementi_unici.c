#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "elementi_unici.h"
#include "res/carica_lista.c"

bool controlla_unicita(lista l);

int main()
{
    printf("Avvio test elementi_unici...\n");
    char *nome_file = malloc(50);
    for (int i = 0; i < 20; i++)
    {
        sprintf(nome_file, "res/test_ricerca%d.txt", i);

        printf("Carico file di test \"%s\".\n", nome_file);
        lista l = carica_lista(nome_file);

        printf("Rimozione elementi duplicati.\n");
        lista d = elementi_unici(l);

        assert(controlla_unicita(d));
        printf("Test %d passato.\n", i);

        // elimina_lista(&l);
        // elimina_lista(&d);
    }
    printf("Test riuscito.\n");
    return EXIT_SUCCESS;
}

/* Si suppone che l sia ordinata */
bool controlla_unicita(lista l)
{
    nodo_lista *e = l.testa;
    while (e->succ != NULL)
    {
        if (e->dato == e->succ->dato)
            return false;
        e = e->succ;
    }
    return true;
}