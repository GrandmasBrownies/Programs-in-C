// 2025 Joel Tann

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 0;
    scanf("%d", &x);
    if (x < 0) {
        exit(1);
    }
    else if (x >= 0) {
        exit(0);
    }

    return 0;
}