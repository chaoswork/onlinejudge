"""
ID: huangch7
LANG: PYTHON3
TASK: milk6
"""
import random

task_name = "milk6"
INF = 100000000


def get_ints_from_line():
    return [int(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()


fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')


N, M = get_ints_from_line()

start = 0
end = N - 1

adj = {x: {} for x in range(N)}
idx = {}
for i in range(1, M + 1):
    s, e, w = get_ints_from_line()
    s = s - 1
    e = e - 1
#    if s not in adj:
#        adj[s] = {}
    if e not in adj[s]:
        adj[s][e] = 0
    adj[s][e] += w
    if (s, e) not in idx:
        idx[(s, e)] = []
    
    idx[(s, e)].append(i)


def one_flow(start, end, adj, remove_node=None):
    visited = [0] * (end + 1)
    prev = [None] * (end + 1)
    flow = [0] * (end + 1)
    flow[start] = INF
    while True:
        # find best flow
        best = 0
        best_pos = None
        for i in range(end + 1):
            if visited[i]:
                continue
            if flow[i] > best:
                best = flow[i]
                best_pos = i
        if best_pos is None:
            break
        visited[best_pos] = 1
#        print('debug', best, best_pos, adj)
        for j in adj[best_pos]:
            # 阻断 node
            if j == remove_node:
                continue
            cur_flow = min(flow[best_pos], adj[best_pos][j])
            if flow[j] < cur_flow:
                flow[j] = cur_flow
                prev[j] = best_pos
    return flow, prev

# print(start, end)
# print(adj)

def copy_dict(adj):
    adj_copy = {}
    for i in adj:
        adj_copy[i] = {}
        for j in adj[i]:
            adj_copy[i][j] = adj[i][j]
    return adj_copy

adj_copy = copy_dict(adj)
ans = []
cost = 0
while True:
    total = [0] * (end + 1)
    adj = copy_dict(adj_copy)
#    print(start, end, adj)
    while True:
    
        flow, prev = one_flow(start, end, adj)
#         valid_paths.append(prev)
    #    print(flow, prev)
        if flow[end] == 0:
            break
        
        cur = end
        while cur != start:
            adj[prev[cur]][cur] -= flow[end]
            if cur not in adj:
                adj[cur] = {}
            if prev[cur] not in adj[cur]:
                adj[cur][prev[cur]] = 0
            adj[cur][prev[cur]] += flow[end]
            total[cur] += flow[end]
            cur = prev[cur]

    if total[end] == 0:
        break
    # find max pipe
    best = 0
    best_se = None

    for i in adj_copy:
        for j in adj_copy[i]:
            if adj[i][j] != 0:
                continue
            if best < adj_copy[i][j]:
                best = adj_copy[i][j]
                best_se = (i, j)
            elif best == adj_copy[i][j]:
                # print(i,j, best_se, len(idx[(s, e)]), len(idx[(best_se[0], best_se[1])]),
                #      sum(idx[(s, e)]), sum(idx[(best_se[0], best_se[1])]))
                if len(idx[(i, j)]) < len(idx[(best_se[0], best_se[1])]):
                    best_se = (i, j)
                elif len(idx[(i, j)]) == len(idx[(best_se[0], best_se[1])]):
                    if sum(idx[(i, j)]) < sum(idx[(best_se[0], best_se[1])]):
                           best_se = (i, j)
                    
                    
    
    ans.append(best_se)
    cost += best
    del adj_copy[best_se[0]][best_se[1]]
# print(cost, ans)

paths = []
for (s, e) in ans:
    paths += idx[(s, e)]

            
fout.write(f"{cost} {len(paths)}\n")
if len(paths):
    paths = sorted(paths)
    for i in range(len(paths)):
        fout.write(f"{paths[i]}\n")

fout.close()
