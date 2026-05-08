// 2025 Joel Tann

#include <stdio.h>

int main()
{
    int num = 0;
    while (scanf("%d", &num) == 1)
    {
        if (4 <= num && num <= 11)
        {
            printf("Good morning\n");
        }
        else if (12 <= num && num <= 17)
        {
            printf("Good afternoon\n");
        }
        else if (18 <= num && num <= 23)
        {
            printf("Good evening\n");
        }
        else
        {
            printf("Hi\n");
        }
    }
    return 0;
}