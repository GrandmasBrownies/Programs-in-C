// 2026 Joel Tann

int boyer_moore(char *text, char *pat) // add op counter
{
    int textlen = strlen(text);
    int patlen = strlen(pat);

    int *good_st = malloc(patlen * sizeof(*good_st));
    for (int i = 0; i < patlen; i++)
    {
        good_st[i] = patlen;
    }

    int bad_char[127];

    create_bad_char_tabel(bad_char, pat, patlen);
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
        int bad_char_shift = max(1, j - bad_char[text[i+j]]);
        i += max(bad_char_shift, good_st[j]);
    }

    free(good_st);

    return -1;
}