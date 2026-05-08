// 2025 Joel Tann

#include <stdio.h>

int reverse_digits(int x);

int main()
{
    int num = 0;
    while (scanf("%d", &num) == 1)
    {
        printf("%d\n", reverse_digits(num));
    }
    return 0;
}

int reverse_digits(int x)
{
    int result = 0;
    for (int i = 0; x > 0; i++)
    {
        result *= 10;
        result += x % 10;
        x /= 10;
    }
    return result;
}