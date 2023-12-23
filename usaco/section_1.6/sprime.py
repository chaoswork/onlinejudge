"""
ID: huangch7
LANG: PYTHON3
TASK: sprime
"""

task_name = "sprime"

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')


def is_prime(x):
    if x < 2:
        return False
    for i in range(2, x):
        if i * i > x:
            break
        if x % i == 0:
            return False
    return True


n = int(fin.readline())

res = [2, 3, 5, 7]

for i in range(n - 1):
    new_res = []
    for x in res:
        for y in range(1, 10, 2):
            num = x * 10 + y
            if is_prime(num):
                new_res.append(num)
    res = new_res
#    print(res)

for x in res:
    fout.write(f"{x}\n")

fout.close()
