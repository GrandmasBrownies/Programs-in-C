// 2025 Joel Tann

#include <stdio.h>

void triple_pointer(int *ptr_num);

int main()
{
    int num = 0;

    while (scanf("%d", &num) == 1)
    {
        triple_pointer(&num);
        printf("%d\n", num);
    }
}

void triple_pointer(int *ptr_num)
{
    *ptr_num *= 3;
}