import hashlib

class HashTable(object):

    def __init__(self, size=10):
        self.size = size
        self.table = [[] for _ in range(self.size)]

    def hash(self, key):
        hash_int = hashlib.md5(key.encode()).hexdigest()
        return int(hash_int, base=16) % 10

    def add(self, key, value):
        index = self.hash(key)
        for data in self.table[index]:
            if data[0] == key:
                data[1] = value
                break
        else:
            self.table[index].append([key, value])

    def get(self, key):
        index = self.hash(key)

        for data in self.table[index]:
            if data[0] == key:
                return data[1]

    def printTable(self):
        for index in range(self.size):
            print(index, end=' ')

            for data in self.table[index]:
                print('--->', end=' ')
                print(data, end=' ')

            print()

    # NOTE: hash['key'] = valueをできるようにする
    def __setitem__(self, key, value):
        self.add(key, value)

    # NOTE: hash['key] => return value
    def __getitem__(self, key):
        return self.get(key)

if __name__ == '__main__':
    hash_table = HashTable()
    hash_table.add('car', 'Tasla')
    hash_table.add('car', 'Tasla')
    hash_table.add('pc', 'Apple')
    hash_table.add('sns', 'YouTube')
    hash_table.printTable()

    print(hash_table.get('sns'))

    hash_table['sns'] = 'twitter'
    hash_table['langage'] = 'python'
    hash_table['food'] = 'sushi'
    hash_table.printTable()
