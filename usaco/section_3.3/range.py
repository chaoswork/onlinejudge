"""
ID: huangch7
LANG: PYTHON3
TASK: range
"""



task_name = "range"

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N = int(fin.readline())

square = []
right_attach = [[0] * N for _ in range(N)]
down_attach = [[0] * N for _ in range(N)]

for _ in range(N):
    square.append(fin.readline().strip())


# DP
# dp[i][j][l] = dp[i + 1][j][l - 1] and dp[i][j + 1][l - 1] and x[i][j] and x[i+l][j+l]

for i in range(N):
    right_attach[i][N - 1] = int(square[i][N - 1])
    for j in range(N - 2, -1, -1):
        if square[i][j] == '0':
            right_attach[i][j] = 0
        else:
            right_attach[i][j] = 1 + right_attach[i][j + 1]
# for line in right_attach:
#     print(line)
# print('-' * 10)

for j in range(N):
    down_attach[N - 1][j] = int(square[N - 1][j])
    for i in range(N - 2, -1, -1):
        if square[i][j] == '0':
            down_attach[i][j] = 0
        else:
            down_attach[i][j] = 1 + down_attach[i + 1][j]
# for line in down_attach:
#     print(line)

ans = [0] * (N + 1)
for i in range(N):
    for j in range(N):
        v = min(right_attach[i][j], down_attach[i][j])
        if v < 2:
            continue
        for k in range(1, N):
            if j + k >= N or i + k >= N:
                break
            v = min(v, down_attach[i][j + k], right_attach[i + k][j])
            if v < k + 1:
                break
            ans[k + 1] += 1

for i in range(N + 1):
    if ans[i]:
        fout.write(f"{i} {ans[i]}\n")

            


fout.close()
