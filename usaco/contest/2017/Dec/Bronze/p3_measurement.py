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

best = 7
label = {
    'Bessie': 1,
    'Elsie': 2,
    'Mildred': 4
}
for i in range(len(logs)):
    produce[logs[i][1]] += logs[i][2]

    max_v = max(produce.values())
    cur_v = 0
    for name in produce:
        if produce[name] == max_v:
            cur_v += label[name]
    if best != cur_v:
    
        ans += 1
        best = cur_v
#        print(best)
#     i = j

# print(ans)
# 对了一下页面样式

fout.write(f"{ans}\n")

fout.close()
