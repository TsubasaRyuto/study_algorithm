#include <stdio.h>
#include <stdlib.h>

int main(void) {
  long array[4] = {10, 20, 30, 40};

  for(int i = 0; i < 4; i++) {
    printf("No: %d, value: %d, addess: %p \n", i, array[i], &array[i]);
  }

  return 0;
}
