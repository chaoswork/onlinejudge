"""
ID: huangch7
LANG: PYTHON3
TASK: telecow
"""
import math
import copy
task_name = "telecow"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N, M, start, target = get_list_from_line()
adj = {i: {} for i in range(1, N + 1)}
adj_init = {i: {} for i in range(1, N + 1)}
for _ in range(M):
    s, e = get_list_from_line()
    adj[s][e] = 1
    adj[e][s] = 1
    adj_init[s][e] = 1
    adj_init[e][s] = 1



def max_flow(start, target, adj, remove_node=[]):
    total = 0
    while True:
        flow = [None] * (N + 1)
        prev = [None] * (N + 1)
        visited = [0] * (N + 1)
        flow[start] = INF
        if len(remove_node) > 0:
            for x in remove_node:
                visited[x] = 1
    
        while True:
            best = 0
            best_pos = 0
    
            for i in range(1, N + 1):
                if visited[i]:
                    continue
                if flow[i] is None:
                    continue
                if best < flow[i]:
                    best = flow[i]
                    best_pos = i
            if best_pos == 0 or best_pos == target:
                break
    
            visited[best_pos] = 1
            for j in adj[best_pos]:
                cur_flow = min(adj[best_pos][j], flow[best_pos])
                if flow[j] is None or flow[j] < cur_flow:
                    flow[j] = cur_flow
                    prev[j] = best_pos
        if flow[target] is None:
            break
#         print(flow)
#         print(prev)
        cur = target
        while cur != start:
#             print('path', cur)
            adj[prev[cur]][cur] -= 1
            if len(remove_node) == 0:
                adj[cur][prev[cur]] += 1
            cur = prev[cur]
#        print('path end', cur)
        total += flow[target]
    return total

# print(max_flow(start, target, adj, remove_node=[6, 7]))

total = max_flow(start, target, adj)



# 点割变边割

def get_new_node(x):
    if x == start or x == end:
        return x
    return 

def get_new_adj(old_adj, remove_node):
    """
    i -> j
    
    i1 -> i2
    j1 -> j2

    
    """
    adj = {}
    for i in old_adj:
        adj[i + 1000] = {}
        adj[i + 2000] = {}
    for i in old_adj:
        if i in remove_node:
            continue
        adj[i + 1000][i + 2000] = 1
        for j in old_adj[i]:
            if j in remove_node:
                continue
            adj[i + 1000][j + 2000] = INF
            adj[i + 2000][j + 1000] = INF
            
            
    return adj

cnt = 0
ans = []

for i in range(1, N + 1):
    if i == start or i == target:
        continue
    
    adj = copy.deepcopy(adj_init)
#    print(ans)
#    print(adj_init)
#    print(get_new_adj(adj_init, remove_node=ans))
    
#    cur = max_flow(start, target, adj, remove_node=ans + [i])
    cur = max_flow(start, target, get_new_adj(adj_init, remove_node=[i]))
    # ans 里包含了已经切断的节点，每切断一个，当前最大流就少一个。
    # 现在寻找能让最大流再减少的节点。
    print(i, cur)
    if cur == total - len(ans) - 1:
        ans.append(i)
        cnt += 1
    if cnt == total:
        break
    
print(ans)

fout.write(f"{total}\n")
line = " ".join([str(x) for x in ans])
fout.write(f"{line}\n")

fout.close()
