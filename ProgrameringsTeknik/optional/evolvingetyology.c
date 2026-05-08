// 2025 Joel Tann

#include <stdio.h>
#include <string.h>

int main()
{
    size_t n = 0;
    int k = 0;

    while (scanf("%zu %d", &n, &k) == 2)
    {
        char firstword[n+1];
        char newword[n+1];
        char currentword[n+1];
        scanf("%s", currentword);
        strcpy(firstword, currentword);
        for (int count = 0; count < k; count++)
        {
            for (int i = 0; i < n; i++)
            {
                newword[i] = currentword[(i*2) % n];
            }
            if (strcmp(newword, firstword) == 0 || strcmp(newword, currentword) == 0) {
                k %= count+1;
                count = -1;
            }
            newword[n] = '\0';
            strcpy(currentword, newword);
        }
        printf("%s\n", currentword);
    }
    return 0;
}