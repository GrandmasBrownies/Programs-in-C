// 2025 Joel Tann

#include <stdio.h>

int volume (int w, int h, int d)
{
    return w*h*d;
}

int area (int w, int h, int d)
{
    return 2*((w*h) + (w*d) + (h*d));
}

int main()
{
    int x, y, z = 0;
    scanf("%d %d %d", &x, &y, &z);
    int vol = volume(x, y, z);
    printf("The volume of a %d by %d by %d box is %d.\n", x, y, z, vol);
    int ar = area(x, y, z);
    printf("The surface area of a %d by %d by %d box is %d.\n", x, y, z, ar);
    return 0;
}