#include <stdio.h>
#include <time.h>
#include "../../c_functions/trace.h"

// sample
void bubble_sort(int A[], int N) {
  int j, i, v;
  for ( i = 0; i < N; i++ ) {
    for (j = N - 1; j > i; j--) {
      if (A[j] < A[j - 1]) {
        int before = A[j - 1];
        int after = A[j];

        A[j] = before;
        A[j - 1] = after;
      }
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
  bubble_sort(A, digits);
  end = clock();

  printf(
      "bubble sort algo:%f\n",
      (double)(end - start) / CLOCKS_PER_SEC
  );

  return 0;
}
