"""
ID: huangch7
LANG: PYTHON3
TASK: cowtour
"""
import math
task_name = "cowtour"

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

pos = []
conn = []
n = int(fin.readline())
dist = [[None] * n for _ in range(n)]

for _ in range(n):
    pos.append([int(x) for x in fin.readline().strip().split()])
for _ in range(n):
    conn.append(fin.readline())

def get_dist(i, j):
    x = pos[i][0] - pos[j][0]
    y = pos[i][1] - pos[j][1]
    return math.sqrt(x * x + y * y)

for i in range(n):
    for j in range(n):
        if conn[i][j] == '0':
            continue

        dist[i][j] = get_dist(i, j)
    dist[i][i] = 0
                              

for k in range(n):
    for i in range(n):
        for j in range(n):
            
            if dist[i][k] is not None and dist[k][j] is not None:
                if dist[i][j] is None or dist[i][j] > dist[i][k] + dist[k][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]

# max dist from x
max_dist = {}
for i in range(n):
    best = 0
    for j in range(n):
        if dist[i][j] is None:
            continue
        if best < dist[i][j]:
            best = dist[i][j]
    max_dist[i] = best

# count parts
cnt = 0
colors = {}
for i in range(n):
    if i in colors:
        continue
    colors[i] = cnt
    cnt += 1
    for j in range(n):
        if dist[i][j] is not None:
            colors[j] = colors[i]
# print(colors)
# for line in dist:
#     print(line)

ans = None
for i in range(n):
    for j in range(n):
        if colors[i] == colors[j]:
            continue
        cur = max_dist[i] + max_dist[j] + get_dist(i, j)
        if ans is None or ans > cur:
            ans = cur
fout.write(f"{ans:.6f}\n")
fout.close()
