// 2025 Joel Tann

#include <stdio.h>

struct rectangle {
    int width;
    int height;
};

int area(struct rectangle rect);
int perimeter(struct rectangle rect);

int main()
{
    struct rectangle rect;
    while (scanf("%d %d", &rect.width, &rect.height) == 2)
    {
        int ar = area(rect);
        int per = perimeter(rect);
        printf("%dx%d rectangle, area = %d, perimeter = %d\n", rect.width, rect.height, ar, per);
    }
}

int area(struct rectangle rect)
{
    return rect.height * rect.width;
}

int perimeter(struct rectangle rect)
{
    return 2*(rect.width+rect.height);
}
