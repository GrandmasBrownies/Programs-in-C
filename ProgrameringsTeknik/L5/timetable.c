// 2025 Joel Tann

#include <stdio.h>

int main()
{
    int hh1, mm1, hh2, mm2, hh3, mm3, hh4, mm4 = 0;

    while (scanf("%d:%d %d:%d %d:%d %d:%d", &hh1, &mm1, &hh2, &mm2, &hh3, &mm3, &hh4, &mm4) == 8)
    {
        int time1 = (hh1*100) + mm1;
        int time2 = (hh2*100) + mm2;
        int time3 = (hh3*100) + mm3;
        int time4 = (hh4*100) + mm4;
        
        if ((time2 > time3 && time4 > time2) || (time1 > time3 && time4 > time1))
        {
            printf("conflict\n");
        } 
        else if ((time3 > time1 && time2 > time3) || (time4 > time1 && time2 > time4))
        {
            printf("conflict\n");
        }
        else {
            printf("ok\n");
        }
    }
    return 0;
}