"""
ID: huangch7
LANG: PYTHON3
TASK: milk2
"""

task = 'milk2'
        
fin = open(f'{task}.in', 'r')
fout = open(f'{task}.out', 'w')

n = int(fin.readline())
times = []
for _ in range(n):
    start, end = [int(x) for x in fin.readline().strip().split()]
    times.append((start, end))

times = sorted(times)
ans1 = times[0][1] - times[0][0]
ans2 = 0

left, right = times[0]
for start, end in times[1:]:
    if start > right:
        # new begin
        ans1 = max(ans1, right - left)
        ans2 = max(ans2, start - right)
        # print(ans1, ans2)
        left, right = start, end
        ans1 = max(ans1, right - left)
        
    else:
        right = max(right, end)
            
#  print(ans1, ans2)    
fout.write(f"{ans1} {ans2}\n")
    
fout.close()
