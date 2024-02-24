task_name = "circlecross"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

s = fin.readline().strip()

loc = {}
for i in range(len(s)):
    if s[i] not in loc:
        loc[s[i]] = []
    loc[s[i]].append(i)
    if len(loc[s[i]]) == 2:
        loc[s[i]] = sorted(loc[s[i]])

ans = set()
for x in loc:
    cnt = {}
    for i in range(loc[x][0] + 1, loc[x][1]):
        if s[i] not in cnt:
            cnt[s[i]] = 0
        cnt[s[i]] += 1
    for y in cnt:
        if cnt[y] == 1:
            ans.add(tuple(sorted([x, y])))

fout.write(f"{len(ans)}\n")
fout.close()        
        
    





        
