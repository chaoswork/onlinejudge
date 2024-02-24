task_name = "diamond"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N, K = get_list_from_line()

best = 1
nums = []
for _ in range(N):
    nums.append(get_list_from_line()[0])
nums = sorted(nums)
last = 0
for i in range(N):
    while abs(nums[i] - nums[last]) > K:
        last += 1
        
    best = max(best, i - last + 1)

fout.write(f"{best}\n")
fout.close()        
        
    





        
