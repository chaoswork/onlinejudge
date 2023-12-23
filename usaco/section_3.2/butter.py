"""
ID: huangch7
LANG: PYTHON3
TASK: butter
"""

from queue import PriorityQueue

task_name = "butter"

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N, P, C = [int(x) for x in fin.readline().split()]

cows = []
pathes = {}
result = {}
for _ in range(N):
    cows.append(int(fin.readline()))

for _ in range(C):
    a, b, d = [int(x) for x in fin.readline().split()]
    if a not in pathes:
        pathes[a] = {}
    pathes[a][b] = d
    if b not in pathes:
        pathes[b] = {}
    pathes[b][a] = d


# for i in range(1, P + 1):
#     pathes[(i, i)] = 0
# 
# for _ in range(C):
#     a, b, d = [int(x) for x in fin.readline().split()]
#     pathes[(a, b)] = d
#     pathes[(b, a)] = d

# O(P^3)
# for k in range(1, P + 1):
#     for i in range(1, P + 1):
#         for j in range(1, P + 1):
#             if (i, k) in pathes and (k, j) in pathes:
#                 if (i, j) not in pathes or pathes[(i, j)] > pathes[(i, k)] + pathes[(k, j)]:
#                     pathes[(i, j)] = pathes[(i, k)] + pathes[(k, j)]

# best = None
# for i in range(1, P + 1):
#     cur = 0
#     cannot_reach = False
#     for j in cows:
#         if (i, j) not in pathes:
#             cannot_reach = True
#             break
#         cur += pathes[(i, j)]
#     if cannot_reach:
#         continue
#     if best is None or best > cur:
#         best = cur

res = [[None] * (P + 1) for _ in range(P + 1)]

for start in set(cows):
    visited = [0] * (P + 1)
    dist = [None] * (P + 1)
    dist[start] = 0
    todo = PriorityQueue()
    todo.put((0, start))
    
    for _ in range(P):
        best = None
        best_node = None
        
        # for node in range(1, P + 1):
        #     if visited[node]:
        #         continue
        #     if dist[node] is None:
        #         continue
        #     if best is None or best > dist[node]:
        #         best = dist[node]
        #         best_node = node
        # visited[best_node] = 1
        # if best_node not in pathes:
        #     continue
        # for node in pathes[best_node]:
        #     if dist[node] is None or dist[node] > best + pathes[best_node][node]:
        #         dist[node] = best + pathes[best_node][node]

        while todo:
            best, best_node = todo.get()
            if not visited[best_node]:
                break
        visited[best_node] = 1
        if best_node not in pathes:
            continue
        for node in pathes[best_node]:
            if dist[node] is None or dist[node] > best + pathes[best_node][node]:
                dist[node] = best + pathes[best_node][node]
                # 这里更好的应该是Decrease Key，这样相当于插入了很多冗余节点
                todo.put((dist[node], node))
        
    for node in range(1, P + 1):
        res[node][start] = dist[node]

best = None
for i in range(1, P + 1):
    cur = 0
    cannot_reach = False
    for j in cows:
        if res[i][j] is None:
            cannot_reach = True
            break
        cur += res[i][j]
    if cannot_reach:
        continue
    if best is None or best > cur:
        best = cur

fout.write(f"{best}\n")


fout.close()
