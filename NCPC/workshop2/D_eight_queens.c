// 2026 Joel tann

#include <stdio.h>

int main()
{
    char bord[9][9];

    for (int i = 0; i < 8; i++)
    {
        scanf("%s", &bord[i]);
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {


            if (bord[i][j] == '*')
            {
                int a = i;
                int b = j;
                
                for (b = 0; b < 8; b++) // Check columns
                {
                    if (j == b) {
                        continue;
                    }
                    
                    if (bord[a][b] == '*') {
                        printf("invalid\n");
                        return -1;
                    }
                }
                
                b = j;
                
                for (a = 0; a < 8; a++) // Check rows
                {
                    if (i == a) {
                        continue;
                    }
                    
                    if (bord[a][b] == '*') {
                        printf("invalid\n");
                        return -1;
                    }
                }

                int decrease_by = 1;

                for (a = i+1; a < 8; a++)
                {
                    if ((b + decrease_by) < 8) {
                        if (bord[a][b + decrease_by] == '*') {
                            printf("invalid\n");
                            return -1;
                        }
                    }
                    if ((b - decrease_by) >= 0) {
                        if (bord[a][b - decrease_by] == '*') {
                            printf("invalid\n");
                            return -1;
                        }
                    }
                    decrease_by++;
                }
                decrease_by = 1;

                for (a = i-1; a >= 0; a--)
                {
                    if ((b + decrease_by) < 8) {
                        if (bord[a][b + decrease_by] == '*') {
                            printf("invalid\n");
                            return -1;
                        }
                    }
                    if ((b - decrease_by) >= 0) {
                        if (bord[a][b - decrease_by] == '*') {
                            printf("invalid\n");
                            return -1;
                        }
                    }
                    decrease_by++;
                }
            }
        }
    }
    printf("valid\n");
}