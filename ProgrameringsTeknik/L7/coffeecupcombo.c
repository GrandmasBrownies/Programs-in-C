// 2025 Joel Tann

#include <stdio.h>
#define MAX 100001

int main()
{
    int lectures = 0;
    while (scanf("%d", &lectures) == 1)
    {
        int extracoffee = 0;
        int awake = 0;
        char num[MAX];
        scanf("%100000s", num);

        for (int i = 0; i < lectures; i++)
        {
            if (num[i] == '1')
            {
                extracoffee = 2;
                awake++;
            }
            if (num[i] == '0' && extracoffee > 0)
            {
                awake++;
                extracoffee--;
            }
        }
        printf("%d\n", awake);
    }
    return 0;
}