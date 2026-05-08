// 2026 Joel Tann

#include <stdio.h>
#define MAX 7

void atm(int array[], const int values[], int num);

int main()
{
    int array[MAX];
    const int values[MAX] = {100, 50, 20, 10, 5, 2, 1};
    int num = 0;
    
    while(scanf("%d", &num) == 1)
    {
        int first = 1;
        atm(array, values, num);
        for (int i = 0; i <= 6; i++)
        {
            if (array[i] > 0)
            {
                if (!first) printf(" ");
                first = 0;
                printf("%dx%d", array[i], values[i]);
            }
        }
        printf("\n");
    }

    return 0;
}

void atm(int array[], const int values[], int num)
{
    for (int i = 0; i <= 6; i++)
    {
        array[i] = num / values[i];
        num -= array[i] * values[i];
    }
}