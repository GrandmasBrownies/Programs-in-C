// 2025 Joel Tann

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char name[62];
    FILE *pfile = NULL;
    pfile = fopen("name.txt", "r");

    if (!pfile)
    {
        fprintf(stderr, "name.txt: file not found\n");
        exit(1);
    }

    fscanf(pfile, "%61s", name);
    printf("%s\n", name);

    fclose(pfile);

    return 0;
}