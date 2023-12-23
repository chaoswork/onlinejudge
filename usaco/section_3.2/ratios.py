"""
ID: huangch7
LANG: PYTHON3
TASK: ratios
"""

task_name = "ratios"

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')


t1, t2, t3 = [int(x) for x in fin.readline().split()]

x1, x2, x3 = [int(x) for x in fin.readline().split()]
y1, y2, y3 = [int(x) for x in fin.readline().split()]
z1, z2, z3 = [int(x) for x in fin.readline().split()]

best = None

for a in range(0, 100):
    for b in range(0, 100):
        for c in range(0, 100):
            p1 = a * x1 + b * y1 + c * z1
            p2 = a * x2 + b * y2 + c * z2
            p3 = a * x3 + b * y3 + c * z3
            if t1 == 0 and p1 != 0:
                continue
            if p1 % t1:
                continue

            d = p1 // t1
#            print(d)
            if d != 0 and t2 * d == p2 and t3 * d == p3:
                if best is None or sum(best[:3]) > a + b + c:
                    best = [a, b, c, d]
#                    print(best)
if best is None:
    fout.write("NONE\n")
else:
    best = [str(x) for x in best]
    fout.write(" ".join(best))
    fout.write("\n")



fout.close()
