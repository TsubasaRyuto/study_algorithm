/* モンテカルロ方による円周率の計算 */

#include <stdio.h>
#include <stdlib.h>

#define NUM 2147483647

double rnd(void);

int main(void) {
  double x, y, pai;
  int i, in = 0;

  for (i=0; i<NUM; i++) {
    x=rnd();
    y=rnd();
    if (x*x+y*y <= 1) {
      in++;
    }
  }

  pai = (double)4*in/NUM;
  printf("円周率＝ %f\n", pai);
  return 0;
}

double rnd(void) {
  return (double)rand() / (RAND_MAX+0.1);
}
