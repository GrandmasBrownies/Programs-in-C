#include <stdio.h>
#include <stdlib.h> // malloc & free

/*
int* twelve()
{
    int *ptr = malloc(sizeof(int));
    *ptr = 12;
    return ptr;
}

int main()
{
    int *p;
    p = twelve();
    printf("%d\n", *p);
    free(p);
}
*/

/*
int main ()
{
    int i, n;
    scanf("%d", &n);
    int *ptr = malloc(n * sizeof(int));
    if (ptr == NULL)
    {
        printf("not enough memory\n");
        return 1;
    }
    for (i = 0; i < n; i++)
    {
        ptr[i] = i;
    }
    for (i = 0; i < n; i++)
    {
        printf("%d ", ptr[i]);
    }
    printf("\n");
    free(ptr);
}
*/

/*
typedef int age_t;

int main()
{
    age_t alice = 32;
    int bob = 15;
    age_t together = alice + bob;
    printf("Bob and Alice is together %d years old\n", together);
}
*/

enum parity {even, odd};

enum parity parity(int n)
{
    if(n % 2 == 0) {
        return even;
    } else {
        return odd;
    }
}

int main()
{
    int s = 0;
    scanf("%d", &s);
    switch (parity(s)) {
        case even:
            printf("even\n");
            break;
        case odd:
            printf("odd\n");
            break;
    }
    return 0;
}