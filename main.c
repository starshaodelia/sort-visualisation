#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "io.h"
#include "linkedlist.h"
#include "newSleep.h"

int main(int argc, char **argv)
{ 
    int sleep;
    sleep = (float)atof(argv[1]); /* casts arg to a float */

    if (argc < 2 || argc > 3)
    {
        printf("to run: ./sort sleepTime [optional file]\n");
    }
    else if (argc == 2)
    {
        sortrandom(sleep);
    }
    else if (argc == 3)
    {
        readfile(argv[2], sleep); 
    }

    return 0;
}

