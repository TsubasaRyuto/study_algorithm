package main

import (
  "fmt"
  "strings"
)

type student struct {
  name string
  id int
  next *student
}

var head, tail *student

func main() {
  var input, command string

  for {
    fmt.Println("----------- 操作方法 --------")
    fmt.Println("A : リストの末尾にノードを追加します")
    fmt.Println("P : リスト内のノードを全て表示します")
    fmt.Println("I : リスト内の任意の場所にノードを挿入します")
    fmt.Println("D : 任意のノードを削除します")
    fmt.Println("コマンドを入力してください:")

    fmt.Scan(&input)
    command = strings.ToUpper(input)
    switch command {
    case "A":
      addNodeTopList()
    case "P":
      printList();
      fmt.Println("リストを表示する")
    case "I":
      insertNode();
      fmt.Println("ノードを挿入")
    case "D":
      deleteNode();
      fmt.Println("ノードを削除する")
    case "E":
      printList()
      fmt.Println("処理終了")
      break
    default:
      fmt.Println("無効なコマンドです。")
    }
  }
}

func createStudent() *student {
  newStudent := new(student)
  return newStudent
}

func addNodeTopList() {
  var newStudent *student = createStudent()
  var inputId int
  var inputName string

  fmt.Println("学籍番号を入力: ")
  fmt.Scan(&inputId)
  newStudent.id = inputId

  fmt.Println("名前を入力: ")
  fmt.Scan(&inputName)
  newStudent.name = inputName

  if head == nil {
    head = newStudent
    tail = newStudent
  } else {
    tail.next = newStudent
    tail = newStudent
  }

  tail.next = nil
  fmt.Println("ノードを追加しました")
}

func insertNode() {
  var insertTargetName, inputName string
  var inputId int
  var current, temp, newStudent *student

  fmt.Println("挿入先のノードのnameを入力してください")
  fmt.Println("入力されたnameを持つノードの後ろに、新しいノードを挿入します");
  fmt.Scan(&insertTargetName)

  current = head
  for current == nil {
    if current.name == insertTargetName {
      fmt.Println("ノードが見つかりました")
      break
    } else {
      current = current.next
    }
  }

  if current == nil {
    fmt.Println("ノードが見つかりませんでした")
    return
  }

  newStudent = createStudent()
  fmt.Println("学籍番号を入力: ")
  fmt.Scan(&inputId)
  newStudent.id = inputId

  fmt.Println("名前を入力: ")
  fmt.Scan(&inputName)
  newStudent.name = inputName

  temp = current.next
  current.next = newStudent
  newStudent.next = temp

  fmt.Println("ノードを挿入しました");
}

func deleteNode() {
  var deleteNodeName string
  var current, prev *student

  current = head
  prev = nil

  for current != nil {
    if current.name == deleteNodeName {
      fmt.Println("ノードが見つかりました")
      break
    } else {
      prev = current
      current = current.next
    }
  }

  if current == nil {
    fmt.Println("ノードが見つかりませんでした")
    return
  }

  if current == head {
    head = current.next
  } else {
    prev.next = current.next
  }

  fmt.Println("ノードを削除しました")
}

func printList() {
  var current *student

  if head == nil && tail == nil {
    fmt.Println("リストは空です")
    return
  }

  current = head

  fmt.Println("--------------------")

  for {
    fmt.Println("学籍番号 : ", current.id)
    fmt.Println("名前     : ", current.name)
    fmt.Println("自身のノードの場所 : ", &current)
    fmt.Println("次のノードの場所   : ", &current.next)
    fmt.Println("----------------------------------")
    if current.next != nil {
        current = current.next
    } else {
      fmt.Println("最後まで表示しました。")
      break
    }
  }
}
