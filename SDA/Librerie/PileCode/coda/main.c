#include <stdio.h>
#include "coda.h"
#include "coda_priorita.h"
#include <assert.h>
#include <stdlib.h>

#define N 40

void verifica_heap_property(coda_priorita pq) {
    int i;
    for (i = 0; i < pq.elementi; i++) {
        if (2 * i + 1 < pq.elementi)
            assert(pq.dati[i].priorita >= pq.dati[2 * i + 1].priorita);
        if (2 * i + 2 < pq.elementi)
            assert(pq.dati[i].priorita >= pq.dati[2 * i + 2].priorita);
    }
}

int main() {
    coda q = crea_coda();
    coda_v qv = crea_coda_v();
    coda_priorita pq = crea_coda_priorita();
  
    int i, n = N;
    for (i = 0; i < n; i++)
    {
        enqueue(&q, (float)i + 10);
        assert(first(q) == 10.0);
        stampa_coda(q);
        enqueue_v(&qv, (float)i + 10);
        assert(first_v(qv) == 10.0);
        stampa_coda_v(qv);
    }
    stampa_coda(q);
    stampa_coda_v(qv);
    for (i = 0; i < n; i++) {
        assert(first(q) == (float)i + 10);
        dequeue(&q);
        stampa_coda(q);
        assert(first_v(qv) == (float)i + 10);
        dequeue_v(&qv);
        stampa_coda_v(qv);
    }
    assert(coda_vuota(q));
    assert(coda_v_vuota(qv));
    stampa_coda(q);
    stampa_coda_v(qv);
    {
        int v[5] = {2, 1, 7, 3, 1}, max = 0;
        for (i = 0; i < 5; i++) {
            elemento_coda_priorita p;
            if (v[i] > v[max])
                max = i;
            enqueue_priorita(&pq, i, v[i]);
            p = first_priorita(pq);
            assert(p.dato == max && p.priorita == v[max]);
        }
        stampa_coda_priorita(pq);
    }
    {
        int p_max[5] = {7, 3, 2, 1, 1};
        for (i = 0; i < 5; i++) {
            elemento_coda_priorita p = first_priorita(pq);
            assert(p.priorita == p_max[i]);
            dequeue_priorita(&pq);
            stampa_coda_priorita(pq);
        }
    }
    {
        for (i = 0; i < N; i++) {
            bool aggiungi = (rand() / (float)RAND_MAX > 0.5);
            int priorita = rand() %  50;
            if (aggiungi || pq.elementi == 0)
                enqueue_priorita(&pq, rand() / (float)RAND_MAX, priorita);
            else
                dequeue_priorita(&pq);
            // verifica che valga la heap property
            stampa_coda_priorita(pq);
            verifica_heap_property(pq);
        }
    }
  
    return 0;
}

