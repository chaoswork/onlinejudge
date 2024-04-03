import sys

xa, ya, xb, yb, xc, yc = [int(x) for x in sys.stdin.readline().strip().split()]

# 111  111
# 222  223
# 333  223

def rotate(rect):
    return [rect[1], rect[0]]

def check_square_one(alist):
    for x1, y1 in [alist[0], rotate(alist[0])]:
        for x2, y2 in [alist[1], rotate(alist[1])]:
            for x3, y3 in [alist[2], rotate(alist[2])]:
                if x1 == x2 == x3 and y1 + y2 + y3 == x1:
                    res = []
                    for _ in range(y1):
                        res.append('A' * x1)
                    for _ in range(y2):
                        res.append('B' * x1)
                    for _ in range(y3):
                        res.append('C' * x1)
                    return res
    return None


found = None

def permuation(alist, cur):
    global logos, found
    if found:
        return
    if len(alist) == 0:
        # cur is one of the permuation
        for x1, y1 in [logos[cur[0]], rotate(logos[cur[0]])]:
            for x2, y2 in [logos[cur[1]], rotate(logos[cur[1]])]:
                for x3, y3 in [logos[cur[2]], rotate(logos[cur[2]])]:
                    if x1 == x2 + x3 and y2 == y3 and y1 + y2 == x1:
                        res = []
                        for _ in range(y1):
                            res.append('ABC'[cur[0]] * x1)
                        for _ in range(y2):
                            res.append('ABC'[cur[1]] * x2 + 'ABC'[cur[2]] * x3)
                        found = res
                        return
            
        return

    for i in range(len(alist)):
        permuation(alist[:i] + alist[i + 1:], cur + [alist[i]])
    

logos = [[xa, ya], [xb, yb], [xc, yc]]
res = check_square_one(logos)
if res:
    print(len(res))
    print('\n'.join(res))
else:
    permuation([0, 1, 2], [])
    if found:
        print(len(found))
        print('\n'.join(found))
    else:
        print(-1)
