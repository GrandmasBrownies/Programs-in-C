// 2025 Joel Tann

#include <stdio.h>

int main()
{
    char word[61];
    int i = 0;

    while (scanf("%60s %d", word, &i) == 2)
    {
        printf("%c\n", word[i]);
    }
    return 0;
}