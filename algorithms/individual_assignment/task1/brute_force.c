// 2026 Joel Tann

int brute_force(char *text, char *pat, int textlen, int patlen)
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