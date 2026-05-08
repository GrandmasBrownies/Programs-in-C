// 2025 Joel Tann

#include <stdio.h>

int countdown(int n)
{
    if (n > 0)
    {
        printf("%d\n", n);
        countdown (n-1);
    }
    else
    {
        printf("Go!\n");
    }
}


int main ()
{
    int num = 0;
    scanf("%d", &num);
    countdown (num);
    return 0;
}