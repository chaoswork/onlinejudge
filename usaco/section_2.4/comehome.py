"""
ID: huangch7
LANG: PYTHON3
TASK: comehome
"""

task_name = "comehome"

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

n = int(fin.readline())
paths = {}
visited = {}
res = {}
for _ in range(n):
    a, b, d = fin.readline().strip().split()
    if a not in paths:
        paths[a] = {}
    if  b not in paths:
        paths[b] = {}
    if b not in paths[a]:
        paths[a][b] = int(d)
    elif paths[a][b] > int(d):
        paths[a][b] = int(d)
        
    paths[b][a] = paths[a][b]
    visited[a] = 0
    visited[b] = 0

res['Z'] = 0
for _ in range(len(visited)):
    # find next node
    best = None
    best_node = None
    for node in visited:
        if visited[node]:
            continue
        if node not in res:
            continue
        if best is None or best > res[node]:
            best = res[node]
            best_node = node
    # print(best_node, res)
    visited[best_node] = 1
    for neighbour in paths[best_node]:
        if neighbour not in res:
            res[neighbour] = res[best_node] + paths[best_node][neighbour]
        elif res[neighbour] > res[best_node] + paths[best_node][neighbour]:
            res[neighbour] = res[best_node] + paths[best_node][neighbour]
# print(res)
best = None
best_node = None
for node in res:
    if 'A' <= node < 'Z':
        if best is None or best > res[node]:
            best = res[node]
            best_node = node

fout.write(f"{best_node} {best}\n")







fout.close()
