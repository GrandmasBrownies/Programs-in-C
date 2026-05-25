// 2026 Joel Tann

int boyer_moore(char *text, char *pat, int textlen, int patlen)
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