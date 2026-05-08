// 2026 Joel Tann

#include <stdio.h>

int main()
{
    int tro = 0;
    int lolo = 0;
    
    while (scanf("%d %d" , &tro, &lolo) == 2)
    {
        int LO = 0;
        int SWITCH = 1;
        for (int i = 0; i < (tro * lolo) || i < tro; i++)
        {
            printf("Tro");
            for (int j = 0; j < lolo; j++)
            {
                if (j == LO) {
                    printf("\033[1;34mLO\033[0m");
                    continue;
                }
                printf("lo");
            }
            printf("...\n");
            if (LO < lolo-1 && SWITCH == 1) {
                LO++;
            } 
            else if (LO >= 1 && SWITCH == 0){
                LO--;
            } 
            else if (SWITCH == 1) {
                SWITCH = 0;
            } 
            else {
                SWITCH = 1;
            }
        }
    }
    return 0;
}