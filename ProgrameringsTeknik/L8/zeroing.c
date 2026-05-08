// 2025 Joel Tann

#include <stdio.h>

void zero_int(int *px);

int main()
{
    int num = 0;

    while (scanf("%d", &num) == 1)
    {
        printf("Before zeroing: %d\n", num);
        zero_int(&num);
        printf("After zeroing: %d\n", num);
    }
}

void zero_int(int *px)
{
    *px = 0;
}