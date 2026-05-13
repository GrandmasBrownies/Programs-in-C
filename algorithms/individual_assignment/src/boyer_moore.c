// 2026 Joel Tann

void create_bad_shift_tabel(int *bad_st, char *pat);
void create_good_shift_tabel(int *good_st, char *pat);

int boyer_moore(char *text, char *pat, int *good_st, int *bad_st) // add op counter
{
    int textlen = strlen(text);
    int patlen = strlen(pat);
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
    return -1;
}

int brute_force(char *text, char *pat);

int max(int good, int bad)
{
    if (good > bad) {
        return good;
    }

    return bad;
}
