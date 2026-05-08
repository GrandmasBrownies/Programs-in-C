// 2025 Joel Tann

#include <stdio.h>

int main()
{
    int time = 0;

    while (scanf("%d", &time) == 1)
    {
        if (time >= 4 && 11 >= time)
        {
            printf("Good morning\n");
        }
        else if (time >= 12 && 17 >= time)
        {
            printf("Good afternoon\n");
        }
        else if (time >= 18 && 23 >= time)
        {
            printf("Good evening\n");
        }
        else {
            printf("Hi\n");
        }
    }
    return 0;
}