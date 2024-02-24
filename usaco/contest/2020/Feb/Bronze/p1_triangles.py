import sys

task_name = 'triangles'

INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f'{task_name}.in')
fout = open(f'{task_name}.out', 'w')

points = []
N = get_list_from_line()[0]
x_map = {}
y_map = {}
for _ in range(N):
    x, y = get_list_from_line()
    points.append((x, y))
    if x not in x_map:
        x_map[x] = []
    x_map[x].append(y)

    if y not in y_map:
        y_map[y] = []
    y_map[y].append(x)

best = 0        
for x1, y1 in points:
    for x2 in y_map[y1]:
        for y2 in x_map[x1]:
            area = abs(y2 - y1) * abs(x2 - x1)
            best = max(best, area)
fout.write(f"{best}\n")
fout.close()
