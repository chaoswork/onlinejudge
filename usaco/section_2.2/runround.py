"""
ID: huangch7
LANG: PYTHON3
TASK: runround
"""

task_name = "runround"

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N = int(fin.readline())


def check_runround(x):
    x = str(x)
    if '0' in x:
        return False
    if len(set(x)) != len(x):
        return False
    hit = [0] * len(x)
    cur = 0
    while hit[cur] == 0:
        # print(cur, x[cur])
        hit[cur] = 1
        cur = (int(x[cur]) + cur) % len(x)
    # print(cur, hit)
    return cur == 0 and sum(hit) == len(x)


N = N + 1
while not check_runround(N):
    N += 1

fout.write(f"{N}\n")


fout.close()
