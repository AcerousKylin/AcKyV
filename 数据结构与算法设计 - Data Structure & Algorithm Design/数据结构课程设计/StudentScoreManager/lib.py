import model

# return value
# -1 = list is empty
# 0 = operation failed
# 1 = operation succeed


class Node:
    def __init__(self, val):
        val = model.Student(-1, None, None, None, None, None, None)
        self.value = val
        self.prev = None
        self.next = None


class CDLList:
    def __init__(self):
        self.head = Node(0)

    def is_empty(self):
        return self.head.next is None

    def append(self, val):
        new_node = Node(val)
        if self.is_empty():
            new_node.next = new_node
            new_node.prev = new_node
            self.head.next = new_node
        else:
            last = self.head.next.prev
            new_node.next = self.head.next
            new_node.prev = last
            last.next = self.head.next.prev = new_node

        return 1

    def sort(self, rule):
        return rule is not None

    def delete(self, val):
        if self.is_empty():
            return -1   # the list is empty

        cur = self.head.next
        while cur.value != val:
            if cur.next == self.head.next:
                return 0    # not found
            cur = cur.next

        if self.head.next == cur:
            if self.head.next.next == self.head.next:
                # if there's only one
                self.head.next = None
            else:
                new_head = Node(-1)
                new_head.next = cur.next
                new_head.next.prev = cur.prev
                cur.prev.next = new_head.next
                self.head = new_head

        return 1    # delete succeed

    def __len__(self):
        if self.is_empty():
            return -1   # list is empty
        cur = self.head.next
        count = 0
        while True:
            count += 1
            cur = cur.next
            if cur == self.head.next:
                break
        return count
