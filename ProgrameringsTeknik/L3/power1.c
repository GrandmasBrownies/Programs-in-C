// 2025 Joel Tann

#include <stdio.h>

int power (int b, int e)
{
    if  (e == 0)
    {
        return 1;
    }
    while (e != 0)
    {
        return b * power (b, (e-1));
    }
}

int main()
{
    int num1, num2 = 0;
    scanf("%d %d", &num1, &num2);
    int sum = power (num1, num2);
    printf("%d\n", sum);
    return 0;
}