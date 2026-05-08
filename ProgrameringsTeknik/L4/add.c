// 2025 Joel Tann

#include <stdio.h>

int add(int x, int y)
{
    return x+y;
}

int main ()
{
    int num1, num2 = 0;
    while (scanf("%d %d", &num1, &num2) == 2)
    {
        int sum = add (num1, num2);
        printf("%d\n", sum);
    }
    return 0;
}