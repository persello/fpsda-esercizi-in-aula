#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    double somma = 0;
    for(int i = 1; i < argc; i++) {
        somma += atof(argv[i]);
    }

    printf("Somma = %lf\n", somma);
    return EXIT_SUCCESS;
}