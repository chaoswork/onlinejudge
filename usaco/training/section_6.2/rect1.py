"""
ID: huangch7
LANG: PYTHON3
TASK: rect1
"""



task_name = "rect1"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')
A, B, N = get_list_from_line()

rect = [[0, 0, A, B, 1]]

for _ in range(N):
    rect.append(get_list_from_line())

def cut_rect(bottom, up):
    if up is None:
        return [bottom]
    xb, yb, Xb, Yb, cb = bottom
    xu, yu, Xu, Yu, cu = up
#     if cb == cu:
#         return [bottom]

    # not interact
    if Xu <= xb or Xb <= xu or Yu <= yb or Yb <= yu:
        return [bottom]
    uib = set()
    for x in [xu, Xu]:
        for y in [yu, Yu]:
            if xb <= x <= Xb and yb <= y <= Yb:
                uib.add((x, y))
    
    biu = set()
    for x in [xb, Xb]:
        for y in [yb, Yb]:
            if xu <= x <= Xu and yu <= y <= Yu:
                biu.add((x, y))

    if len(uib) == 0:
        if len(biu) == 0:
            # cross
            #    +---------------- (Xb, Yb)
            #    |                    |
            # (xb, yb)----------------+
            if xb <= xu <= Xu <= Xb:
                return [[xb, yb, xu, Yb, cb], [Xu, yb, Xb, Yb, cb]]
            else:
                return [[xb, yb, Xb, yu, cb], [xb, Yu, Xb, Yb, cb]]
        elif len(biu) == 2:
            if (xb, yb) in biu:
                if (xb, Yb) in biu:
                    return [[Xu, yb, Xb, Yb, cb]]
                else:
                    return [[xb, Yu, Xb, Yb, cb]]
            else:
                if (xb, Yb) in biu:
                    return [[xb, yb, Xb, yu, cb]]
                else:
                    return [[xb, yb, xu, Yb, cb]]
        elif len(biu) == 4:
            return []
    elif len(uib) == 1:
            #    +---------------- (Xb, Yb)
            #    |                    |
            # (xb, yb)----------------+
        
        if (xu, yu) in uib:
            res = []
            res.append([xb, yu, xu, Yb, cb])
            res.append([xb, yb, xu, yu, cb])
            res.append([xu, yb, Xb, yu, cb])
            return res
        elif (xu, Yu) in uib:
            res = []
            res.append([xb, yb, xu, Yu, cb])
            res.append([xb, Yu, xu, Yb, cb])
            res.append([xu, Yu, Xb, Yb, cb])
            return res
        elif (Xu, yu) in uib:
            res = []
            res.append([xb, yb, Xu, yu, cb])
            res.append([Xu, yb, Xb, yu, cb])
            res.append([Xu, yu, Xb, Yb, cb])
            return res
        else:
            res = []
            res.append([xb, Yu, Xu, Yb, cb])
            res.append([Xu, Yu, Xb, Yb, cb])
            res.append([Xu, yb, Xb, Yu, cb])
            return res
                
    elif len(uib) == 2:
        # biu is 0 or 2
        #    +------------------------- (Xb, Yb)
        #    |        (xu, Yu) (Xu, Yu)
        #    |        (xu, yu) (Xu, yu)  
        # (xb, yb)----------------------------+ 

        if (xu, yu) in uib:
            if (xu, Yu) in uib:
                res = []
                res.append([xb, yu, xu, Yu, cb])
                res.append([xb, Yu, Xb, Yb, cb])
                res.append([xb, yb, Xb, yu, cb])
                return res
            else:
                res = []
                res.append([xb, yb, xu, Yb, cb])
                res.append([xu, yb, Xu, yu, cb])
                res.append([Xu, yb, Xb, Yb, cb])
                return res
        else:
            if (xu, Yu) in uib:
                res = []
                res.append([xb, yb, xu, Yb, cb])
                res.append([Xu, yb, Xb, Yb, cb])
                res.append([xu, Yu, Xu, Yb, cb])
                return res
            else:
                res = []
                res.append([xb, Yu, Xb, Yb, cb])
                res.append([xb, yb, Xb, yu, cb])
                res.append([Xu, yu, Xb, Yu, cb])
        
                return res
    elif len(uib) == 4:
        #    +------------------------- (Xb, Yb)
        #    |        (xu, Yu) (Xu, Yu)
        #    |        (xu, yu) (Xu, yu)  
        # (xb, yb)----------------------------+ 
        
        return [[xb, yb, xu, Yb, cb],
                [xu, yb, Xu, yu, cb],
                [xu, Yu, Xu, Yb, cb],
                [Xu, yb, Xb, Yb, cb]]
    


    
rect_all = [[x] for x in rect]
for i in range(1, len(rect)):    
    for j in range(i):
        new_rect = []
        for item in rect_all[j]:
            if item[0] >= item[2]:
                continue
            if item[1] >= item[3]:
                continue
#            for a in cut_rect(item, rect[i]):
#                if a[0] >= a[2] or a[1] >= a[3]:
#                    print('debug', i, j, item, rect[i], a)
            new_rect += cut_rect(item, rect[i])
        rect_all[j] = new_rect

colors = {}
for item in rect_all:
#     print(item)
    for (x, y, X, Y, c) in item:
        if x >= X or y >= Y:
            continue
        cnt = (X - x) * (Y - y)
        if c not in colors:
            colors[c] = 0
        colors[c] += cnt
# print(colors)

for k, v in sorted(colors.items(), key=lambda x: x[0]):
    if v > 0:
        fout.write(f"{k} {v}\n")


fout.close()
