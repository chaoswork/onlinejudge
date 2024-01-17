"""
ID: huangch7
LANG: PYTHON3
TASK: shopping
"""


task_name = "shopping"

def get_ints_from_line():
    return [int(x) for x in fin.readline().strip().split()]


fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

S = int(fin.readline())

special_offers = []
prices = [0] * 5
needs = [0] * 5
id_map = {}

def get_id(c):
    if c not in id_map:
        id_map[c] = len(id_map)
    return id_map[c]

for _ in range(S):
    cols = get_ints_from_line()
    n = cols[0]
    p = cols[-1]
    packages = [0] * 5
    
    for i in range(1, n + 1):
#         print(cols[i * 2 - 1], get_id(cols[i * 2 - 1]), cols[i * 2])
        packages[get_id(cols[i * 2 - 1])] = cols[i * 2]
    special_offers.append((packages, p))

B = int(fin.readline())
for _ in range(B):
    c, k, p = get_ints_from_line()
    prices[get_id(c)] = p
    needs[get_id(c)] = k

# print(special_offers)
# print(prices, needs)

# dp[a][b][c][d][e] = dp[a - pa][...] + p

def merge(alist):
    res = 0
    for x in alist:
        res *= 10
        res += x
    return res

def split(x):
    res = [0] * 5
    p = len(res) - 1
    while x:
        res[p] = x % 10
        x = x // 10
        p -= 1
    return res

res = {0: 0}

def dp(target_list):
    target_num = merge(target_list)
    if target_num in res:
        return res[target_num]
    best = 0
    for i in range(5):
        best += target_list[i] * prices[i]
    for packages, price in special_offers:
        left = [0] * 5
        valid = True
        for i in range(5):
            left[i] = target_list[i] - packages[i]
            if left[i] < 0:
                valid = False
        if not valid:
            continue
        best = min(best, dp(left) + price)
    res[target_num] = best
    return res[target_num]

fout.write(f"{dp(needs)}\n")
    
fout.close()
