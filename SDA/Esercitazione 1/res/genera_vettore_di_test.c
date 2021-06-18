#include "genera_vettore_di_test.h"
#include <stdlib.h>

vettore_dinamico genera_vettore_di_test(int n) {
  vettore_dinamico a = crea_vettore_dinamico(n);
  for (int i = 0; i < n; i++) {
      if (i == 0)
          a.dati[i] = 0.01 + (float)rand() / (float)RAND_MAX;
      else
          a.dati[i] = a.dati[i - 1] + (float)rand() / (float)RAND_MAX;
  }
  for (int i = 0; i < n; i++)
    a.dati[i] /= a.dati[n - 1];
  return a;
}

