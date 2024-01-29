

task_name = "mixmilk"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

buckets = [get_list_from_line() for _ in range(3)]

cur = 0
for i in range(100):
    nxt = (cur + 1) % 3
    # pour cur to next
    n = min(buckets[cur][1], buckets[nxt][0] - buckets[nxt][1])
    buckets[cur][1] -= n
    buckets[nxt][1] += n
    cur = nxt

for _, x in buckets:
    fout.write(f"{x}\n")
