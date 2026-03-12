from FamilyTree.lib import DoubledList as DL


class LinkedQueue(DL.DoubledList):
    def __init__(self):
        super().__init__()

    def push(self, data):
        self.append_head(data)

    def pop(self):
        return self.delete_tail()

    def traverse(self):
        return super().traverse()
