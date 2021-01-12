package main

import (
  "fmt"
)

type node struct {
  key int
  next, prev *node
}

var head, tail *node

func main() {
  var command_count, key, i int
  var command string

  fmt.Println("----------- 入力 -----------")
  fmt.Scan(&command_count)

  for i=0; i < command_count; i++ {
    fmt.Scan(&command, &key)

    if command == "delete" {
      delete_node(key)
    }

    if command == "insert" {
      insert_node(key)
    }
  }

  print_node()
}


func create_node() *node {
  new_node := new(node)
  return new_node
}

func insert_node(key int) {
  var new_node *node
  new_node = create_node()
  new_node.key = key

  if head == nil && tail == nil {
    head = new_node
    tail = new_node
  } else {
    tail.next = new_node
    new_node.prev = tail
    tail = new_node
  }

  tail.next = nil
}

func delete_node(key int) {
  var current, prev_node *node

  current = head
  prev_node = nil

  for current.key == key {
    if current == head {
      head = current.next
      head.prev = nil
    } else {
      prev_node.next = current.next
      current.next.prev = prev_node
    }

    prev_node = current
    current = current.next
  }
}

func print_node() {
  var current *node

  fmt.Println("---------- 出力 ----------")
  if head == nil && tail == nil {
    fmt.Println("リストは空です")
    return
  }

  current = tail

  for {
    fmt.Printf("%d ", current.key)

    if current.prev == nil {
      break
    }

    current = current.prev
  }

  fmt.Printf("\n")
}
