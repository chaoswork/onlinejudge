task_name = "blocks"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N = get_list_from_line()[0]


ans = {chr(x + 97): 0 for x in range(26)}
for _ in range(N):
    front, back = get_strs_from_line()
    f_cnt = {chr(x + 97): 0 for x in range(26)}
    for x in front:
        f_cnt[x] += 1
    b_cnt = {chr(x + 97): 0 for x in range(26)}
    for x in back:
        b_cnt[x] += 1
    for x in ans:
        ans[x] += max(f_cnt[x], b_cnt[x])

for x in ans:
    fout.write(f"{ans[x]}\n")
fout.close()        
        
    





        
