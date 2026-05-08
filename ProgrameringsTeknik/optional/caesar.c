// 2026 Joel Tann

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#define MAX 100

int main(int argc, char *argv[])
{
    int k = 13;
    if (argc > 1) {
        k = atoi(argv[1]);
        k %= 26;
    }
    char line[MAX];

    while (fgets(line, MAX, stdin) != NULL) {
        for (size_t i = 0; line[i] != '\0'; i++)
        {
            if ((line[i] <= 'z' && line[i] >= 'a') || 
                (line[i] <= 'Z' && line[i] >= 'A'))
            {
                if (k > 0)
                {
                    if ((line[i] <= 'Z' && line[i] + k > 'Z') || line[i] + k > 'z') {
                        line[i] = line[i] - 26 + k;
                    } else {
                        line[i] += k;
                    }
                } 
                else 
                {
                    if ((line[i] >= 'a' && line[i] + k < 'a') || line[i] + k < 'A') {
                        line[i] = line[i] + 26 + k;
                    } else {
                        line[i] += k;
                    }
                }
            }
        }
        printf("%s", line);
    }

    return 0;
}