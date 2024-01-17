"""
ID: huangch7
LANG: PYTHON3
TASK: gift1
"""

        
fin = open('gift1.in', 'r')
fout = open('gift1.out', 'w')

gain = {}
n = int(fin.readline())
for i in range(n):
    name = fin.readline().strip()
    gain[name] = 0
for _ in range(n):
    name = fin.readline().strip()
    gift, m = [int(x) for x in fin.readline().strip().split()]
    gain[name] -= gift
    for _ in range(m):
        name_to = fin.readline().strip()
        gain[name_to] += gift // m
    remain = 0
    if m:
        remain = gift - (gift // m) * m
    gain[name] += remain 

for name, count in gain.items():
    fout.write(f"{name} {count}\n")
    
fout.close()
