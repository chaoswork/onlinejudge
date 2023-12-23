"""
ID: huangch7
LANG: PYTHON3
TASK: combo
"""

task_name = "combo"


def dist(x, y, N):
    if x > y:
        x, y = y, x
    return min(y - x, N - y + x)


def get_comm(x, y, N):
    xy_dist = dist(x, y, N)
    return 5 - min(5, xy_dist)


fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

n = int(fin.readline())


if n <= 5:
    fout.write(f"{n * n * n}\n")
else:
    a1, a2, a3 = [int(x) for x in fin.readline().strip().split()]
    b1, b2, b3 = [int(x) for x in fin.readline().strip().split()]

    res = 5 * 5 * 5 * 2
    res -= get_comm(a1, b1, n) * get_comm(a2, b2, n) * get_comm(a3, b3, n)

    fout.write(f"{res}\n")
fout.close()
