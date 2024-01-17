"""
ID: huangch7
LANG: PYTHON3
TASK: window
"""
import math

task_name = "window"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

def merge(a, b):
    min_x, min_y, max_x, max_y = a
    min_X, min_Y, max_X, max_Y = b
    
 
    max_x = min(max_x, max_X)
    min_x = max(min_x, min_X)
    max_y = min(max_y, max_Y)
    min_y = max(min_y, min_Y)
    return min_x, min_y, max_x, max_y

        


def get_area(win):
#     print('debug', win)
    w = win[0][1]
    max_X = max(w[0], w[2])
    min_X = min(w[0], w[2])
    max_Y = max(w[1], w[3])
    min_Y = min(w[1], w[3])
    cache = []
    res = 0
    total = (max_X - min_X) * (max_Y - min_Y)

    for w in win[1:]:
        w = w[1]
        max_x = max(w[0], w[2])
        min_x = min(w[0], w[2])
        max_y = max(w[1], w[3])
        min_y = min(w[1], w[3])
        if max_x <= min_X or min_x >= max_X:
            continue
        if max_y <= min_Y or min_y >= max_Y:
            continue
        max_x = min(max_x, max_X)
        min_x = max(min_x, min_X)
        max_y = min(max_y, max_Y)
        min_y = max(min_y, min_Y)

        op = [1, -1]
        if len(cache) == 0:
            cache = [[(min_x, min_y, max_x, max_y)]] # A
            res += (max_y - min_y) * (max_x - min_x)
#            print('0', res)
        else:
            cache.append([])
 #           print(cache)
            for i in range(len(cache) - 1, -1, -1):
                if i == 0:
                    cache[0].append((min_x, min_y, max_x, max_y)) # X
                    res += (max_y - min_y) * (max_x - min_x)
#                    print(i, 0, res)
                else:
                    for (min_xx, min_yy, max_xx, max_yy) in cache[i - 1]:
                        if max_xx <= min_x or min_xx >= max_x:
                            continue
                        if max_yy <= min_y or min_yy >= max_y:
                            continue
                        
                        min_xx, min_yy, max_xx, max_yy = merge(
                            (min_x, min_y, max_x, max_y),
                            (min_xx, min_yy, max_xx, max_yy))
                        cache[i].append((min_xx, min_yy, max_xx, max_yy))
                        res += op[i % 2] * ((max_yy - min_yy) * (max_xx - min_xx))
#                        print(i, res)
#    print(cache)
#     print(res, total)
    return 100 * (total - res) / total
            
                        

                



windows = []

while True:
    line = fin.readline().strip()
    if line == '':
        break
    cmd = line[0]
    params = line[2:-1]
    if cmd == 'w':
        cols = params.split(',')
        windows.append((cols[0], [int(x) for x in cols[1:]]))
    else:
        idx = 0
        for i in range(len(windows)):
            if windows[i][0] == params:
                idx = i
                break
        if cmd == 't':
            windows = windows[:idx] + windows[idx + 1:] + [windows[idx]]
        elif cmd == 'b':
            windows = [windows[i]] + windows[:idx] + windows[idx + 1:]
        elif cmd == 'd':
            windows = windows[:idx] + windows[idx + 1:]
        elif cmd == 's':
            fout.write(f"{get_area(windows[idx:]):.3f}\n")




fout.close()
