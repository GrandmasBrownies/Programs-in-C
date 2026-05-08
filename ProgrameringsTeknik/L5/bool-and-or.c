// 2025 Joel Tann

#include <stdio.h>
#include <string.h>

int main ()
{   
    char str1[10], o[10], str2[10];

    while (scanf("%9s %9s %9s", str1, o, str2) == 3)
    {
        if (strcmp(str1, "true") == 0 && strcmp(str2, "true") == 0  )
        {
            printf("true\n");
        }
        else if ((strcmp(o, "or") == 0 && strcmp(str1, "true") == 0) || (strcmp(o, "or") == 0 && strcmp(str2, "true") == 0))
        {
            printf("true\n");
        }
        else
        {
            printf("false\n");
        }
    }
    return 0;
}