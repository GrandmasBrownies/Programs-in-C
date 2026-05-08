// 2025 Joel Tann

#include <stdio.h>

int main()
{
    int num = 0;
    while(scanf("%d", &num) == 1)
    {
        if ((num % 2) == 0)
        {
            printf("even\n");
        } else {
            printf("odd\n");
        }
    }
    return 0;
}