#ifndef SORT_H
#define SORT_H

typedef struct {
    int * numbers;
    int size;
    int min;
    int i;
    int idx;
} Log;

void printAsLog(void *);
void freeLog(void *);

void selectionSort(int *, int, float);
void swap(int *, int *);

void printArr(int *, int, int, int);
void arrowprint(int);
void printwithout(int *, int, int, int, int);
void printpadding(int, int);

#endif
