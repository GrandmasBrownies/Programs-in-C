// 2026 Joel Tann

int boyer_moore(char *text, char *pat) // add op counter
{
    int textlen = strlen(text);
    int patlen = strlen(pat);

    int *good_st = malloc(patlen * sizeof(*good_st));
    *good_st = patlen;

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
}

int brute_force(char *text, char *pat);

void create_bad_shift_tabel(int *bad_st, char *pat, int patlen);

void create_good_shift_tabel(int *good_st, char *pat, int patlen)
{
    int suff[patlen];

    suffix(pat, suff, patlen);
    
    for (int j = 0; j < patlen-1; j++)
    {
        if (suff[j] > 0) {
            good_st[patlen - 1 - suff[j]] = patlen - 1 - j;
        }
        else {
            for (int k = patlen-1; k >= j; k--)
            {
                int l = j-1;
                if (pat[l] == pat[k]) {
                    while (l >= 0) {
                        l--;
                        k--;
                        if ()
                    }
                }
            }
        }
    }
}



void suffix(char *pat, int *suff, int patlen)
{
    suff[patlen-1] = patlen;

    for (int i = patlen-2; i >= 0; i--)
    {
        if (pat[i] != pat[patlen-1]) {
            suff[i] = 0;
        }

    }
}

int max(int good, int bad)
{
    if (good > bad) {
        return good;
    }

    return bad;
}
