/* bubble sort in C */

#include <stdio.h>
#define N 10

int main(void) {
  int array[] = { 5, 2, 7, 10, 1, 3, 8, 4, 9, 6 };

  int current_index;
  int search_index = N;

  for (current_index = 0; current_index < N; current_index++) {
    search_index -= 1;

    for (int inner_index = 0; inner_index < search_index; inner_index++) {
      if (array[inner_index] > array[inner_index + 1]) {
        int tmp = array[inner_index];
        array[inner_index] = array[inner_index + 1];
        array[inner_index + 1] = tmp;
      }
    }
  }

  for (int i = 0; i < N; i++) {
    printf("%d ", array[i]);
  }
}

