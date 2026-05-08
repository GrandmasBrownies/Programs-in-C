// 2025 Joel Tann

#include <stdio.h>
#include <stdlib.h>

char *ordinal(int n);
char *suffix(int n);

int main()
{
    int n = 0;
    while (scanf("%d", &n) == 1)
    {
        char *result = ordinal(n);
        printf("%s\n", result);

        free(result);
    }
    return 0;
}

char *ordinal(int n)
{
    char *array = malloc(n * sizeof(char));
    char *suf = suffix(n);
    sprintf(array, "%d%s", n, suf);
    return array;
}

char *suffix(int n)
{
    if (n == 11 || n == 12 || n == 13)
    {
        return "th";
    }
    int mod = n % 10;
    switch (mod)
    {
        case 1:
            return "st";
            break;
        case 2:
            return "nd";
            break;
        case 3:
            return "rd";
            break;
        default:
            return "th";
    }

}