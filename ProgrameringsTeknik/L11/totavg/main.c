// 2025 Joel Tann

#include "totavg.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size = 0; //Wanted to make into size_t but encounterd problems with the other files

    while (scanf("%d", &size) == 1)
    {
        double *arr = malloc(size * sizeof(double));
        for (size_t i = 0; i < size; i++)
        {
            scanf("%lf", &arr[i]);
        }

        printf("total %.1lf\n", total(arr, size));
        printf("average %.1lf\n", average(arr, size));
        free(arr);
    }
    return 0;
}