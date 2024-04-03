import sys
# a,b = [int(x) for x in input().split()]
# print(a+b)
"""
12345678910111213141516171819202122232425...
"""

n = int(sys.stdin.readline())

def count(k):
    if k == 0:
        return 0
    return 9 * 10 ** (k - 1) * k

base = [count(k) for k in range(0, 18)]
for i in range(1, len(base)):
    base[i] += base[i - 1]
print(base)

def query(k):
    # 0, 9, 9 * 10 * 2, 9 * 10 * 10 * 3, ..., 9 * 10^(k-1) * k
    p = 0
    while p < len(base):
        p += 1
        if base[p] > k:
            break
    # 是个 p 位数
    left = k - base[p - 1]
    n = 0
    q = 0
    for i in range(1, 10):
        n += 10 ** (p - 1) * p
        if n > left:
            q = i
            break
    
    # first number is q
    print(q, left)
        
    
for i in range(n):
    k = int(sys.stdin.readline())
    print(query(k))
