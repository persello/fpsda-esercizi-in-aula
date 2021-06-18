#ifndef LIBDATE_H
#define LIBDATE_H

/* Restituisce 1 se la data inserita è valida, 0 altrimenti. */
int data_valida(int giorno, int mese, int anno);

/* Restituisce quanti giorni ha il mese m dell'anno a. */
int giorni_del_mese(int m, int a);

/* Restituisce 1 se l'anno specificato è bisestile, 0 altrimenti. */
int bisestile(int anno);

/* Restituisce il numero di giorni tra la prima e la seconda data. */
int giorni_fra_date(int g1, int m1, int a1, int g2, int m2, int a2);

/* Restituisce 0 se uguali, numeri negativi se la prima è antecedente alla seconda e numeri positivi nell'altro caso. */
int confronta_date(int g1, int m1, int a1, int g2, int m2, int a2);

/* Modifica i dati in ingresso in modo da incrementare la data fornita di un giorno. */
void giorno_successivo(int *pg, int *pm, int *pa);

/* Legge una data valida da tastiera. */
void leggi_data(int *pg, int *pm, int *pa);

#endif