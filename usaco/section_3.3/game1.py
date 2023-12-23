"""
ID: huangch7
LANG: PYTHON3
TASK: game1
"""

task_name = "game1"

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N = int(fin.readline())

numbers = []

while True:
    line = fin.readline()
    if not line:
        break
    numbers += [int(x) for x in line.strip().split()]

best = [[0] * (N + 1) for _ in range(N)]
total = [[0] * (N + 1) for _ in range(N)]

# best[i][j] means best score from i to j, not include j, [i, j)
# total[i][j] means scores from i to j, not include j
# best[i][j] = max(numbers[i] + total[i + 1][j] - best[i + 1][j], the other player takes the best from i + 1 to j
#                  numbers[j] + total[i][j - 1] - best[i][j - 1])


for i in range(N):
    for j in range(i + 1, N + 1):
        total[i][j] = total[i][j - 1] + numbers[j - 1]
# for line in total:
#     print(line)
# print('-' * 10)

# 0 1 2 3 4 5
# 4 7 2 9 5 2
# best[0][3] =
# total[0][2] = 11
# best[0][2] = 7
# best[1][3] = 7


for length in range(1, N + 1):
    for i in range(N):
        j = i + length
        if j > N:
            continue
        if length == 1:
            best[i][j] = numbers[i]
        else:
            best[i][j] = max(numbers[i] + total[i + 1][j] - best[i + 1][j],
                             numbers[j - 1] + total[i][j - 1] - best[i][j - 1])
# for line in best:
#    print(line)
        
fout.write(f"{best[0][N]} {total[0][N] -best[0][N]}\n")

        



# ans = [0, 0]
# 
# for i in range(N):
#     index = i & 1
#     if len(numbers) == 1:
#         ans[index] += numbers[0]
#     elif len(numbers) == 2:
#         ans[index] += max(numbers)
#         numbers = [min(numbers)]
#     else:
#         a, b, c, d = numbers[0], numbers[1], numbers[-2], numbers[-1]
#         max_v = max(a, b, c, d)
#         if max_v == a:
#             ans[index] += a
#             numbers.pop(0)
#         elif max_v == d:
#             ans[index] += d
#             numbers.pop()
#         else:
#             if a >= b and a >= d:
#                 ans[index] += a
#                 numbers.pop(0)
#             elif d >= a and d >= c:
#                 ans[index] += d
#                 numbers.pop()
#             else:
#                 if b - a < d - c:
#                     ans[index] += a
#                     numbers.pop(0)
#                 elif b - a == d - c:
#                     if a > d:
#                         ans[index] += a
#                         numbers.pop(0)
#                     else:
#                         ans[index] += d
#                         numbers.pop()
#                 else:
#                     ans[index] += d
#                     numbers.pop()
# 
# fout.write(f"{ans[0]} {ans[1]}\n")
fout.close()
