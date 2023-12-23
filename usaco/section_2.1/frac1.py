"""
ID: huangch7
LANG: PYTHON3
TASK: frac1
"""

task_name = "frac1"

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

n = int(fin.readline())


def reduced(x, y):
    # print('raw', x, y)
    for d in range(2, x + 1):
        while x % d == 0 and y % d == 0:
            x = x // d
            y = y // d
    # print('reduced', x, y)
    return (x, y)


res = set()
for i in range(1, n + 1):
    for j in range(1, i):
        res.add(reduced(j, i))

res = sorted(res, key=lambda x: x[0] / x[1])
fout.write("0/1\n")
for x, y in res:
    fout.write(f"{x}/{y}\n")
if n > 0:
    fout.write("1/1\n")
fout.close()
