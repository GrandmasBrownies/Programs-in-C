// 2026 Joel tann

#include <stdio.h>

int main() {
    int n = 0;
    
    while (scanf("%d", &n) == 1)
    {
        int n1 = 1;    
        int n2 = n - n1;

        if (n == 1) {
            n1 = 2;
            n2 = -1;
        }
        else if (n == -999) {
            n1 = -1;
            n2 = -998;
        }
        
        printf("%d %d\n", n1, n2);
    }
    
    return 0;
}