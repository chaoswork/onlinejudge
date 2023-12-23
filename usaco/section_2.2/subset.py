"""
ID: huangch7
LANG: PYTHON3
TASK: subset
"""

task_name = "subset"

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N = int(fin.readline())
N_sum = (N * (N + 1)) // 2

if N_sum & 1:
    fout.write("0\n")
else:
    # DP
    # dp[i][j] 表示第i件物品的时候和可以为j, dp[:,0] = 1 表示什么都不选
    # dp[i][v] = dp[i-1][v] or dp[i-1][v - i]
    target = N_sum // 2
    dp = [[0] * (target + 1) for _ in range(N + 1)]
    for i in range(N + 1):
        dp[i][0] = 1
    for i in range(1, N + 1):
        for v in range(1, target + 1):
            if dp[i - 1][v]:
                dp[i][v] += dp[i - 1][v]
            if v >= i and dp[i - 1][v - i]:
                dp[i][v] += dp[i - 1][v - i]
#    for i in range(N + 1):
#        print(dp[i])
    fout.write(f"{dp[N][target] // 2}\n")
fout.close()


