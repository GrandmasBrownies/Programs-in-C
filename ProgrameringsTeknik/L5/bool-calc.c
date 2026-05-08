// 2025 Joel tann

#include <stdio.h>
#include <string.h>

void function(char *val1, char *op, char *val2)
{
    if (strcmp(op, "and") == 0)
    {
        if (strcmp(val1, "true") == 0 && strcmp(val2, "true") == 0)
        {
            printf("true\n");
        } else {
            printf("false\n");
        }
    }
    else if (strcmp(op, "or") == 0)
    {
        if (strcmp(val1, "true") == 0 || strcmp(val2, "true") == 0)
        {
            printf("true\n");
        } else {
            printf("false\n");
        }
    }
    else if (strcmp(op, "xor") == 0)
    {
        if ((strcmp(val1, "true") == 0 && strcmp(val2, "false") == 0) || (strcmp(val1, "false") == 0 && strcmp(val2, "true") == 0))
        {
            printf("true\n");
        } else {
            printf("false\n");
        }
    }
    else if (strcmp(op, "implies") == 0)
    {
        if (strcmp(val1, "true") == 0 && strcmp(val2, "false") == 0)
        {
            printf("false\n");
        } else {
            printf("true\n");
        }
    }
}

void not(char *val1)
{
    if (strcmp(val1, "true") == 0)
    {
        printf("false\n");
    } else {
        printf("true\n");
    }
}

int main ()
{
    char str1[10], str2[10];

    while (scanf("%9s %9s", str1, str2) == 2)
    {
        if (strcmp(str1, "not") == 0)
        {
            not (str2);
        } else {
            char str3[10];
            scanf("%9s", str3);
            function (str1, str2, str3);
        }
    }
    return 0;
}