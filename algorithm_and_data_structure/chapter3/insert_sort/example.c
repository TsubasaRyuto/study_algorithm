#include <stdio.h>
#include <time.h>
#include "../../c_functions/trace.h"

void insert_sort(int A[], int N) {
  int j, i, v;
  for ( i = 1; i < N; i++ ) {
    v = A[i];
    j = i - 1;
    while ( j >= 0 && A[j] > v ) {

      int before = A[j + 1];
      int after = A[j];

      A[j] = before;
      A[j + 1] = after;
      j--;
    }
    trace(A, N);
  }
}

int main() {
  int digits;
  int A[10000];
  scanf("%d", &digits);
  for (int i = 0; i < digits; i++) scanf("%d", &A[i]);

  trace(A, digits);

  clock_t start, end;

  start = clock();
  insert_sort(A, digits);
  end = clock();

  printf(
      "insert sort algo:%f\n",
      (double)(end - start) / CLOCKS_PER_SEC
  );

  return 0;
}
