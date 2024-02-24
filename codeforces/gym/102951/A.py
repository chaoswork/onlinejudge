import sys
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = sys.stdin
fout = sys.stdout

N = get_list_from_line()[0]
x_list = get_list_from_line()
y_list = get_list_from_line()

best = 0
for i in range(N):
    for j in range(i + 1, N):
        w = x_list[i] - x_list[j]
        h = y_list[i] - y_list[j]
        best = max(best, h * h + w * w)

fout.write(f"{best}\n")
fout.close()        
        
    





        
