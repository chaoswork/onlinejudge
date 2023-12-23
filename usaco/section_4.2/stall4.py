"""
ID: huangch7
LANG: PYTHON3
TASK: stall4
"""


task_name = "stall4"
INF = 100000000


def get_ints_from_line():
    return [int(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()


fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N, M = get_ints_from_line()
adj = {i: {} for i in range(0, N + M + 2)}

# 0 for source,
# [1 - N] for cow
# [N + 1, N + M]
# N + M + 1 for target
for i in range(1, N + 1):
    adj[0][i] = 1
    for j in get_ints_from_line()[1:]:
        adj[i][j + N] = 1
for j in range(N + 1, N + M + 1):
    adj[j][N + M + 1] = 1

# modified dijkstra
total_flow = 0
start = 0
end = N + M + 1
total_node = N + M + 2
while True:
    visited = [0] * total_node
    prev = [None] * total_node
    flow = [0] * total_node
    flow[start] = INF

    while True:
        max_flow = 0
        max_loc = None
        for i in range(0, total_node):
            if visited[i]:
                continue
            if max_flow < flow[i]:
                max_flow = flow[i]
                max_loc = i
        if max_loc is None:
            break
        if max_loc == end:
            break
        visited[max_loc] = 1
        for i in adj[max_loc]:
            if flow[i] < min(max_flow, adj[max_loc][i]):
                flow[i] = min(max_flow, adj[max_loc][i])
                prev[i] = max_loc
    # no path here
    if flow[end] == 0:
        break
    total_flow += flow[end]
    cur = end
    while cur != 0:
        adj[prev[cur]][cur] -= flow[end]
        # try not back flow, but failed
        # this is a really good test case
        # 1 -> 2 10
        # 1 -> 4 8
        # 2 -> 3 10
        # 2 -> 5 6
        # 3 -> 6 10
        # 4 -> 3 8
        # 5 -> 6 6
        adj[cur][prev[cur]] = adj[cur].get(prev[cur], 0) + flow[end]
        cur = prev[cur]

fout.write(f"{total_flow}\n")
        

    
fout.close()
