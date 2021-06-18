#include "alberi_avl.h"
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int _altezza_albero_avl(nodo_albero_avl* r) {
    if (r == NULL)
        return -1;
    else
        return r->altezza;
}

int _figli_cancellati_avl(nodo_albero_avl* r) {
    int tot = 0;
    if (r == NULL)
        return 0;
    if (r->sinistro)
        tot += r->sinistro->figli_cancellati + (r->sinistro->cancellato ? 1 : 0);
    if (r->destro)
        tot += r->destro->figli_cancellati + (r->destro->cancellato ? 1 : 0);
    return tot;
}

/* Albero AV */

int max(int a, int b) {
    return a > b ? a : b;
}

albero_avl crea_avl() {
    albero_avl a;
    a.nodi = 0;
    a.radice = NULL;
    return a;
}

void _elimina_nodi_avl(nodo_albero_avl* r) {
    if (r == NULL)
        return;
    _elimina_nodi_avl(r->destro);
    _elimina_nodi_avl(r->sinistro);
    free(r);
}

nodo_albero_avl* _alloca_nodo_avl(int chiave, float dato) {
    nodo_albero_avl* r = (nodo_albero_avl*)malloc(sizeof(nodo_albero_avl));
    assert(r != NULL);
    r->chiave = chiave;
    r->dato = dato;
    r->padre = NULL;
    r->sinistro = NULL;
    r->destro = NULL;
    r->altezza = 0;
    r->cancellato = false;
    r->figli_cancellati = 0;
    return r;
}

void elimina_avl(albero_avl* a) {
    _elimina_nodi_avl(a->radice);
    a->nodi = 0;
    a->radice = NULL;
}

nodo_albero_avl* _ruota_oraria(nodo_albero_avl* z) {
    nodo_albero_avl* v = z->sinistro;
    z->sinistro = v->destro;
    if (z->sinistro != NULL)
        z->sinistro->padre = z;
    v->destro = z;
    v->padre = z->padre;
    z->padre = v;
    z->altezza = max(_altezza_albero_avl(z->sinistro), _altezza_albero_avl(z->destro)) + 1;
    v->altezza = max(_altezza_albero_avl(v->sinistro), _altezza_albero_avl(v->destro)) + 1;
    z->figli_cancellati = _figli_cancellati_avl(z);
    v->figli_cancellati = _figli_cancellati_avl(v);
    return v;
}

nodo_albero_avl* _ruota_antioraria(nodo_albero_avl* v) {
    nodo_albero_avl* z = v->destro;
    v->destro = z->sinistro;
    if (v->destro != NULL)
        v->destro->padre = v;
    z->sinistro = v;
    z->padre = v->padre;
    v->padre = z;
    z->altezza = max(_altezza_albero_avl(z->sinistro), _altezza_albero_avl(z->destro)) + 1;
    v->altezza = max(_altezza_albero_avl(v->sinistro), _altezza_albero_avl(v->destro)) + 1;
    z->figli_cancellati = _figli_cancellati_avl(z);
    v->figli_cancellati = _figli_cancellati_avl(v);
    return z;
}

nodo_albero_avl* _inserisci_in_albero_avl(nodo_albero_avl* r, int chiave, float dato) {
    if (r == NULL) {
        r = _alloca_nodo_avl(chiave, dato);
        return r;
    }
    if (chiave < r->chiave) {
        r->sinistro = _inserisci_in_albero_avl(r->sinistro, chiave, dato);
        if (r->sinistro)
            r->sinistro->padre = r;
        if (_altezza_albero_avl(r->sinistro) - _altezza_albero_avl(r->destro) == 2) {
            if (chiave > r->sinistro->chiave)
                r->sinistro = _ruota_antioraria(r->sinistro);
            r = _ruota_oraria(r);
        }
    } else if (chiave > r->chiave) {
        r->destro = _inserisci_in_albero_avl(r->destro, chiave, dato);
        if (r->destro)
            r->destro->padre = r;
        if (_altezza_albero_avl(r->destro) - _altezza_albero_avl(r->sinistro) == 2) {
            if (chiave < r->destro->chiave)
                r->destro = _ruota_oraria(r->destro);
            r = _ruota_antioraria(r);
        }
    } else /* chiave == r->chiave */ {
        r->chiave = chiave;
        r->dato = dato;
        if (r->cancellato) {
            /* la chiave era attualmente cancellata
             la ripristiniamo aggiornando il numero di figli cancellati salendo alla radice */
            r->cancellato = false;
            nodo_albero_avl* w = r;
            while (w->padre != NULL) {
                w = w->padre;
                w->figli_cancellati--;
            }
            w->figli_cancellati--;
        }
        return r;
    }
    r->altezza = max(_altezza_albero_avl(r->sinistro), _altezza_albero_avl(r->destro)) + 1;
    r->figli_cancellati = _figli_cancellati_avl(r);
    return r;
}

nodo_albero_avl* _ricerca_albero_avl(nodo_albero_avl* r, int chiave) {
    if (r == NULL)
        return NULL;
    if (chiave == r->chiave) {
        if (!r->cancellato)
            return r;
        else
            return NULL;
    }
    if (chiave < r->chiave)
        return _ricerca_albero_avl(r->sinistro, chiave);
    else
        return _ricerca_albero_avl(r->destro, chiave);
}

nodo_albero_avl* ricerca_albero_avl(albero_avl a, int chiave) {
    return _ricerca_albero_avl(a.radice, chiave);
}

nodo_albero_avl* _copia_nodi_validi(nodo_albero_avl* nr, nodo_albero_avl* r) {
    if (r == NULL)
        return nr;
    if (!r->cancellato)
        nr = _inserisci_in_albero_avl(nr, r->chiave, r->dato);
    nr = _copia_nodi_validi(nr, r->sinistro);
    nr = _copia_nodi_validi(nr, r->destro);
    free(r); // elimina il nodo
    return nr;
}

nodo_albero_avl* _cancella_da_albero_avl(nodo_albero_avl* r, int chiave) {
    nodo_albero_avl* w = _ricerca_albero_avl(r, chiave);
    if (w == NULL)
        return r;
    w->cancellato = true;
    /* verifica se sia necessario ripulire l'albero */
    if (r->figli_cancellati >= pow(2, r->altezza) - 1) { /* quando più del 50% dei figli sono cancellati */
        nodo_albero_avl* nr = NULL;
        r = _copia_nodi_validi(nr, r);
    } else {
        /* altrimenti aggiorna il numero di figli cancellati risalendo verso la radice */
        while (w->padre != NULL) {
            w = w->padre;
            w->figli_cancellati++;
        }
        w->figli_cancellati++;
    }
    return r;
}

/* void VisitaPreordineAlberoAVL(AlberoAVL* r) {
    if (r == NULL)
        return;
    VisitaPreordineAlberoAVL(r->sinistro);
    if (!r->cancellato)
        printf("%d ", r->dato.chiave);
    VisitaPreordineAlberoAVL(r->destro);
}

void VisitaInordineAlberoAVL(AlberoAVL* r) {
    if (r == NULL)
        return;
    if (!r->cancellato)
        printf("%d ", r->dato.chiave);
    VisitaPreordineAlberoAVL(r->sinistro);
    VisitaPreordineAlberoAVL(r->destro);
}

void VisitaPostordineAlberoAVL(AlberoAVL* r) {
    if (r == NULL)
        return;
    VisitaPreordineAlberoAVL(r->sinistro);
    VisitaPreordineAlberoAVL(r->destro);
    if (!r->cancellato)
        printf("%d ", r->dato.chiave);
} */
