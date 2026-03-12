import libs.LinkedQueue as LQ
import libs.SequentialStack as SS
import time


class Car:

    license = str
    arrival = float

    def __init__(self, lic=None, arr=None, dep=None):
        self.license = lic
        self.arrival = arr
        self.departure = dep


class ParkingLot(SS.SequentialStack):

    def __init__(self, n):
        super().__init__(n)
        self.spare = n

    def arrive(self, car_lic):  # return -1 = repeat | 0 = full | 1 = succeed
        new_car = Car(lic=car_lic, arr=time.perf_counter())
        for i in self.sequence:
            if i is not None and i.license == car_lic:
                return -1

        return SS.SequentialStack.push(self, new_car)

    def depart(self, car_pos):  # return -1 = invalid | 0 = empty | departed car license
        if car_pos < 0 or car_pos >= self.capacity:
            return -1
        elif self.sequence is None:
            return 0
        else:
            car_inst = self.sequence[car_pos]
            self.sequence.pop(car_pos)
            self.sequence.append(None)
            self.top -= 1
            car_inst.departure = time.perf_counter()
            return car_inst

    def check(self):
        cir = self.traverse()
        self.spare = self.capacity - cir[-1]
        cir.pop(-1)
        for i in range(len(cir)):
            if cir[i] is None:
                cir[i] = "       "
            else:
                cir[i] = cir[i].license
        return cir


class SideWay(LQ.LinkedQueue):

    waiting = int

    def __init__(self):
        super().__init__()
        self.waiting = 0

    def wait(self, car_inst):   # simply make the car into the side way
        self.push(car_inst)

    def chance(self):   # return the leaving car instance
        if self.head.next is not None:
            car_inst = self.pop()
            car_inst.arrival = time.perf_counter()
            return car_inst
        else:
            return 0

    def check(self):
        cir = self.traverse()
        length = cir.pop(-1)
        self.waiting = length
        for i in range(length):
            cir[i] = cir[i].license
            if cir[i] == 0 or cir[i] == -1:
                cir[i] = "       "
        return cir
