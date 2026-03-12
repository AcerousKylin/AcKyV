import LinkedList


class LinkedStack(LinkedList.LinkedList):
    def __init__(self):
        super().__init__()

    def is_empty(self):
        return super().is_empty()

    def pop(self):
        return super().delete_head()

    def push(self, data):
        return super().append_head(data)

    def get_top(self):
        return super().head.next.data
