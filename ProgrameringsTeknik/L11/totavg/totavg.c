#include <stddef.h>

double total(double arr[], int n)
{
    double total = 0;
    for (size_t i = 0; i < n; i++)
    {
        total += arr[i];
    }
    return total;
}

double average(double arr[], int n)
{
    double total = 0;
    for (size_t i = 0; i < n; i++)
    {
        total += arr[i];
    }
    return total / n;
}