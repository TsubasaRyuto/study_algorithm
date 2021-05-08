/*
 * ----------------
 *  階乗計算の再帰
 * ----------------
 */

#include <stdio.h>

long factorial(int);

int main(void) {
  int n;
  for (n = 0; n  <= 10; n++) {
    printf("%d! = %ld \n", n, factorial(n));
  }

  return 0;
}

long factorial(int n) {
  if (n == 0) return 1L;
  return n * factorial(n - 1);
}
