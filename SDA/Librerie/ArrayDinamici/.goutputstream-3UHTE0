#ifndef _ARRAY_DINAMICI_H
#define _ARRAY_DINAMICI_H

/**
\defgroup array
 
 Struttura dati **Vettore Dinamico**.
 
 \par
 Il descrittore della struttura è costituito da un puntatore allo spazio di memoria allocato per il vettore e dalle dimensioni logica e fisica del vettore.
 \par
 La struttura può essere manipolata attraverso le funzioni di creazione del vettore, ridimensionamento e cancellazione.
*/

/**
 Descrittore di un vettore dinamico
 \ingroup array
 */
typedef struct {
  float *dati; /**< Puntatore allo spazio di memoria allocato per il vettore, ossia al primo elemento del vettore */
  int dimensione; /**< Dimensione logica del vettore, ossia numero di elementi effettivamente utilizzati */
  int capacita; /**< Dimensione fisica del vettore, ossia numero di elementi allocati in memoria */
} vettore_dinamico;

/**
 Crea un vettore dinamico allocando la memoria necessaria per contenere i suoi elementi.
 \param n dimensione logica del vettore
 \return il puntatore ad un descrittore del vettore dinamico con dimensione fisica 2*n e dimensione logica n
 
 \note
 La complessità della funzione è $O(1)$.
 \par
 La funzione non inizializza gli elementi del vettore.
 \ingroup array
*/
vettore_dinamico crea_vettore_dinamico(int n);

/**
 Ridimensiona un vettore dinamico.
 \param v puntatore al descrittore del vettore da ridimensionare
 \param n dimensione logica del vettore in seguito all'operazione di ridimensionamento
 \return il puntatore al descrittore del vettore dinamico modificato
 \note
 La complessità della funzione è $\Omega(1)$ e $O(n)$.
 \par
 Tuttavia, nel caso di operazioni di ridimensionamento che coinvolgano un solo elemento (inserimento/cancellazione) l'analisi ammortizzata sulle $n$ operazioni ci garantisce una complessità $O(1)$.
 \ingroup array
*/
void ridimensiona_vettore_dinamico(vettore_dinamico* v, int n);

/**
 Elimina un vettore dinamico deallocando la memoria utilizzata.
 \param v puntatore al descrittore del vettore da ridimensionare
 
 \note
 La complessità della funzione $O(1)$ nel caso pessimo.
 \ingroup array
 */
void elimina_vettore_dinamico(vettore_dinamico* v);

/**
 Funzione di utilità per la stampa del contenuto di un vettore dinamico
 \param v puntatore al descrittore del vettore da stampare
 \ingroup array, util
*/
void stampa_vettore_dinamico(vettore_dinamico v);

/**
 Funzione di utilità per la stampa del contenuto di un vettore
 \param v vettore da stampare
 \param n dimensione del vettore
 \ingroup array, util
 */
void stampa_vettore(float* v, int n);

#endif
