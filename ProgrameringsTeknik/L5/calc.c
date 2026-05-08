// 2025 Joel Tann

#include <stdio.h>
#include <math.h>

double op (double x, char o, double y)
{
    switch (o)
    {
        case '^':
            return pow (x, y);
            break;
        
        case '+':
            return x+y;
            break;
        
        case '-':
            return x-y;
            break;

        case '*':
            return x*y;
            break;

        case '/':
            return x/y;
            break;
    }
    return 0;
}

int main ()
{
    char x;
    double num1, num2 = 0;
    while (scanf("%lf %c %lf", &num1, &x, &num2) == 3)
    {
        double result = op (num1, x, num2);
        printf("%.2lf\n", result);
    }
    return 0;
}