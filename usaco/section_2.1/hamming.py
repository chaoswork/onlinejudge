"""
ID: huangch7
LANG: PYTHON3
TASK: hamming
"""

task_name = "hamming"

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N, B, D = [int(x) for x in fin.readline().strip().split()]

dist = {}

max_num = 2 ** B
for i in range(max_num):
    for j in range(i, max_num):
        dist[(i, j)] = (i ^ j).bit_count()
        dist[(j, i)] = dist[(i, j)]

found = False
best = None

def dfs(cur):
    global found, best, N, B, D
    if len(cur) == N:
        best = cur
        found = True
        return
    if found:
        return
    start = cur[-1] + 1 if len(cur) else 0

    for i in range(start, max_num):
        ok = True
        for j in range(len(cur)):
            if dist[(i, cur[j])] < D:
                ok = False
                break
        if ok:
            dfs(cur + [i])
        if found:
            break

dfs([])
for i in range(0, len(best), 10):
    fout.write(" ".join([str(x) for x in best[i: i + 10]]))
    fout.write("\n")


fout.close()
