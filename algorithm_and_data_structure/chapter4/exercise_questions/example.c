#include <stdio.h>
#include <string.h>

int value_s[2000];
int value_s_tail = -1;

int area_s[2000];
int area_s_tail = -1;

void push(int value);
int pop();
void area_push(int value);

int main() {
  int i, width, total, value1, value2;
  char input[2000];

  scanf("%s", input);
  while(input[i] != '\0'){
    if (input[i] == '\\') {
      push(i);
    } else if (input[i] == '/' && value_s_tail >= 0) {
      value1 = pop();
      width = i - value1;
      total += width;
    }

    ++i;
  }

  printf("%d\n", total);

  return 0;
}

void push(int value) {
  value_s[++value_s_tail] = value;
}

int pop() {
  int temp = value_s[value_s_tail];
  value_s_tail--;
  return temp;
}

void area_push(int value) {
  area_s[++area_s_tail] = value;
}
