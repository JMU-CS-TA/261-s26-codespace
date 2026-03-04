#include <stdio.h>

int g = 0;

void increment (int *number)
{
    number++;
}

int main ()
{
    g = 4;

    for (int i = 0; i < 7; i++) {
        increment(&g);
    }

    printf("4 + 7 = %d\n", g);
    return 0;
}

