// file: src/task.c
// 2026 Joel Tann

#include <stdio.h>
#include "task.h"

Task task_create(int id, int pages, int arrival_index)
{
    Task t;
    t.id = id;
    t.pages = pages;
    t.arrival_index = arrival_index;
    return t;
}

int task_compare(Task a, Task b)
{
    // TODO: implement comparison according to lab rules
    // primary: pages (fewer pages = higher priority)
    // tie-breaker: arrival_index (smaller = higher priority)
    if (a.pages < b.pages) return 1;
    if (a.pages > b.pages) return -1;

    if (a.arrival_index < b.arrival_index) return 1;
    if (a.arrival_index > b.arrival_index) return -1;

    return 0;
}

void task_print(const Task *t)
{
    if (!t) {
        return;
    }
    // TODO: adjust the format as you like
    printf("Task %d: %d pages (arrival at %d)\n", t->id, t->pages, t->arrival_index);
}