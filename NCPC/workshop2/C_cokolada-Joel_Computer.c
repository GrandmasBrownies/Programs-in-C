// 2026 Joel Tann

#include <stdio.h>

int main()
{
    int input = 0;

    while (scanf("%d", &input) == 1)
    {
        int chocolate_size = 1;

        while (chocolate_size < input) {
            chocolate_size *= 2;
        }

        int leftover = chocolate_size - input;
        int cuts = 0;

        int chocolate_size_copy = chocolate_size;

        if ((leftover % 2) == 1) {
            while (chocolate_size_copy != 1) {
                chocolate_size_copy /= 2;
                cuts++;
            }
        }
        else {
            while (chocolate_size_copy > input) {
                chocolate_size_copy /= 2;
                cuts++;
            }
            while (chocolate_size_copy >= 1 && chocolate_size_copy != input) {
                input = leftover - chocolate_size_copy;
                chocolate_size_copy /= 2;
                cuts++;
            }
        }
        
        printf("%d %d\n", chocolate_size, cuts);
    }
}