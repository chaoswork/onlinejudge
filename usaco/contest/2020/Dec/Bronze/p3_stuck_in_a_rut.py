

task_name = "stuck"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N = get_list_from_line()[0]

cows = []
for _ in range(N):
    d, x, y = get_strs_from_line()
    x = int(x)
    y = int(y)
    cows.append([d, x, y])

# 对于往北走的人来说，只有x相同，和往东的有希望交汇。
for i in range(len(cows)):
    if cows[i][0] == 'N':
        ans = None
        for j in range(len(cows)):
            if i == j:
                continue
            if cows[j][0] == 'N':
                if cows[i][1] != cows[j][1]:
                    continue
                if cows[j][2] < cows[i][2]:
                    continue
                if ans is None or ans > cows[j][2] - cows[i][2]:
                    ans = cows[j][2] - cows[i][2]
            else:
                yy = cows[j][2] - cows[i][2]
                xx = cows[i][1] - cows[j][1]
#                print(i, j, xx, yy)
                if yy <= 0:
                    continue
                if xx < 0:
                    continue
                if xx < yy:
                    if ans is None or ans > yy:
                        ans = yy
        print(ans)
    else: # 'E'
        ans = None
        for j in range(len(cows)):
            if i == j:
                continue
            if cows[j][0] == 'E':
                if cows[i][2] != cows[j][2]:
                    continue
                if cows[j][1] < cows[i][1]:
                    continue
                if ans is None or ans > cows[j][1] - cows[i][1]:
                    ans = cows[j][1] - cows[i][1]
            else:
                yy = cows[i][2] - cows[j][2]
                xx = cows[j][1] - cows[i][1]
                print(i, j, xx, yy)
                if yy < 0:
                    continue
                if xx <= 0:
                    continue
                if yy < xx:
                    if ans is None or ans > xx:
                        ans = xx
        print(ans)


fout.close()
