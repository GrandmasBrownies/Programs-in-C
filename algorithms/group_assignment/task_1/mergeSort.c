// 2026 Group 10: Joel Tann, Isak Johnson

#include <stdlib.h>

void merge_sort(unsigned int *a, unsigned int size)
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
        merge_sort(b, half);
        merge_sort(c, size - half);
        merge(b, c, a, size);
    }

    free (b);
    free (c);
}

void merge(unsigned int *b, unsigned int *c, unsigned int *a, unsigned int size)
{
    unsigned int half = size / 2;

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
    }

    if (i == half) {
        memcpy(a + k, c + j, (size - half - j) * sizeof *a);
    } else {
        memcpy(a + k, b + i, (half - i) * sizeof *a);
    }
}