"""
ID: huangch7
LANG: PYTHON3
TASK: wormhole
"""

task_name = "wormhole"

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

n = int(fin.readline())
xy = []
for _ in range(n):
    xy.append(tuple([int(x) for x in fin.readline().strip().split()]))

next_node = {}
ranks = sorted(xy, key=lambda x: (x[1], x[0]))
for i in range(len(ranks) - 1):
    if ranks[i][1] == ranks[i + 1][1]:
        next_node[ranks[i]] = ranks[i + 1]

#print(next_node)
res = 0

# search all: 11 * 9 * 7 * 5 * 3 = 10395,
# 如何判断成环？
# 只要找到一条线上有两个点的组合。
# 然后从后一个点看是否能走到第一个点即可。


def check_loop(xy_list):
    wormhole = {}
    for item in xy_list:
#        if item[0][1] == item[1][1]:
#            return True
        wormhole[item[0]] = item[1]
        wormhole[item[1]] = item[0]

    for item in xy:
        if item not in next_node:
            continue
        # print('debug-item', item)
        node = wormhole[next_node[item]]
        # print('debug-node', node)
        while True:
            if node not in next_node:
                break
            if node == item:
                return True
            node = wormhole[next_node[node]]

    return False


def perm(cur, left):
    global res
    if len(left) == 0:
        # print(cur, check_loop(cur))
        if check_loop(cur):
            res += 1
        return
    for i in [0]: #range(len(left) - 1):
        for j in range(i + 1, len(left)):
            perm(cur + [(left[i], left[j])], left[:i] + left[i + 1: j] + left[j + 1:])


perm([], xy)
fout.write(f"{res}\n")
fout.close()
