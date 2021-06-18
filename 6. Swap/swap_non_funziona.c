#include <stdlib.h>
#include <stdio.h>

void swap(int a, int b);

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    swap(a, b);
    printf("a = %d, b = %d\n", a, b);

    return EXIT_SUCCESS;
}

void swap(int a, int b)
{
    int c = a;
    a = b;
    b = c;

    printf("Alla fine della funzione swap a = %d, b = %d.\n", a, b);

    return;
}