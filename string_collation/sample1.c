// 素朴な文字列照合

#include <stdio.h>
#include <string.h>

int main() {
  char input[100];
  char collation[100];
  int i, j;

  i = 0;
  j = 0;

  scanf("%s", input);
  scanf("%s", collation);

  while(i + j < strlen(input)) {
    if (collation[j] == input[i + j]) {
      j += 1;

      if (j == strlen(collation)) {
        printf("一致したインデックス: %d \n", i);
        return 0;
      }
    }else {
      i += 1;
      j = 0;
    }
  }

  printf("マッチしませんでした");

  return 0;
}
