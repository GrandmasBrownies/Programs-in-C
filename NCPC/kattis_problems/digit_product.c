// 2026 Joel Tann

#include <stdio.h>

int main()
{
    int x;

    scanf("%d", &x);

    int result;

    do
    {
        result = 1;
        
        while (x > 0)
        {
            int last = x % 10;
    
            if (last != 0)
            {
                result *= last;
            }
    
            x /= 10;
        }

        x = result;

    } while (result > 9);

    printf("%d", result);
}