// 2026 Joel Tann

#include <stdio.h>
#include <stdlib.h>
#include "lab_multiway_trees.h"
#define MAX 4

struct node
{
    struct node *children[MAX];
    int keys[MAX-1];
    int key_count;
};

struct node *root = NULL;

struct node *createNode(int keys[], int count, struct node *children[])
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->key_count = count;
    for (size_t i = 0; i < count; i++)
    {
        newNode->keys[i] = keys[i];
        newNode->children[i] = children[i];
    }
    newNode->children[count] = children[count];
    return newNode;
}

void traverse(struct node *tree, int level)
{
    if (tree == NULL)
    {
        return;
    }
    for (size_t i = 0; i < tree->key_count; i++)
    {
        traverse(tree->children[i], level + 1);
        printf("\n");
        for (size_t i = 0; i < level; i++)
        {
            printf("  ");
            //fflush(stdout);
        }
        printf("%d ", tree->keys[i]);
    }
    traverse(tree->children[tree->key_count], level + 1);
}

struct node *search(struct node *tree, int val)
{
    struct node *ptr = tree;
    if (!ptr) {
        return NULL;
    }
    for (int i = 0; i < ptr->key_count; i++) // Check all keys in node
    {
        if (val < ptr->keys[i]) { // If key value is smaller, then search node left of value
            return search(ptr->children[i], val);
        }
        else if (val == ptr->keys[i]) { // Found key value
            return ptr;
        }
    }
    return search(ptr->children[ptr->key_count], val); // if none of the above was true, check right node
}

int main()
{
    // Max amount of children for all nodes is 4
    struct node *leaf_children[4] = {NULL, NULL, NULL, NULL};

    // Create the left sub-tree
    int leaf1_keys[2] = {18, 27};
    struct node *leaf1 = createNode(leaf1_keys, 2, leaf_children);

    int leaf2_keys[2] = {30, 31};
    struct node *leaf2 = createNode(leaf2_keys, 2, leaf_children);

    int leaf3_keys[2] = {36, 39};
    struct node *leaf3 = createNode(leaf3_keys, 2, leaf_children);

    int inter1_keys[2] = {29, 32};
    struct node *inter1_children[3] = {leaf1, leaf2, leaf3};
    struct node *inter1 = createNode(inter1_keys, 2, inter1_children);

    // Create the right sub-tree
    int leaf4_keys[2] = {46, 47};
    struct node *leaf4 = createNode(leaf4_keys, 2, leaf_children);

    int leaf5_keys[3] = {54, 59, 61};
    struct node *leaf5 = createNode(leaf5_keys, 3, leaf_children);

    int leaf6_keys[2] = {67, 72};
    struct node *leaf6 = createNode(leaf6_keys, 2, leaf_children);

    int inter2_keys[2] = {49, 63};
    struct node *inter2_children[3] = {leaf4, leaf5, leaf6};
    struct node *inter2 = createNode(inter2_keys, 2, inter2_children);

    // Create the root
    int root_keys[1] = {45};
    struct node *root_children[2] = {inter1, inter2};
    root = createNode(root_keys, 1, root_children);

    // Traverse the tree
    traverse(root, 0);
    printf("\n");

    int choice;
    int val;
    while (1)
    {
        printf("1. Search\n");
        printf("2. Quit\n");
        printf("Enter your option: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value to search for: ");
            scanf("%d", &val);
            if (search(root, val)) {
                printf("The key %d is found!\n\n", val);
            } else {
                printf("Could not find key\n");
            }
            break;
        case 2:
            exit(1);
        default:
            printf("Wrong option, please try agian\n");
        }
    }
}