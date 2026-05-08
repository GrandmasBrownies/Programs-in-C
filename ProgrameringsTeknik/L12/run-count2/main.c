// 2026 Joel Tann

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 0;
    int y = 0;
    FILE *pfile = NULL;

    pfile = fopen("runcount2.txt", "r");
    if (!pfile) {
        exit(1);
    }

    fscanf(pfile, "%d", &x);
    fscanf(pfile, "\n\n%d", &y);
    if (y == 1) {
        printf("Could read\n");
    }
    fclose(pfile);

    x++;

    pfile = fopen("runcount2.txt", "w");
    if (!pfile) {
        exit(1);
    }

    fprintf(pfile, "%d\n", x);
    fclose(pfile);

    printf("run #%d\n", x);

    return 0;
}