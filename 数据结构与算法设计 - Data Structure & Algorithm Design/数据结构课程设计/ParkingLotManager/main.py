import os
import Manager
import view

INP = "[INPUT]  :"


def intro():
    print("                                                     __________________________                                                           ")
    print("                                                    /u/ ------------------------- \                                                         ")
    print("                                                   /u/ u$$$$$$$$$$$$$$$$$$$$$$$$$u \                                                       ")
    print("                                                  /u/ u$$$$$$$$$$$$$$$$$$$$$$$$$$$u \                                                     ")
    print("                                                 /u/ u$$$$$$$$$$$$$$$$$$$$$$$$$$$$$u \                                                   ")
    print("                                                /u/ u$$$$$$$$$$$          $$$$$$$$$$u \                                                 ")
    print("                                               /u/ u$$$$$$$$$$$              $$$$$$$$u \                                               ")
    print("                                              |$| $$$$$$$$$$$$$    $$$$$$     $$$$$$$$$ |                                              ")
    print("                                              |$| $$$$$$$$$$$$$    $$$$$$$    $$$$$$$$$ |                                              ")
    print("                                              |$| $$$$$$$$$$$$$    $$$$$$     $$$$$$$$$ |                                              ")
    print("                                              |$| $$$$$$$$$$$$$              $$$$$$$$$$ |                                              ")
    print("                                              |$| $$$$$$$$$$$$$           $$$$$$$$$$$$$ |                                              ")
    print("                                              |$| $$$$$$$$$$$$$    $$$$$$$$$$$$$$$$$$$$ |                                              ")
    print("                                              |$| $$$$$$$$$$$$$    $$$$$$$$$$$$$$$$$$$$ |                                              ")
    print("                                              |$| $$$$$$$$$$$$$    $$$$$$$$$$$$$$$$$$$$ |                                              ")
    print("                                               \\u\\ u$$$$$$$$$$$    $$$$$$$$$$$$$$$$$$u /                                               ")
    print("                                                 \\u\\ u$$$$$$$$$$  $$$$$$$$$$$$$$$$$$u /                                                 ")
    print("                                                   \\u\\ u$$$$$$$$$$$$$$$$$$$$$$$$$$$u /                                                   ")
    print("                                                     \\u\\ u$$$$$$$$$$$$$$$$$$$$$$$$u /                                                     ")
    print("                                                       \\u\\ u$$$$$$$$$$$$$$$$$$$$$u /                                                       ")
    print("                                                         -------------------------                                                           ")
    print("      ___           ___           ___           ___                       ___           ___                    ___       ___         ___      ")
    print("     /\  \         /\  \         /\  \         /\__\          ___        /\__\         /\  \                  /\__\     /\  \       /\  \     ")
    print("    /::\  \       /::\  \       /::\  \       /:/  /         /\  \      /::|  |       /::\  \                /:/  /    /::\  \      \:\  \    ")
    print("   /:/\:\  \     /:/\:\  \     /:/\:\  \     /:/__/          \:\  \    /:|:|  |      /:/\:\  \              /:/  /    /:/\:\  \      \:\  \   ")
    print("  /::\~\:\  \   /::\~\:\  \   /::\~\:\  \   /::\__\____      /::\__\  /:/|:|  |__   /:/  \:\  \            /:/  /    /:/  \:\  \     /::\  \  ")
    print(" /:/\:\ \:\__\ /:/\:\ \:\__\ /:/\:\ \:\__\ /:/\:::::\__\  __/:/\/__/ /:/ |:| /\__\ /:/__/_\:\__\          /:/__/    /:/__/ \:\__\   /:/\:\__\ ")
    print(" \/__\:\/:/  / \/__\:\/:/  / \/_|::\/:/  / \/_|:|~~|~    /\/:/  /    \/__|:|/:/  / \:\  /\ \/__/          \:\  \    \:\  \ /:/  /  /:/  \/__/ ")
    print("      \::/  /       \::/  /     |:|::/  /     |:|  |     \::/__/         |:/:/  /   \:\ \:\__\             \:\  \    \:\  /:/  /  /:/  /      ")
    print("       \/__/        /:/  /      |:|\/__/      |:|  |      \:\__\         |::/  /     \:\/:/  /              \:\  \    \:\/:/  /   \/__/       ")
    print("                   /:/  /       |:|  |        |:|  |       \/__/         /:/  /       \::/  /                \:\__\    \::/  /                ")
    print("                   \/__/         \|__|         \|__|                     \/__/         \/__/                  \/__/     \/__/                 ")

def command_panel():
    print("┌--------------------------------------------------------------------------------------------------------------------------------------------┐")
    print("|                                                   Welcome to Parking Lot with a Side Way                                                   |")
    print("├--------------------------------------------------------------------------------------------------------------------------------------------┤")
    print("|                                          Please entry the index in front of the function you want:                                         |")
    print("├--------------------------------------------------------------------------------------------------------------------------------------------┤")
    print("|                                             p. parking    d.depart    c.circumstance    q.quit                                             |")
    print("└--------------------------------------------------------------------------------------------------------------------------------------------┘", flush=True)


def display_cir(title, content, total):     # be aware of how frame is made
    print(title)

    row = int(total / 15 + 1)
    last = total % 15

    for ii in range(row):

        times = 14 if ii != row-1 else last-1

        temp = "┌-------"
        for i in range(times):
            temp += "┬-------"
        temp += "┐"
        print(temp)

        temp = "|"
        if content is not None:
            for i in range(times+1):
                temp += str(content[i + ii*15]) + "|"
        if total == 0:
            temp += "       |"
        print(temp)

        temp = "└-------"
        for i in range(times):
            temp += "┴-------"
        temp += "┘"
        print(temp)


manager = Manager.Manager()
intro()

while True:

    command_panel()
    option = input()

    if option == 'p':
        print(INP, "Please, your license code, your arrival time will be recorded as you finish.")
        lic = input()
        manager.car_arrive(lic)

    elif option == 'd':
        print(INP, "Please, your parking position, and get ready to pay for parking fee.")
        pos = input()
        manager.car_depart(int(pos))

    elif option == 'c':
        print(Manager.INF, "Here's how spare the parking lot is.")
        total_cir = manager.parking_lot_cir()

        display_cir(
            "Inside the parking lot:\nTotal: " + str(manager.parkingLot.capacity) + " | Spare: " + str(manager.parkingLot.spare),
            total_cir[0],
            manager.parkingLot.capacity,
            )

        display_cir(
            "Outside the parking lot:\nTotal: " + str(manager.sideWay.length),
            total_cir[1],
            manager.sideWay.length
            )

        print(Manager.INF, "The information is all above.")

    elif option == 'q':
        print(Manager.WAR, "Now we're about to be offline, press enter to quit...")
        input()
        exit(0)

    elif option == 'retro':
        app = view.Application()
        app.master.title('Acerous Kylin is watching you...')
        app.mainloop()

    else:
        print(Manager.ERR, "There's no option for your entry, so you will return to main menu.")

    print(Manager.INF, "Waiting for your enter to continue...")
    input()
    # os.system("cls")
