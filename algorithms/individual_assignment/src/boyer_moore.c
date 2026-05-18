// 2026 Joel Tann

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* int boyer_moore(char *text, char *pat) // add op counter
{
    int textlen = strlen(text);
    int patlen = strlen(pat);

    int *good_st = malloc(patlen * sizeof(*good_st));
    for (int i = 0; i < patlen; i++)
    {
        good_st[i] = patlen;
    }

    int bad_st[127];

    create_bad_shift_tabel(bad_st, pat, patlen);
    create_good_shift_tabel(good_st, pat, patlen);

    int i = patlen;

    while (i <= textlen)
    {
        int j = patlen;

        while (1) // Loops until we either get a missmatch or the enitire pattern matches
        {
            if (j == 0) { // That pattern matches
                return i+1;
            }
    
            if (text[i] == pat[j]) { // Char match. Reduce by 1 to check next char
                j--;
                i--;
            } 
            else { // Char did not match
                break;
            }
        }
        i = i + max(bad_st[text[i]], good_st[j]);
    }

    free(good_st);

    return -1;
} */

int brute_force(char *text, char *pat);

void create_bad_shift_tabel(int *bad_st, char *pat, int patlen);

void suffix(char *pat, int *suff, int patlen)
{
    suff[patlen-1] = patlen;

    for (int i = patlen-2; i >= 0; i--)
    {
        int k = patlen-1;
        int j = i;
        int len = 0;

        while (len <= i && pat[j] == pat[k])
        {
            j--;
            k--;
            len++;
        }
        suff[i] = len;
    }
}

int max(int good, int bad)
{
    if (good > bad) {
        return good;
    }

    return bad;
}

void create_good_shift_tabel(int *good_st, char *pat, int patlen)
{
    int *suff = malloc(patlen * sizeof(*suff));

    suffix(pat, suff, patlen);
    
    for (int i = (patlen-1); i >= 0; i--)
    {
        if (suff[i] == i + 1) { // Check for border case
            for (int j = 0; j < patlen - 1 - i; j++)
            {
                if (good_st[j] == patlen) { // Good_st has not been assigned a value yet
                    good_st[j] = patlen - 1 - i;
                }
            }
        }
    }
    for (int i = 0; i < patlen - 1; i++)
    {
        good_st[patlen - 1 - suff[i]] = patlen - 1 - i;
    }
    printf("suff: ");
    for (int i = 0; i < patlen; i++)
    {
        printf("%d ", suff[i]);
    }
    printf("\n");

    free (suff);
}


int main()
{
    char pat[8] = "abcdabc";
    int patlen = 7;
    int good_st[7];

    for (int i = 0; i < patlen; i++)
    {
        good_st[i] = patlen;
    }

    create_good_shift_tabel(good_st, pat, patlen);

    for ( int i = 0; i < patlen; i++)
    {
        printf("%d ", good_st[i]);
    }
}