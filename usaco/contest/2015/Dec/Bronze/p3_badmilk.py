task_name = "badmilk"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N, M, D, S = get_list_from_line()

drink_info = {}
sick_info = {}

for _ in range(D):
    p, m, t = get_list_from_line()
    if p not in drink_info:
        drink_info[p] = [INF] * (M + 1)
    if drink_info[p][m] > t:
        drink_info[p][m] = t
for _ in range(S):
    p, t = get_list_from_line()
    sick_info[p] = t

# print(drink_info)
# print(sick_info)
ans = 0

for m in range(1, M + 1):
    # check if m is the bad milk
    is_bad = True
    for p in drink_info:
        if p not in sick_info:
            continue
        if not (drink_info[p][m] < INF and drink_info[p][m] < sick_info[p]):
            is_bad = False
            break
#    print(m, is_bad)
    if is_bad:
        cnt = S
        for p in drink_info:
            if p in sick_info:
                continue
            if drink_info[p][m] < INF:
                cnt += 1
        ans = max(ans, cnt)

fout.write(f"{ans}\n")    
fout.close()        
