#include <stdio.h>
#include "pila.h"
#include <assert.h>

#define N 10

int main() {
  pila p = crea_pila();
  pila_v pv = crea_pila_v();
  int i, n = N;
  // verifica che la pila sia inizialmente vuota
  assert(empty(p));
  assert(empty_v(pv));
  
  for (i = 0; i < n; i++)
  {
    push(&p, (float)i + 10);
    assert(top(p) == (float)i + 10);
    stampa_pila(p);
    push_v(&pv, (float)i + 10);
    assert(top_v(pv) == (float)i + 10);
    stampa_pila_v(pv);
  }
  stampa_pila(p);
  stampa_pila_v(pv);
  for (i = n - 1; i >= 0; i--) {
    assert(top(p) == (float)i + 10);
    pop(&p);
    stampa_pila(p);
    assert(top_v(pv) == (float)i + 10);
    pop_v(&pv);
    stampa_pila_v(pv);
  }
  assert(empty(p));
  assert(empty_v(pv));
  stampa_pila(p);
  stampa_pila_v(pv);
    
  return 0;
}

