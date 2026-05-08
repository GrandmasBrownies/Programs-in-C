// 2026 Joel Tann

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 101

void rotletters(char words[MAX][MAX], const int word_size, const int k);
int stringcmp(const char s1[], const char s2[]);

int main(int argc, char *argv[])
{
    char lines[MAX][MAX];
    char words[MAX][MAX];
    size_t line_size = 0;
    size_t word_size = 0;

    while (fgets(lines[line_size], MAX, stdin) != NULL)
    {
        char temp[MAX];
        strcpy(temp, lines[line_size++]);
        char *token = strtok(temp, " \n");
        while (token != NULL) {
            strcpy(words[word_size++], token);
            token = strtok(NULL, " \n");
        }
    }

    int k = -1;
    int highest_match = 0;
    for (int i = 0; i < 26; i++)
    {
        int wordmatch = 0;
        for (int h = 1; argc > h; h++)
        {
            for (int j = 0; word_size > j; j++)
            {
                if (stringcmp(words[j], argv[h]) == 0) {
                    ++wordmatch;
                }
            }
        }
        if (wordmatch > highest_match) {
            highest_match = wordmatch;
            k = i;
        }
        rotletters(words, word_size, 1);
    }
    if (k < 0) {
        fprintf(stderr, "could not decrypt\n");
        exit (1);
    } else {
        fprintf(stderr, "encryption key: %d\n", 26-k);
        rotletters(lines, line_size, k);
        for (size_t i = 0; i < line_size; i++)
        {
            printf("%s", lines[i]);
        }
    }
    return 0;
}

void rotletters(char array[MAX][MAX], const int size, const int k)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; array[i][j] != '\0'; j++)
        {
            if ((array[i][j] <= 'z' && array[i][j] >= 'a') || 
                (array[i][j] <= 'Z' && array[i][j] >= 'A'))
            {
                if ((array[i][j] <= 'Z' && array[i][j] + k > 'Z') || array[i][j] + k > 'z') {
                    array[i][j] = array[i][j] - 26 + k;
                } else {
                    array[i][j] += k;
                }
            }
        }
    }
}

int stringcmp(const char s1[], const char s2[])
{
    int j = -1;
    for (size_t i = 0; s1[i] != '\0'; i++)
    {
        j++;
        if (ispunct(s1[i])) {
            j--;
            continue;
        }
        if (s2[j] == '\0' || (s1[i+1] == '\0' && s2[j+1] != '\0')) {
            return 1;
        }
        if (isupper(s1[i])) {
            if (s1[i] != toupper(s2[j])) {
                return 1;
            }
            continue;
        }
        if (s1[i] != s2[j]) {
            return 1;
        }
    }
    return 0;
}