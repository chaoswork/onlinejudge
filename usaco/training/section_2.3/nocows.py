"""
ID: huangch7
LANG: PYTHON3
TASK: nocows
"""
import math
task_name = "nocows"

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N, K = [int(x) for x in fin.readline().strip().split()]

nocows = {}

def dfs_dp(n, k):
    if n & 1 == 0:
        return 0
    if (n, k) in nocows:
        return nocows[(n, k)]
    if not (int(math.log(n + 1, 2)) <= k <= (n + 1) // 2):
        nocows[(n, k)] = 0
        return 0
    if n == 1 and k == 1:
        return 1
    count = 0
    for i in range(1, n, 2):
        for k1 in range(1, k):
            for k2 in range(1, k):
                if max(k1, k2) != k - 1:
                    continue
                # print(i, k1, n - i - 1, k2)
                if i < n - i - 1:
                    count += dfs_dp(i, k1) * dfs_dp(n - i - 1, k2) * 2
                elif i == n - i - 1:
                    count += dfs_dp(i, k1) * dfs_dp(n - i - 1, k2) 
                    
    nocows[(n, k)] = count % 9901
    return nocows[(n, k)]


# print(nocows)
fout.write(f"{dfs_dp(N, K) % 9901}\n")

fout.close()
