import LinkedQueue

tq = LinkedQueue.TwoStackQueue()
number = list()
for i in range(5):
    temp = int()
    input(temp)
    number.append(temp)

for i in number:
    tq.enqueue(i)

for i in range(len(number)):
    if tq.get_head():
        print(tq.dequeue())
