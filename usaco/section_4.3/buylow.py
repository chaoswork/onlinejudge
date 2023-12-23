"""
ID: huangch7
LANG: PYTHON3
TASK: buylow
"""


task_name = "buylow"
INF = 100000000


def get_ints_from_line():
    return [int(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()


fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N = get_ints_from_line()[0]

stock = []
while True:
    part = get_ints_from_line()
    if len(part) == 0:
        break
    stock += part


dp = [1] * N
path = [1] * N
hash_dict = [None] * N
best = 0


for i in range(N):
    cands = {}
    for j in range(i):
        if stock[i] < stock[j]:
            if dp[j] + 1 > dp[i]:
                dp[i] = dp[j] + 1
                cands = {stock[j]: path[j]}
                # path[i] = path[j]
                # prev = set([stock[j]])
                # prev_list.append(stock[j])
            elif dp[j] + 1 == dp[i]:
                cands[stock[j]] = path[j]
                
                # if stock[j] in prev:
                #    continue
                # path[i] += path[j]
                # prev.add(stock[j])
#                prev_list.append(stock[j])
#    hash_dict[i] = get_hash(prev_list)
    path[i] = max(1, sum(cands.values()))
    print(i, stock[i], dp[i], path[i], cands)

    if best < dp[i]:
        best = dp[i]
best_n = 0
cands = {}
for i in range(N):
    if best == dp[i]:
        cands[stock[i]] = path[i]

best_n = sum(cands.values())
fout.write(f"{best} {best_n}\n")        

# stack = []
# best_length = 0
# best_cnt = 0
# 
# cur = N - 1
# while cur >= 0:
#     while stack and stack[-1] >= stock[cur]:
#         stack.pop()
#     stack.append(stock[cur])
#     if len(stack) > best_length:
#         best_length = len(stack)
#         best_cnt = 1
#     elif len(stack) == best_length:
#         best_cnt += 1
#     print(cur, stack)        
#     cur -= 1
# 
    
# fout.write(f"{best_length} {best_cnt}\n")
        
    
fout.close()
