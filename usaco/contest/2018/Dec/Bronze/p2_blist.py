task_name = "blist"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N = get_list_from_line()[0]

blist = [0] * 1001

for _ in range(N):
    s, t, n = get_list_from_line()
    for i in range(s, t + 1):
        blist[i] += n

fout.write(f"{max(blist)}\n")


fout.close()
