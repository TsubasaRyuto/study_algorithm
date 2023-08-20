class Node(object):
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.left = None
        self.right = None


def insert(node, key, value):
    if node is None:
        return  Node(key, value)

    if key < node.key:
        node.left = insert(node.left, key, value)
    else:
        node.right = insert(node.right, key, value)

    return node

def inorder(node, order):
    if (node is not None) and (order == 'asc'):
        inorder(node.left, 'asc')
        print(node.value)
        inorder(node.right, 'asc')

    if (node is not None) and (order == 'desc'):
        inorder(node.right, 'desc')
        print(node.value)
        inorder(node.left, 'desc')

def search(node, target_key):
    if node is None:
        return None

    if node.key == target_key:
        return node.value
    elif node.key > target_key:
        return search(node.left, target_key)
    elif node.key < target_key:
        return search(node.right, target_key)

def min_key(node):
    current = node
    while current.left is not None:
        current = current.left

    return current

def remove(node, target_key):
    if node is None:
        return node

    if target_key < node.key:
        node.left = remove(node.left, target_key)
    elif target_key > node.key:
        node.right = remove(node.right, target_key)
    else:
        if node.left is None:
            return node.right
        elif node.right is None:
            return node.left

        temp = min_key(node.right)
        node.key = temp.key
        node.value = temp.value # 忘れずに。。。
        node.right = remove(node.right, temp.key)

    return node


if __name__ == '__main__':
    root = None
    root = insert(root, 3, 'Ruby')
    root = insert(root, 6, 'Go')
    root = insert(root, 5, 'C')
    root = insert(root, 7, 'PHP')
    root = insert(root, 1, 'Rust')
    root = insert(root, 10, 'C++')
    root = insert(root, 2, 'Python')

    root = remove(root, 6)
