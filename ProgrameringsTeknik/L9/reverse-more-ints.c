// 2025 Joel Tann

#include <stdio.h>
#include <stdlib.h>

int *reverse(int arr[], size_t size);

int main()
{
    size_t size = 0;
    while (scanf("%zu", &size) != EOF)
    {
        if (size == 0) {
            return 0;
        }
        int *arr = malloc(size * sizeof(int));
        if (arr == NULL)
        {
            printf("out of memory\n");
            return 1;
        }
        for (size_t i = 0; i < size; i++)
        {
            scanf("%d", &arr[i]);
        }
    
        int *rev = reverse(arr, size);
        if (rev == NULL)
        {
            printf("out of memory\n");
            return 1;
        }

        printf("reverse:");
        for (size_t i = 0; i < size; i++)
        {
            printf(" %d", rev[i]);
        }
        printf("\n");
        free(arr);
        free(rev);
    }

    return 0;
}

int *reverse(int arr[], size_t size)
{
    int *newarr = malloc(size * sizeof(int));
    if (newarr == NULL) return NULL;

    for (size_t i = 0; i < size; i++)
    {
        newarr[i] = arr[size - 1 - i];
    }

    return newarr;
}