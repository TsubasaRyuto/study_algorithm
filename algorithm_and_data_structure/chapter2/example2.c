#include <stdio.h>
const int MAX = 200000;

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

int main(void) {
  int R[MAX], n;
  scanf("%d", &n);
  for ( int i = 0; i < n; i++ ) scanf("%d", &R[i]);

  int maxv = -2000000000;
  int minv = R[0];

  for ( int i = 1; i< n; i++) {
    maxv = max(maxv, R[i] = minv);
    minv = min(minv, R[i]);
  }

  printf("%d", maxv);
  return 0;
}
