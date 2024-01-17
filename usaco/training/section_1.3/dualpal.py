"""
ID: huangch7
LANG: PYTHON3
TASK: dualpal
"""


def is_pal(x):
    xx = str(x)
    for i in range(len(xx)):
        j = len(xx) - 1 - i
        if i > j:
            break
        if xx[i] != xx[j]:
            return False
    return True


def num2abc(x):
    if x < 10:
        return str(x)
    return chr(x - 10 + ord('A'))


def rebase(x, base):
    res = []
    while x:
        res.append(x % base)
        x = x // base
    res = res[::-1]
    res = [num2abc(x) for x in res]
    return ''.join(res)


task_name = "dualpal"

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

n, s = [int(x) for x in fin.readline().strip().split()]

found = 0
start = s + 1
while found < n:

    n_pal = 0
    for base in range(2, 11):
        if is_pal(rebase(start, base)):
            n_pal += 1
        if n_pal >= 2:
            break

    if n_pal >= 2:
        fout.write(f"{start}\n")
        found += 1

    start += 1

fout.close()
