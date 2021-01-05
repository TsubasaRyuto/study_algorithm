#include <stdio.h>
#include <string.h>
#define LEN 100005

typedef struct {
  char name[100];
  int time;
} process_p;

process_p Q[LEN];
int head, tail, n;

void enqueue(process_p value) {
  Q[tail] = value;
  tail = (tail + 1) % LEN;
}

process_p dequeue() {
  process_p x = Q[head];
  head = (head + 1) % LEN;
  return x;
}

int min(int a, int b) {
  return a < b ? a : b;
}

int main() {
  int elaps = 0, c;
  int i, q;
  process_p u;
  scanf("%d %d", &n, &q);

  for (i = 1; i <= n; i++) {
    scanf("%s", Q[i].name);
    scanf("%d", &Q[i].time);
  }

  head = 1;
  tail = n + 1;

  while (head != tail) {
    u = dequeue();
    c = min(q, u.time);
    u.time -= c;
    elaps += c;
    if (u.time > 0) {
      enqueue(u);
    } else {
      printf("%s %d\n", u.name, elaps);
    }
  }
  return 0;
}
