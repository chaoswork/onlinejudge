"""
ID: huangch7
LANG: PYTHON3
TASK: barn1
"""

task_name = "barn1"

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

M, S, C = [int(x) for x in fin.readline().strip().split()]

arr = []
diffs = []
for i in range(C):
    arr.append(int(fin.readline()))
arr = sorted(arr)
for i in range(C):
    if i > 0:
        diffs.append((arr[i] - arr[i - 1], arr[i - 1], arr[i]))

# can use topk heap to solve this problem
diffs = sorted(diffs, reverse=True)[:M - 1]

diffs = [(None, None, arr[0])] + sorted(diffs, key=lambda x: x[1]) + [(None, arr[-1], None)]

# print(diffs)
ans = 0
for i in range(1, len(diffs)):
    ans += diffs[i][1] - diffs[i - 1][2] + 1
fout.write(f"{ans}\n")
fout.close()
