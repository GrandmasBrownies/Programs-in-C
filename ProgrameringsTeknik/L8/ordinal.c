// 2025 Joel Tann

#include <stdio.h>
#define MAX 60

char* ordinal(int x, char buffer[]);
char* suffix(int n);

int main()
{
    int num = 0;
    char buffer[60];

    while (scanf("%d", &num) == 1)
    {
        ordinal(num, buffer);
        printf("%s\n", buffer);
    }
}

char* ordinal(int x, char buffer[])
{
    char* suf = suffix(x);
    sprintf(buffer, "%d%s", x, suf);
    return buffer;
}

char* suffix(int n)
{
    switch (n)
    {
        case 11:
            return "th";
            break;
        case 12:
            return "th";
            break;
        case 13:
            return "th";
            break;
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