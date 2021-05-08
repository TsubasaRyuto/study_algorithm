/*
 * ----------------------
 *  Horner's rule (再帰)
 * ----------------------
 */

#include <stdio.h>

#define N 4
double forner(double x, double a[], int i);

int main() {
  double a[] = { 1, 2, 3, 4, 5 };
  printf("%f \n", forner(2, a, N));
}

double forner(double x, double a[], int i) {
  if (i == 0) return a[N];
  
  // F(i) = F(i - 1) * x + A(n-1)
  return forner(x, a, i - 1) * x + a[N - i];
}
