#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  int key;
  struct node *next, *prev;
} NODE;

NODE *head = NULL;
NODE *tail = NULL;

NODE *createNode();
void insert_node(int key);
void delete_node(int key);
void print_node();

int main() {
  int command_count, key, i;
  char command[20];

  puts("----------- 入力 -----------");
  scanf("%d", &command_count);

  for (i=0; i < command_count; i++) {
    scanf("%s %d", command, &key);

    if (strcmp(command, "delete") == 0) {
      delete_node(key);
    }

    if (strcmp(command, "insert") == 0) {
      insert_node(key);
    }
  }

  print_node();
  return 0;
}

NODE *create_node() {
  NODE *new_node;
  new_node = (NODE *)malloc(sizeof(NODE));

  return new_node;
}

void insert_node(int key) {
  NODE *new_node;
  new_node = create_node();
  new_node->key = key;

  if ((head == NULL) && (tail == NULL)) {
    head = new_node;
    tail = new_node;
  } else {
    tail->next = new_node;
    new_node->prev = tail;
    tail = new_node;
  }

  tail->next = NULL;
}

void delete_node(int key) {
  NODE *current, *prev_node;

  current = head;
  prev_node = NULL;

  while (current != NULL) {
    if (current->key == key) {
      if (current == head) {
        head = current->next;
        head->prev = NULL;
      } else {
        prev_node->next = current->next;
        current->next->prev = prev_node;
      }
      free(current);
      break;
    }

    prev_node = current;
    current = current->next;
  }
}

void print_node() {
  NODE *current;

  puts("----------- 出力 -----------");
  if ((head == NULL) && (tail == NULL)) {
    puts("リストは空です");
    return;
  }

  current = tail;

  while (1) {
    printf("%d ", current->key);

    if (current->prev == NULL) {
      break;
    }

    current = current->prev;
  }
  printf("\n");
}
