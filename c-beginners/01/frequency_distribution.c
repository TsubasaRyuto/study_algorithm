/* 度数分布 */

#include <stdio.h>
#define Num 20

int main(void) {
  int a[] = {35, 25, 56, 66, 86, 45, 33, 87, 57, 98, 76, 64, 67, 77, 100, 48, 43, 60, 98, 12};
  int i, rank, histo[11];
  for (i = 0; i<= 10; i++) {
    histo[i] = 0;
  }

  for (i = 0; i < Num; i++) {
    rank = a[i] / 10; // 1/10に写像した
    if (0 <= rank && rank <= 10) {
      histo[rank]++;
    }
  }

  for (i = 0; i<= 10; i++) {
    printf("%3d - :%3d\n", i*10, histo[i]);
  }
  
  return 0;
}
