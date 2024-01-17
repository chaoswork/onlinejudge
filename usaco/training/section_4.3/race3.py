"""
ID: huangch7
LANG: PYTHON3
TASK: race3
"""
import random

task_name = "race3"
INF = 100000000


def get_ints_from_line():
    return [int(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()


fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N = 0
adj = {}
while True:
    part = get_ints_from_line()
    if part[0] == -1:
        break
    # remove self loop path 
    adj[N] = {x: 1 for x in part[:-1] if x != N}
    N += 1


start = 0
end = N - 1

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
total = [0] * (end + 1)


adj_one = {}
for i in adj:
    adj_one[i] = {}
    for j in adj[i]:
        adj_one[i][j] = adj[i][j]

def random_adj(adj_one):
    adj = {}
    for i in adj_one:
        adj[i] = {}
        for j in adj_one[i]:
            adj[i][j] = random.randint(1, 100)
    return adj
    
for _ in range(4):

    adj = random_adj(adj_one)
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


ans = []
for i in range(start + 1, end):
    if total[i] == total[end]:
        ans.append(i)
ans1 = [len(ans)] + ans
ans1 = " ".join([str(x) for x in ans1])
fout.write(ans1 + "\n")


    
# find the split
ans2 = []
for node in ans:
    adj = random_adj(adj_one)
    flow, _ = one_flow(start, end, adj, remove_node=node)
    color = [0] * (end + 1)
    for i in range(end + 1):
        color[i] = 1 if flow[i] else 0
    color[node] = 2
#     print(color)
    is_split = True
    for i in adj_one:
        for j in adj_one[i]:
            if color[i] + color[j] == 1:
                is_split = False
    for i in adj_one[node]:
        for j in adj_one[node]:
            if i == j:
                continue
            if color[i] != color[j]:
                is_split = False
        
    if is_split:
        ans2.append(node)

ans2 = [len(ans2)] + ans2
ans2 = " ".join([str(x) for x in ans2])
fout.write(ans2 + "\n")

            
            
            
            


fout.close()
