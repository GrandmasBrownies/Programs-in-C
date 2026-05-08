// 2026 Joel Tann

#include <stdio.h>
#include <string.h>
#define MAX 10000

int main()
{
    int num = 0;
    while (scanf("%d", &num) == 1)
    {
        char string[MAX] = "\0";
        char hash[MAX] = "#";
        for (int i = 0; i < num; i++)
        {
            char space[MAX] = " ";
            for (int j = (num - 1); (j - i) > 1; j--)
            {
                sprintf(space, " %s", space);
            }
            if (i+1 == num) {
                printf("%s\n", hash);
                break;
            }
            sprintf(string, "%s%s", space, hash);
            sprintf(hash, "#%s#", hash);
            printf("%s\n", string);
        }
    }
    return 0;
}