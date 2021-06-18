#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "array.h"

#define N 10

int main() {
  int i, n = N;
  vettore_dinamico v = crea_vettore_dinamico(n);
  for (i = 1; i <= 50; i++) {
    n = n + 1;
    ridimensiona_vettore_dinamico(&v, n);
    assert(v.dimensione == n);
    assert(v.capacita >= n);
    assert(v.dati != NULL);
    printf("Dimensione logica: %d, Dimensione fisica: %d, Puntatore ai dati: %p\n", v.dimensione, v.capacita, v.dati);
  }
  for (i = 1; i <= 50; i++) {
    n = n - 1;
    ridimensiona_vettore_dinamico(&v, n);
    assert(v.dimensione == n);
    assert(v.capacita >= n);
    assert(v.dati != NULL);
    printf("Dimensione logica: %d, Dimensione fisica: %d, Puntatore ai dati: %p\n", v.dimensione, v.capacita, v.dati);
  }
  elimina_vettore_dinamico(&v);
  
  return EXIT_SUCCESS;
}
