#include <stdio.h>


// Maximum size of our array
#define MAX 100


// Computes the average of the given array
double average(double arr[], int sz);


int main()
{
    double array[MAX];
    int n;

    // scan the array, type numbers, finish with "end"
    for (n = 0; n < MAX && scanf("%lf", &array[n])==1; n++);

    // print the average
    printf("%d values read\n", n);
    printf("average: %.1lf\n", average(array, n));

    return 0;
}


double average(double arr[], int sz)
{
    // 2025 - Joel Tann
    double total = 0;
    for (int i = 0; i < sz; i++)
    {
        total += arr[i];
    }
    return total / sz;
}