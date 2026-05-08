// 2025 Joel Tann

#include <stdio.h>
#include <stdlib.h>

char *strange(char s, char e);

int main()
{
    char first[2], second[2];
    while (scanf("%s %s", first, second) == 2)
    {
        char *result = strange(first[0], second[0]);
        if (result == NULL) {
            return 1;
        }
        printf("%s\n", result);

        free(result);
    }
    return 0;
}

char *strange(char s, char e)
{

    char *string = malloc((e - s + 2) * sizeof(char));

    for (int i = 0; i < (e - s + 1); i++)
    {
        string[i] = s+i;
    }
    string[e-s+1] = '\0';
    return string;
}