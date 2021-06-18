#ifndef _PILA_H
#define _PILA_H

#include "lista.h"
#include "array.h"
#include <stdbool.h>

// descrittore di una pila implementata tramite lista

typedef lista pila;

pila crea_pila(void);
void elimina_pila(pila* p);
void push(pila* p, float dato);
void pop(pila* p);
float top(pila p);
bool empty(pila p);
void stampa_pila(pila p);





// descrittore di pila implementata con array dinamico
typedef vettore_dinamico pila_v;

pila_v crea_pila_v(void);
void elimina_pila_v(pila_v* p);
void push_v(pila_v* p, float dato);
void pop_v(pila_v* p);
float top_v(pila_v p);
bool empty_v(pila_v p);
void stampa_pila_v(pila_v p);

#endif
