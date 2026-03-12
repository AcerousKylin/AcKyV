from FamilyTree.lib.TripledTree import TripledTree
import constant as ct
import json
import os


def display_list(title, content, total):  # be aware of how frame is made
    print(title)

    max_width = 10

    row = int(total / max_width + 1)
    last = total % max_width

    for row_th in range(row):

        times = max_width - 1 if row_th != row - 1 else last - 1
        if times <= 0:
            break

        temp = "┌----------"
        for i in range(times):
            temp += "┬----------"
        temp += "┐"
        print(temp)

        temp = "|"
        for i in range(times + 1):
            temp += str(f'{content[i + row_th * max_width].data:10}') + "|"
        if total == 0:
            temp += "          |"
        print(temp)

        temp = "└----------"
        for i in range(times):
            temp += "┴----------"
        temp += "┘"
        print(temp)


class FamilyManager:
    def __init__(self, root_value):
        self.tree = TripledTree(root_value)

    def store(self):
        while True:
            print(ct.ENT_, "File you will store, put it here without suffix: ")
            file_name = input()
            if file_name == 'q':
                print(ct.INFO, ct.PE2GB)
                input()
                return
            elif file_name == 'preset_tree':
                print(ct.WARN, "You can not cover preset tree.")
                print(ct.INFO, ct.PE2GB)
                input()
            elif os.path.exists(f"./data/{file_name}.json") is True:
                print(ct.WARN, "The file name already exists, do you want to cover it? (y/n) ")
                cover = input()
                if cover == 'y' or cover == 'Y':
                    break
                elif cover == 'n' or cover == 'N':
                    continue
                else:
                    print(ct.WARN, "y or n, have to send you back.")
                    print(ct.INFO, ct.PE2GB)
                    input()
                    continue
            else:
                break
        with open(file=f"./data/{file_name}.json",
                  mode="wt",
                  encoding="cp936",
                  errors="strict"
                  ) as tree_file:
            json.dump(self.tree.sequence_traverse(), tree_file)
            print(ct.INFO, "The tree stored.")
            print(ct.INFO, ct.PE2C_)
            input()

    def reclaim(self):
        while True:
            print(ct.ENT_, "Which file you want to reclaim, put it here without suffix: ")
            file_name = input()
            if file_name == 'q':
                print(ct.INFO, ct.PE2GB)
                input()
                return
            elif os.path.exists(f"./data/{file_name}.json") is False:
                print(ct.WARN, "The file does not exist.")
                continue
            else:
                break

        with open(file=f"./data/{file_name}.json",
                  mode="rt",
                  encoding="cp936",
                  errors="strict"
                  ) as tree_file:
            init_dict = json.load(tree_file)
            del self.tree
            self.tree = TripledTree(next(iter(init_dict)))
        for i in init_dict.keys():
            for j in init_dict[i]:
                self.tree.insert(i, j)
        print(ct.INFO, "Tree reclaimed.")
        print(ct.INFO, ct.PE2C_)
        input()

    @staticmethod
    def initial(self):
        with open(file="./data/preset_tree.json",
                  mode="rt",
                  encoding="cp936",
                  errors="strict"
                  ) as tree_file:
            init_dict = json.load(tree_file)
            self.tree.root.data = next(iter(init_dict))
            for i in init_dict.keys():
                for j in init_dict[i]:
                    self.tree.insert(i, j)
        print(ct.INFO, "Preset tree initialed.")
        print(ct.INFO, ct.PE2C_)
        input()

    def add(self):
        while True:
            print(ct.ENT_, "Who has a new child? put it here: ")
            parent_value = input()
            if parent_value == 'q':
                print(ct.INFO, ct.PE2GB)
                input()
                return
            elif self.tree.find(parent_value) is False:
                print(ct.WARN, "No member with the name exist.")
            else:
                cond = self.tree.find_children(parent_value)
                if type(cond) is list and len(cond) == 2:
                    print(ct.WARN, "The member already has two child.")
                else:
                    break

        while True:
            print(ct.ENT_, "And put its new name here: ")
            insert_value = input()
            if insert_value == 'q':
                print(ct.INFO, "Press Enter to go back...")
                input()
                return
            elif self.tree.find(insert_value) is not False:
                print(ct.WARN, "A member with the name exist.")
                continue
            elif len(insert_value) > 10:
                print(ct.WARN, "No support for name longer than 10, sorry.")
                continue
            else:
                break

        result = self.tree.insert(parent_value, insert_value)
        if result == -1:
            print(ct.ERR_, "Parent value does not exist or insert value already exists.")
        elif result == 0:
            print(ct.ERR_, "Parent objects.")
        else:
            print(ct.INFO, "Added.")
        print(ct.INFO, ct.PE2GB)
        input()
        return

    def delete(self):
        print(ct.INFO, "Choose a mode of deletion:")
        print(ct.SPA_, "    1.Delete the person and its all descendants.")
        print(ct.SPA_, "    2.Delete the person only and may offer its descendants a recipient.")

        mode = input()
        while True:
            if mode == "1" or mode == "2":
                break
            elif mode == 'q':
                print(ct.INFO, ct.PE2GB)
                input()
                return
            else:
                print(ct.WARN, "Use the number at the beginning of the option to choose it.")
                print(ct.INFO, "Choose a mode of deletion:")
                print(ct.SPA_, "    1.Delete the person and its all descendants.")
                print(ct.SPA_, "    2.Delete the person only and may offer its descendants a recipient.")
                print(ct.ENT_, "Choose again: ")
                mode = input()

        print(ct.ENT_, "Who you want to exile and his name here: ")
        exile_name = input()
        if exile_name == 'q':
            print(ct.INFO, ct.PE2GB)
            input()
            return

        if mode == "1":
            result = self.tree.delete_tree(exile_name)
            if result == -1:
                print(ct.ERR_, "Exile does not exist.")
            elif result == 0:
                print(ct.ERR_, "You can't exile patriarch, or just cut this tree.")
            else:
                print(ct.INFO, "Exiled.")
        else:
            print(ct.ENT_, "If you have a recipient from descendants, put it here, or entry \"no\": ")
            recipient = input()
            if recipient == "No" or recipient == "no" or recipient == "NO":
                result = self.tree.delete_root(exile_name, None)
                if result == -1:
                    print(ct.ERR_, "Unknown Error.")
                elif result == 0:
                    print(ct.ERR_, "An overloaded elder adoption is made.")
                else:
                    print(ct.INFO, "Elder adoption is made.")
            elif recipient == 'q':
                print(ct.INFO, "Press Enter to get back to main menu...")
                input()
                return
            else:
                result = self.tree.delete_root(exile_name, recipient)
                if result == -1:
                    print(ct.ERR_, "Recipient can't be any descendant of the exile.")
                elif result == 0:
                    print(ct.ERR_, "An overloaded adoption is made.")
                else:
                    print(ct.INFO, "Adoption is made.")
        print(ct.INFO, ct.PE2GB)
        input()
        return

    def brother(self):
        print(ct.ENT_, "Whose brother you want to find, put it here: ")
        target_value = input()
        if target_value == 'q':
            print(ct.INFO, ct.PE2GB)
            input()
            return

        brother = self.tree.find_bro(target_value)
        if brother == -1:
            print(ct.ERR_, "The member does not exist.")
        elif brother == 0:
            print(ct.INFO, "The member does not have a brother.")
        else:
            print(ct.INFO, "The member's brother is " + brother.data)
        print(ct.INFO, ct.PE2GB)
        input()
        return

    def ascendants(self):
        print(ct.ENT_, "Whose ascendants you want to find, put it here: ")
        target_value = input()
        if target_value == 'q':
            print(ct.INFO, ct.PE2GB)
            input()
            return

        asc = self.tree.traverse_ascendant(target_value)
        if asc == -1:
            print(ct.WARN, "The member does not exist.")
        else:
            display_list(ct.INFO + "The member's ascendants listed here: ",
                         asc,
                         len(asc)
                         )
        print(ct.INFO, ct.PE2GB)
        input()
        return

    def descendants(self):
        print(ct.ENT_, "Whose descendants you want to find, put it here: ")
        target_value = input()
        if target_value == 'q':
            print(ct.INFO, ct.PE2GB)
            input()
            return

        desc = self.tree.traverse_descendant(target_value)
        if desc == -1:
            print(ct.WARN, "The member does not exist.")
        else:
            display_list(ct.INFO + "The member's descendants listed here: ",
                         desc,
                         len(desc)
                         )
        print(ct.INFO, ct.PE2GB)
        input()
        return

    def children(self):
        print(ct.ENT_, "Whose children you want to find, put it here: ")
        target_value = input()
        if target_value == 'q':
            print(ct.INFO, ct.PE2GB)
            input()
            return

        children = self.tree.find_children(target_value)
        if children == -1:
            print(ct.ERR_, "The member does not exist.")
        elif children == 0:
            print(ct.INFO, "The member does not have a child.")
        else:
            display_list(ct.INFO + "The member's children listed here: ",
                         children,
                         len(children)
                         )
        print(ct.INFO, ct.PE2GB)
        input()
        return

    def parent(self):
        print(ct.ENT_, "Whose parent you want to find, put it here: ")
        target_value = input()
        if target_value == 'q':
            print(ct.INFO, ct.PE2GB)
            input()
            return

        parent = self.tree.find_parent(target_value)
        if parent == -1:
            print(ct.ERR_, "The member does not exist.")
        elif parent == 0:
            print(ct.INFO, "The member does not have a child.")
        else:
            print(ct.INFO, "The member's parent is " + parent.data)
        print(ct.INFO, ct.PE2GB)
        input()
        return
