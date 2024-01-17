"""
ID: huangch7
LANG: PYTHON3
TASK: money
"""

task_name = "money"

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N, target = [int(x) for x in fin.readline().strip().split()]

V = [None]
while True:
    line = fin.readline().strip()
    if line:
        V += [int(x) for x in line.split()]
    else:
        break


dp = [[0] * (target + 1) for _ in range(N + 1)]

for i in range(N + 1):
    dp[i][0] = 1

for i in range(1, N + 1):
    for x in range(1, target + 1):
        # not use i
        dp[i][x] += dp[i - 1][x]
        # use i
        if x - V[i] >= 0:
            # use only once
            # dp[i][x] += dp[i - 1][x - V[i]]
            # use more than once
            dp[i][x] += dp[i][x - V[i]]
# for line in dp:
#     print(line)
# print(dp[N][target])

fout.write(f"{dp[N][target]}\n")


fout.close()
