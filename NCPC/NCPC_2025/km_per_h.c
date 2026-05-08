// 2026 joel Tann

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n = 0;

    while (scanf("%d", &n) == 1)
    {
        char line[n+1];
        int highest_speed = 0;

        for (int i = 0; i < n; i++)
        {
            scanf("%s", line);
            if (line[0] == '/')
            {
                printf("%d\n", highest_speed);
            } else {
                int speed = atoi(line);
                if (speed >= highest_speed) {
                    highest_speed = ((speed / 10) + 1) * 10;
                }
                printf("%d\n", speed);
            }
        }
    }
    return 0;
}