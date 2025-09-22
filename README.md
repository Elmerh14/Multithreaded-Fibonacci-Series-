# Fibonacci Performance Comparison  


## Setup  
1. Ensure all source files (`fibonacciSingle.c`, `fibonacci_multi.c`) and the provided `makefile` are in the **same directory**.  

## Compilation  
- To compile **both programs**:  
  ```bash
  make all
  ```  

- To compile just one program (e.g., `fibonacciSingle`):  
  ```bash
  make fibonacciSingle
  ```  
  or  
  ```bash
  make fibonacci_multi
  ```  

This will create executables in the same directory.  

## Running the Programs  
Run either program with:  
```bash
./fibonacciSingle
```  
or  
```bash
./fibonacci_multi
```  

Each program will prompt you to enter the maximum Fibonacci number you want to generate (up to 100). The program will then calculate the sequence and display the total execution time.  

## Example  
```bash
./fibonacciSingle
Type in the largest Fibonacci sequence number you wish to generate: 10
Fib(0) = 0
Fib(1) = 1
...
Fib(10) = 55
Total execution time of finding a Fibonacci sequence of 10 = 0.267 ms.
```
