// 2026 Joel Tann

#include <stdio.h>

int main()
{
    int left;
    int right;

    while (scanf("%d %d", &left, &right) == 2)
    {
        int tleft = 0;

        int t = 0;

        for (int i = 0; i < left; i++)
        {
            scanf("%d", &t);
            tleft += t;
        }

        int tright = 0;

        for (int i = 0; i < right; i++)
        {
            scanf("%d", &t);
            tright += t;
        }

        if (tleft < tright)
        {
            printf("left\n");
        }
        else if (tleft > tright)
        {
            printf("right\n");
        }
        else
        {
            printf("either\n");
        }
    }
}