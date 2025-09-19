

CC=gcc
CFLAGS = -g -Wall

all: fibonacciSingle fibonacci_multi

fibonacciSingle: fibonacciSingle.c fibonacci_multi.c
	$(CC) $(CFLAGS) -o fibonacciSingle fibonacciSingle.c 

fibonacci_multi: fibonacci_multi.c
	$(CC) $(CFLAGS) -pthread -o fibonacci_multi fibonacci_multi.c

clean:
	rm fibonacciSingle fibonacci_multi


