// 2025 Joel Tann

#include <stdio.h>

int fibonacci (int x)
{
    if (x == 0)
        return 0;
    else if (x == 1)
        return 1;

    int f0 = 0;
    int f1 = 1;
    int ftotal = 0;
    for (int i = 1; i != x; i++)
    {
        ftotal = f0 + f1;
        f0 = f1;
        f1 = ftotal;
    }
    return ftotal;
}

int main()
{
    int num = 0;

    while (scanf("%d", &num) == 1)
    {
        printf("%d\n", fibonacci(num));
    }
    return 0;
}