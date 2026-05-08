#include <stdio.h>
#define MAX 10000

int main()
{
    int n = 0;

    while (scanf("%d", &n) == 1)
    {
        char string[MAX] = {'\0'};
        for (int i = 1; i <= n; i++)
        {
            string[i-1] = 'e';
            if (i % 3 == 0)
            {
                printf("b%sp\n", string);
            }
            else {
                printf("%d\n", i);
            }
        }
    }
    return 0;
}