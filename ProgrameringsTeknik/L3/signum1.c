// 2025 Joel Tann

#include <stdio.h>

int main()
{
    int num = 0;
    scanf("%d", &num);
    if(num < 0)
    {
        printf("negative\n");
    }
    else if(num > 0)
    {
        printf("positive\n");
    }
    else
    {
        printf("zero\n");
    }
}