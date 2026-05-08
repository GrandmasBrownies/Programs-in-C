// 2025 Joel Tann

#include <stdio.h>

int shape (int x, int y, int z)
{
    if (x == y && y == z)
    {
        printf("equilateral ");
    }
    else if (x != y && x != z && y != z)
    {
        printf("scalene ");
    }
    else
    {
        printf("isosceles ");
    }
}

int angle (int x, int y, int z)
{
    if (x*x == (y*y + z*z) || y*y == (x*x + z*z) || z*z == (x*x + y*y))
    {
        printf("right\n");
    }
    else if (x*x > (y*y + z*z) || y*y > (x*x + z*z) || z*z > (x*x + y*y))
    {
        printf("obtuse\n");
    }
    else
    {
        printf("acute\n");
    }
}

int main()
{
    int num1, num2, num3 = 0;
    while (scanf("%d %d %d", &num1, &num2, &num3) == 3)
    {
        if((num1 + num2) <= num3 || (num1 + num3) <= num2 || (num3 + num2) <= num1)
        {
            printf("impossible\n");
        }
        else {
            shape (num1, num2, num3);
            angle (num1, num2, num3);
        }
    }
    return 0;
}