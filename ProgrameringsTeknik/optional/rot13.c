// 2026 Joel Tann

#include <stdio.h>
#include <stddef.h>
#define MAX 100

int main()
{
    char word[MAX];
    while (fgets(word, MAX, stdin) != NULL) {
        for (size_t i = 0; word[i] != '\0'; i++)
        {
            if ((word[i] <= 'z' && word[i] >= 'a') || 
                (word[i] <= 'Z' && word[i] >= 'A')) 
            {
                if ((word[i] <= 'z' && word[i] >= 'n') || (word[i] <= 'Z' && word[i] >= 'N')) {
                    word[i] += 13;
                }
                else {
                    word[i] -= 13;
                }
            }
        }
        printf("%s", word);
    }

    return 0;
}