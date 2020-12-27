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


func selection_sort(a [100]int , digits int) {
  for i := 0; i < digits; i++ {
    min_index := i
    for j := i; j < digits; j++ {
      if a[j] < a[min_index] {
        min_index = j
      }
    }

    before := a[i]
    after := a[min_index]

    a[i] = after
    a[min_index] = before
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
  selection_sort(a, digits)
}
