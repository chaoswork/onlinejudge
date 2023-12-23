"""
ID: huangch7
LANG: PYTHON3
TASK: shuttle
"""


task_name = "shuttle"
INF = 100000000


def get_ints_from_line():
    return [int(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()


fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N = get_ints_from_line()[0]

# C(7, 3) * 4
# 7!/(3!*4!) * 4 = 7 * 6 * 5 * 4 = 840

target = tuple([1] * N + [-1] + [0] * N)
start = tuple([0] * N + [-1] + [1] * N)
next = {target: None}


# start: (0, 0, 0, ..., _, 1, 1, 1...)
# mid  : (_, 1, 0, 1, 0, 1, 0, ... )
# mid. : (1, 0, 1, 0, ...,        ,_)
# target:(1, 1, 1, ..., _, 0, 0, 0...)




ans = {}
# bfs
deque = [target]

while deque:
    cur = deque.pop(0)

    black = cur.index(-1)
    for i in [-2, -1, 1, 2]:
        idx = black + i
        if idx < 0 or idx >= 2 * N + 1:
            continue
        state = list(cur)[:]
        tmp = state[black]
        state[black] = state[idx]
        state[idx] = tmp
        state = tuple(state)
#         print(state)
        if state in next:
            continue
        next[state] = cur
        ans[state] = idx

        if state == start:
            break
        deque.append(state)

final_ans = []
cur = start
while cur != target:
    line = ""
    for x in cur:
        x = str(x) if x != -1 else "_"
        line += x
    print(line)
    final_ans.append(ans[cur] + 1)
    cur = next[cur]

final_ans = final_ans[::-1]

for i in range(0, len(final_ans), 20):
    fout.write(" ".join([str(x) for x in final_ans[i: i + 20]]))
    fout.write("\n")

        
    

fout.close()
