#include <stdio.h>

long sum(int);

int main(void) {
  printf("result = %ld \n", sum(5));

  return 0;
}

long sum(int n) {
  if (n == 0) return 0;

  long count = n + sum(n - 1);
  printf("n = %d, %ld \n", n, count);

  return count;
}
