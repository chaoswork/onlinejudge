"""
ID: huangch7
LANG: PYTHON3
TASK: kimbits
"""

task_name = "kimbits"

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

cache = {}

def comb(n, m):
    if m == 0:
        return 1
    if n == m:
        return 1
#    if m == 1:
#        return n
    if (n, m) in cache:
        return cache[(n, m)]
    cache[(n, m)] = comb(n - 1, m) + comb(n - 1, m - 1)
    return cache[(n, m)]

def count_num(n, m):
    # return C_n^0 + C_n^1 + ... + C_n^m
    res = 0
    for i in range(m + 1):
        if i <= n:
            res += comb(n, i)
    return res



N, L, Index = [int(x) for x in fin.readline().split()]

# 0000
# 0001
# 0010
# 0011
# 0100
# 0101
# 0110
# 0111
# 1000
# 1001
# 1010
# 1011
# 1100
# 1101
# 1110
# 1111 <- more then 3


ans = ""
for i in range(N, 0, -1):
    cur = count_num(i - 1, L)
#    print(Index, i - 1, cur, L)
    if Index > cur:
        ans += "1"
        L -= 1
        Index -= cur
    else:
        ans += "0"
#    print('ans=', ans)
fout.write(f"{ans}\n")
    



fout.close()
