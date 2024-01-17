"""
ID: huangch7
LANG: PYTHON3
TASK: ariprog
"""

task_name = "ariprog"

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

# 1 4: 1 5 9 13 17



n = int(fin.readline())
m = int(fin.readline())

bisqures = set()

for i in range(m + 1):
    for j in range(m + 1):
        bisqures.add(i * i + j * j)
# print(len(bisqures), bisqures)

def check_ab(a, b, n):
    cur = a + b + b
    for i in range(2, n):
        if cur not in bisqures:
            return False
        cur += b
    return True

# print(check_ab(1, 4, n))

# pre calc margins?
# cand_margins = set()

# for i in rang



max_v = max(bisqures)
min_v = min(bisqures)
cand_list = sorted(bisqures)


res = []

found = False
for i in range(len(cand_list) - n + 1):
    for j in range(i + 1, len(cand_list) - n + 2):
        a = cand_list[i]
        b = cand_list[j] - cand_list[i]
        if a + (n - 1) * b > max_v:
            break
        if check_ab(a, b, n):
            found = True
            # fout.write(f"{a} {b}\n")
            res.append((a, b))
for a, b in sorted(res, key=lambda x: x[1]):
    fout.write(f"{a} {b}\n")
if not found:
    fout.write('NONE\n')
fout.close()
