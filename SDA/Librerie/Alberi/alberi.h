#ifndef _ALBERI_H
#define _ALBERI_H

#include <stdbool.h>

typedef struct _nodo_albero_ricerca {
    int chiave;
    float dato;
    struct _nodo_albero_ricerca* sinistro;
    struct _nodo_albero_ricerca* destro;
} nodo_albero_binario_ricerca;

typedef struct {
    int nodi;
    nodo_albero_binario_ricerca* radice;
} albero_binario_ricerca;

albero_binario_ricerca crea_abr();
void elimina_abr(albero_binario_ricerca* a);
void inserisci_abr(albero_binario_ricerca* a, int chiave, float dato);
nodo_albero_binario_ricerca* ricerca_abr(albero_binario_ricerca a, int chiave);
void cancella_abr(albero_binario_ricerca* a, int chiave);

#endif
