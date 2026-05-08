// 2025 Joel Tann

#include <stdio.h>

int factorial(int x)
{
    if (x == 0)
    {
        return 1;
    } else {
        return x * factorial (x-1);
    }
}

int main()
{
    int num = 0;

    while (scanf("%d", &num) == 1)
    {
        int result = factorial (num);
        printf("%d\n", result);
    }
    return 0;
}