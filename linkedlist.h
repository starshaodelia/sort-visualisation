#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct LinkedListNode {
    void *data; /* any datatype can be stored here */
    struct LinkedListNode *next;
} node;

typedef struct {
    node* head; /* pointer to node */
    node* tail;
} linkedlist; 

typedef void (*listF)(void*); 

linkedlist * createLinkedList();
void insertEnd(linkedlist* list, void* item);
int nodeCount(node* cur);
void printList(linkedlist* list, listF fptr);
void freeList(linkedlist* list, listF fptr);
void freeRec(node* n, listF fptr);

#endif
