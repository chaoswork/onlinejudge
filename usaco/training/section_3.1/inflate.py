"""
ID: huangch7
LANG: PYTHON3
TASK: inflate
"""


task_name = "inflate"

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

M, N = [int(x) for x in fin.readline().strip().split()]

info = []

for _ in range(N):
    point, time = [int(x) for x in fin.readline().strip().split()]
    info.append((point, time))

# print(info)
# dp[v] 表示容量为v能的到的最大分
dp = [None] * (M + 1)
dp[0] = 0

for i in range(1, M + 1):
    for j in range(len(info)):
        prev = i - info[j][1]
        if prev < 0:
            continue
        if dp[i] is None or dp[i] < dp[prev] + info[j][0]:
            dp[i] = dp[prev] + info[j][0]
    # 可以少装一些
    if dp[i] is None or dp[i] < dp[i - 1]:
        dp[i] = dp[i - 1]
# for i in range(0, M + 1, 10):
#     print(i, dp[i: i + 10])
fout.write(f"{dp[M]}\n")
fout.close()
