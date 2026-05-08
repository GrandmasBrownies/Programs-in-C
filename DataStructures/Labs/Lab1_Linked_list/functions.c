// 2026 Joel Tann

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

struct node {
    char name[100];
    char number[15];
    struct node *next;
};

struct node *newnode, *ptr, *preptr;

void display(struct node *start)
{
    ptr = start;
    for (int count = 1; ptr != NULL; count++) {
        printf("%d.\n", count);
        printf("%s\n", ptr->name);
        printf("%s\n", ptr->number);
        ptr = ptr->next;
    }
}

int insert_record(struct node **start)
{
    char name[100];
    char number[15];
    printf("Enter new name and number\n");
    scanf("%99s %14s", name, number);
    ptr = *start;
    while (ptr != NULL) {
        // Checks if name already exists
        if (strcmp(name, ptr->name) == 0) {
            printf("Name already exist\n");
            return -1;
        }
        // Checks if number already exists
        if (strcmp(number, ptr->number) == 0) {
            printf("Number already exist\n");
            return -1;
        }
        ptr = ptr->next;
    }
    newnode = malloc(sizeof(struct node));
    strcpy(newnode->name, name);
    strcpy(newnode->number, number);
    newnode->next = *start;
    *start = newnode;
    return 0;
}

int delete_record(struct node **start)
{
    // If list is empty
    if (*start == NULL) {
        printf("List is already empty\n");
        return -1;
    }
    char number[15];
    printf("Enter the phone number of the element you want to delete\n");
    scanf("%14s", number);
    ptr = *start;

    while (ptr != NULL && strcmp(ptr->number, number) != 0) {
        preptr = ptr;
        ptr = ptr->next;
    }
    // If record is not found
    if (ptr == NULL) {
        printf("Number does not exist in record\n");
        return -1;
    }
    printf("Succesfully deleted %s %s\n", ptr->name, ptr->number);
    // Checks if only one element in list
    if ((*start)->next == NULL) {
        *start = NULL;
    }
    // Checks if ptr->next is the last pointer
    else if (ptr->next == NULL) {
        preptr->next = NULL;
    }
    // Checks if we are trying to delete the first element in a list
    else if (ptr == *start) {
        *start = (*start)->next;
    }
    // Cathes all other cases
    else {
        preptr->next = ptr->next;
    }
    free(ptr);
    return 0;
}

struct node *query_directory(struct node *start, int option)
{
    // If list is empty
    if (start == NULL) {
        printf("No records in list\n");
        return NULL;
    }
    char input[100];
    scanf("%99s", input);
    ptr = start;
    // search by number
    if (option == 1) {
        while (ptr != NULL && strcmp(ptr->number, input) != 0) {
            ptr = ptr->next;
        }
    }
    // Search by name
    else {
        while (ptr != NULL && strcmp(ptr->name, input) != 0) {
            ptr = ptr->next;
        }
    }
    // If can't find
    if (ptr == NULL) {
        printf("record does not exist\n");
        return NULL;
    }
    return ptr;
}

void delete_directory(struct node **start)
{
    ptr = *start;
    *start = NULL;
    while (ptr != NULL) {
        preptr = ptr;
        ptr = ptr->next;
        free (preptr);
    }
}