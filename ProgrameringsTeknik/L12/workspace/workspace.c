#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 0;
    FILE *pfile = NULL;

    pfile = fopen("message.txt", "r");

    if (!pfile) {
        fprintf(stderr, "error: could not open file!\n");
        exit(1);
    }

    fscanf(pfile, "%d", &x);

    printf("what you wrote to the file: %d\n", x);

    fclose(pfile);

    return 0;
}