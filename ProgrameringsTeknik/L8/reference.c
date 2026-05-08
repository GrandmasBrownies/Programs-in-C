#include <stdio.h>

void function(int *pointer);

int main()
{
    int i = 3;
    function(&i);
    printf("%d", i);

}

void function(int *pointer){
    *pointer = 12;

}