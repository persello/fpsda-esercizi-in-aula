#include <stdlib.h>
#include "../Librerie/Lista/lista.h"

lista intersezione(lista l1, lista l2)
{
    lista risultato = crea_lista();
    intersezione_ric(&risultato, l1.testa, l2.testa);

    return risultato;
}

void intersezione_ric(lista *risultato, nodo_lista *nl1, nodo_lista *nl2)
{
    if (nl1 != NULL && nl2 != NULL)
    {
        if (nl1->dato == nl2->dato)
        {
            aggiungi_in_coda(risultato, nl1->dato);
            intersezione_ric(risultato, nl1->succ, nl2->succ);
        }
        else if (nl1->dato > nl2->dato)
        {
            intersezione_ric(risultato, nl1, nl2->succ);
        }
        else
        {
            intersezione_ric(risultato, nl1->succ, nl2);
        }
    }
}