"""
ID: huangch7
LANG: PYTHON3
TASK: fact4
"""

task_name = "fact4"

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N = int(fin.readline())

counts = [0] * 10


def get_res(x, n):
    assert n >= 0
    if n == 0:
        return 1
    if x in [0, 1, 5, 6]:
        return x
    if x == 2:
        return [2, 4, 8, 6][(n - 1) % 4]
    if x == 3:
        return [3, 9, 7, 1][(n - 1) % 4]
    if x == 4:
        return [4, 6][(n - 1) % 2]
    if x == 7:
        return [7, 9, 3, 1][(n - 1) % 4]
    if x == 8:
        return [8, 4, 2, 6][(n - 1) % 4]
    if x == 9:
        return [9, 1][(n - 1) % 2]

# 2 5 -> 1
# 12 15 -> 8
# 22 25 -> 5
# 32 35 -> 2
# (10x + 2) * (10x + 5) -> 100x^2 + 70x + 10 -> 10x^2 + 7x + 1 -> 7x + 1


for i in range(1, N + 1):
    ii = i
    while ii % 5 == 0:
        ii = ii // 5
        counts[5] += 1
    while ii % 2 == 0:
        ii = ii // 2
        counts[2] += 1
    counts[ii % 10] += 1

# print(counts)
assert counts[2] >= counts[5]

counts[2] -= counts[5]
counts[5] = 0

res = 1
for i in range(2, 10):
    res *= get_res(i, counts[i])

fout.write(f"{res % 10}\n")
    
    

fout.close()
