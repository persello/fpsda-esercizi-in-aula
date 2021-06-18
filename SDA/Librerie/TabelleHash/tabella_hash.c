#include "tabella_hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int hash_djb2(char chiave[]) {
    unsigned int result = 86357; /* può essere un qualunque numero primo */
    int c;
    while ((c = *chiave++))
        result = ((result << 5) + result) + c; /* result * 33 + c */
    return result;
}

unsigned int hash_xor(char chiave[]) {
    unsigned int result = 0x55555555;
    int c;
    while ((c = *chiave++)) {
        result ^= c;
        result = (result << 5) | ((result >> (sizeof(unsigned int) * 8 - 5)) & ~(0xFFFFFFFF << 5));
    }
    return result;
}


tabella_hash crea_tabella_hash(int m) {
  tabella_hash t;
  int i;
  t.tabella = (nodo_tabella_hash**)malloc(m * sizeof(nodo_tabella_hash*));
  for (i = 0; i < m; i++)
    t.tabella[i] = NULL;
  t.d = m;
  t.elementi = 0;
  return t;
}

int numero_elementi(tabella_hash t) {
  return t.elementi;
}

nodo_tabella_hash* ricerca_tabella_hash(tabella_hash t, char* chiave) {
    int indice = hash_djb2(chiave) % t.d;
    nodo_tabella_hash* el = t.tabella[indice];
    while (el != NULL && strcmp(el->chiave, chiave) != 0)
        el = el->succ;
    return el;
}

void inserisci_tabella_hash(tabella_hash* t, char* chiave, void* dato) {
  int indice = hash_djb2(chiave) % t->d;
  nodo_tabella_hash *c = t->tabella[indice];
  nodo_tabella_hash *el = (nodo_tabella_hash*)malloc(sizeof(nodo_tabella_hash));
  strcpy(el->chiave, chiave);
  el->dato = dato;
  el->succ = c;
  t->tabella[indice] = el;
  t->elementi++;
}

void rimuovi_tabella_hash(tabella_hash* t, char* chiave) {
  int indice = hash_djb2(chiave) % t->d;
  nodo_tabella_hash *c = t->tabella[indice], *p = NULL;
  if (c == NULL)
    return;
  while (c != NULL && strcmp(c->chiave, chiave) != 0) {
    p = c;
    c = c->succ;
  }
  p->succ = c->succ;
  free(c->dato);
  free(c);
  t->elementi--;
}

void elimina_tabella_hash(tabella_hash* t) {
  int i;
  for (i = 0; i < t->d; i++)
    if (t->tabella[i] != NULL) {
      nodo_tabella_hash* c = t->tabella[i], *p;
      while (c != NULL) {
        p = c;
        c = c->succ;
        free(p->dato);
        free(p);
      }
    }
  free(t->tabella);
}

void stampa_tabella_hash(tabella_hash t, void stampa(void*)) {
  int i;
  for (i = 0; i < t.d; i++) {
    nodo_tabella_hash* c = t.tabella[i];
    printf("%d: {", i);
    while (c != NULL) {
      printf("[%s] = ", c->chiave);
      stampa(c->dato);
      printf(" ");
      c = c->succ;
    }
    printf("} \n");
  }
}
