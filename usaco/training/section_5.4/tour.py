"""
ID: huangch7
LANG: PYTHON3
TASK: tour
"""
import math

task_name = "tour"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N, M = get_list_from_line()
cities = {}
for _ in range(N):
    city = fin.readline().strip()
    cities[city] = len(cities)
adj = {i: [] for i in range(len(cities))}
# adj_rev = {}
visited = [0] * len(cities)

for _ in range(M):
    a, b = get_strs_from_line()
    a = cities[a]
    b = cities[b]
    if a not in adj:
        adj[a] = []
    adj[a].append(b)
    if b not in adj:
        adj[b] = []
    adj[b].append(a)


# 旅行商问题。

dp = [[0] * N for _ in range(N)]

dp[0][0] = 1

for i in range(0, N):
    for j in range(i + 1, N):
        for k in adj[j]:
            if k >= j:
                continue
            if dp[i][k] == 0:
                continue
            dp[i][j] = max(dp[i][j], dp[i][k] + 1)
            dp[j][i] = max(dp[i][j], dp[i][k] + 1)
#    print(dp[i])

ans = 1
for i in adj[N - 1]:
    ans = max(ans, dp[i][N - 1])
fout.write(f"{ans}\n")

fout.close()
# 
# def search_target(adj, cur, target):
#     if cur == target:
#         return 1
#     best = 0
#     for x in adj[cur]:
#         if visited[x]:
#             continue
#         visited[x] = 1
#         ret = search_target(adj, x, target)
#         visited[x] = 0
#         if ret:
#             best = max(best, ret + 1)
#     return best
# 
# res = 0
# def search(adj, cur, step):
#     global res
#     ret = search_target(adj, 0, cur)
#     if cur == len(cities) - 1 and res < ret + step:
# #         print(ret, step, cur)
#         res = ret + step
# 
#     for x in adj[cur]:
#         if visited[x]:
#             continue
#         visited[cur] = 1
#         search(adj, x, step + 1)
#         visited[cur] = 0
# 
# search(adj, 0, 0)
# # print(res)
# res = res - 1
# if res <= 0:
#     res = 1
# fout.write(f"{res}\n")
#         
#         
#     
#     
#     
# 
# 
# fout.close()
