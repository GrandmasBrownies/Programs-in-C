// 2025 Joel Tann

#include <stdio.h>

int main()
{
    int n = 0;
    while (scanf("%d", &n) == 1)
    {
        int matrix1[n][n];
        for (int y = 0; y < n; y++)
        {
            for (int x = 0; x < n; x++)
            {
                scanf("%d", &matrix1[x][y]);
            }
        }
        int matrix2[n][n];
        for (int b = 0; b < n; b++)
        {
            for (int a = 0; a < n; a++)
            {
                scanf("%d", &matrix2[a][b]);
            }
        }

        int result[n][n];
        for (int y = 0, j = 0; y < n; y++)
        {
            for (int a = 0, i = 0; a < n; a++)
            {
                int temp = 0;
                for (int x = 0, b = 0; x < n; x++)
                {
                    temp += matrix1[x][y] * matrix2[a][b];
                    ++b;
                }
                result[i][j] = temp;
                i++;
            }
            j++;
        }

        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n; i++)
            {
                printf("%d", result[i][j]);
                if (result[i][j] != '\0')
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}