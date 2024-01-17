"""
ID: huangch7
LANG: PYTHON3
TASK: job
"""


task_name = "job"
INF = 100000000


def get_ints_from_line():
    return [int(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()


fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N, M1, M2 = get_ints_from_line()

process_time = []
while True:
    part = get_ints_from_line()
    if len(part) == 0:
        break
    process_time += part

A_time = sorted(process_time[:M1]) # make sure chose the quickest machine
B_time = sorted(process_time[M1:])

a_next_time = A_time[:]
b_next_time = B_time[:]
job_time = []
        
# dp or max flow?
# knapsack with time?
# dp[x][t]  with input x, at time t, how much output


for i in range(N):
    best_id = None
    best = None
    for j in range(len(a_next_time)):
        if best is None or best > a_next_time[j]:
            best = a_next_time[j]
            best_id = j

    job_time.append(best)
    a_next_time[best_id] += A_time[best_id]

job_time = sorted(job_time)
ans_a = job_time[-1]

# let the last job using the quickest machine
for i in range(N - 1, -1, -1):
    best_id = None
    best = None
    for j in range(len(b_next_time)):
        if best is None or best > b_next_time[j]:
            best = b_next_time[j]
            best_id = j
    job_time[i] += best
    b_next_time[best_id] += B_time[best_id]

fout.write(f"{ans_a} {max(job_time)}\n")
            


fout.close()
