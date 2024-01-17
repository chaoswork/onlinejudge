"""
ID: huangch7
LANG: PYTHON3
TASK: ditch
"""


task_name = "ditch"
INF = 100000000


def get_ints_from_line():
    return [int(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()


fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

M, N = get_ints_from_line()
adj = {i: {} for i in range(1, N + 1)}

for _ in range(M):
    x, y, n = get_ints_from_line()
    if x not in adj:
        adj[x] = {}
    adj[x][y] = adj[x].get(y, 0) + n

# modified dijkstra
total_flow = 0
while True:
    visited = [0] * (N + 1)
    prev = [None] * (N + 1)
    flow = [0] * (N + 1)
    flow[1] = INF

    while True:
        max_flow = 0
        max_loc = None
        for i in range(1, N + 1):
            if visited[i]:
                continue
            if max_flow < flow[i]:
                max_flow = flow[i]
                max_loc = i
        if max_loc is None:
            break
        if max_loc == N:
            break
        visited[max_loc] = 1
        for i in adj[max_loc]:
            if flow[i] < min(max_flow, adj[max_loc][i]):
                flow[i] = min(max_flow, adj[max_loc][i])
                prev[i] = max_loc
    # no path here
    if flow[N] == 0:
        break
    total_flow += flow[N]
    cur = N
    while cur != 1:
        adj[prev[cur]][cur] -= flow[N]
        # try not back flow, but failed
        # this is a really good test case
        # 1 -> 2 10
        # 1 -> 4 8
        # 2 -> 3 10
        # 2 -> 5 6
        # 3 -> 6 10
        # 4 -> 3 8
        # 5 -> 6 6
        adj[cur][prev[cur]] = adj[cur].get(prev[cur], 0) + flow[N]
        cur = prev[cur]

fout.write(f"{total_flow}\n")
        

    
fout.close()
