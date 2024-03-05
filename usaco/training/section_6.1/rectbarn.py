"""
ID: huangch7
LANG: PYTHON3
TASK: rectbarn
"""


task_name = "rectbarn"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

R, C, P = get_list_from_line()

field = [[0] * (C + 1) for _ in range(R + 1)]
for _ in range(P):
    x, y = get_list_from_line()
    field[x][y] = 1

# for i in range(R + 1):
#     print(field[i])

height = [[1] * (C + 2) for _ in range(R + 1)]
for i in range(1, R + 1):
    for j in range(1, C + 1):
        if field[i][j] == 1:
            height[i][j] = 0
        elif i > 1:
            height[i][j] = height[i - 1][j] + 1
    height[i][-1] = 0

best = 0
for i in range(1, R + 1):
#     print(height[i])
    stack = []
    for j in range(1, C + 2):
        idx, h = None, None
        while len(stack) and stack[-1][1] > height[i][j]:
            idx, h = stack.pop()
            area = (j - idx) * h
            best = max(best, area)
#             print('debug', j, idx, h)
            
        if idx is None:
            stack.append((j, height[i][j]))
        else:
            stack.append((idx, height[i][j]))
#         print(j, stack, best)
    
fout.write(f"{best}\n")
            

fout.close()
