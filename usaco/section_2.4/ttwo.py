"""
ID: huangch7
LANG: PYTHON3
TASK: ttwo
"""

task_name = "ttwo"

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

grid = []
direction = [
    [-1, 0], # 0 for 'N'
    [0, 1], # 1 for E
    [1, 0], # 2 for S
    [0, -1] # 3 for W
]

pos_farmer = None
pos_cow = None
for i in range(10):
    grid.append(fin.readline().strip())
    if 'F' in grid[-1]:
        pos_farmer = (i, grid[-1].find('F'), 0)
    if 'C' in grid[-1]:
        pos_cow = (i, grid[-1].find('C'), 0)

original_posf = pos_farmer
original_posc = pos_cow

def move(pos):
    x, y, d = pos
    xx = x + direction[d][0]
    yy = y + direction[d][1]

    if xx < 0 or xx >= 10:
        return (x, y, (d + 1) % 4)
    if yy < 0 or yy >= 10:
        return (x, y, (d + 1) % 4)
    if grid[xx][yy] == '*':
        return (x, y, (d + 1) % 4)

    return (xx, yy, d)


time = 0
# how to know is infinite?
# 1. follow other
# 2. loop
# 3. both will have a loop
farm_loop = None
cow_loop = None
farm_trace = set()
farm_trace.add(pos_farmer)
cow_trace = set()
cow_trace.add(pos_cow)
while True:
    time += 1

    pos_farmer = move(pos_farmer)
    pos_cow = move(pos_cow)
    if pos_cow[0] == pos_farmer[0] and pos_cow[1] == pos_farmer[1]:
        break

    if cow_loop is None and pos_cow in cow_trace:
        cow_loop = time
#        print(cow_loop)
    cow_trace.add(pos_cow)
    if farm_loop is None and pos_farmer in farm_trace:
        farm_loop = time
#        print(farm_loop)
    farm_trace.add(pos_farmer)

    if farm_loop and cow_loop and (time % farm_loop == 0) and (time % cow_loop == 0):
        time = 0
        break
fout.write(f"{time}\n")
