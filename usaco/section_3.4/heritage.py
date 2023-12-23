"""
ID: huangch7
LANG: PYTHON3
TASK: heritage
"""


task_name = "heritage"
INF = 100000000

def get_ints_from_line():
    return [int(x) for x in fin.readline().strip().split()]

def get_strs_from_line():
    return fin.readline().strip().split()

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

in_order = fin.readline().strip()
pre_order = fin.readline().strip()

class Node(object):
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None


def build_tree(in_order, pre_order):
    if len(in_order) == 0:
        return None
    if len(in_order) == 1:
        assert in_order == pre_order
        return Node(in_order)
    root_value = pre_order[0]
    index = in_order.find(root_value)
    
    left_node = build_tree(in_order[:index], pre_order[1: 1 + index])
    right_node = build_tree(in_order[index + 1:], pre_order[1 + index:])
    root = Node(root_value)
    root.left = left_node
    root.right = right_node
    return root

def post_order(tree):
    if tree is None:
        return ''
    left = post_order(tree.left)
    right = post_order(tree.right)
    return left + right + tree.value
    

fout.write(post_order(build_tree(in_order, pre_order)))
fout.write("\n")



    
fout.close()
