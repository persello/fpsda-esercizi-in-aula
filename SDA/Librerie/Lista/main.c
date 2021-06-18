#include <stdio.h>
#include "lista.h"
#include <assert.h>

#define N 10

int main() {
    float v[6] = { 3.0, 5.0, -1.0, 2.0, 4.0, 1.0 };
    int n = 6, i;
    // Test Lista Semplice
    {
        lista l = crea_lista();
        nodo_lista* c;
        
        assert(lunghezza(l) == 0);
        assert(l.testa == NULL && l.coda == NULL);
        aggiungi_in_testa(&l, v[0]);
        assert(l.testa != NULL && l.coda != NULL && l.testa == l.coda);
        assert(l.testa->dato == v[0] && l.coda->dato == v[0]);
        for (i = 1; i < n; i++) {
            aggiungi_in_testa(&l, v[i]);
        }
        assert(l.testa != NULL && l.coda != NULL);
        assert(lunghezza(l) == n);
        assert(l.testa->dato == v[n - 1]);
        assert(l.coda->dato == v[0]);
        
        c = l.testa;
        i = n - 1;
        while (c) {
            assert(c->dato == v[i]);
            c = c->succ;
            i--;
        }
        
        elimina_in_testa(&l);
        assert(lunghezza(l) == n - 1);
        elimina_in_coda(&l);
        assert(lunghezza(l) == n - 2);
        elimina_lista(&l);
        assert(l.testa == NULL && l.coda == NULL && l.lunghezza == 0);
        
        l = crea_lista();
        assert(lunghezza(l) == 0);
        assert(l.testa == NULL && l.coda == NULL);
        aggiungi_in_coda(&l, v[0]);
        assert(l.testa != NULL && l.coda != NULL && l.testa == l.coda);
        assert(l.testa->dato == v[0] && l.coda->dato == v[0]);
        for (int i = 1; i < n; i++) {
            aggiungi_in_coda(&l, v[i]);
        }
        assert(l.testa != NULL && l.coda != NULL);
        assert(lunghezza(l) == n);
        assert(l.testa->dato == v[0]);
        assert(l.coda->dato == v[n - 1]);
        c = l.testa;
        i = 0;
        while (c) {
            assert(c->dato == v[i]);
            c = c->succ;
            i++;
        }
    }
    // Test Lista Doppia
    {
        lista_doppia l = crea_lista_d();
        nodo_lista_doppia *c, *p;
        
        assert(lunghezza_d(l) == 0);
        assert(l.testa == NULL && l.coda == NULL);
        aggiungi_in_testa_d(&l, v[0]);
        assert(l.testa != NULL && l.coda != NULL && l.testa == l.coda);
        assert(l.testa->succ == NULL && l.coda->succ == NULL && l.testa->pred == NULL && l.coda->pred == NULL);
        assert(l.testa->dato == v[0] && l.coda->dato == v[0]);
        for (i = 1; i < n; i++) {
            aggiungi_in_testa_d(&l, v[i]);
        }
        assert(l.testa != NULL && l.coda != NULL);
        assert(lunghezza_d(l) == n);
        assert(l.testa->succ != NULL && l.coda->succ == NULL && l.testa->pred == NULL && l.coda->pred != NULL);
        assert(l.testa->dato == v[n - 1]);
        assert(l.coda->dato == v[0]);
        
        c = l.testa;
        p = NULL;
        i = n - 1;
        while (c) {
            assert(c->dato == v[i]);
            assert(c->pred == p);
            p = c;
            c = c->succ;
            i--;
        }
        
        c = l.testa->succ;
        elimina_in_testa_d(&l);
        assert(lunghezza_d(l) == n - 1);
        assert(l.testa == c);
        c = l.coda->pred;
        elimina_in_coda_d(&l);
        assert(lunghezza_d(l) == n - 2);
        assert(l.coda == c);
        elimina_lista_d(&l);
        assert(l.testa == NULL && l.coda == NULL && l.lunghezza == 0);
        
        l = crea_lista_d();
        assert(lunghezza_d(l) == 0);
        aggiungi_in_coda_d(&l, v[0]);
        assert(l.testa->dato == v[0] && l.coda->dato == v[0]);
        for (int i = 1; i < n; i++) {
            aggiungi_in_coda_d(&l, v[i]);
        }
        assert(l.testa != NULL && l.coda != NULL);
        assert(lunghezza_d(l) == n);
        assert(l.testa->succ != NULL);
        assert(l.coda->succ == NULL);
        assert(l.testa->pred == NULL);
        assert(l.coda->pred != NULL);
        assert(l.testa->dato == v[0]);
        assert(l.coda->dato == v[n - 1]);
        
        c = l.coda;
        p = NULL;
        i = n - 1;
        while (c) {
            assert(c->dato == v[i]);
            assert(c->succ == p);
            p = c;
            c = c->pred;
            i--;
        }
    }
    return 0;
}

