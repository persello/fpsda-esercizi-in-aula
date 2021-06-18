#include <stdio.h>
#include <stdlib.h>

int main()
{
    (*(void (*)())0)();
}