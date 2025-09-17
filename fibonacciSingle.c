#include <stdio.h>
#include <time.h>

void fibonacci(int n) {
  // initialize the first, second, and next term
  long long t0 = 0, t1 = 1, tn;
  // if statments for edge case, in case user enters 0 or 1
  if (n >= 0) {
    printf("Fib(0) = %lld\n", t0);
  }
  if (n >= 1) {
    printf("Fib(1) = %lld\n", t1);
  }

  for (int i = 2; i <= n; i++) {
    // calculate the next term
    tn = t0 + t1;
    // print next term
    printf("Fib(%d) = %lld\n", i, tn);
    // update the next two previous terms
    t0 = t1;
    t1 = tn;
  }
}

int main() {
  int n;
  printf(
      "Type in the largest Fibonacci sequence number you wish to generate: ");
  scanf("%d", &n);

  if (n < 0 || n > 100) {
    printf("Please enter a number between 0 and 1.\n");
    return 1;
  }

  // start the clock
  clock_t start, end;
  start = clock();

  fibonacci(n);

  // end clock
  end = clock();
  double totalTime = ((double)(end - start) / CLOCKS_PER_SEC) * 1000; // ms

  printf(
      "Total execution time of finding a Fibonacci sequence of %d = %.3f ms.\n",
      n, totalTime);

  return 0;
}
