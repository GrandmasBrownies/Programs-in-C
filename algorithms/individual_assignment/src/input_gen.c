// 2026 Joel Tann

#include "input_gen.h"

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
    text[textlen] = '\0';
}

void random(int textlen, int patlen, char *text, char *pat)
{
    srand(time(NULL)); // Seed to make sure you get different numbers every time

    for (int i = 0; i < textlen; i++)
    {
        char c = (rand() % 95) + 32; // char in ascii tabel between 32-126

        text[i] = c;
        if (c == pat[patlen-1]) { // To make sure pattern is not found in generated text
            int j = patlen - 2;
            int k = i - 1;

            while (1)
            {
                if (k >= 0 && pat[j] == text[k]) {
                    j--;
                    k--;
                }
                else { // patern was not found in text. Move on
                    break;
                }
                
                if (j < 0) {
                    i--; // Go back
                    break;
                }
            }
        }
    }
    text[textlen] = '\0';
}

void char_in_pat(int textlen, int patlen, char *text, char *pat)
{
    srand(time(NULL)); // Seed to make sure you get different numbers every time

    for (int i = 0; i < textlen; i++)
    {
        char c = pat[rand() % patlen];

        text[i] = c;
        if (c == pat[patlen-1]) { // To make sure pattern is not found in generated text
            int j = patlen - 2;
            int k = i - 1;

            while (1)
            {
                if (k >= 0 && pat[j] == text[k]) {
                    j--;
                    k--;
                }
                else { // patern was not found in text. Move on
                    break;
                }
                
                if (j < 0) {
                    i--; // Go back
                    break;
                }
            }
        }
    }
    text[textlen] = '\0';
}