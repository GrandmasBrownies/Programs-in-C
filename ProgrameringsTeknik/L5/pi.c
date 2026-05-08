// 2025 Joel Tann

#include <stdio.h> 
#include <math.h>

double circumference (double r)
{
    return 2 * M_PI * r;
}

double area (double r)
{
    return r * r * M_PI;
}

int main()
{
    double x = 0;
    while(scanf("%lf", &x) == 1)
    {
        double ci = circumference(x);
        double ar = area (x);
        printf("%.2f %.2f\n", ci, ar);
    }
    return 0;
}