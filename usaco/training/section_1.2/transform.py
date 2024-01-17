"""
ID: huangch7
LANG: PYTHON3
TASK: transform
"""

task = 'transform'

def check_same(matrix_a, matrix_b):
    for i in range(len(matrix_a)):
        if matrix_a[i] != matrix_b[i]:
            return False
    return True

def rotate_90(matrix):
    """
    123    741
    456 -> 852
    789    963
    (1, 2): 6
    (2, 1): 6
    """
    res = [[None] * len(matrix) for _ in range(len(matrix))]
    for i in range(len(matrix)):
        for j in range(len(matrix)):
            res[j][len(matrix) - i - 1] = matrix[i][j]
    res = [''.join(line) for line in res]
    return res

def reflection(matrix):
    """
    123    321
    456 -> 654
    789    987
    """
    res = [[None] * len(matrix) for _ in range(len(matrix))]
    for i in range(len(matrix)):
        for j in range(len(matrix)):
            res[i][len(matrix) - j - 1] = matrix[i][j]
    res = [''.join(line) for line in res]
    return res


def get_action(ma, mb):
    mc = rotate_90(ma)
    if check_same(mc, mb):
        return 1
    mc = rotate_90(mc)
    if check_same(mc, mb):
        return 2
    mc = rotate_90(mc)
    if check_same(mc, mb):
        return 3
    md = reflection(ma)
    if check_same(md, mb):
        return 4
    
    mc = rotate_90(md)
    if check_same(mc, mb):
        return 5
    mc = rotate_90(mc)
    if check_same(mc, mb):
        return 5
    mc = rotate_90(mc)
    if check_same(mc, mb):
        return 5
    if check_same(ma, mb):
        return 6
    
    return 7

    

        
fin = open(f'{task}.in', 'r')
fout = open(f'{task}.out', 'w')

n = int(fin.readline())
ma = []
mb = []

for i in range(n):
    ma.append(fin.readline().strip())
for i in range(n):
    mb.append(fin.readline().strip())

fout.write(f"{get_action(ma, mb)}\n")

