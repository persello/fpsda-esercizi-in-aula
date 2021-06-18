#include <stdlib.h>
#include "elementi_unici.h"

/* Si suppone che l sia ordinata */
lista elementi_unici(lista l)
{
    nodo_lista *c = l.testa;
    while (c != NULL && c->succ != NULL)
    {
        /* Se l'elemento è uguale al successivo */
        if (c->dato == c->succ->dato)
        {
            /* Salvo il successore */
            nodo_lista *n = c->succ;

            /* Escludo il successore dalla lista */
            c->succ = n->succ;

            /* Elimino il successore */
            l.lunghezza--;
            elimina_nodo(n);
        }
        else
        {
            c = c->succ;
        }
    }
    return l;
}