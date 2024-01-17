"""
ID: huangch7
LANG: PYTHON3
TASK: prefix
"""

task_name = "prefix"

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

text = fin.readlines()

# tree, hit
trie = [{}, 0]

def add_trie(s):
    global trie
    p = trie
    for i, x in enumerate(s):
        hit = 1 if i == len(s) - 1 else 0
        if x not in p[0]:
            p[0][x] = [{}, 0]
        if hit:
            p[0][x][1] = hit
        p = p[0][x]
#    print(trie)


state = 'build tree'
seqs = ''
for line in text:
    if line.strip() == '.':
        state = 'finish build tree'
        continue
    if state == 'build tree':
        for item in line.strip().split():
            add_trie(item)
    else:
        seqs += line.strip()

#print(trie)
has_begun = False
start = 0
# res = [0] * len(seqs)
buff = []
best = -1
while has_begun == False or len(buff):
    if has_begun == False:
        has_begun = True
    else:
        start = buff.pop(0) + 1
        if best < start - 1:
            best = start - 1
#    print('start=', start)
    p = trie
    for q in range(start, len(seqs)):
#         print(q, seqs[q], p)
        if seqs[q] in p[0]:
            if p[0][seqs[q]][1] == 1 and q not in buff:
                buff.append(q)
            p = p[0][seqs[q]]
        else:
            break

#print(best)
fout.write(f"{best + 1}\n")


fout.close()
