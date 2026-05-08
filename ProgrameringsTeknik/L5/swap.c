// 2025 Joel Tann

#include <stdio.h>

int main ()
{
    char str[31];
    int num = 0;

    while (scanf("%d %30s", &num, str) == 2)
    {
        printf("%s %d\n", str, num);
    }
    return 0;
}