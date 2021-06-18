#include <stdlib.h>
#include <stdio.h>

#include "funzioni_abr.h"

// Funzioni ricorsive
int _massimo_chiave_abr_ric(nodo_albero_binario_ricerca *nodo);
void _stampa_valori_minori_ric(nodo_albero_binario_ricerca *nodo, float valore_massimo);
int _altezza_max_sottoalbero(nodo_albero_binario_ricerca *nodo);
bool _albero_bilanciato_ric(nodo_albero_binario_ricerca *nodo);

int massimo_chiave_abr(albero_binario_ricerca albero)
{
    return _massimo_chiave_abr_ric(albero.radice);
}

int _massimo_chiave_abr_ric(nodo_albero_binario_ricerca *nodo)
{
    if (nodo->destro == NULL)
    {
        return nodo->chiave;
    }
    else
    {
        return _massimo_chiave_abr_ric(nodo->destro);
    }
}

void stampa_valori_minori(albero_binario_ricerca albero, float valore_massimo)
{
    _stampa_valori_minori_ric(albero.radice, valore_massimo);
}

void _stampa_valori_minori_ric(nodo_albero_binario_ricerca *nodo, float valore_massimo)
{
    _stampa_valori_minori_ric(nodo->sinistro, valore_massimo);
    if (nodo != NULL)
    {
        if (nodo->dato < valore_massimo)
        {
            printf("%f\n", nodo->dato);
        }
        else
        {
            return;
        }
    }
    else
    {
        return;
    }
    _stampa_valori_minori_ric(nodo->destro, valore_massimo);
}

bool albero_bilanciato(albero_binario_ricerca albero)
{
    _albero_bilanciato_ric(albero.radice);
}

bool _albero_bilanciato_ric(nodo_albero_binario_ricerca *nodo)
{
    if (nodo == NULL)
    {
        return true;
    }
    else if (abs(_altezza_max_sottoalbero(nodo->destro) - _altezza_max_sottoalbero(nodo->sinistro)) > 1)
    {
        return false;
    }
    else
    {
        return (_albero_bilanciato_ric(nodo->destro) && _albero_bilanciato_ric(nodo->sinistro));
    }
}

int _altezza_max_sottoalbero(nodo_albero_binario_ricerca *nodo)
{
    if (nodo == NULL)
    {
        return 0;
    }
    else
    {
        int altezza_destra = _altezza_max_sottoalbero(nodo->destro);
        int altezza_sinistra = _altezza_max_sottoalbero(nodo->sinistro);

        return (altezza_destra > altezza_sinistra ? altezza_destra : altezza_sinistra) + 1;
    }
}