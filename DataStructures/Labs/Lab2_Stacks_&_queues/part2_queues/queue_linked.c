// 2026 Joel Tann

#include "queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX_ID_LENGTH 32

struct queue {
    struct node *front;
    struct node *rear;
};

struct node {
    char id[MAX_ID_LENGTH];
    struct node *next;
};

Queue queue_create(void)
{
    Queue newqueue = malloc(sizeof *newqueue);
    if (newqueue == NULL) {
        return NULL;
    }
    newqueue->front = NULL;
    newqueue->rear = NULL;

    return newqueue;
}

void queue_destroy(Queue q)
{
    while (!queue_is_empty) {
        struct node *ptr = q->front;
        q->front = q->front->next;
        free (ptr);
    }
    free (q);
}

int queue_is_empty(Queue q)
{
    if (q->front == NULL) {
        return 1;
    }
    return 0;
}

void queue_enqueue(Queue q, const char *id)
{
    struct node *newnode = malloc(sizeof *newnode);
    // If malloc fails
    if (newnode == NULL) {
        printf("Memory allocation failure\n");
        exit(1);
    }

    strcpy(newnode->id, id);
    newnode->next = NULL;
    // If empty
    if (q->front == NULL) {
        q->front = newnode;
        q->rear = q->front;
    } 
    else {
        q->rear->next = newnode;
        q->rear = newnode;
    }
}

int queue_dequeue(Queue q, char *out, int out_size)
{
    if (queue_is_empty(q)) {
        return 0;
    }
    strncpy(out, q->front->id, out_size - 1);
    out[out_size - 1] = '\0';

    struct node *ptr = q->front;
    q->front = q->front->next;
    free (ptr);

    return 1;
}

int queue_front(Queue q, char *out, int out_size)
{
    if (queue_is_empty(q)) {
        return 0;
    }
    strncpy(out, q->front->id, out_size - 1);
    out[out_size - 1] = '\0';

    return 1;
}

void queue_print(Queue q)
{
    if (queue_is_empty(q)) {
        printf("Queue is empty\n");
    } else {
        struct node *ptr = q->front;
        printf("Queue:");
        while (ptr != NULL) {
            printf(" %s", ptr->id);
            ptr = ptr->next;
        }
        printf("\n");
    }
}