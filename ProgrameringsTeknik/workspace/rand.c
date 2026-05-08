#include <stdio.h>
#include <stdlib.h>

int main()
{
    for (int i = 1; i < 10; i++)
    {
        int num = 1 + rand() % 6;
        printf("%d\n", num);
    }
    return 0;
}