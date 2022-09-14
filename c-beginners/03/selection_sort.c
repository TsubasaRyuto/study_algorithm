/* selection sort in C */

#include <stdio.h>
#define N 10

int main(void) {
  int array[] = { 5, 2, 7, 10, 1, 3, 8, 4, 9, 6 };
  int min_num_index = 0;
  int current_index;

  for (current_index = 0; current_index < N; current_index++) {
    int min_num = array[current_index];
    min_num_index = current_index;

    for (int j = current_index + 1; j < N; j++) {
      if (min_num > array[j]) {
        min_num = array[j];
        min_num_index = j;
      }
    }

    array[min_num_index] = array[current_index];
    array[current_index] = min_num;
  }

  for (int i = 0; i < N; i++) {
    printf("%d ", array[i]);
  }

  return 0;
}
