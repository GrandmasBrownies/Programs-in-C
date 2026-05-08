// 2025 Joel Tann

#include <stdio.h>

int main()
{
    int num1, num2 = 0;
    scanf("%d %d", &num1, &num2);
    if (num1 < num2)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    return 0;
}