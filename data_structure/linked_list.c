/* Linked list in C */
// NOTE: 途中

#include <stdio.h>
#include <stdlib.h>

struct tfield {
  char *name;
  struct tfield *pointer;
} *head;

struct tfield *talloc(void);
void appendList(char *name);
void printList();
void insert(void);

int main(void) {
  appendList("Python");
  appendList("Ruby");
  appendList("Go");
  printList();

  return 0;
}

struct tfield *talloc(void) {
  return (struct tfield *)malloc(sizeof(struct tfield));
}

void appendList(char *name) {
  struct tfield *new_node, *last_node;

  new_node = talloc();
  new_node->name = name;
  printf("name is %s \n", new_node->name);

  if (head == NULL) {
    head = new_node;
    return;
  }

  last_node = head;
  while (last_node->pointer == NULL) {
    last_node = last_node->pointer;
    return;
  }
  // last_node->pointer = new_node;
}

void insert(void) {
  struct tfield *new_node;

  new_node = talloc();
  scanf("%s %s", new_node->name);
  new_node->pointer = head;
  head = new_node;
}

void printList() {
  struct tfield *p;
  p = head;
  while (p != NULL) {
    printf("name is %s \n", p->name);
    p = p-> pointer;
  }
}
