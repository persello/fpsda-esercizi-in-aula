#include <stdbool.h>
#include <stdlib.h>
#include "ordinamento.h"

/* Funzioni di utilità */

void _scambia(float* a, float* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/* Selection Sort */

int _minimo_a_partire_da(float a[], int n, int i) {
    int j, m = i;
    for (j = i + 1; j < n; j++) 
        if (a[j] < a[m])
            m = j;
    return m;
}

void selection_sort(float a[], int n) {
    int i, indice_minimo;
    for (i = 0; i < n - 1; i++) {
        indice_minimo = _minimo_a_partire_da(a, n, i);
        _scambia(&a[i], &a[indice_minimo]);
    }
}

/* Insertion Sort */

void insertion_sort(float a[], int n) {
    int i, j, prossimo;
    for (i = 0; i < n; i++) {
        prossimo = a[i];
        j = i;
        while (j > 0 && a[j - 1] > prossimo) { 
            a[j] = a[j - 1];
            j = j - 1;
        }
        a[j] = prossimo;
    }
}

/* Bubble Sort */

void bubble_sort(float a[], int n) {
    bool scambio;
    int k, i;
    scambio = true;
    k = n - 1;
    while (scambio) {
        scambio = false;
        for (i = 0; i < k; i++) {
            if (a[i] > a[i + 1]) {
                _scambia(&a[i], &a[i + 1]);
                scambio = true;
            }
        }
        k = k - 1;
    }
}

/* Merge Sort */

void _merge(float a[], int sinistra, int centro, int destra) {
    int i = sinistra, j = centro + 1, k = 0, n = destra - sinistra + 1;
    float* b = malloc(n * sizeof(float));
    while (i <= centro && j <= destra) {
        if (a[i] <= a[j]) {
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            j++;
        }
        k++;    
    }
    for (; i <= centro; i++, k++)
        b[k] = a[i];
    for (; j <= destra; j++, k++)
        b[k] = a[j];
    for (i = sinistra; i <= destra; i++)
        a[i] = b[i - sinistra];
    free(b);
}

void _merge_sort(float a[], int sinistra, int destra) {
    int centro;
    if (sinistra < destra) {
        centro = (sinistra + destra) / 2;
        _merge_sort(a, sinistra, centro);
        _merge_sort(a, centro + 1, destra);
        _merge(a, sinistra, centro, destra);
    }
}

void merge_sort(float a[], int n) {
    _merge_sort(a, 0, n - 1);
}

/* Quick Sort */

int _distribuzione(float a[], int sinistra, int pivot, int destra) {
  int i, j;
  if (pivot < destra)
    _scambia(&a[pivot], &a[destra]);
  i = sinistra;
  j = destra - 1;
  while (i <= j) {
    while (i <= j && a[i] <= a[destra])
      i++;
    while (i <= j && a[j] >= a[destra])
      j--;
    if (i < j)
      _scambia(&a[i], &a[j]);
  }
  if (i != destra)
    _scambia(&a[i], &a[destra]);

  return i;
}

void _quick_sort(float a[], int sinistra, int destra) {
  if (sinistra < destra) {
    int pivot = sinistra + rand() % (destra - sinistra + 1), rango; // genera un valore casuale compreso fra sinistra e destra
    rango = _distribuzione(a, sinistra, pivot, destra);
    _quick_sort(a, sinistra, rango - 1);
    _quick_sort(a, rango + 1, destra);
  }
}

void quick_sort(float a[], int n) {
  _quick_sort(a, 0, n - 1);
}

/* Heap Sort */

int _hs_padre(int i) {
  return (i - 1) / 2;
}

int _hs_sinistro(int i) {
  return 2 * i + 1;
}

int _hs_destro(int i) {
  return 2 * i + 2;
}

int _hs_migliore_padre_figli(float a[], int n, int i) {
  int k = i;
  if (_hs_sinistro(i) < n && a[k] < a[_hs_sinistro(i)])
    k = _hs_sinistro(i);
  if (_hs_destro(i) < n && a[k] < a[_hs_destro(i)])
    k = _hs_destro(i);
  return k;
}

void _hs_riorganizza_heap_enqueue(float a[], int n, int i) {
  /* Enqueue */
  while (i > 0 && a[i] > a[_hs_padre(i)]) {
    _scambia(&a[i], &a[_hs_padre(i)]);
    i = _hs_padre(i);
  }
}

void _hs_riorganizza_heap_dequeue(float a[], int n) {
  int i = 0;
  /* Dequeue */
  while (_hs_sinistro(i) < n && i != _hs_migliore_padre_figli(a, n, i)) {
    int figlio_migliore = _hs_migliore_padre_figli(a, n, i);
    _scambia(&a[i], &a[figlio_migliore]);
    i = figlio_migliore;
  }
}

void heap_sort(float a[], int n) {
  int i;
  for (i = 0; i < n; i++) {
    // di fatto è equivalente ad effettuare un Enqueue()
    _hs_riorganizza_heap_enqueue(a, i + 1, i);
  }
  i = n - 1;
  while (i > 0) {
    // e le due istruzioni seguenti sono equivalenti ad effettuare un Dequeue()
    _scambia(&a[0], &a[i]);
    i = i - 1;
    _hs_riorganizza_heap_dequeue(a, i + 1);
  }
}
