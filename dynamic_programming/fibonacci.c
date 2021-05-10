/*
 * -----------------------------
 *  動的計画法によるフィボナッチ
 * -----------------------------
 */

#include <stdio.h>

#define MAX_N 100

int fibo(int n);

int main() {
  int n = 30;
  
  printf("n = %d の時フィボナッチ数列のf(%d) = %d \n", n, n, fibo(n));

  return 0;
}

int fibo(int n) {
  int i;
  int a[MAX_N];

  a[1] = 1;
  a[2] = 1;

  for (i = 3; i <=n; i++) {
    a[i] = a[i - 1] + a[i - 2];
  }

  return a[n];
}
