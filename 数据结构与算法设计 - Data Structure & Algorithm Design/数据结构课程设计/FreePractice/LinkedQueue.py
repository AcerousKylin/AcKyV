import LinkedList
import LinkedStack


class LinkedQueue(LinkedList.LinkedList):
    def __init__(self):
        super().__init__()

    def is_empty(self):
        return super().is_empty()

    def enqueue(self, data):
        return super().append_tail(data)

    def dequeue(self):
        return super().delete_head()

    def get_head(self):
        return super().head.next.data


class TwoStackQueue():
    def __init__(self):
        self.stack_in = LinkedStack.LinkedStack()
        self.stack_out = LinkedStack.LinkedStack()

    def is_empty(self):
        return self.stack_in.is_empty() and self.stack_out.is_empty()

    def enqueue(self, data):
        if self.stack_in.is_empty():
            while self.stack_out.is_empty():
                self.stack_in.push(self.stack_out.pop())
        return self.stack_in.push(data)

    def dequeue(self):
        if self.stack_out.is_empty():
            while self.stack_in.is_empty():
                self.stack_out.push(self.stack_in.pop())
        return self.stack_out.pop()

    def get_head(self):
        if self.stack_out.is_empty():
            while self.stack_in.is_empty():
                self.stack_out.push(self.stack_in.pop())
        return self.stack_out.get_top()
