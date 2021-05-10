#include <stdio.h>
#include <stdlib.h>

#define N 1000

int main() {
  int n, i;
  int DP[N];
  int h[N];

  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &h[i]);

  DP[0] = 0;
  DP[1] = abs(h[0] - h[1]);

  for (i = 2; i <= n - 1; i++) {
    int h_1, h_2;
    h_1 = DP[i - 1] + abs(h[i - 1] - h[i]);
    h_2 = DP[i - 2] + abs(h[i - 2] - h[i]);

    DP[i] = (h_1 > h_2) ? h_2 : h_1;
  }

  printf("最小値 = %d\n", DP[n - 1]);

  return 0;
}
