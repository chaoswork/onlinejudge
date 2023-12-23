"""
ID: huangch7
LANG: PYTHON3
TASK: camelot
"""


task_name = "camelot"
INF = 10000000000

def get_ints_from_line():
    return [int(x) for x in fin.readline().strip().split()]

def get_strs_from_line():
    return fin.readline().strip().split()

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

R, C = get_ints_from_line()

pos = []

while True:
    cols = get_strs_from_line()
    if len(cols) == 0:
        break
    for i in range(0, len(cols), 2):
        pos.append((int(cols[i + 1]) - 1, ord(cols[i]) - ord('A')))

king = pos[0]
knights = pos[1:]

# print(king)
# print(len(knights))

paths = {}

def dp(x1, y1, x2, y2):

    if (x1, y1, x2, y2) in paths:
        return paths[(x1, y1, x2, y2)]
    # position, distance, pick_king
    deque = [((x1, y1), 0)]
    paths[(x1, y1, x1, y1)] = 0
    while len(deque):
        start, dist = deque.pop(0)
        for x, y in [(-1, 2), (-1, -2), (1, -2), (1, 2),
                     (-2, 1), (-2, -1), (2, -1), (2, 1)]:
            x_mid, y_mid = start[0] + x, start[1] + y
            if x_mid < 0 or x_mid >= R or y_mid < 0 or y_mid >= C:
                continue
            if (x1, y1, x_mid, y_mid) in paths:
                continue
            paths[(x1, y1, x_mid, y_mid)] = 1 + dist
            paths[(x_mid, y_mid, x1, y1)] = 1 + dist
# TODO: if add this, WA
#             if (x1, y1, x2, y2) in paths:
#                 break
            deque.append(((x_mid, y_mid), dist + 1))
    if (x1, y1, x2, y2) not in paths:
        paths[(x1, y1, x2, y2)] = INF
        paths[(x2, y2, x1, y1)] = INF

    return paths[(x1, y1, x2, y2)]


# print('debug-1', dp(2, 0, 2, 3))
# print('debug-1', dp(2, 3, 2, 0))


best = None
for x in range(R):
    for y in range(C):
        total = 0

        for x_k, y_k in knights:
            total += dp(x_k, y_k, x, y)

        total_knights = total
        total += max(abs(x - king[0]), abs(y - king[1]))
        if best is None or best > total:
            best = total
        for x_k, y_k in knights:
            pick_king_dist = total_knights - dp(x_k, y_k, x, y)
            pick_king_dist += dp(x_k, y_k, king[0], king[1])
            pick_king_dist += dp(king[0], king[1], x, y)
            best = min(best, pick_king_dist)
#            if x == 2 and y == 3:
#                print('debug', x_k, y_k, total_knights, dp(x_k, y_k, x, y), dp(x_k, y_k, king[0], king[1]), dp(king[0], king[1], x, y))
#         print(x, y, total_knights, best)

fout.write(f"{best}\n")

# print(dp(2, 0, 4, 1))
# print(pick_king[(2, 0, 4, 1)])
# print(dp(7, 0, 4, 1))
# print(pick_king[(7, 0, 4, 1)])
# print(dp(0, 7, 4, 1))
# print(pick_king[(0, 7, 4, 1)])
# print(dp(7, 7, 4, 1))
# print(pick_king[(7, 7, 4, 1)])
    
fout.close()
