// 2025 Joel Tann

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *pfile = NULL;
    pfile = fopen("message.txt", "w");
    if (!pfile) {
        exit(1);
    }

    fprintf(pfile, "Hello file system.\n");
    fclose(pfile);
    printf("Created text file message.txt\n");

    return 0;
}