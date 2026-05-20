// 2026 Joel Tann
#ifndef BOYER_MOORE_H
#define BOYER_MOORE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int boyer_moore(char *text, char *pat);

void create_bad_char_tabel(int *bad_char, char *pat, int patlen);

void suffix(char *pat, int *suff, int patlen);

void create_good_shift_tabel(int *good_st, char *pat, int patlen);

int max(int good, int bad);

int brute_force(char *text, char *pat);

#endif // BOYER_MOORE_H