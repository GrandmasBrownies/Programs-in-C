// 2026 Joel Tann

#include <stdio.h>
#include <string.h>

int main()
{
    int size = 0;

    while (scanf("%d", &size) == 1)
    {
        int x = 0;
        
        while (x < size)
        {
            char word[101] = {'\0'};
            char newword[101] = {'\0'};
            scanf("%s", word);

            int j = 0;

            for (int i = 0; word[i] != '\0'; i++)
            {
                if (word[i] != word[i+1]) {
                    if (word[i+1] == '\0') {
                        newword[i+1] = '\0';
                    }
                    newword[j] = word[i];
                    j++;
                }
            }

            j = 0;
            char newword2[101] = {'\0'};

            for (int i = 0; newword[i] != '\0'; i++)
            {
                if (i != 0 && newword[i+1] != '\0' && (newword[i] == 'a' || newword[i] == 'e' || newword[i] == 'i' || newword[i] == 'o' || newword[i] == 'u')) {
                    continue;
                }
                else {
                    if (newword[i+1] == '\0') {
                        newword2[j+1] = '\0';
                    }
                    newword2[j] = newword[i];
                    j++;
                }
            }
            if (x+1 < size) {
                printf("%s ", newword2);
            } else {
                printf("%s\n", newword2);
            }
            x++;
        }
    }
}