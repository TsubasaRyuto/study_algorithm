#include <stdio.h>

int search(int S[], value, left, right, mid)
{
  while (left < right) {
    if (value == S[mid]) return 1;
    if (value > S[mid]) {
      left = mid + 1;
    } else {
      right = mid;
    }
    mid = (left + right) / 2;
  }
  return 0;
}

int main()
{
  int i, n, S[100000], q, value, left, right, mid, count = 0;

  scanf("%d", &n);
  for (i = 0; i < n; i++) scanf("%d", &S[i]);
  left = 0;
  right = n;
  mid = (left + right) / 2;

  scanf("%d", &q);
  for (i = 0; i < q; i++) {
    scanf("%d", &value);
    if (search(S, value, left, right, mid)) count++;
  }

  printf("%d\n", count);
  return 0;
}
