// 2025 Joel Tann

#include <stdio.h>

int inc (int x)
{
    return x += 1;
}

int main()
{
    int num = 0;

    while (scanf("%d", &num) == 1)
    {
        int result = inc (num);
        printf("%d\n", result);
    }
    return 0;
}