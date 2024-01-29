task_name = "cowsignal"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

M, N, K = get_list_from_line()

for _ in range(M):
    line = fin.readline().strip()
    newline = "".join([x * K for x in line])
    for _ in range(K):
        fout.write(newline)
        fout.write("\n")
