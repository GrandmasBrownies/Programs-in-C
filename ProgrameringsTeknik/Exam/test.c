#include <string.h>
#include <ctype.h>
#include <stdio.h>
// add any additional includes here
int isVowel(char c) {   
   return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

char rotatelist(char arr[])
{
    char holder[1000] = {'\0'};
    for (int i = 0; arr[i] != '\0'; i++)
    {
        if ((arr[i+1]) == '\0')
        {
            holder[0] = arr[i];
        }
    }
    for (int i = 0, u = 1; arr[i] != '\0'; i++)
    {
        holder[u] = arr[i];
        printf("%c", holder[u]);
        u++;
    }
}

int main() {
    char string[10] = {"abcde"};
    printf("%s", rotatelist(string));
}
