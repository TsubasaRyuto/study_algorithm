/* 暗号解読 */
/* A = 65, B = 66, Z = 90 */
/* K - A = 75 - 65 = 10 => table配列のindex10に格納されている文字Aを出力 */

#include <stdio.h>

int main(void) {
  char table[] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M', '?'};
  char *p, *ango="KSOIDEPZ";

  int i;

  p = ango;

  while (*p != '\0') {
    if ('A' <= *p && *p <= 'Z') {
      i = *p - 'A';
    } else {
      i = 26;
    }

     putchar(table[i]);
    p++;
  }

  printf("\n");
  return 0;
}
