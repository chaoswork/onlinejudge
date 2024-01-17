"""
ID: huangch7
LANG: PYTHON3
TASK: numtri
"""

task_name = "numtri"

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')


n = int(fin.readline())

res = []
for _ in range(n):
    nums = [int(x) for x in fin.readline().strip().split()]
    if len(res) == 0:
        res = nums
    else:
        for i in range(len(nums)):
            if i == 0:
                nums[i] += res[i]
            elif i == len(nums) - 1:
                nums[i] += res[i - 1]
            else:
                nums[i] += max(res[i], res[i - 1])
        res = nums

fout.write(f'{max(res)}\n')
fout.close()
