"""
ID: huangch7
LANG: PYTHON3
TASK: hidden
"""


task_name = "hidden"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N = get_list_from_line()[0]

chars = set()
min_char = None
s = ""
cands = []
while True:
    part = fin.readline().strip()
    if not part:
        break
    s += part

for idx, x in enumerate(s):
    chars.add(x)
    if min_char is None or min_char > x:
        min_char = x
#         cands = [[idx, 1]]
#     elif min_char == x:
#         if cands[-1][0] + 1
#         cands.append([idx, 1])

p = 0
while p < N:
    if s[p] == min_char:
        cands.append([p, 1])
        while p < N and s[p] == min_char:
            p += 1
    else:
        p += 1

# print(chars)
# print(len(cands))

if len(chars) == 1:
    ans = 0
else:
    while len(cands) > 1:
#         print(len(cands), cands)
        new_cands = []
        min_char = s[(cands[0][0] + cands[0][1]) % N]
        for start, offset in cands:
            cur = (start + offset) % N
            if min_char == s[cur]:
                new_cands.append([start, offset + 1])
            elif min_char > s[cur]:
                new_cands = [[start, offset + 1]]
                min_char = s[cur]
        cands = [new_cands[0]]
#        print(new_cands)
        for i in range(1, len(new_cands)):
            # period here
            if new_cands[i - 1][0] + new_cands[i - 1][1] == new_cands[i][0]:
                continue
            cands.append(new_cands[i])
                
#         cands = new_cands
#        print(cands)




# print(cands)
fout.write(f"{cands[0][0]}\n")
        
 

fout.close()
