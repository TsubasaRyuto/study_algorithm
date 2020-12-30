package main

import (
  "fmt"
  "strconv"
)

var arry [1000]int
var arry_top int

func push(value int) {
  arry_top++
  arry[arry_top] = value
}

func pop() int {
  temp := arry[arry_top]
  arry_top--
  return temp
}

func main() {
  var value1, value2, result int
  var formula string

  for {
    fmt.Scan(&formula)
    if formula == "=" {
      break
    }

    switch formula {
      case "+":
        value2 = pop()
        value1 = pop()
        result = value1 + value2
        push(result)
      case "-":
        value2 = pop()
        value1 = pop()
        result = value1 - value2
        push(result)
      case "*":
        value2 = pop()
        value1 = pop()
        result = value1 * value2
        push(result)
      case "/":
        value2 = pop()
        value1 = pop()
        result = value1 / value2
        push(result)
      default:
        i, _ := strconv.Atoi(formula)
        push(i);
    }
  }

  result = pop()
  fmt.Println(result)
}
