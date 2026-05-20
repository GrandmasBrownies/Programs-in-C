// 2026 Joel Tann

#include "include/input_gen.h"

void char_not_in_pat(int textlen, int patlen, char *text, char *pat)
{
    srand(time(NULL)); // Seed to make sure you get different numbers every time

    for (int i = 0; i < textlen; i++)
    {
        char c = (rand() % 95) + 32; // char in ascii tabel between 32-126

        for (int j = 0; j < patlen; j++) // make sure text characters are not part of pattern characters
        {
            if (c == pat[j]) {
                c = (rand() % 95) + 32; // get new char
                j = -1; // make loop run agian
            }
        }
        text[i] = c;
    }
}

void random(int textlen, int patlen, char *text, char *pat)
{
    srand(time(NULL)); // Seed to make sure you get different numbers every time

    for (int i = 0; i < textlen; i++)
    {
        char c = (rand() % 95) + 32; // char in ascii tabel between 32-126

        text[i] = c;
        if (c == pat[patlen-1]) { // To make sure pattern is not found in generated text
            while (1)
            {
                int j = patlen - 1;
                int k = i;

                if (j == 0) {
                    i--; // Go back
                    break;
                }

                if (k >= 0 && pat[j] == text[k]) {
                    j--;
                    k--;
                }
                else { // patern was not found in text. Move on
                    break;
                }
            }
        }
    }
}

void char_in_pat(int textlen, int patlen, char *text, char *pat)
{
    srand(time(NULL)); // Seed to make sure you get different numbers every time

    for (int i = 0; i < textlen; i++)
    {
        int something = rand() % patlen;

        char c = pat[something];

        text[i] = c;
        if (c == pat[patlen-1]) { // To make sure pattern is not found in generated text
            while (1)
            {
                int j = patlen - 2;
                int k = i - 1;

                if (j == 0) {
                    i--; // Go back
                    break;
                }

                if (k >= 0 && pat[j] == text[k]) {
                    j--;
                    k--;
                }
                else { // patern was not found in text. Move on
                    break;
                }
            }
        }
    }
}