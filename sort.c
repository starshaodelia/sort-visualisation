#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "linkedlist.h"
#include "newSleep.h"

/* colors:
 * xxxxx31m is red
 * xxxxx32m is green
 * xxxxx0m is resetting to default
 */

void freeLog(void * n)
{
    Log * log = (Log *) n;
    free(log->numbers);
}

void printAsLog(void * n)
{ 
    int arrSz; 
    Log * log = (Log *) n;
    arrSz = log->size;
  
    printArr(log->numbers, arrSz, (log->idx)+1, -1);

    if (log->min != log->i)
    {
        printf("value no. %d is %d after replacing %d\n", (log->idx)+1, log->i, log->min);
    }
    else 
    {
        printf("value no. %d, %d is already in the right spot\n", (log->idx)+1, log->min);
    }
}

/* ALGORITHM TAKEN FROM DSA
 * (originally in python)
 * returns sorted array 
 * is unstable */
void selectionSort(int * arr, int sz, float sleep)
{   
    int * arrcpy;
    int i, j, k, l, min;
    Log * log;
    linkedlist * list = createLinkedList();

    for (i = 0; i < sz-1; i++)
    {
        /* 1st element set to the default minimum */
        min = i;
        for (j = i+1; j < sz; j++) /* i ignored as thats already the initial minimum index */
        {
            if (arr[j] < arr[min])
            {
                /* updates newly found index of min value */
                min = j; 
            }
            
            /* animates arrow */
            system("clear");
            printf("\n");
            printArr(arr, sz, i, min);
            arrowprint(j);
            newSleep(sleep);
        }

        /* animates and does swap */
        if (i != min)
        {
            system("clear");
            printpadding(arr[i], i);
            printwithout(arr, sz, i, min, i);
            printpadding(arr[min], min);
            newSleep(sleep);
            for (k = 1; k <= min-i; k++)
            {
                system("clear");
                printpadding(arr[i], k+i);
                printwithout(arr, sz, i, min, i);
                printpadding(arr[min], min-k);
                newSleep(sleep);
            }
        }
        else
        {
            newSleep(sleep);
            system("clear");
        }
        swap(&arr[min], &arr[i]);
        /* done animating and swapping */
        
        /* linkedlist stuff here */
        arrcpy = (int *) malloc(sizeof(int) * sz);
        for (l = 0; l < sz; l++)
        {
            arrcpy[l] = arr[l];
        }

        log = (Log *) malloc(sizeof(Log));
        log->numbers = arrcpy;
        log->size = sz;
        log->min = arr[min];
        log->i = arr[i];
        log->idx = i;
        insertEnd(list, log);
    }
    system("clear");
    printf("\n");
    printArr(arr, sz, i + 1, -1);
    printf("\n");
    newSleep(sleep);
    system("clear"); 
    printf("\n sorted array: ");
    printArr(arr, sz, i + 1, -1);
    printf("\n - process log - \n");
    printList(list, &printAsLog); 
    printArr(arr, sz, i + 1, -1);
    printf("the last number is %d\n", arr[sz - 1]);
    freeList(list, &freeLog);
}

/* function below swaps stuff */
void swap(int * x, int * y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/* prints the array + colors
 * did not use separate function for colors
 * found this easier to track and "visualise" */
void printArr(int * arr, int sz, int sortUntil, int curMin)
{
    int x;
    for(x = 0; x < sz; x++)
    {
        if (x < sortUntil)
        {
            printf("\x1b[32m");
        }
        else if (x == curMin)
        {
            printf("\x1b[31m");
        }
        printf("%03d ", arr[x]);
        printf("\x1b[0m");
    }
    printf("\n");
}

/* printing the arrow */
void arrowprint(int pos)
{
    int x;
    int k = 4*pos+1;
    for(x = 0; x < k; x++)
    {
        printf("%c", ' ');
    }
    printf("%c\n", '^');
}

/* prints array with blank spaces (and colors!) during swap animation */
void printwithout(int * arr, int sz, int x, int y, int sortUntil)
{
    int i;
    for(i = 0; i < sz; i++)
    {
        if (i == x || i == y)
        {   
            printf("    ");
        }
        else
        {
            if (i < sortUntil)
            {
                printf("\x1b[32m");
            }
            printf("%03d ", arr[i]);
            printf("\x1b[0m");
        }
    }
    printf("\n");
}

/* print top/bottom digits */
void printpadding(int val, int pad)
{
    int i;
    for (i = 0; i < pad; i++)
    {
        printf("    ");
    }
    printf("%03d\n", val);
}
