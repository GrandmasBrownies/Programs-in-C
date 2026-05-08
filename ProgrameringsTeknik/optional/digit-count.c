// 2025 Joel Tann

#include <stdio.h>

int digit_count(int d, int x);

int main()
{
    int num1 = 0;
    int num2 = 0;

    while (scanf("%d %d", &num1, &num2) == 2)
    {
        int result = digit_count(num1, num2);
        printf("%d\n", result);
    }
}

int digit_count(int d, int x)
{
    int counter = 0;
    while (x > 0)
    {
        if (x % 10 == d)
        {
            counter++;
        }
        x /= 10;
    }
    return counter;
}