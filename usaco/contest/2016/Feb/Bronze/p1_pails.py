task_name = "pails"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

X, Y, M = get_list_from_line()

reach = [0] * 1024

reach[0] = 1

best = 0
for i in range(M + 1):
    if i - X >= 0 and reach[i - X]:
        reach[i] = 1
    if i - Y >= 0 and reach[i - Y]:
        reach[i] = 1
    if reach[i] and best < i:
        best = i

fout.write(f"{best}\n")
fout.close()        
        
    





        
