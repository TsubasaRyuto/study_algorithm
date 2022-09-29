class Node:
    def __init__(self, data, next_node = None):
        self.data = data
        self.next = next_node


class LinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        new_node = Node(data)

        if self.head is None:
            # HEAD
            self.head = new_node
            return

        last_node = self.head
        while last_node.next:
            last_node = last_node.next
        last_node.next = new_node


    def insert(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node

    def remove(self, data):
        current_node = self.head

        if current_node and current_node.data == data:
            self.head = current_node.next
            current_node = None
            return

        previous_node = None
        while current_node and current_node.data != data:
            previous_node = current_node
            current_node = current_node.next

        if current_node is None:
            return

        previous_node.next = current_node.next
        current_node = None

    def reverse_iterative(self):
        previous_node = None
        current_node = self.head

        while current_node:
            next_node = current_node.next
            current_node.next = previous_node

            previous_node = current_node
            current_node = next_node

        self.head = previous_node


    def print(self):
        current_node = self.head

        while current_node:
            print(current_node.data)
            current_node = current_node.next


if __name__ == '__main__':
    l = LinkedList()
    l.append(1)
    l.append(2)
    l.append(3)
    l.append(4)
    l.print()

    print("#############")
    l.reverse_iterative()
    l.print()

