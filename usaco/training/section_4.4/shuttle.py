"""
ID: huangch7
LANG: PYTHON3
TASK: shuttle
"""


task_name = "shuttle"
INF = 100000000


def get_ints_from_line():
    return [int(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()


fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N = get_ints_from_line()[0]

# C(7, 3) * 4
# 7!/(3!*4!) * 4 = 7 * 6 * 5 * 4 = 840

start = [1] * N + [-1] + [0] * N
#target = tuple([0] * N + [-1] + [1] * N)



# target: (0, 0, 0, ..., _, 1, 1, 1...)
# mid  : (_, 1, 0, 1, 0, 1, 0, ... )
# mid. : (1, 0, 1, 0, ...,        ,_)
# start:(1, 1, 1, ..., _, 0, 0, 0...)

def display(alist):
    line = ""
    for x in alist:
        x = str(x) if x != -1 else "_"
        line += x
    # print(line)

def swap(i, j, alist):
    tmp = alist[i]
    alist[i] = alist[j]
    alist[j] = tmp
    display(alist)

display(start)
ans = [N]
swap(N - 1, N, start)
# display(start)
# 搬运1个0
state = [0, 1]
p = N - 1
while state[1] < N:
    n = state[1]
    while n:
        nextp = p + 2 if state[0] == 0 else p - 2
        ans.append(nextp + 1)
        swap(p, nextp, start)
        p = nextp
        n -= 1
    nextp = p + 1 if state[0] == 0 else p - 1
    ans.append(nextp + 1)
    swap(p, nextp, start)
    p = nextp

    state = [1 - state[0], state[1] + 1]

# N = 4
# 4 6 7 5 3 2 4 6 8 9 7 5 3 1 2 4 6 8 7 5
# 3 4 6 5
# N = 6
# 6 8 9 7 5 4 6 8 10 11 9 7 5 3 2 4 6 8 10 12
# 13 11 9 7 5 3 1 2 4 6 8 10 12 11 9 7 5 3 4 6
# 8 10 9 7 5 6 8 7
#print(state)

while state[1] > 0:
    n = state[1]
    while n:
        nextp = p + 2 if state[0] == 0 else p - 2
        ans.append(nextp + 1)
        swap(p, nextp, start)
        p = nextp
        n -= 1
    nextp = p - 1 if state[0] == 0 else p + 1
    ans.append(nextp + 1)
    swap(p, nextp, start)
    p = nextp

    state = [1 - state[0], state[1] - 1]
    
    

# print(ans)




final_ans = ans

for i in range(0, len(final_ans), 20):
    fout.write(" ".join([str(x) for x in final_ans[i: i + 20]]))
    fout.write("\n")

        
    

fout.close()
