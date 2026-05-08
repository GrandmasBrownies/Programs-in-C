#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

int main(void) {
    Stack undo = stack_create();
    Stack redo = stack_create();

    if (undo == NULL || redo == NULL) {
        fprintf(stderr, "Error: could not create stacks.\n");
        return 1;
    }

    char cmd[16];
    char c;

    printf("Commands:\n");
    printf("  do <c>   - type character c\n");
    printf("  undo     - undo last character\n");
    printf("  redo     - redo last undone character\n");
    printf("  print    - show Undo and Redo stacks\n");
    printf("  exit     - quit\n\n");

    while (1) {
        printf("> ");

        if (scanf("%15s", cmd) != 1) {
            break;
        }

        if (strcmp(cmd, "do") == 0) {

            if (scanf(" %c", &c) != 1) {
                printf("Error: expected a character after 'do'.\n");
                continue;
            }
            stack_push(undo, c);
            char pop = 'a'; // 'a' is a place holder. Does not mean anything
            // Function returns '\0' when empty. So we loop until empty
            while (pop != '\0') {
                pop = stack_pop(redo);
            }

            printf("Typed: %c\n", c);

        } else if (strcmp(cmd, "undo") == 0) {

            if (stack_is_empty(undo)) {
                printf("Nothing to undo.\n");
            } else {
                char ch = stack_pop(undo);
                stack_push(redo, ch);

                printf("Undo: removed %c\n", ch);
            }

        } else if (strcmp(cmd, "redo") == 0) {

            if (stack_is_empty(redo)) {
                printf("Nothing to redo.\n");
            } else {
                char ch = stack_pop(redo);
                stack_push(undo, ch);

                printf("Redo: restored %c\n", ch);
            }

        } else if (strcmp(cmd, "print") == 0) {
            printf("Undo:\n");
            if (stack_is_empty(undo)) {
                printf("    Empty\n");
            } else {
                display(undo);
            }
            printf("Redo:\n");
            if (stack_is_empty(redo)) {
                printf("    Empty\n");
            } else {
                display(redo);
            }
            
        } else if (strcmp(cmd, "exit") == 0) {
            break;

        } else {
            printf("Unknown command: %s\n", cmd);
            printf("Valid commands: do <c>, undo, redo, print, exit\n");
        }
    }

    stack_destroy(undo);
    stack_destroy(redo);

    return 0;
}