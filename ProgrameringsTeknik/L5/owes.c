// 2025 Joel Tann

#include <stdio.h>

int main ()
{
    float amount = 0;
    char name1[31], name2[31];

    while(scanf("%f %30s %30s", &amount, name1, name2) == 3)
    {
        printf("%s owes $%.2f dollars to %s.\n", name1, amount, name2);
    }
}