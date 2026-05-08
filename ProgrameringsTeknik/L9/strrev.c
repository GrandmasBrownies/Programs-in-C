// 2025 Joel Tann

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 61

int size(const char str[]);
char *strreverse(const char *s);

int main()
{
    char string[MAX];
    while (scanf("%60s", string) == 1)
    {
        char *rev = strreverse(string);
        if (rev == NULL) return 1;

        printf("The reverse of \"%s\" is \"%s\".\n", string, rev);

        free(rev);
    }

    return 0;
}

int size(const char str[])
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

char *strreverse(const char *s)
{
    int sz = size(s);
    char *newstring = malloc(sz * sizeof(char));
    if (newstring == NULL) return NULL;
    strcpy(newstring, s);
    for (int i = 0; i < sz; i++)
    {
        newstring[i] = s[sz - 1 - i];
    }
    return newstring;
}