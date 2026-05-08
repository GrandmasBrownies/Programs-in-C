// 2026 Joel Tann

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 300001

int charvalue(char c);
int *convertingromans(char **array, int size);

int main()
{
    int size = 0;
    while (scanf("%d", &size) == 1)
    {
        char **lines = malloc(sizeof(*lines) * size);
        char buffer[MAX];
        for (int i = 0; i < size; i++)
        {
            scanf("%300000s", buffer);
            lines[i] = malloc(strlen(buffer)+1);
            strcpy(lines[i], buffer);
        }
        int *results = convertingromans(lines, size);
        for (int i = 0; i < size; i++)
        {
            printf("%d\n", results[i]);
            free (lines[i]);
        }
        free (lines);
        free (results);
    }
    return 0;
}

int charvalue(char c)
{
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: exit (1);
    }
}

int *convertingromans(char **array, int size)
{
    int *result = malloc(sizeof(int) * size);
    int *values;
    for (int i = 0; i < size; i++)
    {
        int string_length = strlen(array[i]);
        values = malloc(sizeof(int) * (string_length+1));
        result[i] = 0;
        // Make array of all Roman Char Values
        for (int j = 0; array[i][j] != '\0'; j++)
        {
            values[j] = charvalue(array[i][j]);
        }
        // Calculate result
        int u = 0;
        for (int j = string_length-1; j >= 0; j--)
        {
            result[i] += values[j];
            if (values[j] > values[j-1]) {
                for (u = j-1; values[u] < values[j] && u >= 0; u--)
                {
                    result[i] -= values[u];
                }
                j = u+1;
            }
        }
        free (values);
    }

    return result;
}