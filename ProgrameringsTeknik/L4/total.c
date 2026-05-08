// 2025 Joel Tann

#include <stdio.h>

int total(int n)
{
    int x = 0;
    scanf("%d", &x);
    if (n == 1)
    {
        return x;
    }
    else
    {
        return x + total (n-1);
    }
}

int main()
{
    int num = 0;
    scanf("%d", &num);
    int sum = total (num);
    printf("%d\n", sum);
    return 0;
}