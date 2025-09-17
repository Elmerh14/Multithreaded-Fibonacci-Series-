

CC=gcc
CFLAGS = -g -Wall

all: fibonacciSingle

fibonacciSingle: fibonacciSingle.c
	$(CC) $(CFLAGS) -o fibonacciSingle fibonacciSingle.c

clean:
	rm fibonacciSingle 
