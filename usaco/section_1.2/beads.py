"""
ID: huangch7
LANG: PYTHON3
TASK: beads
"""

        
fin = open('beads.in', 'r')
fout = open('beads.out', 'w')

n = int(fin.readline())
beads = fin.readline().strip()
max_length = len(beads)
beads += beads

left_r = [None] * len(beads)
left_b = [None] * len(beads)
right_r = [None] * len(beads)
right_b = [None] * len(beads)


# left extend
for i in range(len(beads)):
    if beads[i] == 'b':
        left_b[i] = 1 if i == 0 else left_b[i - 1] + 1
        left_r[i] = 0
    elif beads[i] == 'r':
        left_r[i] = 1 if i == 0 else left_r[i - 1] + 1
        left_b[i] = 0
    else: # w
        left_r[i] = 1 if i == 0 else left_r[i - 1] + 1
        left_b[i] = 1 if i == 0 else left_b[i - 1] + 1

# right extend
for i in range(len(beads) - 1, -1, -1):
    if beads[i] == 'b':
        right_b[i] = 1 if i == len(beads) - 1 else right_b[i + 1] + 1
        right_r[i] = 0
    elif beads[i] == 'r':
        right_r[i] = 1 if i == len(beads) - 1 else right_r[i + 1] + 1
        right_b[i] = 0
    else: # w
        right_r[i] = 1 if i == len(beads) - 1 else right_r[i + 1] + 1
        right_b[i] = 1 if i == len(beads) - 1 else right_b[i + 1] + 1

best = 0
for i in range(len(beads) - 1):
    best = max(best, left_b[i] + right_r[i + 1])
    best = max(best, left_r[i] + right_b[i + 1])

best = min(max_length, best)
fout.write(f"{best}\n")
    
fout.close()
