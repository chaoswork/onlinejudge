

task_name = "shell"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N = get_list_from_line()[0]

cur_pos = [1, 2, 3]
ans = [0, 0, 0]

for _ in range(N):
    a, b, g = get_list_from_line()
    for i in range(len(cur_pos)):
        x = cur_pos[i]
        if x == a:
            cur_pos[i] = b
        if x == b:
            cur_pos[i] = a
        if cur_pos[i] == g:
            ans[i] += 1

fout.write(f"{max(ans)}\n")
        
    

