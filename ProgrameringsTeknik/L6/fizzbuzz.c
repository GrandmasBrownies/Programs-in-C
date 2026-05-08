// 2025 Joel Tann

#include <stdio.h>

int fizz(int x)
{
    for (int i = 1; i <= x; i++)
    {
        if (i % 15 == 0)
        {
            printf("FizzBuzz\n");
        }
        else if (i % 5 == 0)
        {
            printf("Buzz\n");
        }
        else if (i % 3 == 0)
        {
            printf("Fizz\n");
        } 
        else 
        {
            printf("%d\n", i);
        }
    }
    return 0;
}

int main()
{
    int num = 0;

    while(scanf("%d", &num) == 1)
    {
        fizz (num);
    }
    return 0;
}