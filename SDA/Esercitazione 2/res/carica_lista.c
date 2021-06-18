#include "../../Librerie/Lista/lista.h"
#include <stdio.h>
#include <assert.h>

lista carica_lista(char* nome_file) {
    int elementi, i;
    float valore;
    lista l = crea_lista();
    FILE* fp = fopen(nome_file, "r");
    
    assert(fp != NULL);
    
    fscanf(fp, "%d", &elementi);
    
    for (i = 0; i < elementi; i++) {
        fscanf(fp, "%f", &valore);
        aggiungi_in_coda(&l, valore);
    }
    
    return l;
}