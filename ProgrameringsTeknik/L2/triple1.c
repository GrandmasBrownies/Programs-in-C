// 2025 Joel Tann

#include <stdio.h>

int triple (int x)
{
    x*=3;
}

int main()
{
    int x, y =1;
    scanf("%d", &x);
    y = triple(x);
    printf("%d\n", y);
}