import sys


INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = sys.stdin
fout = sys.stdout

cands = set()
conds = []
N = get_list_from_line()[0]

for _ in range(N):
    op, num = get_strs_from_line()
    num = int(num)
    cands.add(num + 1)
    cands.add(num)
    cands.add(num - 1)
    conds.append((op, num))

best = N
for x in cands:
    fail = 0
    for k, v in conds:
        if k == 'G':
            if x < v:
                fail += 1
        else:
            if x > v:
                fail += 1
    best = min(fail, best)
            
        
fout.write(f"{best}\n")    
    
fout.close()
