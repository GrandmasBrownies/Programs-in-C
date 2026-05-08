#include <stdio.h>

/* int main(void)
{
    int num1 = 5;
    while (num1++ != 10)
    {
        printf("%d\n", num1);
    }

} */

/*
int main ()
{
    int x = 0;
    scanf("%d", &x);
    puts (x >= 60 ? "Passed" : "Failed");
    return 0;
    }

int main ()
    {
        char str[12];
        scanf("%c", &str);
        printf("%c\n", str);
        return 0;
    }
*/

/* int main ()
{
    short int x = 19;
    int y = 5;
    int total = 0;
    total = (float) x / y;
    printf("%d", total);
    return 0;
} */

int main()
{
    int a[3][4];
    int total = 0;

    for (int row = 0; row <= 2; ++row) {
        for (int column = 0; column <= 3; ++column)
        {
            scanf("%d", &a[row][column]);
            total += a[row][column];
        }
    }
    printf("%d\n", total);
    return 0;
}