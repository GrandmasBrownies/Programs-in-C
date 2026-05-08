// 2025 Joel Tann

#include <stdio.h>

int main ()
{
    char name[31];
    while (scanf("%30s", name) == 1)
    {
        printf("Hello, %s!\n", name);
    }
    return 0;

}