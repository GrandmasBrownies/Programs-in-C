// 2026 Joel Tann

#include "include/boyer_moore.h"

#define MAX_PATTERN_LENGTH 101

int main()
{
/*     int choice_ = 0;

    printf("Choice a text fromat to try your pattern on:\n");
    printf("(1) Your word as the first word in the text\n");
    printf("(2) Your word as the last word\n");
    printf("(3)\n");
    printf("(4)\n");
    printf("(5)\n");
    printf("(6)\n"); */

    char text[101] = {"Hello, my name is Jeff"}; // make input sizes for text

    
    printf("Type pattern to search for:\n");
    
    char pat[MAX_PATTERN_LENGTH];
    scanf("%s", pat); // pattern to search for in text

    int op = 0;

    int position = boyer_moore(text, pat, &op); // add op counter

    if (position >= 0) {
        printf("Found match at text[%d]\n", position);
    }
    else {
        printf("Could not find pattern in text\n");
    }

    FILE *pfile = NULL;
    
    pfile = fopen("output.txt", "a");
    if (!pfile) {
        printf("Could not write to file\n");
        fclose(pfile);
    }
    else {
        fprintf(pfile, "Algorithm: %s\n", alg_name);
        fprintf(pfile, "Input:     %s\n", order_name);
        fprintf(pfile, "Size n     %d\n", size);
        fprintf(pfile, "--------------------------------\n");
        fprintf(pfile, "256          %llu\n", op[0]);
        fprintf(pfile, "512          %llu\n", op[1]);
        fprintf(pfile, "1024         %llu\n", op[2]);
        fprintf(pfile, "2048         %llu\n", op[3]);
        fprintf(pfile, "4096         %llu\n", op[4]);
        fprintf(pfile, "8192         %llu\n", op[5]);
        fprintf(pfile, "16384        %llu\n", op[6]);
        fprintf(pfile, "32768        %llu\n\n", op[7]);
        fclose(pfile);
    }

    return 0;
}