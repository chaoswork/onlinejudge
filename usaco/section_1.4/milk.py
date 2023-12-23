"""
ID: huangch7
LANG: PYTHON3
TASK: milk
"""

task_name = "milk"

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

n, m = [int(x) for x in fin.readline().strip().split()]

price_amount = []
for _ in range(m):
    p, t = [int(x) for x in fin.readline().strip().split()]
    price_amount.append((p, t))

price_amount = sorted(price_amount)

cost = 0
for i in range(m):
    p, t = price_amount[i]
    if n >= t:
        cost += p * t
        n -= t
    else:
        cost += p * n
        n = 0
fout.write(f"{cost}\n")

fout.close()
