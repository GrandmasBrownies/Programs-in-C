// 2025 Joel Tann

#include <stdio.h>
#include <string.h>

int main ()
{
    char prof[100];
    int age = 0;

    while (scanf("%99s %d", prof, &age) == 2)
    {
        if (age < 18 || age >= 65 || (strcmp(prof, "student") == 0 && age <= 25))
        {
            printf("discount\n");
        } else {
            printf("full price\n");
        }
    }
    return 0;
}