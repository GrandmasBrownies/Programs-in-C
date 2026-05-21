// 2026 Joel Tann

#include <stdio.h>

int knapsack(int m, int *items, int tot, int i, int size)
{
    while (i < size)
    {
        knapsack(m, items, tot + items[i], i+1, size);
        i++;
    }
    if (tot <= m)
    {
        printf("%d\n", tot);
        return tot;
    }
}

int main()
{
    int m = 0;

    while (scanf("%d", &m) == 1)
    {
        int size = 7;
        int items[7] = {5,3,7,2,6,8,4};

        int tot = 0;

        tot = knapsack(m, items, tot, 0, size);
        printf("biggest knapsack of maxweight %d you can get is %s\n", m, tot);
    }
    return 0;
}