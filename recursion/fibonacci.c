/*
 * ----------------------------
 *  フィボナッチ数列（再帰関数）
 * ----------------------------
 */


#include <stdio.h>

long fib(int n);

int main() {
  int n;

  for (n = 1; n <= 20; n++) {
    printf("%d: %ld \n", n,fib(n));
  }

  return 0;
}

long fib(int n) {
  if (n == 1 || n == 2) {
    return 1L;
  }

  return fib(n - 1) + fib(n - 2);
}
