import model
import constant as ct

fam_manager = model.FamilyManager(None)

while True:
    print(ct.SPA_, "Welcome to Family Tree System.")
    print(ct.SPA_, "Firstly, how do you initial the system?")
    print(ct.SPA_, "0. Initial preset tree.")
    print(ct.SPA_, "1. Reclaim from local file(./data).")
    print(ct.SPA_, "2. Build a tree with a patriarch.")
    print(ct.SPA_, "q. Quit.")

    command = input()
    if command == 'q':
        print(ct.INFO, ct.PE2Q_)
        input()
        exit(0)
    elif command == '0':
        model.FamilyManager.initial(fam_manager)
        break
    elif command == '1':
        fam_manager.reclaim()
        break
    elif command == '2':
        print(ct.ENT_, "What is patriarch's name, put it here: ")
        patriarch = input()
        if patriarch == 'q':
            print(ct.WARN, "You name can not be 'q', make another one.")
            continue
        else:
            fam_manager = model.FamilyManager(patriarch)
            break

while True:
    print(ct.SPA_, "Welcome to Family Tree System, functions down below")
    print(ct.SPA_, "!! You can entry 'q' in anytime to return to upper function !!")
    print(ct.SPA_, "0. Re-Initial preset tree.")
    print(ct.SPA_, "1. Re-Reclaim from local file(./data).")
    print(ct.SPA_, "2. Store the current tree.")
    print(ct.SPA_, "3. Add a member.")
    print(ct.SPA_, "4. Exile a member.")
    print(ct.SPA_, "5. Find a member's relatives.")
    print(ct.SPA_, "q. Quit.")

    command = input()
    if command == '0':
        model.FamilyManager.initial(fam_manager)
    elif command == '1':
        fam_manager.reclaim()
    elif command == '2':
        fam_manager.store()
    elif command == '3':
        fam_manager.add()
    elif command == '4':
        fam_manager.delete()
    elif command == '5':
        while True:
            print(ct.INFO, "What type of relative you want to find: ")
            print(ct.SPA_, "0. Children")
            print(ct.SPA_, "1. Parent")
            print(ct.SPA_, "2. Brother")
            print(ct.SPA_, "3. Descendants")
            print(ct.SPA_, "4. Ascendants")
            print(ct.SPA_, "q. Main menu.")

            command = input()
            if command == '0':
                fam_manager.children()
                break
            elif command == '1':
                fam_manager.parent()
                break
            elif command == '2':
                fam_manager.brother()
                break
            elif command == '3':
                fam_manager.descendants()
                break
            elif command == '4':
                fam_manager.ascendants()
                break
            elif command == 'q':
                print(ct.INFO, ct.PE2GB)
                input()
                break
            else:
                print(ct.WARN, "Wrong command.")
                print(ct.INFO, ct.PE2C_)
                input()
                continue
    elif command == 'q':
        print(ct.INFO, ct.PE2Q_)
        input()
        break
    else:
        print(ct.WARN, "Wrong command.")
        print(ct.INFO, ct.PE2C_)
        input()
        continue

exit(0)
