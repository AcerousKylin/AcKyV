class SequentialStack:

    sequence = []

    def __init__(self, n: int):
        self.top = 0
        self.capacity = n
        for i in range(n):
            self.sequence.append(None)

    def is_empty(self):
        if self.top == 0:
            return 1
        else:
            return 0

    def is_full(self):
        if self.top == self.capacity:
            return 1
        else:
            return 0

    def push(self, data):
        if self.is_full():
            return 0
        else:
            self.sequence[self.top] = data
            self.top += 1
            return 1

    def pop(self):  # return 0 = empty | data = succeed
        if self.is_empty():
            return 0
        else:
            self.top -= 1
            return self.sequence.pop(self.top+1)

    def traverse(self):
        full_list = []
        have = 0
        for i in range(0, len(self.sequence)):
            full_list.append(self.sequence[i])
            if self.sequence[i] is not None:
                have += 1

        full_list.append(have)

        return full_list
