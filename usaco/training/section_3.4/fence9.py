"""
ID: huangch7
LANG: PYTHON3
TASK: fence9
"""


task_name = "fence9"
INF = 100000000


def get_ints_from_line():
    return [int(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()


fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

n, m, p = get_ints_from_line()

# line 1: y = x * m / n
# line 2: y = x * m / (n - p) - p * m / (n - p)
total = 0
if n == p:
    for x in range(1, p):
        k = x * m // n
        total += k
        if k * n == x * m:
            total -= 1
elif n > p:
    for x in range(1, n):
        k = x * m // n
        total += k
        if k * n == x * m:
            total -= 1
    for x in range(p + 1, n):
        k = (x - p) * m // (n - p)
        total -= k
else:
    for x in range(1, n + 1):
        k = x * m // n
        total += k
        if k * n == x * m:
            total -= 1
        #print(total)
    
    for x in range(n + 1, p):
        k = (x - p) * m // (n - p)
        total += k
        if k * (n - p) == (x - p) * m:
            total -= 1
        #print(total)
        
fout.write(f"{total}\n")



    
fout.close()
