// 2025 Joel Tann

#include <stdio.h>

int seq (int x, int y)
{
    while (x <= y)
    {
        printf("%d\n", x);
        x++;
    }
}

int main()
{
    int num1, num2 = 0;
    scanf("%d %d", &num1, &num2);
    seq (num1, num2);
    return 0;
}