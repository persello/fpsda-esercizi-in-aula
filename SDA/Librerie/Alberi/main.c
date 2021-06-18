#include <stdio.h>
#include "alberi.h"
#include "array.h"
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define N 50

bool verifica_ordine(nodo_albero_binario_ricerca *r)
{
  if (r == NULL)
    return true;
  bool verifica = true;
  if (r->sinistro)
    verifica = r->chiave > r->sinistro->chiave && verifica_ordine(r->sinistro);
  if (!verifica)
    return false;
  if (r->destro)
    verifica = r->chiave <= r->destro->chiave && verifica_ordine(r->destro);
  return verifica;
}

int main()
{
  albero_binario_ricerca a = crea_abr();
  int i;
  float v[N];
  for (i = 0; i < N; i++)
  {
    v[i] = rand() % 100;
    inserisci_abr(&a, v[i], 0.0);
  }
  assert(verifica_ordine(a.radice));

  return 0;
}
