package main

import "fmt"

func trace(a [5]int, digits int) {
  for i := 0; i < digits; i++ {
    if i > 0 {
      fmt.Print(" ")
    }
    fmt.Print(a[i])
  }
  fmt.Println("\n")
}

func insert_sort(a [5]int, digits int) {
  var j, i, v int
  for i = 1; i < digits; i++ {
    v = a[i]
    j = i - 1

    for j >= 0 && a[j] > v {
      before := a[j + 1];
      after := a[j];

      a[j] = before;
      a[j + 1] = after;
      j--
    }
    trace(a, digits)
  }
}

func main() {
  var digits int
  var a [5]int

  fmt.Scan(&digits)
  for i := 0; i < digits; i++ {
    fmt.Scan(&a[i])
  }

  trace(a, digits)
  insert_sort(a, digits)
}

