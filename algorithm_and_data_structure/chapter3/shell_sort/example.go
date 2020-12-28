package main
import "fmt"

func swap(x, y *int) {
  var temp int

  temp = *x
  *x = *y
  *y = temp
}

func trace(a [100]int, digits int) {
  for i := 0; i < digits; i++ {
    if i > 0 {
      fmt.Print(" ")
    }
    fmt.Print(a[i])
  }
  fmt.Print("\n")
}

func shell_sort(a [100]int, digits int) {
  var i, j, h int
  for h = 1; h <= digits / 9; h = 3 * h + 1 {}

  for ; h > 0; h /= 3 {
    for i = h; i < digits; i++ {
      j = i
      for (j > h - 1) && (a[j - h] > a[j]) {
        swap(&a[j - h], &a[j])
        j -= h
      }
    }
  }

  trace(a, digits)
}

func main() {
  var digits int
  var a [100]int

  fmt.Scan(&digits)
  for i := 0; i < digits; i++ {
    fmt.Scan(&a[i])
  }

  trace(a, digits)
  shell_sort(a, digits)
}
