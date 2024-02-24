

task_name = "guess"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N = get_list_from_line()[0]
# 尝试统计多次出现的 feature，但是应该统计两个动物之间相似最多的个数才对。
animals = {}
for _ in range(N):
    info = get_strs_from_line()
    name = info[0]
    animals[name] = set(info[2:])


best = 0

names = list(animals.keys())

for i in range(len(names)):
    for j in range(i + 1, len(names)):
        cnt = len(animals[names[i]] & animals[names[j]])
        best = max(cnt, best)
        

# animals = {}
# features = {}
# for _ in range(N):
#     info = get_strs_from_line()
#     name = info[0]
#     animals[name] = []
# 
#     feat_set = set(info[2:])
#     for feat in feat_set:
#         if feat not in features:
#             features[feat] = 0
#         features[feat] += 1
#         animals[name].append(feat)
# 
# best = 0
# for name in animals:
#     cur = 0
#     for feat in animals[name]:
#         if features[feat] > 1:
#             cur += 1
#     best = max(cur, best)
    
fout.write(f"{best + 1}\n")
        
    

