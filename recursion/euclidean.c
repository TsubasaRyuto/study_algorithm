/* 
 * ----------------------
 *  ユークリッドの互除法
 * ----------------------
 */

#include <stdio.h>
int gcd(int m, int n);

int main() {
  int a, b;
  printf("2つの整数を入力してください");
  scanf("%d %d", &a, &b);

  printf("最大公約数 = %d \n", gcd(a, b));
}

int gcd(int m, int n) {
  if (n == 0) return m;
  return gcd(n, m % n);
}
