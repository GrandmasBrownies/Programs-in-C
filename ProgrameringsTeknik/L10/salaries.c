// 2025 Joel Tann

#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME 60

struct employee {
    char name[MAX_NAME];
    int salary;
};

int total_salary(const struct employee employees[], size_t n_employees);
struct employee highest_salary(const struct employee employees[], size_t n);
struct employee lowest_salary(const struct employee employees[], size_t n);

int main()
{
    size_t size = 0;
    while (scanf("%zu", &size) == 1)
    {
        struct employee employee[size];
        for (int i = 0; i < size; i++)
        {
            scanf("%59s %d", employee[i].name, &employee[i].salary);
        }
        int total = total_salary(employee, size);
        struct employee high = highest_salary(employee, size);
        struct employee low = lowest_salary(employee, size);

        printf("%s has the highest salary: %d kr\n", high.name, high.salary);
        printf("%s has the lowest salary: %d kr\n", low.name, low.salary);
        printf("The total monthly cost is %d kr\n", total);
    }
    return 0;
}

int total_salary(const struct employee employees[], size_t n_employees)
{
    int total = 0;
    for (int i = 0; i < n_employees; i++)
    {
        total += employees[i].salary;
    }
    return total;
}

struct employee highest_salary(const struct employee employees[], size_t n)
{
    struct employee highest_sal = employees[0];
    for (int i = 1; i < n; i++)
    {
        if (highest_sal.salary < employees[i].salary) 
        {
            highest_sal = employees[i];
        }
    }
    return highest_sal;
}

struct employee lowest_salary(const struct employee employees[], size_t n)
{
    struct employee lowest_sal = employees[0];
    for (int i = 1; i < n; i++)
    {
        if (lowest_sal.salary > employees[i].salary) 
        {
            lowest_sal = employees[i];
        }
    }
    return lowest_sal;
}