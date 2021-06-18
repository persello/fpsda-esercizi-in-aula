#ifndef _DIZIONARIO_H
#define _DIZIONARIO_H

#include <stdbool.h>

// funzioni di hash su stringhe

unsigned int hash_djb2(char chiave[]);
unsigned int hash_xor(char chiave[]);

typedef struct _nodo_tabella_hash {
  char chiave[128];
  void* dato;
  struct _nodo_tabella_hash* succ;
} nodo_tabella_hash;

typedef struct  {
  nodo_tabella_hash** tabella;
  int d;
  int elementi; 
} tabella_hash;

tabella_hash crea_tabella_hash(int m); // m è la dimensione del dizionario
int numero_elementi(tabella_hash t);
nodo_tabella_hash* ricerca_tabella_hash(tabella_hash t, char* chiave);
void inserisci_tabella_hash(tabella_hash* t, char* chiave, void* dato);
void rimuovi_tabella_hash(tabella_hash* t, char* chiave);
void elimina_tabella_hash(tabella_hash* t);
void stampa_tabella_hash(tabella_hash t, void stampa(void*));

#endif
