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

int main()
{
    struct node *ptr, *start = NULL;
    int option = 0;
    int choice = 0;
    while (1)
    {
        printf("(1) Display all records\n");
        printf("(2) Insert new record at the beginning\n");
        printf("(3) Delete a record\n");
        printf("(4) Search for record\n");
        printf("(5) Delete directory\n");
        printf("(6) Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
            case (1):
                display(start);
                break;
            case (2):
                insert_record(&start);
                break;
            case (3):
                delete_record(&start);
                break;
            case (4):
                printf("Enter 1 to search by number or 2 to search by name\n");
                scanf("%d", &option);
                ptr = query_directory(start, option);
                if (ptr != NULL) {
                    printf("Record found:\n");
                    printf("Name: %s\n", ptr->name);
                    printf("Phone number: %s\n", ptr->number);
                }
                break;
            case (5):
                printf("Are you sure you want to delete the directory?\n");
                printf("(1) Yes\n");
                printf("(2) No\n");
                scanf("%d", &option);
                if (option == 1) {
                    delete_directory(&start);
                }
                break;
            case (6):
                printf("Are you sure you want to exit?\n");
                printf("(1) Yes\n");
                printf("(2) No\n");
                scanf("%d", &option);
                if (option == 1) {
                    delete_directory(&start);
                    return 0;
                }
                break;
            default:
                printf("Incorrect number. Please enter 1, 2, 3, 4 or 5\n");
                break;
        }
    }
}