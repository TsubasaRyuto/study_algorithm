/* Linear search in C */

#include <stdio.h>
#include <stdlib.h>

#define N 1000

int main(void){
  int array[N], i, result_index;
  int y = 115;

  for(i = 0; i < N; i++) {
    array[i] = rand() % 1000 + 1;
  }

  printf("検索対象 = %d\n", y);

  for (i = 0; i < N; i++) {
    if (array[i] == y) {
      result_index = i;
      printf("%dはarrayの%d番目にあります \n", y, i + 1);

      return 0;
    }
  }

  printf("%dはarrayに存在しません \n", y);
  return 0;
}
