/* Brute Force Search in C */

#include <stdio.h>
#include <string.h>

int search(char *, char*);

int main(void) {
  static char text[] = "algorithm";
  char *target = "rit";

  int result = search(text, target);

  if (result >= 0) {
    printf("検索一致の最初のインデックス %d \n", result);
  } else {
    printf("見つかりませんでした \n");
  }

  return 0;
}

int search(char *text, char *target) {
  int i = 0, j = 0;

  while (i + j < strlen(text)) {
    if (target[j] == text[j + i]) {
      j += 1;
      if (strlen(target) == j) { return i; }
    } else {
      j = 0;
      i += 1;
    }
  }

  return -1;
}

