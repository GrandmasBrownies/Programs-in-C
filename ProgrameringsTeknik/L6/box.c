// 2025 Joel Tann

#include <stdio.h>

int volume(int w, int h, int d)
{
    return w * h * d; 
}

int area(int w, int h, int d)
{
    return 2*((w*h) + (w*d) + (h*d));
}

int main()
{
    int num1, num2, num3 = 0;

    while (scanf("%d %d %d", &num1, &num2, &num3) == 3)
    {
        int vol = volume(num1, num2, num3);
        int ar = area(num1, num2, num3);

        printf("The volume of a %d by %d by %d box is %d.\n", num1, num2, num3, vol);
        printf("The surface area of a %d by %d by %d box is %d.\n", num1, num2, num3, ar);
        printf("\n");
    }
    return 0;
}