task_name = "measurement"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N = get_list_from_line()[0]

logs = []
for _ in range(N):
    day, name, diff = get_strs_from_line()
    day = int(day)
    diff = int(diff)
    logs.append([day, name, diff])

logs = sorted(logs, key=lambda x: x[0])

best = ('Bessie', 'Elsie', 'Mildred')
produce = {
    'Bessie': 7,
    'Elsie': 7,
    'Mildred': 7
}

ans = 0
# i = 0
# while i < len(logs):
#     j = i + 1
#     while j < len(logs) and logs[j][0] == logs[i][0]:
#         j += 1
#     for k in range(i, j):
#         produce[logs[k][1]] += logs[k][2]
        
#     print(i, produce)
for i in range(len(logs)):
    produce[logs[i][1]] += logs[i][2]
#     print(produce)
    cur_best = produce['Bessie']
    cur_best_name = ['Bessie']
    for name in ['Elsie', 'Mildred']:
        if produce[name] > cur_best:
            cur_best_name = [name]
            cur_best = produce[name]
        elif produce[name] == cur_best:
            cur_best_name.append(name)
    if tuple(cur_best_name) != best:
        ans += 1
        best = tuple(cur_best_name)
#         print(best)
#     i = j

# print(ans)
# 对了一下样式需求和排期。
# 有一个输出结果为空的问题，业务目前来用默认话术兜底。

fout.write(f"{ans}\n")

fout.close()
