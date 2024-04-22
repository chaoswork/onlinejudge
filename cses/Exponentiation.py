
mod = 1000000007
n = int(input())
for i in range(n):
    a, b = [int(x) for x in input().split()]
    if a == 1 or b == 0:
        print(1)
        continue
    if a == 0:
        print(0)
        continue
    base = a
    res = 1
    while b:
        if (b % 2):
#             if res * base > 2**64:
#                 print('debug', res, base)
            
            res = (res * base) % mod
#        print('debug', b, res)
        b = b >> 1
        base *= base
        base = base % mod
    print(res)
    
    
