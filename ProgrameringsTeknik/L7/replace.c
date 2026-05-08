// 2025 Joel Tann

#include <stdio.h>
#define MAX 61

int main()
{
    char word[MAX];
    char c;
    int index = 0;
    while (scanf("%60s %d %c", word, &index, &c) == 3)
    {
        word[index] = c;
        printf("%s\n", word);
    }
    return 0;
}