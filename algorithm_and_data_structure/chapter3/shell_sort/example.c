#include <stdio.h>
#include <time.h>
#include "../../c_functions/trace.h"
#include "../../c_functions/swap.h"

void shell_sort(int A[], int digits) {
  int i, j, h;

  for ( h = 1; h <= digits/9; h = 3 * h + 1);

  for (; h > 0; h /= 3) {
    for (i = h; i < digits; i++) {
      j = i;
      while ( (j > h - 1 ) && (A[j - h] > A[j])) {
        swap(&A[j - h], &A[j]);
        j -= h;
      }
    }
  }
  trace(A, digits);
}

int main() {
  int digits;
  int A[10000];

  scanf("%d", &digits);
  for (int i = 0; i < digits; i++) scanf("%d", &A[i]);

  trace(A, digits);

  clock_t start, end;

  start = clock();
  shell_sort(A, digits);
  end = clock();

  printf(
      "insert sort algo:%f\n",
      (double)(end - start) / CLOCKS_PER_SEC
  );

  return 0;
}
