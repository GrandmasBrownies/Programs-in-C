// 2026 Joel Tann

#include <stdio.h>

int gcd(int x, int y);

int main()
{
    int x = 0;
    int y = 0;
    while (scanf("%d %d", &x, &y) == 2)
    {
        printf("%d\n", gcd(x, y));
    }
    return 0;
}

int gcd(int x, int y)
{
    while (1)
    {
        int temp = 0;
        if (y == 0) {
            return x;
        } else if (x == 0) {
            return y;
        }
        if (x > y) 
        {
            if (x % y == 0) {
                return y;
            } else {
                temp = x;
                x = y;
                y = temp % y;
            }
        } 
        else 
        {
            if (y % x == 0) {
                return x;
            } else {
                temp = y;
                y = x;
                x = temp % x;
            }
        }
    }
}