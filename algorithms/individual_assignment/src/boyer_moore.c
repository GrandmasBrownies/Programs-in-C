// 2026 Joel Tann

void create_bad_shift_tabel(int *bad_st, int pattern_length);
void create_good_shift_tabel(int *good_st, int pattern_length);

void boyer_moore(char *text, char *pattern, int *bad_st, int *good_st); // add op counter

int max(int good, int bad)
{
    if (good > bad) {
        return good;
    }

    return bad;
}
