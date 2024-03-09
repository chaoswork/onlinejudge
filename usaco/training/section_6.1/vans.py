"""
ID: huangch7
LANG: PYTHON3
TASK: vans
"""



task_name = "vans"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')
N = get_list_from_line()[0]

# *|#
# _|   -> f(n - 1)
# *|#

# *_|#
# *_|  -> f(n - 2)
# **|#

# *_|#
# **|# -> f(n - 2) - f(n - 3)
# *_|#

# **|#
# *_|  -> f(n - 2)
# *_|#

# **|
# *_|_
# **|

# *_|#
# **|# -> 0
# **|

# f(n) = f(n-1) + 3f(n-2) - f(n-3) + 2f(n - 3) + ... + 1

# f(1) = 0
# f(2) = 1
# f(3) = 2
# f(4) = 6
# f(5) = 

ans = [0] * (max(4, N + 1))

ans[1] = 0
ans[2] = 1
ans[3] = 2

for i in range(4, N + 1):
    ans[i] = ans[i - 1] + 3 * ans[i - 2] - ans[i - 3]
    for j in range(i, 4, -1):
        ans[i] += 2 * ans[j - 3]
    ans[i] += 1

fout.write(f"{ans[N] * 2}\n")



fout.close()
