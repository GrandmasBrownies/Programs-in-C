#ifndef SORTING_H
#define SORTING_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void selection_sort(unsigned int *array, unsigned int size, unsigned long long int *op);
void insertion_sort(unsigned int *array, unsigned int size, unsigned long long int *op);
void merge_sort(unsigned int *a, unsigned int size, unsigned long long int *op);

#endif // SORTING_H