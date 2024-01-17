"""
ID: huangch7
LANG: PYTHON3
TASK: concom
"""

task_name = "concom"

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N = int(fin.readline())
## controls = [[0] * 110 for _ in range(110)]
## ans = [[None] * 110 for _ in range(110)]
## counts = {}
## 
## companys = set()
## 
## for _ in range(N):
##     x, y, z = [int(e) for e in fin.readline().strip().split()]
##     companys.add(x)
##     companys.add(y)
##     controls[x][y] = z
## 
## 
## for x in companys:
##     controls[x][x] = 100
## 
## for x in companys:
##     for y in companys:
##         if controls[x][y] == 0:
##             continue
##         for z in companys:
##             if controls[y][z] > 0:
##                 # ans[x][z] = 0
##                 if (x, z) not in counts:
##                     counts[(x, z)] = 0
##                 counts[(x, z)] += 1
## 
## 
## print([x[:6] for x in ans[1:6]])
## def dfs_dp(x, y):
##     if ans[x][y] is not None:
##         return ans[x][y]
##     print('debug', x, y)
##     if controls[x][y] > 50:
##         ans[x][y] = 1
##         return 1
##     total = 0
##     for z in companys:
##         if dfs_dp(x, z):
##             total += controls[z][y]
##     if total > 50:
##         ans[x][y] = 1
##     else:
##         ans[x][y] = 0
##     return ans[x][y]
## 
## print(controls[2][3])
## print(dfs_dp(2, 3))
## 
## companys = sorted(companys)
## final = []
## for (x, y), c in sorted(counts.items(), key=lambda x: x[1]):
##     print(x, y, c)
##     if x == y:
##         continue
##     if dfs_dp(x, y):
##         final.append((x, y))
## 
## print(final)

# companys = set()
# controls = {}
# res = {}
# for _ in range(N):
#     x, y, z = [int(e) for e in fin.readline().strip().split()]
#     companys.add(x)
#     companys.add(y)
#     if x not in controls:
#         controls[x] = {}
#     controls[x][y] = z
#     if controls[x][y] > 50 and x != y:
#         if x not in res:
#             res[x] = {}
#         res[x][y] = 1
# # print(controls)
# while True:
#     found = False
#     for x in res:
#         for z in companys:
#             if z in res[x].keys():
#                 continue
#             if z == x:
#                 continue
#             total = 0
#             if x in controls and z in controls[x]:
#                 total += controls[x][z]
#             for y in res[x]:
#                 if y in controls and z in controls[y]:
#                     total += controls[y][z]
#             if total > 50:
#                 res[x][z] = 1
#                 found = True
#     if not found:
#         break
# 
# for x in sorted(res.keys()):
#     for y in sorted(res[x].keys()):
#         fout.write(f"{x} {y}\n")
#                 
# 
# fout.close()

companys = set()
controls = {}
res = {}
for _ in range(N):
    x, y, z = [int(e) for e in fin.readline().strip().split()]
    companys.add(x)
    companys.add(y)
    if x not in controls:
        controls[x] = {}
    controls[x][y] = z
#     if controls[x][y] > 50 and x != y:
#         if x not in res:
#             res[x] = {}
#         res[x][y] = 1
# print(controls)
while True:
    found = False
    for x in companys:
        for y in companys:
            if y == x:
                continue
            if x in res and y in res[x]:
                continue
            
            if x in controls and y in controls[x] and controls[x][y] > 50:
                # x control y now
                found = True
                if x not in res:
                    res[x] = {}
                res[x][y] = 1
                if y not in controls:
                    continue
                for z in controls[y]:
                    if z not in controls[x]:
                        controls[x][z] = 0
                    controls[x][z] += controls[y][z]
            
#             total = 0
#             if x in controls and z in controls[x]:
#                 total += controls[x][z]
#             for y in res[x]:
#                 if y in controls and z in controls[y]:
#                     total += controls[y][z]
#             if total > 50:
#                 res[x][z] = 1
#                 found = True
    if not found:
        break

for x in sorted(res):
    for y in sorted(res[x]):
        fout.write(f"{x} {y}\n")
                

fout.close()
