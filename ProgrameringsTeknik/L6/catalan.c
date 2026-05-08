// 2025 Joel Tann

#include <stdio.h>

long double factorial (long double x)
{
    if (x == 0)
    {
        return 1;
    } else {
        return x * factorial(x-1);
    }
}

unsigned int komb (double x, double y)
{
    return factorial(x) / (factorial(y) * factorial(x-y));
}

unsigned int catalan (double x)
{
    return (1/(x+1)) * komb(2*x, x);
}

int main()
{
    unsigned int num = 0;

    while (scanf("%u", &num) == 1)
    {
        printf("%u\n", catalan(num));
    }
    return 0;
}