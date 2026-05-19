// 2026 Joel Tann

int brute_force(char *text, char *pat)
{
    int patlen = strlen(pat);
    int textlen = strlen(text);

    int i = patlen;

    while (i <= textlen)
    {
        int j = patlen;
        int k = i;

        while (1)
        {
            if (j == 0) {
                return i+1;
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