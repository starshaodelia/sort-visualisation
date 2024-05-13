# makefile for ./sort #
# unix and c programming [comp1000], final assignment #
# author = starsha odelia #

CC = gcc
CFLAGS = -Wall -Werror -pedantic -ansi -g
OBJ = main.o sort.o io.o linkedlist.o newSleep.o
EXEC = sort

ifdef STACK
CFLAGS += -D STACK
STACK : clean $(EXEC)
endif

$(EXEC): $(OBJ)
	$(CC) $(OBJ) -o $(EXEC)

newSleep.o : newSleep.c newSleep.h
	$(CC) -c newSleep.c $(CFLAGS)

linkedlist.o : linkedlist.h
	$(CC) -c linkedlist.c $(CFLAGS)

sort.o : sort.h newSleep.h
	$(CC) -c sort.c $(CFLAGS)

main.o : main.c sort.h io.h newSleep.h
	$(CC) -c main.c $(CFLAGS)

io.o : sort.h io.h
	$(CC) -c io.c $(CFLAGS)

clean:
	rm -f $(EXEC) $(OBJ)
