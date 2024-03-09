"""
ID: huangch7
LANG: PYTHON3
TASK: cowxor
"""


task_name = "cowxor"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')
N = get_list_from_line()[0]

xor_res = [0]
for i in range(1, N + 1):
    x = get_list_from_line()[0]
    xor_res.append(xor_res[i - 1] ^ x)

best = -1
best_s = None
best_e = None

for i in range(0, N + 1):
    for j in range(i + 1, N + 1):
        res = xor_res[i] ^ xor_res[j]
        if res == best:
            if j - i - 1 < best_e - best_s:
                best_s = i + 1
                best_e = j
        elif res > best:
            best = res
            best_s = i + 1
            best_e = j
fout.write(f"{best} {best_s} {best_e}\n")        
    

fout.close()
