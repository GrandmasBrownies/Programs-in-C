// 2025 Joel Tann

#include "maxmin.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    size_t size = 0;

    while (scanf("%d", &size) == 1)
    {
        int *arr = malloc(size * sizeof(int));
        for (size_t i = 0; i < size; i++)
        {
            scanf("%d", &arr[i]);
        }

        printf("maximum %d\n", maximum(arr, size));
        printf("minimum %d\n", minimum(arr, size));

        free(arr);
    }
    return 0;
}