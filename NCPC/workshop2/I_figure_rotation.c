// 2026 Joel Tann

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int size = 0;
    int first  = 1;
    
    while (scanf("%d", &size) == 1 && size != 0)
    {
        getchar();

        char **matrix = malloc(size * sizeof (char *));
        if (!matrix) {
            printf("memory allocation fails\n");
            exit(1);
        }
        
        int longest_matrix_row = 0;
        
        for (int i = 0; i < size; i++)
        {
            matrix[i] = malloc(102);
            fgets(matrix[i], 102, stdin);

            int len = strlen(matrix[i]);

            if (len > 0 && matrix[i][len-1] == '\n') {
                matrix[i][--len] = '\0';
            }

            if (len > longest_matrix_row) {
                longest_matrix_row = len;
            }
        }
        
        for (int i = 0; i < size; i++)
        {
            int len = strlen(matrix[i]);
            
            for (int j = len; j < longest_matrix_row; j++)
            {
                matrix[i][j] = ' ';
            }
            matrix[i][longest_matrix_row] = '\0';
        }

        char **rotated_matrix = malloc(longest_matrix_row * sizeof (char *));
        if (!rotated_matrix) {
            printf("memory allocation fails\n");
            exit(1);
        }

        for (int i = 0; i < longest_matrix_row; i++)
        {
            rotated_matrix[i] = malloc(size + 1);
            int u = (size-1);
            for (int j = 0; j < size; j++)
            {
                if (matrix[u][i] == '-') {
                    rotated_matrix[i][j] = '|';
                }
                else if (matrix[u][i] == '|') {
                    rotated_matrix[i][j] = '-';
                }
                else {
                    rotated_matrix[i][j] = matrix[u][i];
                }
                u--;
            }
            rotated_matrix[i][size] = '\0';
        }

        if (!first) {
            printf("\n");
        }
        first = 0;

        for (int i = 0; i < longest_matrix_row; i++)
        {
            int j = size - 1;
            while (j >= 0 && rotated_matrix[i][j] == ' ') {
                j--;
            }
            rotated_matrix[i][j+1] = '\0';

            printf("%s\n", rotated_matrix[i]);
            free (rotated_matrix[i]);
        }

        for (int i = 0; i < size; i++) {
            free (matrix[i]);
        }

        free (rotated_matrix);
        free (matrix);
    }
}