"""
pythonの場合、listのappend()とpop(0)を使うと
listをqueueとして扱える
"""

class Queue(object):
    def __init__(self):
        self.max = 10
        self.index = -1
        self.queue = [None] * self.max

    def enqueue(self, data):
        self.index += 1
        self.queue[self.index] = data

    def dequeue(self):
        value = self.queue[0]
        self.index -= 1

        for i in range(self.max):
            if self.queue[i] is None:
                break

            self.queue[i] = self.queue[i + 1]

        return value

if __name__ == '__main__':
    q = Queue()
    q.enqueue(10)
    q.enqueue(20)
    q.enqueue(30)

    print(q.dequeue())
    print(q.dequeue())

