"""
ID: huangch7
LANG: PYTHON3
TASK: castle
"""

task_name = "castle"

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

m, n = [int(x) for x in fin.readline().strip().split()]

castle = []
mark = []
count = {}
# unmark = set()
for i in range(n):
    castle.append([int(x) for x in fin.readline().strip().split()])
    mark.append([0] * m)


def floodfill(x, y, label):
    """
      2
    1   4
      8
    """
    # print(x, y, label)
    if mark[x][y] > 0:
        return
    mark[x][y] = label
    if label not in count:
        count[label] = 0
    count[label] += 1
    if x > 0 and castle[x][y] & 2 == 0:
        floodfill(x - 1, y, label)
    if x < n - 1 and castle[x][y] & 8 == 0:
        floodfill(x + 1, y, label)
    if y > 0 and castle[x][y] & 1 == 0:
        floodfill(x, y - 1, label)
    if y < m - 1 and castle[x][y] & 4 == 0:
        floodfill(x, y + 1, label)


label = 1
#print(mark)
while True:
    # use a set storage unmarked castle
    pos = None
    for i in range(n):
        for j in range(m):
            if mark[i][j] == 0:
                pos = (i, j)
                break
    if pos is None:
        break
    # print('pos=', pos)
    floodfill(pos[0], pos[1], label)
    label += 1

fout.write(f"{label - 1}\n")
fout.write(f"{max(count.values())}\n")
best = 0
best_ans = None

for j in range(0, m):
    for i in range(n - 1, -1, -1):    
        # check north wall first
        if i > 0 and mark[i - 1][j] != mark[i][j]:
            total = count[mark[i - 1][j]] + count[mark[i][j]]
            if total > best:
                best = total
                best_ans = (i, j, 'N')
        # then the east wall
        if j < m - 1 and mark[i][j + 1] != mark[i][j]:
            total = count[mark[i][j + 1]] + count[mark[i][j]]
            if total > best:
                best = total
                best_ans = (i, j, 'E')
fout.write(f"{best}\n")
fout.write(f"{best_ans[0] + 1} {best_ans[1] + 1} {best_ans[2]}\n")
fout.close()
