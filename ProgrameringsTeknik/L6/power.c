// 2025 Joel Tann

#include <stdio.h>

int power(int x, int y)
{
    if (y == 0)
    {
        return 1;
    } else {
        return x * power (x, (y-1));
    }
}

int main()
{
    int num1, num2 = 0;

    while (scanf("%d %d", &num1, &num2) == 2)
    {
        int result = power (num1, num2);
        printf("%d\n", result);
    }
    return 0;
}