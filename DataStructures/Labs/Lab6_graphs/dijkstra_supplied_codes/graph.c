// 2026 Joel Tann

#include "graph.h"
#include <stdlib.h>

//create a graph
//parameters: int, the number of nodes in the graph 
//return: the pointer points to the graph
struct graph* createGraph(int n)
{
    struct graph *gr = malloc(sizeof *gr);
    if (!gr) {
        return NULL;
    }

    gr->N = n;
    
    gr->array = malloc(n * sizeof(struct adjList));
    if (!gr->array) {
        free(gr);
        return NULL;
    }

    for (int i = 0; i < n; i++)
    {
        gr->array[i].head = NULL;
    }

    return gr;
}

//display an edge between the source node and the target node
//parameters: graph, the pointer points to the graph
//            cities, the cities referenced by the node id in the graph  
void displayGraph(struct graph* graph, char **cities)
{
    for (int i = 0; i < graph->N; i++)
    {
        struct adjListNode *ptr = graph->array[i].head;
        printf("%s", cities[i]);
        while (ptr != NULL)
        {
            printf("->");
            printf("%s", cities[ptr->graph_node_id]);
            ptr = ptr->next;
        }
        printf("\n");
    }
}


//add an edge between the source node and the target node
//parameters: graph, the pointer points to the graph
//            source, the id of the source node
//            target, the id of the target node
//            weight, the weight of the edge
void addEdge(struct graph* graph, int source, int target, int weight)
{
    struct adjListNode *newedge = malloc(sizeof *newedge);
    if (!newedge) return;

    newedge->next = graph->array[source].head;
    newedge->graph_node_id = target;
    newedge->weight = weight;
    graph->array[source].head = newedge;
}

//delete the edge between the source node and the target node
//parameters: graph, the pointer points to the graph
//            source, the id of the source node
//            target, the id of the target node
void deleteEdge(struct graph* graph, int source, int target)
{
struct adjListNode *ptr = graph->array[source].head;
struct adjListNode *prev = NULL;

while (ptr != NULL && ptr->graph_node_id != target) {
    prev = ptr;
    ptr = ptr->next;
}

if (ptr == NULL) return;

if (prev == NULL) {
    graph->array[source].head = ptr->next;
} else {
    prev->next = ptr->next;
}

free(ptr);
}