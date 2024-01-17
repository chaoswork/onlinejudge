"""
ID: huangch7
LANG: PYTHON3
TASK: holstein
"""

task_name = "holstein"

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

V = int(fin.readline())

need = [int(x) for x in fin.readline().strip().split()]

G = int(fin.readline())

feeds = []
for _ in range(G):
    feeds.append([int(x) for x in fin.readline().strip().split()])

def check_need(need, total):
    for i in range(V):
        if total[i] < need[i]:
            return False
    return True

best = None
for x in range(1, 2 ** G):
    p = 0
    total = [0] * V
    ans = []
    while x:
        if x & 1:
            ans.append(p)
            
        x = x // 2
        p += 1
    
    for p in ans:
        for i in range(V):
            total[i] += feeds[p][i]

    # print(ans, total)
    if check_need(need, total):
        if best is None or len(best) > len(ans):
            best = ans
        elif len(best) == len(ans):
            if best > ans:
                best = ans
fout.write(f"{len(best)} ")
fout.write(f'{" ".join([str(x + 1) for x in best])}\n')
        
                
            

fout.close()
