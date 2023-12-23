"""
ID: huangch7
LANG: PYTHON3
TASK: fc
"""
import math

task_name = "fc"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()


def get_angle(x, y):
    return math.atan2(x, y) * (180.0 / math.pi) % 360


def clockwise_angle(v1, v2):
    dot_product = v1[0] * v2[0] + v1[1] * v2[1]
    cross_product = v1[0] * v2[1] - v1[1] * v2[0]
    
    angle = math.atan2(cross_product, dot_product)
    angle_degrees = math.degrees(angle)
    
    if angle_degrees < 0:
        angle_degrees += 360
    
    return angle_degrees

def vec(p1, p2):
    return [p2[0] - p1[0], p2[1] - p1[1]]

# angle = clockwise_angle(v1, v2)
# print("顺时针夹角为:", angle)



# print(get_angle(1, 0)) # why atan2 measure form (0, 1)
# print(get_angle(0, 1))
fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N = get_list_from_line()[0]
points = []
mid = [0, 0]

for _ in range(N):
    points.append(get_list_from_line(float))
    mid[0] += points[-1][0]
    mid[1] += points[-1][1]
mid[0] = mid[0] / N
mid[1] = mid[1] / N
# print(mid)

for i in range(N):
    points[i].append(get_angle(points[i][0] - mid[0], points[i][1] - mid[1]))

points = sorted(points, key=lambda x: x[-1])
points = [x[:2] for x in points]
# print(points)

# points = [
#     [1, 0],
#     [2, 1],
#     [2, -1],
#     [-2, -1],
#     [-2, 1],
#     [-1, 0]
# ]
# N = len(points)

ans = [0, 1]

for i in range(2, N):
    # a bug in here, using i not use the last of ans
    last = len(ans) - 1
    while last > 0:
#         print('debug', i, points[last - 1], points[last], points[i], ans)
        # vecta = [points[last - 1][0] - points[last][0], points[last - 1][1] - points[last][1]]
        # vectb = [points[i][0] - points[last][0], points[i][1] - points[last][1]]
        right = points[i]
        middle = points[ans[last]]
        left = points[ans[(last - 1) % len(ans)]]
        
#         print(clockwise_angle(vecta, vectb))
#         if clockwise_angle(vecta, vectb) > 180:
        if clockwise_angle(vec(middle, left), vec(middle, right)) > 180:
            ans.pop()
        else:
            break
        last -= 1
#        print(ans)
    ans.append(i)

#     print(ans)



# check last


while True:
    # check non convex hull at 0
    last = 0
    found = False
    right = points[ans[(last + 1) % len(ans)]]
    middle = points[ans[last]]
    left = points[ans[(last - 1) % len(ans)]]
    
    if clockwise_angle(vec(middle, left), vec(middle, right)) > 180:
        ans.pop(0)
        found = True
    # check non convex hull at N - 1
    last = len(ans) - 1
#     print(last, last - 1, ans[last - 1], last + 1, ans[last + 1 - len(ans)])
    right = points[ans[(last + 1) % len(ans)]]
    middle = points[ans[last]]
    left = points[ans[(last - 1) % len(ans)]]
    
    if clockwise_angle(vec(middle, left), vec(middle, right)) > 180:
        ans.pop()
        found = True
    
    if not found:
        break

# print(ans)

# while True:
#     # check non convex hull at 0
#     found = False
#     for last in range(len(ans)):
#         right = points[ans[(last + 1) % len(ans)]]
#         middle = points[ans[last]]
#         left = points[ans[(last - 1) % len(ans)]]
#         
#         if clockwise_angle(vec(middle, left), vec(middle, right)) > 180:
#             ans = ans[:last] + ans[last + 1:]
#             found = True
#             break
#     if not found:
#         break


def length(p1, p2):
    a = p1[0] - p2[0]
    b = p1[1] - p2[1]
    return math.sqrt(a * a + b * b)

total = 0
for i in range(len(ans)):
    total += length(points[ans[i]], points[ans[(i + 1) % len(ans)]])
fout.write(f"{total:.2f}\n")

fout.close()
