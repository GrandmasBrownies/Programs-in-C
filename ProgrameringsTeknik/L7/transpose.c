// 2025 Joel Tann

#include <stdio.h>

int main()
{
    int n = 0;
    while (scanf("%d", &n) == 1)
    {
        int matrix[n][n];
        int x, y;
        for (x = 0; x < n; x++)
        {
            for (y = 0; y < n; y++)
            {
                scanf("%d", &matrix[x][y]);
            }
        }

        for (y = 0; y < n; y++)
        {
            for (x = 0; x < n; x++)
            {
                printf("%d", matrix[x][y]);
                if (matrix[x][y] != '\0')
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
    
    }
    return 0;
}