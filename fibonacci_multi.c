#include <pthread.h>
#include <stdio.h>
#include <time.h>

// helper to print __int128
void print_int128(__int128 n) {
  if (n == 0) {
    printf("0");
    return;
  }
  char buffer[64]; // large enough for 128-bit
  int i = 0;
  while (n > 0) {
    buffer[i++] = (n % 10) + '0';
    n /= 10;
  }
  for (int j = i - 1; j >= 0; j--) {
    putchar(buffer[j]);
  }
}
// global variable
int n;

void *fibonacci(void *arg) {
  // initialize the first, second, and next term
  __int128 t0 = 0, t1 = 1, tn;
  // if statments for edge case, in case user enters 0 or 1
  if (n >= 0) {
    printf("Fib(0) = ");
    print_int128(t0);
    printf("\n");
  }
  if (n >= 1) {
    printf("Fib(1) = ");
    print_int128(t1);
    printf("\n");
  }

  for (int i = 2; i <= n; i++) {
    // calculate the next term
    tn = t0 + t1;
    // print next term
    printf("Fib(%d) = ", i);
    print_int128(tn);
    printf("\n");
    // update the next two previous terms
    t0 = t1;
    t1 = tn;
  }
  pthread_exit(NULL);
}

int main() {
  pthread_t tid;
  pthread_attr_t attr;

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

  pthread_attr_init(&attr); // initailize defoult attributes
  pthread_create(&tid, &attr, fibonacci,
                 NULL);    // start a thread running fibonnaci function
  pthread_join(tid, NULL); // wait for that thread to finish

  // end clock
  end = clock();
  double totalTime = ((double)(end - start) / CLOCKS_PER_SEC) * 1000;

  printf(
      "Total execution time of finding a Fibonacci sequence of %d = %.3f ms.\n",
      n, totalTime);

  return 0;
}
