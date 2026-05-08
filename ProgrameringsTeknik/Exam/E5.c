#include <stdio.h>
#define MAX 10000
 
void accum(int arr[], int size);
 
int main()
{
    int arr[MAX];
    int sz = 0;
    int i;
    char c;
    while (scanf("%d%c",&arr[sz++],&c)==2 && c==' ');
    accum(arr, sz);
    for (i=0; i<sz; i++)
        printf("%s%d", i?" ":"", arr[i]);
    printf("\n");
    return 0;
}
 
void accum(int arr[], int size)
{
    for (size_t i = size; i > 0; i--)
    {
        for (size_t j = 0; j < i; j++)
        {
            arr[i] += arr[j];
        }
    }
}