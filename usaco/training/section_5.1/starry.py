"""
ID: huangch7
LANG: PYTHON3
TASK: starry
"""
import math

task_name = "starry"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()





# print(get_angle(1, 0)) # why atan2 measure form (0, 1)
# print(get_angle(0, 1))
fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

W = get_list_from_line()[0]
H = get_list_from_line()[0]

star_map = []
for _ in range(H):
    star_map.append(fin.readline().strip())

colored = [[0] * W for _ in range(H)]
color_id = 1


def floodfill(i, j, first_touch=True):
    """
    Returns
    -------
    list
        [color_id, min_h, max_h, min_w, max_w]

    """
    global color_id
    if i < 0 or i >= H:
        return [None] * 5
    if j < 0 or j >= W:
        return [None] * 5
    if colored[i][j]:
        return [None] * 5
    if star_map[i][j] == '0':
        return [None] * 5
    colored[i][j] = color_id
    min_h, max_h, min_w, max_w = i, i + 1, j, j + 1
    for ii in range(-1, 2):
        for jj in range(-1, 2):
            if ii == 0 and jj == 0:
                continue
            res = floodfill(i + ii, j + jj, False)
            if res[0] is not None:
                min_h = min(min_h, res[1])
                max_h = max(max_h, res[2])
                min_w = min(min_w, res[3])
                max_w = max(max_w, res[4])
    if first_touch:
        color_id += 1
    return [color_id - 1, min_h, max_h, min_w, max_w]

area = {}
matrix_map = {}

for i in range(H):
    for j in range(W):
        res = floodfill(i, j)
        if res[0] is not None:
            # get matrix
            cid, min_h, max_h, min_w, max_w = res
            matrix = [[0] * (max_w - min_w) for _ in range(max_h - min_h)]
            for r in range(min_h, max_h):
                for c in range(min_w, max_w):
                    if colored[r][c] == cid:
                        matrix[r - min_h][c - min_w] = 1
            area[res[0]] = res[1:]
            matrix_map[cid] = matrix
#    print(colored[i])

# print(area)
# print(matrix_map)



def clockwise_transform(matrix):
    """
    a matrix full of 0, 1
    """
    new_matrix = [[0] * len(matrix) for _ in range(len(matrix[0]))]
    for i in range(len(matrix)):
        for j in range(len(matrix[i])):
            new_matrix[j][len(matrix) - i - 1] = matrix[i][j]
    return new_matrix

def flip_transform(matrix):
    """
    a matrix full of 0, 1
    """
    new_matrix = [[0] * len(matrix[0]) for _ in range(len(matrix))]
    for i in range(len(matrix)):
        for j in range(len(matrix[i])):
            new_matrix[i][len(matrix[0]) - j - 1] = matrix[i][j]
    return new_matrix


def matrix_equal(a, b):
    if len(a) != len(b):
        return False
    if len(a[0]) != len(b[0]):
        return False
    for i in range(len(a)):
        for j in range(len(a[0])):
            if a[i][j] != b[i][j]:
                return False
    return True

id2az = {}
letters = "abcdefghijklmnopqrstuvwxyz"
letter_id = 0

# need sort?
for cid in matrix_map:
    if cid in id2az:
        continue
    cur = matrix_map[cid]
    cands = [cur]
    for _ in range(3):
        cands.append(clockwise_transform(cands[-1]))
    cands.append(flip_transform(cur))
    for _ in range(3):
        cands.append(clockwise_transform(cands[-1]))
    
    
    for cmp_cid in matrix_map:
        if cid == cmp_cid:
            continue
        is_same = False
        for matrix in cands:
            if matrix_equal(matrix, matrix_map[cmp_cid]):
                is_same = True
                break
        
        if is_same:
            id2az[cmp_cid] = letters[letter_id]
    id2az[cid] = letters[letter_id]
    letter_id += 1

# print(id2az)
id2az[0] = '0'

res = []
for i in range(H):
    line = ""
    for j in range(W):
        line += id2az[colored[i][j]]
    fout.write(line)
    fout.write("\n")
fout.close()
