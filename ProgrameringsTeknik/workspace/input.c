#include <stdio.h>

int main() {
    int x = 0;
    printf("Write a number here: ");
    scanf("%d",&x);
    printf(x <= 10 ? "10 or less\n" : "more then 10\n");
    return 0;
}