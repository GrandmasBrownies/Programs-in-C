// 2025 Joel Tann

#include <stdio.h>

int pizza (double x)
{
    return (1 + (x+1) * (x/2));
}

int main()
{
    int num = 0;

    while (scanf("%d", &num) == 1)
    {
        printf("%d\n", pizza(num));
    }
    return 0;
}