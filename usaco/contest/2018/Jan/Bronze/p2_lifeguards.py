task_name = "lifeguards"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N = get_list_from_line()[0]

count = [0] * 1024

for i in range(1, N + 1):
    s, e = get_list_from_line()
    for j in range(s, e):
        if count[j] != 0:
            count[j] = -1
        else:
            count[j] = i

total_cover = 0
for i in range(len(count)):
    if count[i] != 0:
        total_cover += 1

min_length = len(count)
for i in range(1, N + 1):
    i_cnt = 0
    for j in range(len(count)):
        if count[j] == i:
            i_cnt += 1
    min_length = min(min_length, i_cnt)
        
    
ans = total_cover - min_length
fout.write(f"{ans}\n")
fout.close()        
        
    





        
