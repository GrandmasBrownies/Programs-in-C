// 2026 Joel Tann

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

// Stack structure
struct stack {
    struct node *top;
};

// Linked List
struct node {
    char c;
    struct node *next;
};

Stack stack_create(void)
{
    Stack newstack = malloc(sizeof *newstack);
    // If malloc fails
    if (newstack == NULL) {
        return NULL;
    }
    newstack->top = NULL;
    return newstack;
}

void stack_destroy(Stack s)
{
    // free element until list is empty
    while (s->top != NULL) {
        struct node *ptr = s->top;
        s->top = ptr->next;
        free(ptr);
    }
    free(s);
}

int stack_is_empty(Stack s)
{
    if (s->top == NULL) {
        return 1;
    }
    return 0;
}

void stack_push(Stack s, char value)
{
    struct node *newnode = malloc(sizeof *newnode);
    // If malloc fails
    if (newnode == NULL) {
        printf("Memory allocation failure\n");
    }
    newnode->c = value;
    newnode->next = s->top;
    s->top = newnode;
}

char stack_pop(Stack s)
{
    if (s->top == NULL) {
        return '\0';
    }
    struct node *ptr = s->top;
    char copy = ptr->c;

    s->top = ptr->next;
    free(ptr);

    return copy;
}

char stack_top(Stack s)
{   
    return s->top->c;
}

void display(Stack s)
{
    struct node *ptr = s->top;
    int first = 1;
    while (ptr != NULL)
    {
        if (first) {
            printf("Top  %c", ptr->c);
            first = 0;
        } else {
            printf(" -> %c", ptr->c);
        }
        ptr = ptr->next;
    }
    printf("  Bottom\n");
}