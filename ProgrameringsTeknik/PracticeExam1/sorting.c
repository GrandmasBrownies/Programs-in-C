// 2025 Joel Tann

#include <stdio.h>
#define MAX 10000


void sort(int arr[], int size);


int main()
{
    int a[MAX];
    int n = 0;
    int i;
    char c;
    while (scanf("%d%c",&a[n++],&c)==2) {
        if (c == ' ')
            continue;
        sort(a, n);
        for (i=0; i<n; i++)
            printf("%s%d", i?" ":"", a[i]);
        printf("\n");
        n = 0;
    }
    return 0;
}


// The sort function puts the elements of the given array in order.
//
// The first argument is a pointer to the starting element of the array.
// The second argument indicates the number of elements in the array.
void sort(int arr[], int size)
{
    int holder = 0;
    while (size > 1)
    {
        for (int i = 0; i < size-1; i++)
        {
            if (arr[i] > arr[i+1])
            {
                holder = arr[i+1];
                arr[i+1] = arr[i];
                arr[i] = holder;
            }
        }
        size--;
    }
}