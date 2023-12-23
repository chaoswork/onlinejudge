"""
ID: huangch7
LANG: PYTHON3
TASK: palsquare
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


task_name = "palsquare"

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

n = int(fin.readline())

# print(rebase(15, 16))
# print(rebase(20, 16))


res = []

for x in range(1, 301):
    xx = x * x
    xx_rebase = rebase(xx, n)
    if is_pal(xx_rebase):
        fout.write(f"{rebase(x, n)} {xx_rebase}\n")

fout.close()
