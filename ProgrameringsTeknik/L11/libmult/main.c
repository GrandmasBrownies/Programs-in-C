// 2025 Joel Tann

#include "libmult.h"
#include <stdio.h>

int main()
{
    int x = 0;

    while (scanf("%d", &x) == 1)
    {
        printf("triple(%d) = %d\n", x, triple(x));
        printf("quadruple(%d) = %d\n", x, quadruple(x));
        printf("quintuple(%d) = %d\n", x, quintuple(x));
        printf("sixtuple(%d) = %d\n", x, sixtuple(x));
        printf("septuple(%d) = %d\n", x, septuple(x));
    }
    return 0;
}