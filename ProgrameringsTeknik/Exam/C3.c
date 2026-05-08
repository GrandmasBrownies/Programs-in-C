#include <stdio.h>

int main()
{
    float c = 0;

    while (scanf("%f", &c) == 1)
    {
        float f = (c * (9.0/5.0)) + 32;
        printf("%.1f\n", f);
    }
    return 0;
}