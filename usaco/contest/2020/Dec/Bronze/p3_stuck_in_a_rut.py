import sys

task_name = "stuck"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = sys.stdin #open(f'{task_name}.in', 'r')
fout = sys.stdout # open(f'{task_name}.out', 'w')

N = get_list_from_line()[0]

cows = []
for _ in range(N):
    d, x, y = get_strs_from_line()
    x = int(x)
    y = int(y)
    # last element, None for move, int for stop time
    cows.append([d, x, y, None])

# 每次找一个下一个交汇

def find_next(cows):
    # 对于往北走的牛来说，只有x相同，和往东的有希望交汇。
    min_stop_time = None
    min_index = None
    for i in range(len(cows)):
        # i 已经停了
        if cows[i][-1] is not None:
            continue
        stop_time = None        
        if cows[i][0] == 'N':

            for j in range(len(cows)):
                if i == j:
                    continue
                if cows[j][0] == 'N':
                    # x 不同，永远不会相交
                    if cows[i][1] != cows[j][1]:
                        continue
                    # 在下方，永远不会相交
                    if cows[j][2] < cows[i][2]:
                        continue
                    
                    if stop_time is None or stop_time > cows[j][2] - cows[i][2]:
                        stop_time = cows[j][2] - cows[i][2]
                else:
                    yy = cows[j][2] - cows[i][2]
                    xx = cows[i][1] - cows[j][1]
    #                print(i, j, xx, yy)
                    if yy <= 0:
                        # 在下方，永远不相交
                        continue
                    if xx < 0:
                        # 在右侧，永远不相交
                        continue
                    if cows[j][-1] is not None and cows[j][-1] < xx + 1:
                        # 还没走到相交的位置就停止了
                        continue
                    # 走到同一个格子可以继续走。
                    if xx < yy:
                        # xx 至少比 yy 小1，早走一步。
                        
                        if stop_time is None or stop_time > yy:
                            stop_time = yy
            # print(stop_time)
        else: # 'E'
        
            for j in range(len(cows)):
                if i == j:
                    continue
                if cows[j][0] == 'E':
                    if cows[i][2] != cows[j][2]:
                        continue
                    if cows[j][1] < cows[i][1]:
                        continue
                    if stop_time is None or stop_time > cows[j][1] - cows[i][1]:
                        stop_time = cows[j][1] - cows[i][1]
                else:
                    yy = cows[i][2] - cows[j][2]
                    xx = cows[j][1] - cows[i][1]
                    # print(i, j, xx, yy)
                    if yy < 0:
                        # 上方，用不相遇
                        continue
                    if xx <= 0:
                        # 左侧，永不相遇
                        continue
                    if cows[j][-1] is not None and cows[j][-1] < yy + 1:
                        continue
                    if yy < xx:
                        if stop_time is None or stop_time > xx:
                            stop_time = xx
            # print(stop_time)
        # check min
        if stop_time is not None:
            if min_stop_time is None or min_stop_time > stop_time:
                min_stop_time = stop_time
                min_index = i
    return min_index, min_stop_time
        
            
while True:
    idx, stop_time = find_next(cows)
    if idx is None:
        break
    cows[idx][-1] = stop_time

for i in range(len(cows)):
    # print(cows[i])
    if cows[i][-1] is None:
        fout.write("Infinity\n")
    else:
        fout.write(f"{cows[i][-1]}\n")

fout.close()
