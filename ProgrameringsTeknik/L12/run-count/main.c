// 2025 Joel Tann

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 0;
    FILE *pfile = NULL;
    
    pfile = fopen("runcount.txt", "r");
    if (!pfile) {
        exit(1);
    }

    fscanf(pfile, "%d", &x);
    fclose(pfile);

    x++;

    pfile = fopen("runcount.txt", "w");
    if (!pfile) {
        exit(1);
    }
    
    fprintf(pfile, "%d\n", x);
    fclose(pfile);

    printf("run #%d\n", x);

    return 0;
}