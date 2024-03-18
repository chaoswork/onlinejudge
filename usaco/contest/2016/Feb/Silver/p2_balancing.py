task_name = "balancing"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N = get_list_from_line()[0]

loc = []

for _ in range(N):
    x, y = get_list_from_line()

    loc.append([x, y])

loc_by_x = sorted(loc, key=lambda e: e[0])
loc_by_y = sorted(loc, key=lambda e: e[1])

no_more_than_x = {}
no_more_than_y = {}

i = 0
t = 0
n = 0
while i < len(loc_by_x):
    n = 0
    while i + n < len(loc_by_x) and loc_by_x[i + n][0] <= loc_by_x[i][0]:
        n += 1
    t += n
    no_more_than_x[loc_by_x[i][0]] = t
    i = i + n
# print(no_more_than_x)    

i = 0
t = 0

while i < len(loc_by_y):
    n = 0
    while i + n < len(loc_by_y) and loc_by_y[i + n][1] <= loc_by_y[i][1]:
        n += 1
    t += n
    no_more_than_y[loc_by_y[i][1]] = t
    i = i + n
# print(no_more_than_y)    
best = INF
for i in range(len(loc_by_x)):
    x = loc_by_x[i][0]
    t = 0
    last = loc_by_y[0][1] - 1
    for j in range(0, len(loc_by_y)):
        if loc_by_y[j][0] > x:
            continue
        if last in no_more_than_y and loc_by_y[j][1] > last:
            # print(x, last, t, no_more_than_x[x], no_more_than_y.get(last, None))
            best = min(best, max(t, no_more_than_x[x] - t, no_more_than_y[last] - t,
                                 N - (no_more_than_x[x] + no_more_than_y[last] - t)))
        t += 1
        last = loc_by_y[j][1]
    # last number
    # print(x, last, t, no_more_than_x[x], no_more_than_y.get(last, None))
    best = min(best, max(t, no_more_than_x[x] - t, no_more_than_y[last] - t,
                         N - (no_more_than_x[x] + no_more_than_y[last] - t)))
            
        
fout.write(f"{best}\n")    

# x_list = sorted(set([x for (x, y) in loc]))
# y_list = sorted(set([y for (x, y) in loc]))
# x_list.append(x_list[-1] + 2)
# y_list.append(y_list[-1] + 2)
# 
# 
# # try to find the middle first?
# x_mid_val = [x for (x, y) in loc][N//2]
# x_mid_idx = x_list.index(x_mid_val)
# y_mid_val = [y for (x, y) in loc][N//2]
# y_mid_idx = y_list.index(y_mid_val)
# 
# 
# 
#     
#     
# 
# best = None
# # for i in range(len(x_list)):
# #     for j in range(len(y_list)):
# #         x = x_list[i] - 1
# #         y = y_list[j] - 1
# k = 10
# x_mid_idx = N // 2
# y_mid_idx = N // 2
# x_list = sorted([x for (x, y) in loc])
# y_list = sorted([y for (x, y) in loc])
# x_list.append(x_list[-1] + 2)
# y_list.append(y_list[-1] + 2)
# 
# for x in x_list[max(0, x_mid_idx - k): min(len(x_list), x_mid_idx + k + 1)]:
#     x = x - 1
#     for y in y_list:#[max(0, y_mid_idx - k): min(len(y_list), y_mid_idx + k + 1)]:
#         y = y - 1
# 
#         cnt = [0] * 4
#         for xx, yy in loc:
#             if xx < x and yy < y:
#                 cnt[0] += 1
#             if xx < x and yy > y:
#                 cnt[1] += 1
#             if xx > x and yy < y:
#                 cnt[2] += 1
#             if xx > x and yy > y:
#                 cnt[3] += 1
#         cur = max(cnt)
#         if best is None or cur < best:
#             best = cur
# fout.write(f"{best}\n")
fout.close()





        
