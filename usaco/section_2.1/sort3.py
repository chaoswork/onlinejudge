"""
ID: huangch7
LANG: PYTHON3
TASK: sort3
"""

task_name = "sort3"

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

n = int(fin.readline())

arr = []
counts = [0, 0, 0, 0]
for _ in range(n):
    x = int(fin.readline())
    counts[x] += 1
    arr.append(x)

swap = {(1, 2): 0, (2, 1): 0, (1, 3): 0,
        (3, 1): 0, (2, 3): 0, (3, 2): 0}
for i in range(len(arr)):
    should_be = None
    if i < counts[1]:
        should_be = 1
    elif i < counts[1] + counts[2]:
        should_be = 2
    else:
        should_be = 3
    key = (arr[i], should_be)
    if key[0] == key[1]:
        continue
#    if key not in swap:
#        swap[key] = 0
    swap[key] += 1
# print(swap)

swap12 = min(swap[(1, 2)], swap[(2, 1)])
swap12_left = max(swap[(1, 2)], swap[(2, 1)]) - swap12

swap13 = min(swap[(1, 3)], swap[(3, 1)])
swap13_left = max(swap[(1, 3)], swap[(3, 1)]) - swap13

swap23 = min(swap[(3, 2)], swap[(2, 3)])
swap23_left = max(swap[(3, 2)], swap[(2, 3)]) - swap23

assert swap12_left == swap13_left
assert swap12_left == swap23_left

fout.write(f"{swap12 + swap23 + swap13 + 2 * swap12_left}\n")

fout.close()
