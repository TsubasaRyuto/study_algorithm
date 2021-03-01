#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VALUE_SIZE 12
#define TABLE_SIZE 100

typedef struct node {
  char value[MAX_VALUE_SIZE];
  struct node *pNextNode;
} node_t;

int hashFunction(char *value) {
  int sum = 0;
  int i = 0;
  while (value[i] != '\0') {
    sum += value[i];
    i++;
  }

  return sum % TABLE_SIZE;
}

void initHashTable(node_t *pHashTable[TABLE_SIZE]) {
  int i;

  for (i = 0; i < TABLE_SIZE; i++) {
    pHashTable[i] = NULL;
  }
}


node_t* initNode(char *value) {
  node_t* pNode = NULL;

  pNode = (node_t*)malloc(sizeof(node_t));
  if(pNode == NULL) {
    printf("init malloc error\n");
    return NULL;
  }

  strcpy(pNode->value, value);
  pNode->pNextNode = NULL;

  return pNode;
}

void insert(node_t *pHashTable[TABLE_SIZE], char *value) {
  node_t* pNode = NULL;
  node_t* pPreNode = NULL;
  int hashVal = hashFunction(value);
  if (strlen(value) > MAX_VALUE_SIZE - 1) {
    printf("arg error\n");
    return;
  }
  if (pHashTable[hashVal] == NULL) {
    pHashTable[hashVal] = initNode(value);
    return;
  }

  pNode = pHashTable[hashVal];
  pPreNode = pNode;

  while (pNode != NULL) {
    if (strcmp(value, pNode->value) == 0) return;
    pPreNode = pNode;
    pNode = pNode->pNextNode;
  }

  pPreNode->pNextNode = initNode(value);
}

void deleteKey(node_t *pHashTable[TABLE_SIZE], char *value) {
  node_t* pNode = NULL;
  node_t* pPreNode = NULL;
  int hashVal = hashFunction(value);

  if (pHashTable[hashVal] == NULL) return;

  pNode = pHashTable[hashVal];
  while(pNode != NULL) {
    if (strcmp(value, pNode->value) == 0) {
      if (pNode == pHashTable[hashVal]) {
        pHashTable[hashVal] = pNode->pNextNode;
      } else {
        pPreNode->pNextNode = pNode->pNextNode;
      }

      free(pNode);
      return;
    }
  }
  pPreNode = pNode;
  pNode = pNode->pNextNode;
}

void deleteNode(node_t *pHashTable[TABLE_SIZE]) {
  node_t* pNode = NULL;
  node_t* pPreNode = NULL;
  int i;

  for (i = 0; i < TABLE_SIZE; i++) {
    if(pHashTable[i] != NULL) {
      pNode = pHashTable[i];
      while(pNode != NULL) {
        pPreNode = pNode;
        pNode = pNode->pNextNode;
        free(pPreNode);
      }
      pHashTable[i] = NULL;
    }
  }
}

void findValue(node_t *pHashTable[TABLE_SIZE], char *value) {
  node_t* pNode = NULL;
  int hashVal = hashFunction(value);
  if (pHashTable[hashVal] != NULL) {
      pNode = pHashTable[hashVal];
      while (pNode != NULL) {
        if (strcmp(value, pNode->value) == 0) {
          printf("探索結果：YES\n");
          return;
        }
        pNode = pNode->pNextNode;
      }
      printf("探索結果：NO\n");
  } else {
    printf("探索結果：NO\n");
  }
}

int main() {
  int i, count;
  char order[10], value[MAX_VALUE_SIZE];
  node_t* pHashTable[TABLE_SIZE];

  initHashTable(pHashTable);

  scanf("%d", &count);

  for (i = 0; i < count; i++) {
    scanf("%s %s", order, value);

    if (strcmp("insert", order) == 0) {
      insert(pHashTable, value);
    } else if (strcmp("delete", order) == 0) {
      deleteKey(pHashTable, value);
    } else if (strcmp("find", order) == 0) {
      findValue(pHashTable, value);
    } else {
      printf("ERROR\n");
    }
  }
  deleteNode(pHashTable);
  return 0;
}
