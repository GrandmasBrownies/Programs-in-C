// 2025 Joel Tann

#include <stdio.h>

int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return fibonacci (n-1) + fibonacci (n-2);
    }
}

int main()
{
    int num = 0;
    scanf("%d", &num);
    int sum = fibonacci (num);
    printf("%d\n", sum);
    return 0;
}