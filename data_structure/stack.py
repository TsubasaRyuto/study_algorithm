"""
pythonの場合、listのappend()とpop()を使うと
listをstackとして扱える
"""

class Stack(object):
    def __init__(self):
        self.max = 10
        self.stack = [None] * self.max
        self.index = -1

    def push(self, data):
        if self.index == self.max - 1:
            print("Stack overflow")
            return

        self.index += 1
        self.stack[self.index] = data

    def pop(self):
        if self.index > -1:
            value = self.stack[self.index]
            self.stack[self.index] = None
            self.index -= 1
            return value

        print("Stack is empty")

if __name__ == '__main__':
    stack = Stack()
    stack.push(200)
    stack.push(100)
    stack.push(0)
    print(stack.pop())
    print(stack.pop())
    print(stack.pop())
