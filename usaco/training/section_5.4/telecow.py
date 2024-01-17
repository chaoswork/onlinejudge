"""
ID: huangch7
LANG: PYTHON3
TASK: telecow
"""
# import math
# import copy
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





def max_flow(start, target, adj):

    def bfs(start, target, adj):
        level = {k: 0 for k in adj}
        queue = [start]
        level[start] = 1
        while len(queue):
            cur = queue.pop(0)
            for x in adj[cur]:
                if level[x]:
                    continue
                if adj[cur][x] <= 0:
                    continue
                level[x] = level[cur] + 1
                queue.append(x)
        return level[target] > 0, level

    def dfs(start, target, adj, cap, level):
        left = cap
        if start == target:
            return cap
        can_del = []
        for x in adj[start]:
            if level[x] == level[start] + 1 and adj[start][x] > 0:
                cur_flow = dfs(x, target, adj, min(left, adj[start][x]), level)
                adj[start][x] -= cur_flow
                if adj[start][x] == 0:
                    can_del.append(x)
                if start not in adj[x]:
                    adj[x][start] = 0
                adj[x][start] += cur_flow
                left -= cur_flow
#        for x in can_del:
#            del adj[start][x]
        return cap - left
                

    total = 0
    flow = {}
    for i in adj:
        flow[i] = {}
        for j in adj:
            flow[i][j] = 0

    while True:
        bfs_ok, level = bfs(start, target, adj)
        if not bfs_ok:
            break
#         print('level', level)
        total += dfs(start, target, adj, INF, level)
#         print(total, adj)

    return total
    
# print('debug', max_flow(1, 6, {1: {2:10, 4: 8}, 2:{3:10, 5:6}, 3:{6:10},
#                               4:{3:8}, 5:{6:6}, 6:{}}))

# print('debug', max_flow(start, target, adj))
        
    


# 点割变边割


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
            adj[i + 2000][j + 1000] = INF
            adj[j + 2000][i + 1000] = INF
            
            
    return adj

cnt = 0
ans = []

total = max_flow(start + 2000, target + 1000, get_new_adj(adj_init, remove_node=[]))
# 1 -- 3 -\ / 6 - 2   
#.  +- 4 - 9 -  7 --+
#.  +- 5 -/ \- 8 --+


# print(total)
for i in range(1, N + 1):
    if i == start or i == target:
        continue
    
#     adj = copy.deepcopy(adj_init)
#    print(ans)
#    print(adj_init)
#    print(get_new_adj(adj_init, remove_node=ans))
    
#    cur = max_flow(start, target, adj, remove_node=ans + [i])
    cur = max_flow(start + 2000, target + 1000, get_new_adj(adj_init, remove_node=ans + [i]))
    # ans 里包含了已经切断的节点，每切断一个，当前最大流就少一个。
    # 现在寻找能让最大流再减少的节点。
#     print(i, cur)

    if cur == total - len(ans) - 1:
        ans.append(i)
        cnt += 1
    if cnt == total:
        break
    
# print(ans)

fout.write(f"{total}\n")
line = " ".join([str(x) for x in ans])
fout.write(f"{line}\n")

fout.close()
