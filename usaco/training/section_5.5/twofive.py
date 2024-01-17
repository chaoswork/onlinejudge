"""
ID: huangch7
LANG: PYTHON3
TASK: twofive
"""


task_name = "twofive"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()
def display_matrix(m):
    for line in m:
        print(''.join(line))
    print('-' * 5)


fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

cmd = fin.readline().strip()
if cmd == 'N':
    N = get_list_from_line()[0]
    target = None
else:
    N = None
    target = fin.readline.strip()

# bfs

matrix = [["_"] * 7 for _ in range(7)]
for i in range(7):
    matrix[0][i] = "A"
    matrix[i][0] = "A"
matrix[1][1] = "A"

import copy

buff = [matrix]

#AB  ABC   AB  ABC  AB   AB
#          C   D    CD   C
#                        D
#
#A  AC   A
#B  B    B
#        C
for idx, x in enumerate("BCDEFGHIJK"): #LMNOPQRSTUVWXY":
    new_buff = []
    for cur in buff:
        for i in range(1, 6):
            for j in range(1, 6):
                if cur[i][j] != '_':
                    continue
                t1 = cur[i - 1][j] != '_'
                t2 = cur[i][j - 1] != '_'
    
                if t1 and t2:
                    if x > cur[i - 1][j] and x > cur[i][j - 1]:
                        # pruning
                        if idx + 2 < i * j:
                            continue
                        if 25 - (idx + 2) < (5 - i) * (5 - j):
                            continue
                        tmp = copy.deepcopy(cur)
                        tmp[i][j] = x
                        new_buff.append(tmp)
                # if t1 and not t2:
                #     if x > cur[i - 1][j]:
                #         tmp = copy.deepcopy(cur)
                #         tmp[i][j] = x
                #         new_buff.append(tmp)
                # if not t1 and t2:
                #     if x > cur[i][j - 1]:
                #         tmp = copy.deepcopy(cur)
                #         tmp[i][j] = x
                #         new_buff.append(tmp)
    buff = new_buff
                    
    print(len(buff))
for item in buff[-10:]:
    display_matrix(item)

fout.close()
