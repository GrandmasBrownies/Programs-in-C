#include <stdio.h>
#include <stdlib.h>
#include "employee.h"


struct employee *highest_salary(struct employee employees[], size_t size)
{
    struct employee *highest = &employees[0];
    for (size_t i = 1; i < size; i++)
    {
        if (employees[i].salary > highest->salary)
        {
            highest = &employees[i];
        }
    }
    return highest;
}

struct employee *lowest_salary(struct employee employees[], size_t size)
{
    struct employee *lowest = &employees[0];
    for (size_t i = 1; i < size; i++)
    {
        if (employees[i].salary < lowest->salary)
        {
            lowest = &employees[i];
        }
    }
    return lowest;
}
int total_salary(const struct employee employees[], size_t size)
{
    unsigned total = 0;
    for (int i = 0; i < size; i++)
    {
        total += employees[i].salary;
    }
    return total;
}