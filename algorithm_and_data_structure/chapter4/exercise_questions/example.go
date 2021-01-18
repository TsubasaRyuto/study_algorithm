package main

import (
  "fmt"
)

var value_stuck []int
var value_s_tail int = -1

func pop(arry []int) int {
  temp := arry[len(arry) - 1]
  value_stuck = arry[:len(arry) - 1]
  return temp
}

func main() {
  i := 0
  var width, total, value1 int
  var input string

  fmt.Scan(&input)

  for _, c := range input {
    if c == '\\' {
      value_stuck = append(value_stuck, i)
    } else if c == '/' && len(value_stuck) - 1 >= 0 {
      value1 = pop(value_stuck)
      width = i - value1
      total += width
    }
    i++
  }

  fmt.Println(total)
}
