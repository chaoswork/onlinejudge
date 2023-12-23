"""
ID: huangch7
LANG: PYTHON3
TASK: agrinet
"""

task_name = "agrinet"

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N = int(fin.readline())

adj = []
while True:
    cur = [int(x) for x in fin.readline().strip().split()]
    if len(adj) == 0:
        adj.append(cur)
    elif len(adj[-1]) < N:
        adj[-1] += cur
    else:
        adj.append(cur)
    if len(adj) == N and len(adj[-1]) == N:
        break
    

visited = [0] * N
dist = [None] * N
dist[0] = 0
ans = 0

for _ in range(N):
    best = None
    node = None
    for i in range(N):
        if visited[i]:
            continue
        if dist[i] is None:
            continue
        if best is None or dist[i] < best:
            best = dist[i]
            node = i
    visited[node] = 1
    ans += best
    for i in range(N):
        if visited[i]:
            continue
        if dist[i] is None or dist[i] > adj[node][i]:
            dist[i] = adj[node][i]
fout.write(f"{ans}\n")
fout.close()
