#include <stdio.h>

int main()
{
    int x=12;
    int *pointer = &x;

    printf("%d\n", x);
    printf("%d\n", *pointer);

    *pointer = 60;
    printf("%d", x);

}