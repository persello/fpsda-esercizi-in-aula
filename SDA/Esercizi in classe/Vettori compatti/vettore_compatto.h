#ifndef VETTORE_COMPATTO_H
#define VETTORE_COMPATTO_H

typedef struct _elemento_compatto
{
    int dato;
    int molteplicita;
    _elemento_compatto *succ;
} elemento_compatto;

typedef struct
{
    elemento_compatto *testa;
    elemento_compatto *coda;
    int n;
} vettore_compatto;

vettore_compatto crea_vettore_compatto();

void aggiungi_in_coda(vettore_compatto *v, int dato);

int cerca_prima_posizione(vettore_compatto v, int dato);

int valore_di_indice(vettore_compatto v, int indice);

void elimina_vettore_compatto(vettore_compatto *v);

#endif