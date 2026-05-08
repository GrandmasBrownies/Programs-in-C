// 2026 Joel Tann

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

// Stack structure
struct stack {
    char data[MAX];
    int top;
};


Stack stack_create(void)
{
    Stack newstack = malloc(sizeof *newstack);
    // If malloc fails
    if (newstack == NULL) {
        return NULL;
    }
    newstack->top = -1;
    return newstack;
}

void stack_destroy(Stack s)
{
    free (s);
}

int stack_is_empty(Stack s)
{
    if (s->top == -1) {
        return 1;
    }
    return 0;
}

void stack_push(Stack s, char value)
{
    if (s->top + 1 != MAX) {
        s->top += 1;
        s->data[s->top] = value;
    }
}

char stack_pop(Stack s)
{
    if (s->top > -1) {
        char copy = s->data[s->top];
        s->top -= 1;
        return copy;
    }
    return '\0';
}

char stack_top(Stack s)
{   if (s->top == -1) {
    return '\0';
    }
    return s->data[s->top];
}

void display(Stack s)
{
    int first = 1;
    for (int i = s->top; i >= 0; i--)
    {
        if (first) {
            printf("Top  %c", s->data[i]);
            first = 0;
        } else {
            printf(" -> %c", s->data[i]);
        }
    }
    printf("  Bottom\n");
}