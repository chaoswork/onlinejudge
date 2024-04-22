
mod = 1000000007

def exp(a, b):
    if a == 1 or b == 0:
        return 1
    if a == 0:
        return 0
    
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
    return res
    

n = int(input())
for i in range(n):
    a, b, c = [int(x) for x in input().split()]
    if c == 0:
        print(a % 1000000007)
        continue
    ans = exp(a, b)
    for i in range(c - 1):
        ans = exp(ans, b)
    print(ans)
    # f(a, b, c) = f(a, b, c - 1) ^ b = f(a, b, c - 2) ^ b ^ b = f(a, b, 1) ^ b1 ^ b2 ... ^ b_c, 

    
    
    
