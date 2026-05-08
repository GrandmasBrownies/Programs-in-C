// 2026 Joel Tann

#include <stdio.h>
#include <math.h>

struct frac {
    int n;
    int d;
};

int gcd(int x, int y);
struct frac math(struct frac frac1, struct frac frac2);

int main()
{
    struct frac frac1;
    struct frac frac2;
    int num = 0;
    char c = '\0';
    int count = 0;
    while (scanf("%d%c", &num, &c) != EOF)
    {
        ++count;
        frac2.d = 1;
        if (c == ' ') {
            frac1.n = num;
            frac1.d = 1;
            continue;
        }
        else if (c == '/' && count == 1) {
            frac1.n = num;
            scanf("%d", &frac1.d);
            continue;
        }
        else if (c == '/' && count == 2) {
            scanf("%d", &frac2.d);
        }
        frac2.n = num;
        struct frac result = math(frac1, frac2);
        printf("%d", result.n);
        if (result.d != 1) {
            printf("/%d", result.d);
        }
        printf("\n");
        count = 0;
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

struct frac math(struct frac frac1, struct frac frac2)
{
    struct frac result;
    frac1.n *= 3 * 2;
    frac2.n *= 3 * 2;
    result.d = frac2.d * frac1.n;
    result.n = frac2.n * frac1.d + result.d;
    int biggest = gcd(result.d, result.n);
    result.d /= biggest;
    result.n /= biggest;
    return result;
}