// 2025 Joel Tann

#include <stdio.h>
#include <math.h>

double circumference(double r);
double area(double r);

int main()
{
    double r = 0;

    while (scanf("%lf", &r) == 1)
    {
        printf("%.2lf %.2lf\n", circumference(r), area(r));
    }
    return 0;
}

double circumference(double r)
{
    return 2 * M_PI * r;
}

double area(double r)
{
    return M_PI * r * r;
}