"""
ID: huangch7
LANG: PYTHON3
TASK: milk4
"""
import math

task_name = "milk4"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

Q = get_list_from_line()[0]
N = get_list_from_line()[0]
buckets = []
for _ in range(N):
    buckets.append(get_list_from_line()[0])

comb = [set() for _ in range(Q + 1)]
ans = [None] * (Q + 1)
one_ans = set()
for x in buckets:
    cur = x
    while cur <= Q:
        ans[cur] = 1
        one_ans.add(cur)
        if len(comb[cur]) == 0:
            comb[cur].add(x)
        cur += x

def greater(a, b):
    aa = list(sorted(a))
    bb = list(sorted(b))

    for i in range(len(aa)):
        if aa[i] == bb[i]:
            continue
        return aa[i] > bb[i]
                   

cands = set()
for x in one_ans:
    cands.add(x)
cnt = 2
while ans[Q] is None:
    new_cands = set()
    for x in one_ans:
        for y in cands:
            if x + y > Q:
                continue
            if ans[x + y] is None:
                new_cands.add(x + y)
                ans[x + y] = cnt
                comb[x + y] = comb[x] | comb[y]
            elif ans[x + y] == cnt:
                new_comb = comb[x] | comb[y]
                # 局部最优  vs 全局？
                if greater(comb[x + y], new_comb):
                    comb[x + y] = new_comb
    
    cnt += 1
    cands = new_cands



line = " ".join([str(x) for x in sorted(comb[Q])])
fout.write(f"{ans[Q]} {line}\n")




    



fout.close()
