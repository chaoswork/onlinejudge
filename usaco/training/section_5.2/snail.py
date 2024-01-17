"""
ID: huangch7
LANG: PYTHON3
TASK: snail
"""
import math

task_name = "snail"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N, B = get_list_from_line()
barriers = set()
for _ in range(B):
    line = fin.readline()
    col = ord(line[0]) - ord('A')
    row = int(line[1:]) - 1
    barriers.add((row, col))

visited = [[0] * N for _ in range(N)]
visited[0][0] = 1
best = 0

direction_map = {
    0: [0, 1], # >
    1: [1, 0], # V
    2: [0, -1],# <
    3: [-1, 0] # ^
}
# cache = {}

def display_visited():
    for i in range(len(visited)):
        print("".join([str(x) for x in visited[i]]))
    print('-' * 10)

total = 0
def move(row, col, direction):
    global total
#    print(row, col, direction)
#    display_visited()
    
#    total += 1
#    if total > 10:
#        return -1
#     if (row, col, direction) in cache:
#        return cache[(row, col, direction)]
    cur = [row, col]
    cur_steps = 0
    is_end = False
    buff = []
    while True:
        cur[0] += direction_map[direction][0]
        cur[1] += direction_map[direction][1]
        if (cur[0], cur[1]) in barriers:
            break
        if (cur[0] < 0 or cur[0] >= N):
            break
        if (cur[1] < 0 or cur[1] >= N):
            break
        if visited[cur[0]][cur[1]]:
            is_end = True
            break
        visited[cur[0]][cur[1]] = 1
        cur_steps += 1
        buff.append(tuple(cur))
    cur[0] -= direction_map[direction][0]
    cur[1] -= direction_map[direction][1]
    if not is_end and (cur[0] != row or cur[1] != col):
        cur_steps += max(move(cur[0], cur[1], (direction + 1) % 4),
                         move(cur[0], cur[1], (direction - 1) % 4))
    # backforward the visited
#     print(buff)
    for r, c in buff:
        visited[r][c] = 0

#    cache[(row, col, direction)] = cur_steps
    return cur_steps

best = move(0, 0, 0)
# display_visited()
best = max(move(0, 0, 1), best)

fout.write(f"{best + 1}\n")


fout.close()
