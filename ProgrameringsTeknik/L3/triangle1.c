// 2025 Joel Tann

#include <stdio.h>

int main()
{
    int num1, num2, num3 = 0;
    scanf("%d %d %d", &num1, &num2, &num3);
    if (num1 == num2 && num2 == num3)
    {
        printf("equilateral\n");
    }
    else if ((num1 + num2) <= num3 || (num1 + num3) <= num2 || (num2 + num3) <= num1)
    {
        printf("impossible\n");
    }
    else if (num1 != num2 && num2 != num3 && num1 != num3)
    {
        printf("scalene\n");
    }
    else
    {
        printf("isosceles\n");
    }
    return 0;
}