// 2025 Joel Tann

#include <stdio.h>

int mult (int x, int y, int z)
{
    return x*y*z;
}

int main()
{
    int num1, num2, num3 = 0;
    scanf("%d %d %d", &num1, &num2, &num3);
    int result = mult (num1, num2, num3);
    printf("%d\n", result);
}