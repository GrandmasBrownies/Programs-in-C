#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 0;
    FILE *pfile = NULL;
    pfile = fopen("message.txt", "w");

    if(!pfile)
    {
        fprintf(stderr, "error: could not open file!\n");
        exit(1);
    }

    scanf("%d", &x);

    fprintf(pfile, "%d", x);

    fclose(pfile);
    return 0;
}