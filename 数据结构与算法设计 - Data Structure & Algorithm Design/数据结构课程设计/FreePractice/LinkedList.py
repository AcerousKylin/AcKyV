class LinkedNode:
    def __init__(self, data=None):
        self.data = data
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = LinkedNode()
        self.head.data = self.head.next = None
        self.tail = self.head
        self.length = 0

    def is_empty(self):
        if self.head == self.tail:
            return True
        else:
            return False

    def append_head(self, data):
        new_node = LinkedNode(data)
        new_node.next = self.head.next
        self.head = new_node

    def append_tail(self, data):
        new_node = LinkedNode(data)
        new_node.next = self.tail.next
        self.tail = new_node

    def delete_head(self):
        if self.is_empty():
            return False
        else:
            del_node = self.head.next
            if del_node is self.tail:
                self.tail = self.head

            self.head.next = self.head.next.next
            del_data = del_node.data
            del del_node
            return del_data

    def delete_tail(self):
        if self.is_empty():
            return False
        else:
            i = self.head
            while i.next != self.tail:
                i = i.next
            del_node = self.tail
            self.tail = i
            self.tail.next = None
            del_data = del_node.data
            del del_node
            return del_data
