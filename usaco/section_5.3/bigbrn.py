"""
ID: huangch7
LANG: PYTHON3
TASK: bigbrn
"""
import math

task_name = "bigbrn"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N, T = get_list_from_line()
barns = []
dp = [[1] * N for _ in range(N)]
for _ in range(T):
    x, y = get_list_from_line()
    barns.append((x, y))
    dp[x - 1][y - 1] = 0

best = 0
for i in range(N):
    best = max(dp[i][0], best)
    best = max(dp[0][i], best)
for i in range(1, N):
    for j in range(1, N):
        if dp[i][j] == 0:
            continue
        if dp[i - 1][j] == 0:
            continue
        if dp[i][j - 1] == 0:
            continue
        n = min(dp[i][j - 1], dp[i - 1][j])
#         while n > 0:
#             if dp[i - n][j - n]:
#                 dp[i][j] = max(n + 1, dp[i][j])
#             n -= 1
        if dp[i - n][j - n]:
            dp[i][j] = max(n + 1, dp[i][j])
        else:
            dp[i][j] = max(n, dp[i][j])
            
        if best < dp[i][j]:
            best = dp[i][j]
#     print(dp[i])
fout.write(f"{best}\n")
fout.close()
