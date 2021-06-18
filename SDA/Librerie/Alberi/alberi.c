#include "alberi.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <math.h>

albero_binario_ricerca crea_abr() {
    albero_binario_ricerca a;
    a.nodi = 0;
    a.radice = NULL;
    return a;
}

void _elimina_tutti_i_nodi(nodo_albero_binario_ricerca* r) {
    if (r == NULL) /* caso base della ricorsione */
        return;
    if (r->destro != NULL)
        _elimina_tutti_i_nodi(r->destro);
    if (r->sinistro != NULL)
        _elimina_tutti_i_nodi(r->sinistro);
    free(r); /* dealloca il nodo r */
}

void elimina_abr(albero_binario_ricerca* a) {
    _elimina_tutti_i_nodi(a->radice);
    a->radice = NULL;
    a->nodi = 0;
}

nodo_albero_binario_ricerca* _inserisci(nodo_albero_binario_ricerca* r, int chiave, float dato) {
    if (r == NULL) {
        /* un nuovo nodo dev'essere allocato */
        nodo_albero_binario_ricerca* r = malloc(sizeof(nodo_albero_binario_ricerca));
        assert(r != NULL);
        r->chiave = chiave;
        r->dato = dato;
        r->sinistro = NULL;
        r->destro = NULL;
        return r;
    }
    else if (chiave < r->chiave)
        r->sinistro = _inserisci(r->sinistro, chiave, dato);
    else if (chiave > r->chiave)
        r->destro = _inserisci(r->destro, chiave, dato);
    else /* r->chiave == chiave, in tal caso aggiorna il dato corrente */
        r->dato = dato;
    return r;
}

void inserisci_abr(albero_binario_ricerca* a, int chiave, float dato) {
    a->radice = _inserisci(a->radice, chiave, dato);
    a->nodi++;
}

nodo_albero_binario_ricerca* _minimo_sottoalbero(nodo_albero_binario_ricerca* r) {
  while (r->sinistro != NULL)
    r = r->sinistro;
  return r;
}

nodo_albero_binario_ricerca* _cancella(nodo_albero_binario_ricerca* r, int chiave) {
  if (r == NULL)
    return NULL;
  if (chiave == r->chiave) {
    if (r->sinistro == NULL)
      r = r->destro;
    else if (r->destro == NULL)
      r = r->sinistro;
    else {
      nodo_albero_binario_ricerca* w = _minimo_sottoalbero(r->destro);
      r->dato = w->dato;
      r->destro = _cancella(r->destro, w->chiave);
    }
  } else if (chiave < r->chiave)
    r->sinistro = _cancella(r->sinistro, chiave);
  else /* chiave > r->dato->chiave */
    r->destro = _cancella(r->destro, chiave);
  return r;
}

void cancella_abr(albero_binario_ricerca* a, int chiave) {
    _cancella(a->radice, chiave);
    a->nodi--;
}

nodo_albero_binario_ricerca* _ricerca(nodo_albero_binario_ricerca* r, int chiave) {
  if (r == NULL)
    return NULL;
  if (chiave == r->chiave)
    return r;
  if (chiave < r->chiave)
    return _ricerca(r->sinistro, chiave);
  else
    return _ricerca(r->destro, chiave);
}

nodo_albero_binario_ricerca* ricerca_abr(albero_binario_ricerca a, int chiave) {
    return _ricerca(a.radice, chiave);
}



