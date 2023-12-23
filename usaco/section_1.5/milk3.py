"""
ID: huangch7
LANG: PYTHON3
TASK: milk3
"""

task_name = "milk3"

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')


A, B, C = [int(x) for x in fin.readline().split()]

checked = set()


def dfs(a, b, c):
    if (a, b, c) in checked:
        return
    # print('debug', a, b, c)
    checked.add((a, b, c))
    # a to b
    pour = min(a, B - b)
    dfs(a - pour, b + pour, c)
    # b to a
    pour = min(A - a, b)
    dfs(a + pour, b - pour, c)
    # a to c
    pour = min(a, C - c)
    dfs(a - pour, b, c + pour)
    # c to a
    pour = min(A - a, c)
    dfs(a + pour, b, c - pour)
    # b to c
    pour = min(C - c, b)
    dfs(a, b - pour, c + pour)
    # c to b
    pour = min(c, B - b)
    dfs(a, b + pour, c - pour)


dfs(0, 0, C)
res = set()
for item in checked:
    if item[0] == 0:
        res.add(item[2])

fout.write(" ".join([str(x) for x in sorted(res)]))
fout.write('\n')
fout.close()
