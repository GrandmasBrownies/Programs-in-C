// 2026 Joel Tann

#include "heap.h"
#include <stdlib.h>

struct minheap *create_heap(int m)
{
    struct minheap *heap = malloc(sizeof *heap);
    if (!heap) return NULL;

    heap->max_size = m;
    heap->cur_size = 0;

    heap->array = malloc(m * sizeof *heap->array);
    if (!heap->array) {
        free (heap);
        return NULL;
    }

    heap->pos = malloc(m * sizeof *heap->pos);
    if (!heap->pos) {
        free (heap->array);
        free (heap);
        return NULL;
    }

    return heap;
}

struct minHeapNode* new_min_heap_node(int n, int dist)
{
    struct minHeapNode *newnode = malloc(sizeof *newnode);
    if (!newnode) {
        return NULL;
    }

    newnode->graph_node_id = n;
    newnode->dist = dist;

    return newnode;
}

int insert_heap(struct minheap *h, struct minHeapNode *n)
{
    if (h->cur_size == h->max_size) {
        return 0;
    }

    // insert
    int i = h->cur_size;
    h->array[i] = n;
    h->pos[n->graph_node_id] = i;
    h->cur_size++;

    // Heapify up
    while (i > 0 && h->array[i]->dist < h->array[(i-1) / 2]->dist)
    {
        int parent = (i-1) / 2;

        // swap
        struct minHeapNode *temp = h->array[i];
        h->array[i] = h->array[parent];
        h->array[parent] = temp;

        // update position
        h->pos[h->array[i]->graph_node_id] = i;
        h->pos[h->array[parent]->graph_node_id] = parent;

        i = parent;
    }
    return 1;
}

int delete_heap(struct minheap *h)
{
    if (is_empty(h)) {
        return 0;
    }
    
    struct minHeapNode *root = h->array[0];
    struct minHeapNode *last = h->array[h->cur_size-1];

    // swap root with last
    h->array[0] = last;
    h->pos[last->graph_node_id] = 0;
    h->cur_size--;

    // Heapify down
    int i = 0;
    
    while (1)
    {        
        int left = 2*i + 1;
        int right = 2*i + 2;
        int smallest = i;

        if (left < h->cur_size && 
            h->array[left]->dist < h->array[smallest]->dist) { // If left node exists, check if swap is needed
            smallest = left;
        }
    
        if (right < h->cur_size &&
            h->array[right]->dist < h->array[smallest]->dist) { // If right node exists, check if swap is needed
            smallest = right;
        }
    
        if (smallest != i) // swap is needed
        {
            struct minHeapNode *temp = h->array[i];
            h->array[i] = h->array[smallest];
            h->array[smallest] = temp;
    
            // update pos
            h->pos[h->array[i]->graph_node_id] = i;
            h->pos[h->array[smallest]->graph_node_id] = smallest;

            i = smallest;
        }
        else break;
    }
    
    free (root);
    return 1;
}

void decreaseKey(struct minheap* h, int n, int dist)
{
    int i = h->pos[n];
    h->array[i]->dist = dist;

    // heapify up
    while (i > 0 && h->array[i]->dist < h->array[(i-1)/2]->dist)
    {
        int parent = (i-1) / 2;

        // swap
        struct minHeapNode *temp = h->array[i];
        h->array[i] = h->array[parent];
        h->array[parent] = temp;

        // update position
        h->pos[h->array[i]->graph_node_id] = i;
        h->pos[h->array[parent]->graph_node_id] = parent;

        i = parent;
    }
}

struct minHeapNode *findmin(struct minheap *h)
{
    return h->array[0];
}

void destroy_heap(struct minheap *h)
{
    if (!h) return;

    free (h->array);
    free (h->pos);
    free (h);
}

int is_empty(struct minheap *h)
{
    if (!h->cur_size)
        return 1;
    else {
        return 0;
    }
}

void display_heap(struct minheap *h)
{
    if (is_empty(h)) {
        printf("Error: heap is empty.\n");
        return;
    }
    
    for (int i = 0; i < h->cur_size; i++)
    {
        struct minHeapNode *node = h->array[i];
        printf("Task %d: at length: %d (arrival at %d)\n", node->graph_node_id, node->dist, h->pos[h->array[i]->graph_node_id]);
    }
}