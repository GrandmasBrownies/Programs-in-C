// 2025 Joel Tann

#include <stdio.h>

struct rectangle {
    int xbot;
    int ybot;
    int xtop;
    int ytop;
};

int main()
{
    struct rectangle rect1;
    struct rectangle rect2;
    while (scanf("%d %d %d %d %d %d %d %d", &rect1.xbot, &rect1.ybot, &rect1.xtop, &rect1.ytop, 
        &rect2.xbot, &rect2.ybot, &rect2.xtop, &rect2.ytop) == 8)
    {
        // If rec2 is on teh right side of rec1 || rec2 is above rec1
        if (rect2.xbot > rect1.xtop || rect2.ybot > rect1.ytop) {
            printf("no\n");
        }
        // If the input of the rectangles change place
        else if (rect1.xbot > rect2.xtop || rect1.ybot > rect2.ytop) {
            printf("no\n");
        }
        else {
            printf("yes\n");
        }
    }
    return 0;
}