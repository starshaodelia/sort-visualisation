#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"


/* creating a new empty linked list */
linkedlist* createLinkedList()
{
    linkedlist* list;
    list = (linkedlist*)malloc(sizeof(linkedlist));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void insertEnd(linkedlist* list, void* item)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = item;
    newNode->next = NULL;

    if (list->tail != NULL)
    {
        list->tail->next = newNode;
    }
    list->tail = newNode;

    if (list->head == NULL)
    {
        list->head = newNode;
    }
}

int nodeCount(node* cur)
{
    int len = 0;
    if (cur != NULL)
    {
        len = 1 + nodeCount(cur->next);
    }
    return len;
}

void printList(linkedlist* list, listF fptr) /* print the nodes in linkedlist; requires "specifier" */
{
    node* n = list->head;
    while (n != NULL)
    {
        (*fptr)(n->data);
        printf("\n");
        n = n->next;
    }
}

void freeList(linkedlist* list, listF fptr) 
/* recursion wrapper method */
{
    freeRec(list->head, fptr);
    free(list);
}

void freeRec(node* n, listF fptr)
/* freeing linked list with recursion */
{
    if (n->next != NULL)
    {
        freeRec(n->next, fptr);
    }
    (*fptr)(n->data);
    free(n);
}
