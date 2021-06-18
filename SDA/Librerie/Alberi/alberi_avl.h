#ifndef alberi_avl_h
#define alberi_avl_h

#include <stdbool.h>

/* void VisitaPreordineAlberoBinario(AlberoBinario* r);
void VisitaInordineAlberoBinario(AlberoBinario* r);
void VisitaPostordineAlberoBinario(AlberoBinario* r); */

typedef struct _nodo_albero_AVL {
    int chiave;
    float dato;
    struct _nodo_albero_AVL *padre, *sinistro, *destro;
    int altezza;
    bool cancellato;
    int figli_cancellati;
} nodo_albero_avl;

typedef struct {
    int nodi;
    nodo_albero_avl* radice;
} albero_avl;

albero_avl crea_avl();
void elimina_avl(albero_avl* a);
void inserisci_avl(albero_avl* a, int chiave, float dato);
nodo_albero_avl* ricerca_avl(albero_avl a, int chiave);
void cancella_avl(albero_avl* a, int chiave);


#endif /* alberi_avl_h */
