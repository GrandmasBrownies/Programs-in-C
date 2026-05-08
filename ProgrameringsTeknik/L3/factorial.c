// 2025 Joel Tann

#include <stdio.h>

int factorial (int n)
{
    if (n == 0)
    {
        return 1;
    }
    while (n != 1)
    {
        return n * factorial (n-1);
    }
}

int main()
{
    int num = 0;
    scanf("%d", &num);
    int fac = factorial (num);
    printf("%d\n", fac);
    return 0;
}