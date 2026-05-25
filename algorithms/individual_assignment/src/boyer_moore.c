// 2026 Joel Tann

#include "boyer_moore.h"

int boyer_moore(char *text, char *pat, int textlen, int patlen, unsigned int *op)
{
    int *good_st = malloc(patlen * sizeof(*good_st));
    for (int i = 0; i < patlen; i++)
    {
        good_st[i] = patlen;
    }

    int bad_char[128];

    create_bad_char_tabel(bad_char, pat, patlen);
    create_good_shift_tabel(good_st, pat, patlen);

    int i = patlen - 1;

    while (i < textlen)
    {
        int j = patlen - 1;
        int k = i;

        while (1) // Loops until we either get a missmatch or the enitire pattern matches
        {
            if (j < 0) { // That pattern matches
                free(good_st);
                return k + 1;
            }

            (*op)++;
            if (text[k] == pat[j]) { // Char match. Reduce by 1 to check next char
                j--;
                k--;
            } 
            else { // Char did not match
                break;
            }
        }
        int bad_char_shift = max(1, j - bad_char[text[k]]);
        i += max(bad_char_shift, good_st[j]);
    }

    free(good_st);

    return -1;
}

void create_bad_char_tabel(int *bad_char, char *pat, int patlen)
{
    for (int i = 0; i < 128; i++)
    {
        bad_char[i] = - 1;
    }

    for (int i = 0; i < patlen; i++)
    {
        bad_char[pat[i]] = i;
    }
}

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

    free (suff);
}

int max(int good, int bad)
{
    if (good > bad) {
        return good;
    }

    return bad;
}

int brute_force(char *text, char *pat, int textlen, int patlen, unsigned int *op)
{
    int i = patlen - 1;

    while (i < textlen)
    {
        int j = patlen - 1;
        int k = i;

        while (1)
        {
            if (j < 0) {
                return i + 1;
            }

            (*op)++;
            if (text[k] == pat[j]) {
                k--;
                j--;
            }
            else {
                break;
            }
        }
        i++;
    }
    return -1;
}