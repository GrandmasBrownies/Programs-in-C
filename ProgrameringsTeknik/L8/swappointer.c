// 2025 Joel Tann

#include <stdio.h>

void swap(int *x, int *y);

int main()
{
    int num1 = 0;
    int num2 = 0;

    while (scanf("%d %d", &num1, &num2) == 2)
    {
        swap(&num1, &num2);
        printf("%d %d\n", num1, num2);
    }
    return 0;
}

void swap(int *x, int *y)
{
    int z = *x;
    *x = z;
    *x = *y;
    *y = z;
}