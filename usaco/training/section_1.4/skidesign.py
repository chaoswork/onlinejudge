"""
ID: huangch7
LANG: PYTHON3
TASK: skidesign
"""

task_name = "skidesign"

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

n = int(fin.readline())
heights = []
for _ in range(n):
    heights.append(int(fin.readline()))

# heights = sorted(heights)

# 增和减貌似并不需要严格一致，5可以分成3和2？
# 或者简单的想一下，山增和减于其他的没关系？
# 感觉是把右边高的填充到左边。然后形成一段
#        --------
#     ---
# ----
# 或者换一种思路，因为最高就是0-100，所以我遍历0-17,1-18,...,然后取最小的？
# 我这里多考虑了一个条件。就是砍去的山的数量和新增的数量并不需要保持一致=。=

best = None
for i in range(101):
    j = i + 17
    cost = 0
    if j > 100:
        break
    for x in heights:
        if x < i:
            cost += (i - x) * (i - x)
        elif x > j:
            cost += (x - j) * (x - j)
    if best is None or best > cost:
        best = cost


fout.write(f"{best}\n")
fout.close()
