// 2025 Joel Tann

#include <stdio.h>
#include <string.h>
#define MAX 101

int count = 0;

int main()
{
    int stack[MAX];
    char word[6];
    char s;
    int num = 0;

    while (scanf("%5s%c", word, &s) == 2)
    {
        if (strcmp(word, "push") == 0 && s == ' ')
        {
            scanf("%d", &stack[count]);
            count++;
        }
        else if (strcmp(word, "pop") == 0)
        {
            if (count-1 < 0) {
                printf("empty\n");
                continue;
            }
            count--;
            printf("%d\n", stack[count]);
            stack[count] = '\0';
        }
    }
    return 0;
}