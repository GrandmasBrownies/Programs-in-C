// 2026 Joel Tann

#include <stdio.h>

int palindrome(int num);
int reverse_digits(int x);

int main()
{
    int num = 0;
    while (scanf("%d", &num) == 1)
    {
        if (palindrome(num)) {
            printf("%d is palindrome\n", num);
        } else {
            printf("%d is not palindrome\n", num);
        }
    }
    return 0;
}

int palindrome(int num)
{
    if (num == reverse_digits(num)) {
        return 1;
    } else {
        return 0;
    }
}

int reverse_digits(int x)
{
    int result = 0;
    for (int i = 0; x > 0; i++)
    {
        result *= 10;
        result += x % 10;
        x /= 10;
    }
    return result;
}