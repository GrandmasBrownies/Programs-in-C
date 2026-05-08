// 2026 Group 10: Joel Tann, Isak Johnson

#include "sorting.h"

void selection_sort(unsigned int *array, unsigned int size, unsigned long long int *op)
{
    for (int i = 0; i < size-2; i++)
    {
        int min = i;
        for (int j = i+1; j < size-1; j++)
        {
            (*op)++;
            if (array[j] < array[min]) { // find smallest
                min = j;
            }
        }
        // swap
        int temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}

void insertion_sort(unsigned int *array, unsigned int size, unsigned long long int *op)
{
    for (int i = 1; i < size; i++){
        unsigned int key = array[i];
        int j = i - 1;

        while (j >= 0) {
            (*op)++;
            if (array[j] > key) {
                array[j + 1] = array[j];
                j = j - 1;
            } else {
                break;
            }
        }
        array[j + 1] = key;
    }
}

void merge_sort(unsigned int *a, unsigned int size, unsigned long long int *op)
{
    unsigned int half = size / 2;

    unsigned int *b = malloc(half * sizeof *b);
    unsigned int *c = malloc((size - half) * sizeof *c);

    if (!b || !c) {
        printf("No free memory\n");
        exit (-1);
    }
    
    if (size > 1)
    {
        memcpy(b, a, half * sizeof *a);
        memcpy(c, a + half, (size - half) * sizeof *a);
        merge_sort(b, half, op);
        merge_sort(c, size - half, op);

        unsigned int i = 0; // b counter
        unsigned int j = 0; // c counter
        unsigned int k = 0; // a counter

        while (i < half && j < (size - half))
        {
            if (b[i] <= c[j]) {
                a[k] = b[i++];
            } else {
                a[k] = c[j++];
            }
            k++;
            (*op)++;
        }

        if (i == half) {
            memcpy(a + k, c + j, (size - half - j) * sizeof *a);
        } else {
            memcpy(a + k, b + i, (half - i) * sizeof *a);
        }
    }

    free (b);
    free (c);
}