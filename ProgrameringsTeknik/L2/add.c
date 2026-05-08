// 2025 Joel Tann

#include <stdio.h>

int add (int x, int y)
{
    return x+y;
}

int main()
{
    int num1, num2 = 0;
    scanf("%d %d", &num1, &num2);
    printf("%d\n", add (num1, num2));
}