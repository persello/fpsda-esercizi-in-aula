#include "libstring.h"

#include <ctype.h>

int my_strstr(char *s, char *t)
{
    int lent = my_strlen(t);
    int lens = my_strlen(s);
    int indices, indicet;

    for (indices = 0; indices < lens; indices++)
    {
        indicet = 0;
        while (s[indices + indicet] == t[indicet])
        {
            if (indicet == lent - 1)
                return indices;

            indicet++;
        }
    }

    return -1;
}

int my_strncmp(char *s, char *t, int n)
{
    int lent = my_strlen(t);
    int lens = my_strlen(s);

    /* Trovo il valore minimo tra strlen(s), strlen(t) ed n */
    int lunghezza_minima = lens < lent ? lens : lent;
    lunghezza_minima = lunghezza_minima < n ? lunghezza_minima : n;

    for (int i = 0; i < lunghezza_minima; i++)
    {
        if (s[i] != t[i])
            return 0;
    }

    return 1;
}

void my_strinsert(char s[], char t[])
{
    int lent = my_strlen(t);
    int lens = my_strlen(s);

    /* Sposto in avanti s di lent caratteri (incluso '\0') */
    for (int i = lent + lens; i >= lent; i--)
    {
        s[i] = s[i - lent];
    }

    /* Copio t senza '\0' */
    for (int i = 0; i < lent; i++)
    {
        s[i] = t[i];
    }

    return;
}

void my_strcat(char s[], char t[])
{
    int lent = my_strlen(t);
    int lens = my_strlen(s);

    for (int i = lens; i <= lens + lent; i++)
    {
        s[i] = t[i - lens];
    }

    return;
}

void my_strcpy(char s[], char t[])
{
    int lunghezza = my_strlen(t);
    for (int i = 0; i <= lunghezza; i++)
    {
        s[i] = t[i];
    }

    return;
}

int frase_palindroma(char s[])
{
    int lunghezza = my_strlen(s);

    int indice_stringa_lettere = 0;
    char stringa_lettere[200];

    /* Tolgo tutti i segni e gli spazi */
    for (int i = 0; i < lunghezza - 1; i++)
    {
        if (isalpha(s[i]))
        {
            /* Carattere alfabeto. lo rendo minuscolo */
            if (isupper(s[i]))
            {
                /* Maiuscolo */
                stringa_lettere[indice_stringa_lettere] = s[i] - ('A' - 'a');
                indice_stringa_lettere++;
            }
            else
            {
                /* Minuscolo */
                stringa_lettere[indice_stringa_lettere] = s[i];
                indice_stringa_lettere++;
            }
        }
    }

    stringa_lettere[indice_stringa_lettere] = '\0';

    return palindroma(stringa_lettere);
}

int palindroma(char s[])
{
    int lunghezza = my_strlen(s);
    int i, j;

    for (i = 0, j = lunghezza - 1; i < j; i++, j--)
        if (s[i] != s[j])
            return 0;

    return 1;
}

int my_strlen(char s[])
{
    int i = 0;
    while (s[i] != '\0')
        i++;

    return i;
}
