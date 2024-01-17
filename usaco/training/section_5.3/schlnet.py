"""
ID: huangch7
LANG: PYTHON3
TASK: schlnet
"""
import math

task_name = "schlnet"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')
# +-------------+
# v             |
# 1-+-> 2 ---+->5
#   |-> 3    |
#   +-> 4<---+
# 跟之前的company control 有点像
# 可以用O(N^3) 的方法来求任意两点之间的最短路径
# 也可以用O(N^2)，每个点求floodfill,
# O(N)?，每个点已经求过到话，直接merge就行。

N = get_list_from_line()[0]
adj = {i: [] for i in range(1, N + 1)}
for i in range(1, N + 1):
    adj[i] += get_list_from_line()[:-1]

visited = [0] * (N + 1)


reach = [[0] * (N + 1) for _ in range(N + 1)]
n_reach = [0] * (N + 1)
n_can_reach = [0] * (N + 1)

def floodfill(cur):
    if visited[cur]:
        return
    visited[cur] = 1
    for x in adj[cur]:
        floodfill(x)


idx = 0
for i in range(1, N + 1):
    visited = [0] * (N + 1)
    floodfill(i)
    n = 0
    for j in range(1, N + 1):
        if visited[j]:
            reach[i][j] = 1
            n += 1
        n_reach[i] = n

for j in range(1, N + 1):

    n = 0
    for i in range(1, N + 1):
        if reach[i][j]:
            n += 1
    n_can_reach[j] = n
#     print(j, n_reach[j], n_can_reach[j], reach[j])        
    


n_cluster = 0

cands = list(range(1, N + 1))
best_ids = []
while len(cands):
    best = 0
    best_id = 0
    for i in cands:
        if n_reach[i] > best:
            best = n_reach[i]
            best_id = i
    best_ids.append(best_id)
    n_cluster += 1
    new_cands = []
    for i in cands:
        if reach[best_id][i]:
            continue
        new_cands.append(i)
    cands = new_cands

res2 = 0

# 计算强联通分量
new_id = 1
new_graph = [0] * (N + 1)

for i in range(1, N + 1):
    for j in range(i, N + 1):
        if reach[i][j] and reach[j][i]:
            if new_graph[i] == 0:
                new_graph[i] = new_id
                new_id += 1
            new_graph[j] = new_graph[i]

if n_cluster == 1 and new_id == 2:
    res = 2
else:
#    print(new_graph)
    new_adj = {i: set() for i in range(1, new_id)}
    for i in range(1, N + 1):
        for j in range(1, N + 1):
            if reach[i][j] and new_graph[i] != new_graph[j]:
                new_adj[new_graph[i]].add(new_graph[j])
    
#    print(new_adj)
    in_degree = [0] * (new_id)
    out_degree = [0] * (new_id)
    for i in new_adj:
        for j in new_adj[i]:
            out_degree[i] += 1
            in_degree[j] += 1
#    print(in_degree, out_degree)
    
    zero_in_degree = 0
    zero_out_degree = 0
    
    for i in range(1, new_id):
        if in_degree[i] == 0:
            zero_in_degree += 1
        if out_degree[i] == 0:
            zero_out_degree += 1
#    print(zero_in_degree, zero_out_degree)
    res2 = max(zero_in_degree, zero_out_degree)
            

    

# print(n_cluster)
# 
# res2 = 0 # cluster edges
# if n_cluster > 1:
#     res2 = n_cluster
# for best_id in best_ids:
#     cands = []
#     for i in range(1, N + 1):
#         if i == best_id:
#             continue
#         if reach[best_id][i] and not reach[i][best_id]:
#             cands.append(i)
#     # add local edges
#     while len(cands):
#         best = 0
#         best_j = 0
#         for j in cands:
#             if n_can_reach[j] > best:
#                 best = n_can_reach[j]
#                 best_j = j
#         res2 += 1
#         new_cands = []
#         for i in cands:
#             if reach[i][best_j]:
#                 continue
#             new_cands.append(i)
#         cands = new_cands
#         
#             
#         
                
        

# print(res2)

fout.write(f"{n_cluster}\n{res2}\n")

fout.close()
