task_name = "cbarn"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N = get_list_from_line()[0]

nums = []
for _ in range(N):
    nums.append(get_list_from_line()[0])

best = None
for i in range(N):
    cur = 0
    for j in range(N):
        pos = (i + j) % N
        cur += j * nums[pos]
    if best is None or best > cur:
        best = cur
print(best)

fout.write(f"{best}\n")
        

#4 7 8 6 4    
# (+ 7 8 8 6 6 6 4 4 4 4)
# (+ 8 6 6 4 4 4 4 4 4 4)
fout.close()        
        
    





        
