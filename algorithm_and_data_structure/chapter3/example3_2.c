#include <stdio.h>
#include <time.h>

void trace(int A[], int digits) {
  for (int i = 0; i < digits; i ++) {
    if (i > 0) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");
}

// original
void mysort(int A[], int digits) {
  int n = 0;
  for (int i = 0; i < digits; i ++) {
    for (int n = 0; n < digits; n++) {
      if (n + 1 == digits) break;
      if (A[n] > A[n + 1]) {
        int before = A[n + 1];
        int after = A[n];
        A[n] = before;
        A[n + 1] = after;
      }
    }
    trace(A, digits);
    n = 0;
  }
}

// sample
void sample_sort(int A[], int N) {
  int j, i, v;
  for ( i = 1; i < N; i++ ) {
    v = A[i];
    j = i - 1;
    while ( j >= 0 && A[j] > v ) {
      A[j + 1] = A[j];
      j--;
    }
    A[j + 1] = v;
    trace(A, N);
  }
}

int main() {
  int digits;
  int A[1000];
  scanf("%d", &digits);
  for (int i = 0; i < digits; i++) scanf("%d", &A[i]);

  trace(A, digits);

  clock_t startA, endA, startB, endB;

  startA = clock();
  mysort(A, digits);
  endA = clock();

  printf(
      "my algo:%f\n",
      (double)(endA - startA) / CLOCKS_PER_SEC
  );

  startB = clock();
  sample_sort(A, digits);
  endB = clock();

  printf(
      "sample algo:%f\n",
      (double)(endB - startB) / CLOCKS_PER_SEC
  );

  return 0;
}
