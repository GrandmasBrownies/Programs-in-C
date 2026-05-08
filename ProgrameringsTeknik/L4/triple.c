// 2025 Joel Tann

#include <stdio.h>

int triple(int x)
{
    return x*3;
}

int main()
{
    int num = 0;
    while (scanf("%d", &num) == 1)
    {
        int sum = triple (num);
        printf("%d\n", sum);
    }
    return 0;
}