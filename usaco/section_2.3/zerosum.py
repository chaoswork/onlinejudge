"""
ID: huangch7
LANG: PYTHON3
TASK: zerosum
"""
import math
task_name = "zerosum"

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N = int(fin.readline())

res = []
def dfs(cur, n):
    if n == N + 1:
        if eval(cur.replace(' ', '')) == 0:
            res.append(cur)
        return
    dfs(cur + f' {n}', n + 1)
    dfs(cur + f'+{n}', n + 1)
    dfs(cur + f'-{n}', n + 1)

dfs('1', 2)
for line in sorted(res):
    fout.write(f"{line}\n")
fout.close()
