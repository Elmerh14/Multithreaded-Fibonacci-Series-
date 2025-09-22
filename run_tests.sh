#!/bin/bash

# clear old results if they exist
>single_times.csv
>thread_times.csv

# Run single process version 10 times
for i in {1..10}; do
  echo 100 | ./fibonacciSingle | grep "Total execution time" | awk '{print $12}' >>single_times.csv
done

# Run threaded version 10 times
for i in {1..10}; do
  echo 100 | ./fibonacci_multi | grep "Total execution time" | awk '{print $12}' >>thread_times.csv
done
