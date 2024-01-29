task_name = "speeding"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N, M = get_list_from_line()

cur = 0
limits = [0] * 100
for _ in range(N):
    length, limit = get_list_from_line()
    for i in range(cur, cur + length):
        limits[i] = limit
    cur += length

cur = 0
ans = 0
for _ in range(M):
    length, speed = get_list_from_line()
    for i in range(cur, cur + length):
        if limits[i] < speed:
            ans = max(ans, speed - limits[i])
    cur += length

fout.write(f"{ans}\n")
        
        
