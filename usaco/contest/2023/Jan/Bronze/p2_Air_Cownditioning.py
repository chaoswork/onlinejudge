import sys


INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = sys.stdin
fout = sys.stdout


cows = []
products = []
N, M = get_list_from_line()
for _ in range(N):
    # s, e, c
    cows.append(get_list_from_line())

for _ in range(M):
    # a, b, p, m
    products.append(get_list_from_line())


best = sum([x[-1] for x in products]) + 1


def santisfy(cows, cur):
    stall = [0] * 128
    for i in range(len(cur)):
        for j in range(cur[i][0], cur[i][1] + 1):
            # 降低多少度，不是降低到多少度
#             print(j, stall[j], cur[i][2])
            # stall[j] = max(stall[j], cur[i][2])
            stall[j] += cur[i][2]
#     print(stall[:10])
    for i in range(len(cows)):
        for j in range(cows[i][0], cows[i][1] + 1):
            if stall[j] < cows[i][2]:
#                print('debug', j, stall[j], cows[i][2])
                return False
    return True

# print(santisfy(cows, products[0:1] + products[2:]))

def search(left, cur):
    global best
    if len(left) == 0:
        total = sum([x[-1] for x in cur])
        if total >= best:
            return
        if santisfy(cows, cur):
            best = min(best, total)
        return

    search(left[1:], cur + [left[0]])
    search(left[1:], cur)

search(products, [])
print(best)
fout.close()
