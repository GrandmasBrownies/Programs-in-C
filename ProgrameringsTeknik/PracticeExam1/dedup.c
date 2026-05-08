// 2025 Joel Tann

#include <stdio.h>
#define MAX 61

int main()
{
    char word[MAX];
    char newword[MAX];

    while (scanf("%60s", word) == 1)
    {
        for (int i = 0, u = 0; word[i] != '\0'; i++)
        {
            if (word[i] != word[i+1])
            {
                newword[u] = word[i];
                u++;
            }
            if (word[i+1] == '\0') {
                newword[u] = '\0';
            }
        }
        printf("%s\n", newword);
    }
    return 0;
}