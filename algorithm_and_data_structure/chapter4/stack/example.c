#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int arry_top, arry[1000];

void push(int value) {
  arry[++arry_top] = value;
}

int pop() {
  int temp = arry[arry_top];
  arry_top--;
  return temp;
}

int main() {
  int i, value1, value2, result;
  char num[1000];
  char formula[1000];

  while (1) {
    scanf("%[^\n]", formula);
    if (formula[i] == '=') break;

    switch(formula[i]){
      case ' ':
        memset(num, '\0', sizeof(num));
        break;
      case '+':
        value2 = pop();
        value1 = pop();
        result = value1 + value2;
        push(result);
        break;
      case '-':
        value2 = pop();
        value1 = pop();
        result = value1 - value2;
        push(result);
        break;
      case '*':
        value2 = pop();
        value1 = pop();
        result = value1 * value2;
        push(result);
        break;
      case '/':
        value2 = pop();
        value1 = pop();
        result = value1 / value2;
        push(result);
        break;
      default:
        if (num[0] == '\0') {
          strcpy(num, &formula[i]);
          printf("%d\n", atoi(num));
          push(atoi(num));
        } else {
          char temp[1];
          temp[0] = formula[i];
          strcat(num, temp);
          arry[arry_top] = atoi(num);
        }
    }

    i++;
  }

  result = pop();
  printf ("%d\n", result);
  return 0;
}
