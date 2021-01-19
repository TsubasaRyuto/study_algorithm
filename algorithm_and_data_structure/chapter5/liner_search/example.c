#include <stdio.h>

int search(int A[], int n, int value) {
  int i = 0;
  A[n] = value;
  while(A[i] != value) i++;
  return i != n;
}

int main() {
  int i, n, A[10000+1], q, value, sum = 0;

  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &A[i]);

  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    scanf("%d", &value);
    if (search(A, n, value)) sum++;
  }

  printf("%d\n", sum);
  return 0;
}
