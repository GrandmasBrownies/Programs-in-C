// file: src/priority_queue_heap.c
// 2026 Joel Tann

#include <stdio.h>
#include <stdlib.h>
#include "priority_queue.h"
#include "task.h"

struct PriorityQueue {
    Task *data;     // array-based min-heap
    int size;
    int capacity;
};

#define PARENT(i) (i  / 2)
#define LEFT(i)   (2*i)
#define RIGHT(i)  (2*i + 1)

static void heapify_up(PriorityQueue *pq, int index);
static void heapify_down(PriorityQueue *pq, int index);

PriorityQueue* pq_create(int capacity)
{
    PriorityQueue *pq = malloc(sizeof *pq);
    if (!pq) return NULL;
    
    pq->data = malloc((capacity+1) * sizeof *pq->data);
    if (!pq->data) {
        free (pq);
        return NULL;
    }

    pq->size = 0;
    pq->capacity = capacity;

    return pq;
}

void pq_destroy(PriorityQueue *pq)
{
    if (!pq) return;

    free (pq->data);
    free (pq);
}

int pq_is_empty(const PriorityQueue *pq)
{
    if (!pq->size)
        return 1;
    else {
        return 0;
    }
}

int pq_is_full(const PriorityQueue *pq)
{
    if (pq->size == pq->capacity) // Checks for overflow
        return 1;
    return 0;
}

int pq_insert(PriorityQueue *pq, Task task)
{
    if (pq_is_full(pq)) { // Check for overflow
        return -1;
    }

    pq->size++;
    pq->data[pq->size] = task;

    heapify_up(pq, pq->size);

    return 0;
}

int pq_peek(const PriorityQueue *pq, Task *out)
{
    if (pq_is_empty(pq)) {
        return -1;
    }

    *out = pq->data[1];
    return 0;
}

int pq_extract_min(PriorityQueue *pq, Task *out)
{
    if (pq_is_empty(pq)) {
        return -1;
    }

    int last = pq->size;

    // swap root with last node, and delete
    *out = pq->data[1];
    pq->data[1] = pq->data[last];
    pq->size--;

    heapify_down(pq, 1);
    return 0; 
}

void pq_print(const PriorityQueue *pq)
{
    if (pq_is_empty(pq)) {
        printf("Error: priority queue is empty.\n");
        return;
    }

    for (int i = 1; i <= pq->size; i++)
    {
        task_print(&pq->data[i]);
    }
}

static void heapify_up(PriorityQueue *pq, int index)
{
    Task *ptr = pq->data;

    int parent = PARENT(index);

    if (parent) { // parent index is bigger then 0
        if (task_compare(ptr[index], ptr[parent]) > 0) // Child is bigger then parent
        {
            // swap
            Task holder = ptr[index];
            ptr[index] = ptr[parent];
            ptr[parent] = holder;

            heapify_up(pq, parent); // recursion if further readjustment is needed
        }
    }
}

static void heapify_down(PriorityQueue *pq, int index)
{
    Task *ptr = pq->data;

    int left = LEFT(index);
    int right = RIGHT(index);
    int smallest = index;

    if (left <= pq->size && task_compare(ptr[left], ptr[smallest]) > 0) // If left node exists, check if swap is needed
        smallest = left;

    if (right <= pq->size && task_compare(ptr[right], ptr[smallest]) > 0) // If right node exists, check if swap is needed
        smallest = right;

    if (smallest != index) // If smallest is unchanged, no swap is needed
    {
        // swap
        Task holder = ptr[index];
        ptr[index] = ptr[smallest];
        ptr[smallest] = holder;

        heapify_down(pq, smallest); // recursion if further readjustment is needed
    }
}