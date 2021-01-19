package main

import (
  "fmt"
)

func search(A [10000+1]int, n, value int) bool {
  var i int = 0
  A[n] = value
  for A[i] != value {
    i++
  }

  return i != n
}

func main() {
  var n, q, value int
  var sum int = 0
  var A [10000+1]int

  fmt.Scan(&n)
  for i := 0; i < n; i++ {
    fmt.Scan(&A[i])
  }

  fmt.Scan(&q)
  for i := 0; i < q; i++ {
    fmt.Scan(&value)
    if search(A, n, value) {
      sum++
    }
  }

  fmt.Println(sum)
}
