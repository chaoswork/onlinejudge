"""
ID: huangch7
LANG: PYTHON3
TASK: picture
"""


task_name = "picture"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N = get_list_from_line()[0]

coods = []


# def check_point_in_rect(x, y, rect):
#     # not include the area, realy in it
#     return rect[0] < x < rect[2] and rect[1] < y < rect[3]
# 
# def check_rect_in_rect(rect_a, rect_b):
# 
#     return rect_b[0] <= rect_a[0] <= rect_b[2] and \
#         rect_b[0] <= rect_a[2] <= rect_b[2] and \
#         rect_b[1] <= rect_a[1] <= rect_b[3] and \
#         rect_b[1] <= rect_a[3] <= rect_b[3]
        
    

for _ in range(N):
    rect = get_list_from_line()
    coods.append(rect)
#    continue
#     rm_idx = []
#     keep = True
#     for idx, rect_cur in enumerate(coods):
#         if check_rect_in_rect(rect, rect_cur):
#             keep = False
#         if check_rect_in_rect(rect_cur, rect):
#             rm_idx.append(idx)
#     if len(rm_idx):
#         coods = [x for idx, x in enumerate(coods) if idx not in rm_idx]
#     if keep:
#         coods.append(rect)
    
    
# print(coods)

#   +-----X,Y
#   |      |
#   |      |
#  x,y-----+

visited = [0] * 20010

v_coods = []
h_coods = []
for x, y, X, Y in coods:
    v_coods.append((x, 0, y, Y))
    v_coods.append((X, 1, y, Y))
    h_coods.append((y, 0, x, X))
    h_coods.append((Y, 1, x, X))

v_coods = sorted(v_coods)
h_coods = sorted(h_coods)
# print(v_coods)
# print(h_coods)

ans = 0
for x, t, y, Y in v_coods:
    for i in range(y, Y):
        if t == 0:
            if visited[i] == 0:
                ans += 1
            visited[i] += 1
        if t == 1:
            if visited[i] == 1:
                ans += 1
            visited[i] -= 1

# print(sum(visited))
for y, t, x, X in h_coods:
    for i in range(x, X):
        if t == 0:
            if visited[i] == 0:
                ans += 1
            visited[i] += 1
        if t == 1:
            if visited[i] == 1:
                ans += 1
            visited[i] -= 1

fout.write(f"{ans}\n")
# def get_cross_point(rect_a, rect_b):
#     xa, ya, Xa, Ya = rect_a
#     xb, yb, Xb, Yb = rect_b
# 
#     if xa > Xb or Xa < xb or ya > Yb or Ya < yb:
#         return set()
# 
#     x = max(xa, xb)
#     y = max(ya, yb)
#     X = min(Xa, Xb)
#     Y = min(Ya, Yb)
#     res = set()
#     res.add((x, y))
#     res.add((x, Y))
#     res.add((X, y))
#     res.add((X, Y))
# 
#     return res
# 
# def inside(x, y):
#     for rect in coods:
#         if check_point_in_rect(x, y, rect):
#             return True
#     return False
# 
# #print(get_cross_point([0, 0, 10, 10], [0, 0, 5, 5]))
# 
# all_set = set()
#     
# for i in range(len(coods)):
#     for j in range(i + 1, len(coods)):
#         all_set |= get_cross_point(coods[i], coods[j])
# 
#     x, y, X, Y = coods[i]
#     all_set.add((x, y))
#     all_set.add((x, Y))
#     all_set.add((X, y))
#     all_set.add((X, Y))
# 
# new_set = []
# 
# 
# for (x, y) in all_set:
#     if inside(x, y):
#         continue
#     new_set.append((x, y))
# 
# print(new_set)        
# 
# # print(new_set, start)
# visited = [0] * len(new_set)
# 
# ans = 0
# 
# cnt = 0
# 
# def look_down(start, new_set):
#     global ans
#     new_start = None
#     new_pos = None
#     
#     for j, (x, y) in enumerate(new_set):
#         # V
#         if x == start[0] and y < start[1]:
#             if new_start is None or new_start[1] < y:
#                 new_start = (x, y)
#                 new_pos = j
#     if new_start is not None:
#         ans += start[1] - new_start[1]
#                 
#     return new_start, new_pos
# 
# def look_right(start, new_set):
#     global ans
#     new_start = None
#     new_pos = None
#     
#     for j, (x, y) in enumerate(new_set):
#         # >
#         if x > start[0] and y == start[1]:
#             if new_start is None or new_start[0] > x:
#                 new_start = (x, y)
#                 new_pos = j
#     if new_start is not None:
#         ans += new_start[0] - start[0]
#     return new_start, new_pos
# 
# 
# def look_up(start, new_set):
#     global ans
#     new_start = None
#     new_pos = None
#     for j, (x, y) in enumerate(new_set):
#         # ^
#         if x == start[0] and y > start[1]:
#             if new_start is None or new_start[1] > y:
#                 new_start = (x, y)
#                 new_pos = j
#     if new_start is not None:
#         ans += new_start[1] - start[1]
#     
# 
#     return new_start, new_pos
# 
# def look_left(start, new_set):
#     global ans
#     new_start = None
#     new_pos = None
#     for j, (x, y) in enumerate(new_set):
#         # <
#         if x < start[0] and y == start[1]:
#             if new_start is None or new_start[0] < x:
#                 new_pos = j
#                 new_start = (x, y)
#     if new_start is not None:
#         ans += start[0] - new_start[0]
# 
#     return new_start, new_pos
# 
# while True:
#     start = (None, None)
#     start_pos = None
# 
#     for idx, (x, y) in enumerate(new_set):
#         if visited[idx]:
#             continue
#         if start[1] is None or start[1] > y:
#             start = (x, y)
#             start_pos = idx
#         elif start[1] == y and start[0] > x:
#             start = (x, y)
#             start_pos = idx
#     if start_pos is None:
#         break
#     print(cnt, start, start_pos)
#     cnt += 1
#     # visited[start_pos] = 1
# 
#     dirs_func = [look_down, look_right, look_up, look_left]
#     dirs = 0
# 
#     while True:
#         print('inner', start, ans, dirs)
#         new_start = None
#         new_pos = None
#         new_start, new_pos = dirs_func[(dirs - 1) % 4](start, new_set)
#         print('debug', new_start)
#             
#         if new_start is None:
#             new_start, new_pos = dirs_func[(dirs + 1) % 4](start, new_set)
#             if new_start is None:
#                 pass
#             else:
#                 dirs = (dirs + 1) % 4
#                 
#         else:
#             dirs = (dirs - 1) % 4
#             
#         if new_start is None:
#             break
#         print('dbeug', dirs)
# 
#         visited[new_pos] = 1
#         start = new_start
#         if start[0] == new_set[start_pos][0] and start[1] == new_set[start_pos][1]:
#             break
# 
#     
# 
# print(ans)


fout.close()
