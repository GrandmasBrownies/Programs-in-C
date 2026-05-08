#include <string.h>
#include <ctype.h>
#include <stdio.h>
// add any additional includes here
 
int isVowel(char c);
void rotateVowels(char word[]);
int main() { 
   char word[60] = ""; 
   char sep = '\n'; 
   while (scanf("%59s%c", word, &sep)>=1) { 
      rotateVowels(word);
      printf("%s%c", word, sep); 
      sep = '\n'; 
   } 
}
 
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
 
void rotateVowels(char word[]) {
   char vowels[1000] = {'\0'};
   for (int i = 0, j = 0; word[i] != '\0'; i++)
   {
        if (1 == isVowel(word[i]))
        {
            vowels[j] = word[i];
            j++;
        }
   }

   for (int i = 0, j = 0; word[i] != '\0'; i++)
    {
        if (1 == isVowel(word[i]))
        {
            word[i] = rotatelist(word)[j];
            j++;
        }
    }
}
 
// add any additional functions here