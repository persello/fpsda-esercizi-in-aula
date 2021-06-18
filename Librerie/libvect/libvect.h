#ifndef LIBVECT_H
#define LIBVECT_H

/* Legge un vettore di dimensione massima dim_max dalla tastiera. Restituisce il numero di valori letti. */
int leggi_vettore(int v[], int dim_max);

void stampa_vettore(int v[], int dim);

void stampa_vettore_al_contrario(int v[], int dim);

void inverti_vettore(int v[], int dimensione);

/* Cerca valore_cercato nel vettore v dall'indice inizio all'indice fine. */
int cerca_in_sottovettore(int v[], int inizio, int fine, int valore_cercato);

void scorrimento_circolare(int v[], int dim);

int massimo_in_sottovettore(int v[], int inizio, int fine);


#endif