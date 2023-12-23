"""
ID: huangch7
LANG: PYTHON3
TASK: frameup
"""


task_name = "frameup"
INF = 100000000


def get_ints_from_line():
    return [int(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()


fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')


matrix = []

N, M = get_ints_from_line()
for i in range(N):
    matrix.append(fin.readline().strip())

# get max min

max_min = {}

for i in range(N):
    for j in range(M):
        uid = matrix[i][j]
        if uid == '.':
            continue
        if uid not in max_min:
            # min_row, min_col, max_row, max_col
            max_min[uid] = [N + 1, M + 1, 0, 0]
        max_min[uid][0] = min(i, max_min[uid][0])
        max_min[uid][1] = min(j, max_min[uid][1])
        max_min[uid][2] = max(i, max_min[uid][2])
        max_min[uid][3] = max(j, max_min[uid][3])

# print(max_min)
adj = {k: set() for k in max_min}


def check_uid(x, uid):

    if x != uid:
        adj[uid].add(x)


for uid in max_min:
    min_row, min_col, max_row, max_col = max_min[uid]
    for i in range(min_row, max_row + 1):
        check_uid(matrix[i][min_col], uid)
        check_uid(matrix[i][max_col], uid)
    for j in range(min_col, max_col + 1):
        check_uid(matrix[min_row][j], uid)
        check_uid(matrix[max_row][j], uid)

# print(adj)

ans = []

def find_ans(adj, cur):
    if len(adj) == 0:
        ans.append(cur)
        return
    for uid in adj:
        if len(adj[uid]) == 0:
            new_adj = {}
            for key in adj:
                if key == uid:
                    continue
                new_adj[key] = set()
                for value in adj[key]:
                    if value == uid:
                        continue
                    new_adj[key].add(value)
            find_ans(new_adj, cur + uid)

find_ans(adj, "")
for i in range(len(ans)):
    ans[i] = ans[i][::-1]

for line in sorted(ans):
    fout.write(line + "\n")
        


fout.close()
