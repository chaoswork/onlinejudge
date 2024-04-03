import sys
# a,b = [int(x) for x in input().split()]
# print(a+b)

N = int(sys.stdin.readline())
nums = [int(x) for x in sys.stdin.readline().split()]

# DP: find the sum which is nearest to total//2, but the nums is too large
# search : 2 ** 20

total = sum(nums)

best = total


def search(arr, cur):
    global best
    if len(arr) == 0:
        best = min(abs(total - cur - cur), best)
        return
    search(arr[1:], cur + arr[0])
    search(arr[1:], cur)

search(nums, 0)
print(best)

