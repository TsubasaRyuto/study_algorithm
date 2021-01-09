#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
  char name[20];
  int id;
  struct student *next;
} STUDENT;

STUDENT *head = NULL;
STUDENT *tail = NULL;

STUDENT *createStudent();
void addNodeTopList();
void printList();
void insertNode();
void deleteNode();

int main() {
  char input;
  char command;

  while (1) {
    puts("----------- 操作方法 --------");
    puts("A : リストの末尾にノードを追加します");
    puts("P : リスト内のノードを全て表示します");
    puts("I : リスト内の任意の場所にノードを挿入します");
    puts("D : 任意のノードを削除します");
    puts("コマンドを入力してください:");

    scanf("%s", &input);
    command = toupper(input);
    switch (command) {
      case 'A':
        addNodeTopList();
        break;
      case 'P':
        printList();
        break;
      case 'I':
        insertNode();
        break;
      case 'D':
        deleteNode();
        break;
      case 'E':
        printList();
        return 0;
      default:
        printf("無効なコマンドです。\n");
        break;
    }
    printf("\n");
  }
  return 0;
}

STUDENT *createStudent() {
  STUDENT *newStudent;
  newStudent = (STUDENT *)malloc(sizeof(STUDENT));

  return newStudent;
}

void addNodeTopList() {
  STUDENT *newStudent;
  int inputId;
  char inputName[20];

  newStudent = createStudent();

  puts("学籍番号を入力: ");
  scanf("%d", &inputId);
  newStudent->id = inputId;

  puts("名前を入力: ");
  scanf("%s", inputName);
  strcpy(newStudent->name, inputName);

  if ((head == NULL) && (tail == NULL)) {
    head = newStudent;
    tail = newStudent;
  } else {
    tail->next = newStudent;
    tail = newStudent;
  }

  tail->next = NULL;
  puts("ノードを追加しました");
}

void insertNode() {
  char insertTargetName[20] = "";
  STUDENT *current, *temp, *newStudent;

  int inputId;
  char inputName[20];

  puts("挿入先のノードのnameを入力してください");
  printf("入力されたnameを持つノードの後ろに、新しいノードを挿入します");
  scanf("%s", insertTargetName);

  current = head;
  while (current != NULL) {
    if (strcmp(current->name, insertTargetName) == 0) {
      puts("ノードが見つかりました");
      break;
    } else {
      current = current->next;
    }
  }

  if (current == NULL) {
    puts("ノードが見つかりませんでした");
    return;
  }

  newStudent = createStudent();

  puts("学籍番号を入力: ");
  scanf("%d", &inputId);
  newStudent->id = inputId;

  puts("名前を入力: ");
  scanf("%s", inputName);
  strcpy(newStudent->name, inputName);

  temp = current->next;
  current->next = newStudent;
  newStudent->next = temp;

  printf("ノードを挿入しました");
}

void deleteNode() {
  char insertTargetName[20] = "";
  STUDENT *current, *prev;

  puts("削除するノードのnameを入力してください");
  printf("入力されたnameを持つノードを削除します");
  scanf("%s", insertTargetName);

  current = head;
  prev = NULL;
  while (current != NULL) {
    if (strcmp(current->name, insertTargetName) == 0) {
      puts("ノードが見つかりました");
      break;
    } else {
      prev = current;
      current = current->next;
    }
  }

  if (current == NULL) {
    puts("ノードが見つかりませんでした");
    return;
  }

  if (current == head) {
    head = current->next;
  } else {
    prev->next = current->next;
  }

  free(current);

  printf("ノードを削除しました");
}

void printList() {
  STUDENT *current;

  if ((head == NULL) && (tail == NULL)) {
    puts("リストは空です");
    return;
  }

  current = head;

  puts("--------------------");

  while (1) {
    printf("学籍番号 : %d\n", current->id);
    printf("名前     : %s\n", current->name);
    printf("自身のノードの場所 : %p\n", current);
    printf("次のノードの場所   : %p\n", current->next);
    printf("----------------------------------\n");
    if (current->next != NULL) {
        current = current->next;
    } else {
      printf("最後まで表示しました。\n");
      break;
    }
  }
}
