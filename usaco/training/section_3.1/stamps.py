"""
ID: huangch7
LANG: PYTHON3
TASK: stamps
"""

task_name = "stamps"

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

K, N = [int(x) for x in fin.readline().strip().split()]

coins = []
# dp[x] = y, values x need at least y coins
dp = [None] * 2000010
dp[0] = 0
while len(coins) < N:
    coins += [int(x) for x in fin.readline().strip().split()]

ans = 0
for i in range(1, len(dp)):
    best = None
    
    for j in range(len(coins)):
        prev = i - coins[j]
        if prev >= 0 and dp[prev] is not None and dp[prev] <= K - 1:
            if best is None or best > dp[prev] + 1:
                best = dp[prev] + 1
    if best is None:
        ans = i - 1        
        break
    dp[i] = best

# print(dp[:20])
# print(ans)
fout.write(f"{ans}\n")
fout.close()
