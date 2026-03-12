import model
import time


N = int(2)

PRESENT = "time"
ERR = "[ERROR]  :"
INF = "[INFO]   :"
WAR = "[WARNING]:"


class Manager:

    parkingLot = model.ParkingLot
    sideWay = model.SideWay
    timer = float

    def __init__(self):
        self.parkingLot = model.ParkingLot(N)
        self.sideWay = model.SideWay()
        self.timer = time.perf_counter()

    def car_arrive(self, lic):
        if len(lic) != 7 or str(lic).strip().isalnum() is False:
            print(WAR, "Sorry, foreign license is not allowed to park here.")
            return
        new_car = model.Car(lic=lic, arr=time.perf_counter())
        pla = self.parkingLot.arrive(new_car.license)
        if pla == -1:
            print(ERR, "The car you entry has already existed!")

        elif pla == 0:
            print(WAR, "The parking lot is full, please wait on the side way.")
            self.car_wait(new_car)

        else:   # pla == 1
            print(INF, "You have your car in the parking lot.")

    def car_wait(self, car_inst):
        self.sideWay.wait(car_inst)
        print(INF, "You have your car in the side way.")

    def car_depart(self, pos):
        pld = self.parkingLot.depart(pos)
        if pld == -1:
            print(ERR, "The position you entry is invalid.")

        elif pld == 0:
            print(ERR, "No car in the parking lot.")

        else:   # pld == departed car instance
            expense = 0.25 / 60 * (pld.departure - pld.arrival)
            print(INF, "You have paid ", "{:.2f}".format(expense), " to have your car out of parking lot.")
            self.car_chance()

    def car_chance(self):
        chance = self.sideWay.chance()
        if chance == 0:
            print(WAR, "No car in the side way.")
        else:   # chance == car instance that left the side way
            self.parkingLot.arrive(chance.license)
            print(INF, "Have a car in the parking lot from the side way.")

    def parking_lot_cir(self):
        total_cir = [None, None]
        total_cir[0] = self.parkingLot.check()
        print()
        total_cir[1] = self.sideWay.check()

        return total_cir
