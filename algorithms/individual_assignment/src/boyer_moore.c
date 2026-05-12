// 2026 Joel Tann

void create_bad_shift_tabel(int *bad_st, int pattern_length);
void create_good_shift_tabel(int *good_st, int pattern_length);

int max(int good, int bad)
{
    if (good > bad) {
        return good;
    }

    return bad;
}
