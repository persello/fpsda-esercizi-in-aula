#include <stdio.h>
#include "tabella_hash.h"
#include <assert.h>

#define N 10

void stampa_dato_null(void* dato) {
  return;
}

int main() {
  char* chiavi[N] = { "Italia", "Germania", "Belgio", "Paesi Bassi", "Svizzera", "Francia", "Spagna", "Austria", "Slovenia", "Portogallo" };
  tabella_hash t = crea_tabella_hash(5);
  int i;
  for (i = 0; i < N; i++)
    inserisci_tabella_hash(&t, chiavi[i], NULL);
  
  stampa_tabella_hash(t, stampa_dato_null);
  
  for (i = 0; i < N; i++)
    assert(ricerca_tabella_hash(t, chiavi[i]) != NULL);
  assert(ricerca_tabella_hash(t, "Non Presente") == NULL);
  
  elimina_tabella_hash(&t);
  
  return 0;
}

