"""
ID: huangch7
LANG: PYTHON3
TASK: humble
"""

task_name = "humble"

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

K, N = [int(x) for x in fin.readline().strip().split()]

primes = []
for _ in range(K):
    primes += [int(x) for x in fin.readline().strip().split()]
primes = sorted(primes)

primes_index = [0] * len(primes)

ans = [1]
for _ in range(N):
    min_value = None
    min_index = None
    for i in range(len(primes)):
        while ans[primes_index[i]] * primes[i] == ans[-1]:
            primes_index[i] += 1
        num = ans[primes_index[i]] * primes[i]
        if min_value is None or min_value > num:
            min_value = num
            min_index = i
    ans.append(min_value)
    primes_index[min_index] += 1
# print(ans)
# the numbers of multiply primes are so large, even use binary search
### def bsearch(x, alist):
###     # find position larger than
###     # l < r && alist[l] < x <= alist[r]
###     l, r = -1, len(alist)
###     while l + 1 != r:
###         mid = (l + r) // 2
###         if alist[mid] >= x:
###             r = mid
###         else:
###             l = mid
###     return r
###         
### 
### ans = [1]
### ans_set = set(ans)
### 
### cur = 0
### while cur < N:
###     for x in primes:
###         num = ans[cur] * x
###         if num in ans_set:
###             continue
###         pos = bsearch(num, ans[cur:])
###         ans.insert(pos + cur, num)
###         ans_set.add(num)
###         
###     cur += 1
# print(ans)
fout.write(f"{ans[-1]}\n")
fout.close()
