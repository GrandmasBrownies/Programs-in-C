// 2026 Joel Tann

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    int position = boyer_moore(text, pat); // add op counter

    if (position >= 0) {
        printf("Found match at text[%d]\n", position);
    }
    else {
        printf("Could not find pattern in text\n");
    }

    return 0;
}