// 2026 Joel Tann

#include <stdio.h>

int main()
{
    int amount;
    while (scanf("%d", &amount) == 1)
    {
        int *items;

        for (int i = 1; i <= amount; i++)
        {
            scanf("%d", items[i]);
        }

        int moves = 0;

        for (int i = 1; i <= amount; i++)
        {
            int new = i;
            int last;

            while (items[new] != i)
            {
                last = new;
                new = items[items[last]];
                items[last] = last;
                moves++;
            }
        }
    }
}