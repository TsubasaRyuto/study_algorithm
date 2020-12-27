package main

import "fmt"

func trace (a [100]int, digits int) {
  for i := 0; i < digits; i++ {
    if i > 0 {
      fmt.Print(" ")
    }
    fmt.Print(a[i])
  }
  fmt.Print("\n")
}

func bubble_sort(a [100]int, digits int) {
  var j, i int
  for i = 0; i < digits; i++ {
    for j = digits - 1; j > i; j-- {
      if a[j] < a[j - 1] {
        before := a[j - 1];
        after := a[j];

        a[j] = before;
        a[j - 1] = after;
      }
    }
    trace(a, digits)
  }
}

func main() {
  var digits int
  var a [100]int

  fmt.Scan(&digits)
  for i := 0; i < digits; i++ {
    fmt.Scan(&a[i])
  }

  trace(a, digits)
  bubble_sort(a, digits)
}
