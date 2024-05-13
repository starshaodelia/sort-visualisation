#include <stdio.h>
#include <time.h> 
#include <stdlib.h>
#include "sort.h"
#include "io.h"

/* prompts user for user input, returns the size of random array */
int randprompt(void)
{
    int randsize;

    do
    {
        printf("enter integer from 3-10: \n");
        scanf("%d", &randsize);
    }
    while (randsize < 3 || randsize > 10);
    
    return randsize;
}

/* takes in an integer to generate an array of random numbers */
int * random(int size)
{
    int i; 
    int * randArr = (int*) malloc(sizeof(int) * size);

    srand(time(NULL)); /* uses time since Epoch to generate rand no. */
    while (i < size)
    {
        /* put random values 0-999 in array */
        randArr[i] = rand() % 1000;
        i++;
    }

    return randArr;
}

/* gets called in main */
void sortrandom(float sleeptime)
{
    int sz;
    int * randArr;
    
    sz = randprompt();
    randArr = random(sz);
    selectionSort(randArr, sz, sleeptime);
    free(randArr);
}

/* reads from file, turns it into sorted array */
void readfile(char * f, float sleeptime)
{
    FILE * numlist = fopen(f, "r");
    int i;
    int lenlist = getlines(numlist);
    int * filearr = (int*) malloc(sizeof(int) * lenlist);
    char success = 1;

    if (lenlist > 10)
    {
        printf("too many elements to sort.\n");
        free(filearr);
        fclose(numlist);
    }
    else
    {
        rewind(numlist);

        for (i = 0; i < lenlist; i++) 
        {
            fscanf(numlist, "%d", &filearr[i]);
            if (filearr[i] > 999)
            {
                printf("number in file too big. \n");
                success = 0;
            }
        }
        fclose(numlist); /* somewhat good practise */
        
        if (success)
        {
            selectionSort(filearr, lenlist, sleeptime);
        }
        free(filearr);

    }
}

/* this assumes the last line of the file contains no newline */
int getlines(FILE* file)
{
    char ch;
    int linecounter = 0;
    
    while ((ch = fgetc(file)) != EOF)
    {
        if (ch == '\n')
        {
            linecounter++;
        }
    }
    
    return linecounter;
}
