#include <stdio.h>
#include <time.h>
#include "../../c_functions/trace.h"

void selection_sort(int A[], int digits) {
  int i, j;
  for ( i = 0; i < digits; i++) {

    int min_index = i;

    for ( j = i; j < digits; j++) {
      if (A[j] < A[min_index]) {
        min_index = j;
      }
    }

    int before = A[i];
    int after = A[min_index];
    A[i] = after;
    A[min_index] = before;
    trace(A, digits);
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
  selection_sort(A, digits);
  end = clock();

  printf(
      "selection sort algo:%f\n",
      (double)(end - start) / CLOCKS_PER_SEC
  );
  return 0;
}

