class DoubledNode:

    def __init__(self, data):
        self.data = data
        self.prev = None
        self.next = None


class DoubledList:

    head = DoubledNode
    tail = DoubledNode

    def __init__(self):
        self.head = DoubledNode(None)
        self.head.prev = self.head.next = None
        self.tail = self.head
        self.length = 0

    def is_empty(self):
        if (self.head.next is None) | (self.tail is None):
            return -1

    def append_head(self, data):
        new_node = DoubledNode(data)
        new_node.next = self.head.next
        self.head.next = new_node
        if new_node.next is not None:
            new_node.next.prev = new_node
        new_node.prev = self.head

        if self.tail == self.head:
            self.tail = new_node

        self.length += 1

    def append_tail(self, data):     # append at tail
        new_node = DoubledNode(data)
        self.tail.next = new_node
        new_node.prev = self.tail
        self.tail = new_node
        self.length += 1

    def delete_head(self):
        del_node = self.head.next
        if del_node == self.tail:
            self.tail = self.head
        data = del_node.data

        self.head.next = self.head.next.next
        del_node.prev = None
        self.head.next.prev = self.head

        self.length -= 1
        return data

    def delete_tail(self):
        del_node = self.tail
        data = del_node.data

        self.tail = self.tail.prev
        del_node.prev = self.tail.next = None

        self.length -= 1
        return data

    def traverse(self):
        t = []
        i = self.tail

        while i != self.head:  # loop if i is not tail OR i is not None
            t.append(i.data)
            i = i.prev

        t.append(self.length)

        return t
