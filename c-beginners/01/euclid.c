/* ユーグリッドの互除法 */

#include <stdio.h>

int main(void) {
  int a = 128;
  int b = 72;
  int m, n, k, ans;

  m = a;
  n = b;

  do {
    k = m % n;
    m = n;
    n = k;
  } while (k != 0);

  ans = m;
  printf("%d\n", ans);

  return 0;
}
