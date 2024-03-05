import sys


INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()


fin = sys.stdin
fout = sys.stdout

T = get_list_from_line()[0]

for _ in range(T):
    N = get_list_from_line()[0]
    nums = get_list_from_line()

    total = sum(nums)
    max_n = max(nums)

    if max_n == 0:
        fout.write("0\n")
        continue

    for n in range(max_n, total + 1):
        if total % n:
            continue
        ans = 0
        cur = 0
        succ = True
        for i in range(len(nums)):
            cur += nums[i]
            if cur == n:
                cur = 0
            elif cur > n:
                succ = False
                break
            else:
                ans += 1
        if succ:
            fout.write(f"{ans}\n")
            break

fout.close()
