task_name = "mowing"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N = get_list_from_line()[0]

farm = [[0] * 1024 for _ in range(1024)]

x, y = 0, 0

dirs = {'W': [-1, 0], 'E': [1, 0], 'N': [0, 1], 'S': [0, -1]}
cnt = 1
best = -1
for _ in range(N):
    d, s = get_strs_from_line()
    s = int(s)
    for i in range(s):
        if farm[x][y] > 0:
            if best == -1 or best > cnt - farm[x][y]:
                best = cnt - farm[x][y]
        farm[x][y] = cnt
        cnt += 1
        x += dirs[d][0]
        y += dirs[d][1]

fout.write(f"{best}\n")
    
    

fout.close()        
        
    





        
