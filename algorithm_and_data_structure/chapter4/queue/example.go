package main

import (
  "fmt"
)

const MAX int = 1000

type Process struct {
  name string
  time int
}

var que [MAX]Process
var head, tail, n int

func enqueue(value Process) {
  que[tail] = value;
  tail = (tail + 1) % MAX
}

func dequeue() Process {
  var x Process = que[head]
  head = (head + 1) % MAX
  return x
}

func min(a, b int) int {
  var x int
  if a < b {
    x = a
  } else {
    x = b
  }
  return x
}

func main() {
  var elaps int = 0
  var i, q, c int
  var u Process

  fmt.Scan(&n, &q)

  for i = 1; i <= n; i++ {
    fmt.Scan(&que[i].name)
    fmt.Scan(&que[i].time)
  }

  head = 1
  tail = n + 1

  for head != tail {
    u = dequeue()
    c = min(q, u.time)
    u.time -= c;
    elaps += c;
    if u.time > 0 {
      enqueue(u);
    } else {
      fmt.Printf("%s %d\n", u.name, elaps)
    }
  }
}
