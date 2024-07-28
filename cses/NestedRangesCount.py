import sys
# a,b = [int(x) for x in input().split()]
# print(a+b)


def query(BIT, x):
    total = 0
    while x > 0:
        total += BIT[x]
        x -= (x & -x)
    return total


def update(BIT, maxv, x):
    while x <= maxv:
        if x not in BIT:
            BIT[x] = 0
        BIT[x] += 1
        x += (x & -x)


N = int(sys.stdin.readline())
maxv = 0

rngs = []
uniqs = set()
for i in range(N):
    # print([int(x) for x in sys.stdin.readline().split()])
    x, y = [int(x) for x in sys.stdin.readline().split()]
    uniqs.add(x)
    uniqs.add(y)
    rngs.append([x, y, i])
    maxv = max(maxv, x, y)

# rngs.sort(cmp=lambda a,b: a[0] > b[0] if a[1] == b[1] else a[1] < b[1])

cnt = 1
idmap = {}
for item in sorted(list(uniqs)):
    idmap[item] = cnt
    cnt += 1

rngs.sort(key=lambda x: (x[1], -x[0]))
# for i in range(N):
#     print(rngs[i])
BIT = [0] * (N * 2 + 10)
ans1 = [0] * N
for i in range(N):
    ans1[rngs[i][2]] = i - query(BIT, idmap[rngs[i][0]] - 1)
    update(BIT, idmap[maxv], idmap[rngs[i][0]])


rngs.sort(key=lambda x: (x[0], -x[1]))
BIT = [0] * (N * 2 + 10)
ans2 = [0] * N
for i in range(N):
    ans2[rngs[i][2]] = i - query(BIT, idmap[rngs[i][1]] - 1)
    update(BIT, idmap[maxv], idmap[rngs[i][1]])

print(" ".join([str(x) for x in ans1]))
print(" ".join([str(x) for x in ans2]))





