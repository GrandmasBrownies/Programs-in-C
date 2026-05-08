// 2026 Joel Tann

//FIX:
/*
While loop to run function agian should be outside
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;
struct node *newnode, *ptr;

void insert_at_beginning(int num);
void insert_at_specified(int num);
void insert_at_end(int num);
void delete_first();
void delete_last();
void display();

int main()
{
    while (1)
    {
        printf("(1) add a value to the list (2) delete a value from the list\n");
        int choice1 = 0;
        scanf("%d", &choice1);
        int choice2 = 0;
        switch (choice1)
        {
            case (1):
                printf("(1) Insert at the beginning. (2) Insert after specified value. (3) Insert at the end\n");
                scanf("%d", &choice2);
                int num = 0;
                printf("Enter value to add:\n");
                scanf("%d", &num);
                switch (choice2)
                {
                    case (1):
                        insert_at_beginning(num);
                        break;
                    case (2):
                        insert_at_specified(num);
                        break;
                    case (3):
                        insert_at_end(num);
                        break;
                    default:
                        printf("Incorrect number. Please enter 1, 2 or 3\n");
                        break;
                }
            case (2):
                printf("(1) Delete the first element. (2) Delete the last element.\n");
                scanf("%d", &choice2);
                switch (choice2)
                {
                    case (1):
                        delete_first();
                        break;
                    case (2):
                        delete_last();
                        break;
                    default:
                        printf("Incorrect number. Please enter 1 or 2\n");
                        break;
                }
            default:
                printf("Incorrect number. Please enter 1 or 2\n");
                break;
        }
    }
    free(newnode);
    return 0;
}

void insert_at_beginning(int num)
{
    while (num != -1)
    {
        newnode = malloc(sizeof(struct node));
        newnode->data = num;

        newnode->next = start;
        start = newnode;
        printf("Enter new value, or -1 to exit\n");
        scanf("%d", &num);
    }
    display();
}

void insert_at_specified(int num)
{
    while (num != -1)
    {
        int specified = 0;
        printf("What is the specified node?\n");
        scanf("%d", &specified);

        newnode = malloc(sizeof(struct node));
        newnode->data = num;
        ptr = start;
        while (ptr->data != specified) {
            ptr = ptr->next;
            if (ptr == NULL) {
                printf("That value does not exist in the list\n");
                break;
            }
        }
        newnode->next = ptr->next;
        ptr->next = newnode;
        display();
        printf("Enter new value, or -1 to exit\n");
        scanf("%d", &num);
    }
}

void insert_at_end(int num)
{
    while(num != -1)
    {
        newnode = malloc(sizeof(struct node));
        newnode->data = num;

        if (start == NULL) {
            start = newnode;
            newnode->next = NULL;
        }
        else {
            ptr = start;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            ptr->next = newnode;
            newnode->next = NULL;
        }
        printf("Enter new value, or -1 to exit\n");
        scanf("%d", &num);
    }
    display();
}

void delete_first()
{
    int num = 0;
    while (num != -1)
    {
        if (start == NULL) {
            printf("No values exist. Try adding one\n");
            break;
        }
        else if (start->next == NULL) {
            ptr = NULL;
            start = NULL;
            printf("No more elements in list\n");
            break;
        }
        ptr = start;
        start = ptr->next;
        printf("Enter -1 to exit, or any other value to delete the next element\n");
        scanf("%d", &num);
    }
    display();
}

void delete_last()
{
    int num = 0;
    while (num != -1)
    {
        if (start == NULL) {
            printf("No values exist. Try adding one\n");
            break;
        }
        else if (start->next == NULL) {
            ptr = NULL;
            start = NULL;
            printf("No more elements in list\n");
            break;
        }
        ptr = start;
        while (ptr->next->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = NULL;
        printf("Enter -1 to exit, or any other value to delete the next element\n");
        scanf("%d", &num);
    }
    display();
}

void display()
{
    if (start != NULL) {
        ptr = start;
        while (ptr != NULL) {
            if (ptr->next == NULL) {
                printf("%d\n", ptr->data);
                break;
            }
            printf("%d -> ", ptr->data);
            ptr = ptr->next;
        }
    }
}