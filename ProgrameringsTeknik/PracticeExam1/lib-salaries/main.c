// 2025 Joel Tann

#include "employee.h"
#include <stdio.h>
#define MAX_EMPLOYEES 101

int main()
{
    size_t size = 0;
    
    while (scanf("%zu", &size) == 1)
    {
        struct employee employees[size];
        for (size_t i = 0; i < size; i++)
        {
            scanf("%59s %d", &employees[i].name, &employees[i].salary);
        }
        struct employee *highest = highest_salary(employees, size);
        struct employee *lowest = lowest_salary(employees, size);
        
        printf("%s has the highest salary: %d kr\n", highest->name, highest->salary);
        printf("%s has the lowest salary: %d kr\n", lowest->name, lowest->salary);
        printf("%d\n", total_salary(employees, size));
    }
    return 0;
}