/* binary search in C */

#include <stdio.h>
#define N 14

int find_number_index(int *array, int y);

int main(void) {
  int array[] = {8, 9, 15, 18, 19, 24, 29, 31, 33, 36, 43, 50, 99, 101};
  int y = 36;
  int result = find_number_index(array, y);

  if (result > 0)
    printf("%dはarrayの%d番目にあります", y, result + 1);
  else
    printf("%dはarrayに存在しませ", y);
  return 0;
}

int find_number_index(int *array, int y) {
  int left = 0;
  int right = N - 1;

  while(right >= left) {
    int mid = left + (right - left) / 2;

    if (array[mid] == y) {
      return mid;
    }

    if (array[mid] < y) {
      left = mid + 1;
    }

    if (array[mid] > y) {
      right = mid - 1;
    }
  }

  return -1;
}

