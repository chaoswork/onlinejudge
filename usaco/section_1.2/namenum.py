"""
ID: huangch7
LANG: PYTHON3
TASK: namenum
"""

task = 'namenum'

name_set = set()

num_map = {
    "2": "A,B,C",
    "5": "J,K,L",
    "8": "T,U,V",
    "3": "D,E,F",
    "6": "M,N,O",
    "9": "W,X,Y",
    "4": "G,H,I",
    "7": "P,R,S"
}

# TODO: Using prefix tree optimize
with open('dict.txt') as f:
    for line in f:
        name_set.add(line.strip())
        
fin = open(f'{task}.in', 'r')
fout = open(f'{task}.out', 'w')

num = fin.readline().strip()

cands = [""]

for s in num:
    new_cands = []
    for item in cands:
        for ch in num_map[s].split(','):
            new_cands.append(item + ch)
    cands = new_cands

found = False
for name in cands:
    if name in name_set:
        fout.write(f"{name}\n")
        found = True
if not found:
    fout.write(f"NONE\n")
    

