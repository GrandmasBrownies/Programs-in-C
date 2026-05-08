// 2026 Joel Tann

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vertices = 0;
    int edges = 0;

    while (scanf("%d %d", &vertices, &edges) == 2)
    {
        int from = 0;
        int to = 0;
        int k = 0;
        int *followers = malloc(vertices * sizeof *followers);

        while (k < edges)
        {
            scanf("%d %d", &from, &to);
            matrix[from][to] = 1;

            if (matrix[to][from] == 1) {
                followers[to] -= 1;
            } else {
                followers[to] += 1;

            }
            k++;
        }

        int most_followers = 0;
        int most_index = 0;

        for (int i = 0; i < vertices; i++)
        {
            if (followers[i] > most_followers) {
                most_followers = followers[i];
                most_index = i;
            }
        }
        printf("%d %d\n", most_index, most_followers);
        
        free(followers);
    }
}