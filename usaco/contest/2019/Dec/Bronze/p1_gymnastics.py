task_name = "gymnastics"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

K, N = get_list_from_line()

ans = [[1] * (N + 1) for _ in range(N + 1)]
for i in range(N + 1):
    ans[i][i] = 0
for _ in range(K):
    pairs = get_list_from_line()
    for i in range(N):
        for j in range(i + 1, N):
            ans[pairs[j]][pairs[i]] = 0
total = 0
for i in range(1, N + 1):
    for j in range(1, N + 1):
        if ans[i][j]:
            total += 1
            print(i, j)
fout.write(f"{total}\n")
        
fout.close()
        
    





        
