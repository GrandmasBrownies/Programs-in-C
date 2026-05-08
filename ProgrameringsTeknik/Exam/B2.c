#include <stdio.h>

int main()
{
    int array[4];

    while (scanf("%d %d %d", &array[0], &array[1], &array[2]) == 3)
    {
        int smallest = array[0];

        for (int i = 1; i < 3; i++)
        {
            if (array[i] < smallest)
            {
                smallest = array[i];
            }
        }
        printf("%d\n", smallest);
    }
    return 0;
}