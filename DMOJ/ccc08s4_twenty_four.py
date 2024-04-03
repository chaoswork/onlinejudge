import sys


def get_int():
    return int(sys.stdin.readline())

N = get_int()

best = 0

def search(nums):
    if len(nums) == 1:
        return [nums[0]]
    res = set()
    for i in range(1, len(nums)):
        left = search(nums[:i])
        right = search(nums[i:])
        for x in left:
            for y in right:
                res.add(x + y)
                res.add(x - y)
                res.add(x * y)
                if y and x % y == 0:
                    res.add(x // y)
    return res


for _ in range(N):
    nums = []
    for _ in range(4):
        nums.append(get_int())
    res = set()
    for i in range(4):
        x = nums[i]
        nums_i = nums[:i] + nums[i + 1:]
        for j in range(3):
            y = nums_i[j]
            nums_j = nums_i[:j] + nums_i[j + 1:]
            p, q = nums_j
            nums_a = [x, y, p, q]
            res = res.union(search(nums_a))
            nums_b = [x, y, q, p]
            res = res.union(search(nums_b))
    # res = search(nums)
    best = min(res)
    for x in res:
        if x > 24:
            continue
        best = max(best, x)
    print(best)
