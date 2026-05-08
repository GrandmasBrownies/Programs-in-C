// 2025 Joel Tann

#include "employee.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    size_t size = 0;
    while (scanf("%zu", &size) == 1)
    {
        struct employee employee[size];
        for (int i = 0; i < size; i++)
        {
            scanf("%61s %d", employee[i].name, &employee[i].salary);
        }
        struct employee *high = highest_salary(employee, size);
        struct employee *low = lowest_salary(employee, size);
        int total = total_salary(employee, size);

        printf("%s has the highest salary: %d kr\n", high->name, high->salary);
        printf("%s has the lowest salary: %d kr\n", low->name, low->salary);
        printf("The total monthly cost is %d kr\n", total);
    }
    return 0;
}