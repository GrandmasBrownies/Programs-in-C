// 2026 Joel Tann

#ifndef INPUT_GEN
#define INPUT_GEN

#include <stdlib.h>
#include <string.h>
#include <time.h>

void char_not_in_pat(int textlen, int patlen, char *text, char *pat);
void random(int textlen, int patlen, char *text, char *pat);
void char_in_pat(int textlen, int patlen, char *text, char *pat);

#endif // INPUT_GEN