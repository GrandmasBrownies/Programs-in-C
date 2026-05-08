// 2025 Joel Tann

#include <stdio.h>

int inc (int x)
{
    return x+=1;
}

int main()
{
    int x = 0;
    scanf("%d", &x);
    printf("%d\n", inc(x));
}