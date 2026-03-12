from FamilyTree.lib import LinkedQueue as LQ


class TreeNode:
    def __init__(self, data=None):
        self.left = self.right = self.parent = None
        self.data = data


class TripledTree:
    def __init__(self, data=None):
        self.root = TreeNode(data)

# rules:
    # a. tree has two or more nodes have the same value
    # b. can not delete the root node, use del syntax to tree object
    # c. insert is left-prior
    # d. every output list is of nodes
    # e. pass legal arguments as possible as it can

    def sequence_traverse(self):
        static_tree = {}
        tra_queue = LQ.LinkedQueue()
        tra_queue.push(self.root)  # queue's element is tree node
        while tra_queue.is_empty() == 0:
            cur = tra_queue.pop()
            static_tree[cur.data] = []  # dictionary's value is a list of data of its children node
            if cur.left is not None:
                tra_queue.push(cur.left)
                static_tree[cur.data].append(cur.left.data)
            if cur.right is not None:
                tra_queue.push(cur.right)
                static_tree[cur.data].append(cur.right.data)
        return static_tree

    # False          = can't find valued tree node
    # Type(TreeNode) = found valued tree node
    def find(self, value):
        tra_queue = LQ.LinkedQueue()
        tra_queue.push(self.root)  # queue's element is tree node
        result = False
        while tra_queue.is_empty() == 0:
            cur = tra_queue.pop()
            if cur.data == value:
                result = cur
                break
            if cur.left is not None:
                tra_queue.push(cur.left)
            if cur.right is not None:
                tra_queue.push(cur.right)
        return result

    # -1 = ascendant isn't exist
    # 0  = can't find a descendant fits
    # 1  = find a descendant fits
    def is_descendant(self, d_value, a_value):
        a_node = self.find(a_value)
        if a_node is False:
            return -1

        tra_queue = LQ.LinkedQueue()
        tra_queue.push(a_node)  # queue's element is tree node
        while tra_queue.is_empty() == 0:
            cur = tra_queue.pop()
            if cur.data == d_value:
                return 1
            if cur.left is not None:
                tra_queue.push(cur.left)
            if cur.right is not None:
                tra_queue.push(cur.right)
        return 0

    # -1 = descendant isn't exist
    # 0  = can't find an ascendant fits
    # 1  = find an ascendant fits
    def is_ascendant(self, a_value, d_value):
        cur = self.find(d_value)
        if cur is False:
            return -1
        while cur is not None:
            cur = cur.parent
            if cur.data == a_value:
                return 1
        return 0

    # -1 = node with the value isn't exist
    # 0  = node with value1 and node with value2 are not sibling
    # 1  = node with value1 and node with value2 are sibling
    def is_cousin(self, value1, value2):
        node1 = self.find(value1)
        if node1 is False:
            return -1
        node2 = self.find(value2)
        if node2 is False:
            return -1

        if node1.parent == node2.parent:
            return 1
        else:
            return 0

    # -1             = node with the value isn't exist
    # 0              = node with value has no brother
    # Type(TreeNode) = node with value has a brother
    def find_bro(self, value):
        target_node = self.find(value)
        if target_node is False:
            return -1
        if target_node.parent.left is None \
                or target_node.parent.right is None:
            return 0
        else:
            return target_node.parent.left \
                if target_node.parent.right == target_node \
                else target_node.parent.right

    # -1             = node with the value isn't exist
    # 0              = node with value is root
    # Type(TreeNode) = node with value has parent
    def find_parent(self, value):
        target_node = self.find(value)
        if target_node is False:
            return -1
        if target_node.parent is None:
            return 0
        else:
            return target_node.parent

    # -1             = node with the value isn't exist
    # 0              = node with value has no child
    # Type(TreeNode) = node with value has child
    def find_children(self, value):
        target_node = self.find(value)
        if target_node is False:
            return -1
        if target_node.left is None and target_node.right is None:
            return 0
        else:
            if target_node.left is None:
                return [target_node.right]
            elif target_node.right is None:
                return [target_node.left]
            else:
                return [target_node.left, target_node.right]

    # -1   = node with the value isn't exist
    # list = descendants of node with the value
    def traverse_descendant(self, value):
        cur = self.find(value)
        if cur is False:
            return -1

        desc = []
        tra_queue = LQ.LinkedQueue()
        tra_queue.push(cur)  # queue's element is tree node
        while tra_queue.is_empty() == 0:
            cur = tra_queue.pop()
            desc.append(cur)
            if cur.left is not None:
                tra_queue.push(cur.left)
            if cur.right is not None:
                tra_queue.push(cur.right)
        desc.pop(0)
        return desc

    # -1   = node with the value isn't exist
    # list = ascendants of node with the value
    def traverse_ascendant(self, value):
        cur = self.find(value)
        if cur is False:
            return -1

        asc = []
        while cur.parent is not None:
            cur = cur.parent
            asc.append(cur)
        return asc

    # -1 = node with value does not exist
    # 0  = parent has two children already
    # 1  = insert successfully
    def insert(self, parent_value, insert_value):
        parent_node = self.find(parent_value)
        if parent_node is False:
            return -1
        elif parent_node.left is None:
            parent_node.left = TreeNode(insert_value)
            parent_node.left.parent = parent_node
            return 1
        elif parent_node.right is None:
            parent_node.right = TreeNode(insert_value)
            parent_node.right.parent = parent_node
            return 1
        else:
            return 0

    # -1 = any of argument nodes is unavailable
    # 0  = morph and succeed
    # 1  = no morph and succeed
    @staticmethod
    def children_transit(trg_node, rcv_node):
        # rule c is worthy here
        if trg_node.parent == rcv_node:
            if rcv_node.left == trg_node:
                rcv_node.left = None
            elif rcv_node.right == trg_node:
                rcv_node.right = None

        left_ = trg_node.left is not None
        right_ = trg_node.right is not None
        _2left = rcv_node.left is not None
        _2right = rcv_node.right is not None

        if _2right:
            new_node = TreeNode("+" + rcv_node.data)
            new_node.parent = rcv_node
            new_node.left = rcv_node.left
            new_node.right = rcv_node.right
            rcv_node.left.parent = rcv_node.right.parent = new_node
            rcv_node.left = new_node

            new_node = TreeNode("*" + rcv_node.data)
            new_node.parent = rcv_node
            new_node.left = trg_node.left
            new_node.right = trg_node.right
            trg_node.left.parent = trg_node.right.parent = new_node
            rcv_node.right = new_node

            return 0

        elif _2left:
            if right_:
                new_node = TreeNode("*" + rcv_node.data)
                new_node.left = trg_node.left
                new_node.right = trg_node.right
                trg_node.left.parent = trg_node.right.parent = new_node
                rcv_node.right = new_node
                new_node.parent = rcv_node
            elif left_:
                rcv_node.right = trg_node.left
                trg_node.left.parent = rcv_node
            return 0

        else:
            rcv_node.left = trg_node.left
            rcv_node.right = trg_node.right
            trg_node.left.parent = trg_node.right.parent = rcv_node
            return 1

    # -1 = no node of value found
    # 0  = node of value is root
    # 1  = node deletion succeed
    def delete_tree(self, value):
        del_node = self.find(value)
        if del_node is False:
            return -1
        else:
            if del_node.parent is None:
                return 0
            else:
                parent_node = del_node.parent
                if parent_node.left == del_node:
                    parent_node.left = parent_node.right    # keep rule c
                parent_node.right = None
                del_node.parent = None
                del del_node
                return 1

    # -1 = any of argument nodes is unavailable
    # 0  = morph and delete successfully
    # 1  = no morph and succeed
    def delete_root(self, del_value, rcv_value):
        if rcv_value is None:
            del_node = self.find(del_value)
            rcv_node = del_node.parent
        elif self.is_descendant(rcv_value, del_value):
            return -1
        else:
            del_node = self.find(del_value)
            rcv_node = self.find(rcv_value)

        if del_node is False or rcv_node is False or del_node.parent is None:
            return -1

        result = self.children_transit(del_node, rcv_node)
        if result == 1 or result == 0:
            if del_node.parent != rcv_node:
                parent_node = del_node.parent
                if parent_node.left == del_node:
                    parent_node.left = parent_node.right    # keep rule c
                parent_node.right = None
            del_node.parent = None
            del del_node

        return result

    # -1 = node with the value isn't exist
    def change(self, value):
        cur = self.find(value)
        if cur is False:
            return -1

        cur.data = value
        return 1
