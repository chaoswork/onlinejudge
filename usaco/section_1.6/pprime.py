"""
ID: huangch7
LANG: PYTHON3
TASK: pprime
"""

task_name = "pprime"

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

a, b = [int(x) for x in fin.readline().strip().split()]

# primes = [2]
# prime cache?
def is_prime(x):
    if x <= 1:
        return False
    for y in range(2, x):
        if y * y > x:
            break
        if x % y == 0:
            return False
    return True


res = [5, 7]
res = [x for x in res if a <= x <= b]


for x in range(10, b):
    x = str(x)
    xx = int(x + x[:-1][::-1])
    if xx > b:
        break
    if xx < a:
        continue
    if is_prime(xx):
        res.append(xx)

for x in range(1, b):
    x = str(x)
    xx = int(x + x[::-1])
    if xx > b:
        break
    if xx < a:
        continue
    if is_prime(xx):
        res.append(xx)

for x in sorted(res):
    fout.write(f"{x}\n")
fout.close()
