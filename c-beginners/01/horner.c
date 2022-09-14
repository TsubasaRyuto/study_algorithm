/* hornerの方法 - 多項式計算 */
/* 漸化式 f(0) = an, f(x) = f(x-1) * x + a(n-1) */

# include <stdio.h>

double fn(double, double *, int);

int main(void) {
  double a[] = {1, 2, 3, 4, 5}; // f(x) = 5x**4 + 4x**3 + 3x**2 + 2x + 1
  double x;

  for (x = 1; x <= 5; x++) {
    printf("fn(%f)=%f\n", x, fn(x, a, 4));
  }
}

double fn(double x, double a[], int n) {
  double p;
  int i;

  p = a[n];

  for (i = n - 1; i >= 0; i--) {
    p = p * x + a[i];
  }

  return p;
}
