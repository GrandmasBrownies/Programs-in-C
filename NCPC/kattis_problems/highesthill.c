// 2026 Joel Tann
// update 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int size = 0;
    
    srand(time(NULL));

    while (scanf("%d", &size) == 1)
    {
        size = rand() % 20;
        printf("%d\n", size);

        long long int *range = malloc(size * sizeof(*range));
        if (!range) {
            printf("memory overflow\n");
            return 1;
        }

        for (int i = 0; i < size; i++) { // read the mountain range
            // scanf("%lld", &range[i]);
            range[i] = rand() % 100;
            printf("%lld ", range[i]);
        }
        printf("\n");

        long long int biggest_dif = 0;
        long long int leftdif = 0;
        long long int rightdif = 0;

        int decending = 0; // False or true
        
        long long int right = range[0];
        long long int top = range[0];
        long long int left = range[0];

        for (int i = 1; i < size; i++)
        {
            if (range[i] > range[i-1]) { // bigger then last 
                top = range[i];
                if (decending) {
                    if (leftdif > biggest_dif && (rightdif >= leftdif || rightdif == 0)) {
                        biggest_dif = leftdif;
                    }
                    else if (rightdif > biggest_dif && (rightdif <= leftdif || leftdif == 0)) {
                        biggest_dif = rightdif;
                    }
                    left = range[i-1];
                    rightdif = 0;
                    decending = 0;
                }
                leftdif = top-left;
            }
            else if (range[i] < range[i-1]) { // smaller then last
                right = range[i];
                rightdif = top-right;
                decending = 1;
            }
        }
        if (leftdif > biggest_dif && (rightdif >= leftdif || rightdif == 0)) {
            biggest_dif = leftdif;
        }
        else if (rightdif > biggest_dif && (rightdif <= leftdif || leftdif == 0)) {
            biggest_dif = rightdif;
        }

        printf("%lld\n", biggest_dif);

        free (range);
    }
    
    return 0;
}