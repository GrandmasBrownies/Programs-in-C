// 2026 Joel Tann

#include <stdio.h>
#include <string.h>

#define MAX_PATTERN_LENGTH 101

int main()
{
    int choice_ = 0;

    printf("Choice a text fromat to try your pattern on:\n");
    printf("(1) Your word as the first word in the text\n");
    printf("(2) Your word as the last word\n");
    printf("(3)\n");
    printf("(4)\n");
    printf("(5)\n");
    printf("(6)\n");

    char pattern[MAX_PATTERN_LENGTH];

    printf("Type pattern to search for:\n");
    scanf("%s", pattern);

    int pattern_length = strlen(pattern);

    int bad_st[127] = {pattern_length};
    int good_st[127] = {pattern_length};

    create_bad_shift_tabel(bad_st, pattern_length);
    create_good_shift_tabel(good_st, pattern_length);

    boyer_moore(good_st, bad_st);

    return 0;
}