// 2025 Joel Tann

#include <stdio.h>

int main()
{
    int num = 0;

    while (scanf("%d", &num) == 1)
    {
        while (num > 0)
        {
            printf("%d\n", num--);
        }
        printf("Go!\n");
    }
    return 0;
}