"""
ID: huangch7
LANG: PYTHON3
TASK: nuggets
"""


task_name = "nuggets"
INF = 100000000


def get_ints_from_line():
    return [int(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()


fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

n = int(fin.readline())
prods = []
for _ in range(n):
    prods.append(int(fin.readline()))
prods = sorted(prods)


period = 0
period_cnt = 0
ans = [0] * (prods[-1] + 1)
result = 0
ans[0] = 1

for i in range(1, prods[-1] + 1):
    found = False
    for x in prods:
        if i - x >= 0 and ans[i - x]:
            ans[i] = 1
            found = True
            break
    if not found:
        result = i
cur = prods[-1] + 1

covered_length = 0
while True:
    found = False
    for x in prods:
        if cur - x >= 0 and ans[cur - x]:
            found = True
            break
    if not found:
        if cur - result != period:
            period = cur - result
            period_cnt = 1
        else:
            period_cnt += 1
        # but I don't kown how to limit the period count
        if period_cnt > 20000:
            result = 0
            break
        result = cur
        covered_length = 0
        ans.append(0)
    else:
        ans.append(1)
        covered_length += 1
        if covered_length == prods[0]:
            break
#     print(cur, found, covered_length)
    cur += 1

fout.write(f"{result}\n")


fout.close()
