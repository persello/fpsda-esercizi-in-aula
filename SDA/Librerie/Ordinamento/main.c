#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "ordinamento.h"
#include "array/array.h"

#define N 5

bool verifica_ordine(float a[], int n) {
  int i;
  for (i = 0; i < n - 1; i++)
    if (a[i] > a[i + 1])
      return false;
  return true;
}

void copia_vettore(float a[], int n, float v[]) {
    int i;
    for (i = 0; i < n; i++)
        v[i] = a[i];
}

int main() {
  int n = N;
  float disordinato[N] = {2, 1, 3, 4, -1}, v[N];
  
  copia_vettore(disordinato, n, v);
  selection_sort(v, n);
  assert(verifica_ordine(v, n));

  copia_vettore(disordinato, n, v);
  insertion_sort(v, n);
  assert(verifica_ordine(v, n));

  copia_vettore(disordinato, n, v);
  bubble_sort(v, n);
  assert(verifica_ordine(v, n));

  copia_vettore(disordinato, n, v);
  merge_sort(v, n);
  assert(verifica_ordine(v, n));
  
  copia_vettore(disordinato, n, v);
  quick_sort(v, n);
  assert(verifica_ordine(v, n));
  
  copia_vettore(disordinato, n, v);
  heap_sort(v, n);
  stampa_vettore(v, n);
  assert(verifica_ordine(v, n));
  
  return 0;
}
