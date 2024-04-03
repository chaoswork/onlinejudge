import sys
# a,b = [int(x) for x in input().split()]
# print(a+b)

source = ''.join(sorted(sys.stdin.readline().strip()))
ans = {}

def dfs(s):
    if len(s) == 1:
         ans[s] = set([s])
         return ans[s]
    key = ''.join(sorted(s))
    if key in ans:
        return ans[key]
    buff = set()
    for i in range(len(s)):
        s_left = s[:i] + s[i + 1:]
        for suffix in dfs(s_left):
            buff.add(s[i] + suffix)
    ans[key] = buff
    return ans[key]


print(len(dfs(source)))
for item in sorted(ans[source]):
    print(item)


