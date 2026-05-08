// 2025 Joel Tann

#include <stdio.h>

int digit_sum(int x)
{
    while (x > 0)
    {
        return (x % 10) + digit_sum (x / 10);
    }
}

int main()
{
    int num = 0;
    while (scanf("%d", &num) == 1)
    {
        int result = digit_sum (num);
        printf("%d\n", result);
    }
    return 0;
}