// 2025 Joel Tann

#include <stdio.h>

int main ()
{
    char name[31];
    int age = 0;

    while (scanf("%30s %d", name, &age) == 2)
    {
        printf("%s is %d years old.\n", name, age);
    }
    return 0;
}