// 2025 Joel Tann

#include <stdio.h>
#include <string.h>

int main ()
{
    char str[10];

    while (scanf("%9s", str) == 1)
    {
        if (strcmp(str, "true") == 0)
        {
            printf("false\n");
        } else {
            printf("true\n");
        }
    }
    return 0;
}