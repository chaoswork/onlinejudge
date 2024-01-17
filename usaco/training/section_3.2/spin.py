"""
ID: huangch7
LANG: PYTHON3
TASK: spin
"""

from queue import PriorityQueue

task_name = "spin"

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

V = [None] * 5
wheels = [[] for _ in range(5)]

for i in range(5):
    cols = [int(x) for x in fin.readline().strip().split()]
    V[i] = cols[0]
    w = cols[1]
    for j in range(w):
        s, e = cols[2 + j * 2], cols[2 + j * 2 + 1]
        # wheels[i].append(((s + e + 1) % 360, 360 - e - 1))
        wheels[i].append((s, e))
#print(wheels)
best = None

for t in range(360):
    cover = [0] * 360
    for i in range(len(wheels)):
        for wheel in wheels[i]:
            start = (t * V[i] + wheel[0]) % 360
            end = (start + wheel[1])
            if end < 360:
                for k in range(start, end + 1):
                    cover[k] += 1
            else:
                for k in range(start, 360):
                    cover[k] += 1
                for k in range(end - 359):
                    cover[k] += 1
                
#    print(cover)
    for i in range(len(cover)):
        if cover[i] >= 5:
            best = t
            break
    if best is not None:
        break

if best is None:
    fout.write('none\n')
else:
    fout.write(f"{best}\n")
            
        
        
# t= 9
# 270-30
# 240-330
# 360-90
# 170-350
# 270-330



fout.close()
