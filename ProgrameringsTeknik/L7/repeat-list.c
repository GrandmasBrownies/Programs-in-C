// 2025 Joel Tann

#include <stdio.h>
#define MAX 101

int main()
{
    int elements = 0;
    while (scanf("%d", &elements) == 1)
    {
        int array[MAX];
        for (int i = 0; i < elements; i++)
        {
            scanf("%d", &array[i]);  
        }

        printf("%d elements:", elements);
        for (int i = 0; i < elements; i++)
        {
            printf(" %d", array[i]);
        }
        printf("\n");
    }
    return 0;
}