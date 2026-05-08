#include <stdio.h>
#include <math.h>
 
typedef struct point {
	double x;
	double y;
} point_t;
 
double distance(point_t a, point_t b);
 
int main()
{
	point_t a, b;
	scanf("(%lf,%lf) (%lf,%lf)", &a.x, &a.y, &b.x, &b.y);
	printf("%.2lf\n", distance(a,b));
}
 
double distance(point_t a, point_t b)
{
    return sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2));
}