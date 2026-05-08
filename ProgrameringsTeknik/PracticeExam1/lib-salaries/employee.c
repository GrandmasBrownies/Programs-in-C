#include "employee.h"
#include <stdio.h>

int total_salary(const struct employee employees[], size_t n_employees)
{
    int total = 0;
    for (size_t i = 0; i < n_employees; i++)
    {
        total += employees[i].salary;
    }
    return total;
}

struct employee *highest_salary(struct employee employees[], size_t n)
{
    struct employee *holder = &employees[0];
    for (size_t i = 1; i < n; i++)
    {
        if (employees[i].salary > holder->salary) {
            holder = &employees[i];
        }
    }
    return holder;
}

struct employee *lowest_salary(struct employee employees[], size_t n)
{
    struct employee *holder = &employees[0];
    for (size_t i = 1; i < n; i++)
    {
        if (employees[i].salary < holder->salary) {
            holder = &employees[i];
        }
    }
    return holder;
}