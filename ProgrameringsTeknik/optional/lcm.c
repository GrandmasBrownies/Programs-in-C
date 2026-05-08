// 2026 Joel Tann

#include <stdio.h>

int lcm(int x, int y);
int gcd(int x, int y);


int main()
{
    int m = 0;
    int n = 0;

    while (scanf("%d %d", &m, &n) == 2)
    {
        printf("%d\n", lcm(m, n));
    }
    return 0;
}

int gcd(int x, int y)
{
    while (1)
    {
        int temp = 0;
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

int lcm(int x, int y)
{
    int result = 1;
    int z = 0;
    while (z != 1)
    {
        z = gcd(x, y);
        result *= z;
        x /= z;
        y /= z;
    }
    result *= x * y;
    return result;
}