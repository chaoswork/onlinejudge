"""
ID: huangch7
LANG: PYTHON3
TASK: maze1
"""

"""
5 3
+-+-+-+-+-+
|         |
+-+ +-+ + +
|     | | |
+ +-+-+ + +
| |     |  
+-+ +-+-+-+
"""

task_name = "maze1"

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

m, n = [int(x) for x in fin.readline().strip().split()]
maze = []
ans = [[None] * m for _ in range(n)]

for _ in range(n * 2 + 1):
    maze.append(fin.readline())

# find gate
queue = set()
for j in range(m):
    # 0 -> 1, 1 -> 3, 2 -> 5
    if maze[0][j * 2 + 1] == ' ':
        ans[0][j] = 0
        queue.add((0, j))

for j in range(m):
    # 0 -> 1, 1 -> 3, 2 -> 5
    if maze[n * 2][j * 2 + 1] == ' ':
        ans[n - 1][j] = 0
        queue.add((n - 1, j))

for i in range(n):
    # 0 -> 1, 1 -> 3, 2 -> 5
    if maze[i * 2 + 1][0] == ' ':
        ans[i][0] = 0
        queue.add((i, 0))

for i in range(n):
    # 0 -> 1, 1 -> 3, 2 -> 5
    if maze[i * 2 + 1][m * 2] == ' ':
        ans[i][m - 1] = 0
        queue.add((i, m - 1))

# bfs
def count(x, y, ans_x, ans_y, cnt):
    if ans_x < 0 or ans_x == n or ans_y < 0 or ans_y == m:
        return
    if maze[x][y] == ' ':
        if ans[ans_x][ans_y] is None or ans[ans_x][ans_y] > cnt + 1:
            ans[ans_x][ans_y] = cnt + 1
            queue.add((ans_x, ans_y))

while len(queue):
    new_queue = list(queue)
    queue = set()
    for x, y in new_queue:
        # cur: x * 2 + 1, y * 2 + 1
        count(x * 2, y * 2 + 1, x - 1, y, ans[x][y])
        count(x * 2 + 1, y * 2, x, y - 1, ans[x][y])
        count(x * 2 + 2, y * 2 + 1, x + 1, y, ans[x][y])
        count(x * 2 + 1, y * 2 + 2, x, y + 1, ans[x][y])
best = 0
for line in ans:
    if best < max(line):
        best = max(line)
fout.write(f"{best + 1}\n")
fout.close()
