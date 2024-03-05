import sys

task_name = "bcs"

INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f"{task_name}.in")
fout = open(f"{task_name}.out", 'w')

N, K = get_list_from_line()

target = []
target_cnt = 0
for _ in range(N):
    target.append(fin.readline().strip())
    target_cnt += target[-1].count('#')

parts = []
parts_cnt = []
shift_left = []
shift_up = []
shift_right = []
shift_down = []

for _ in range(K):
    cur = []
    cur_cnt = 0
    for _ in range(N):
        cur.append(fin.readline().strip())
        cur_cnt += cur[-1].count('#')
    
    parts.append(cur)
    parts_cnt.append(cur_cnt)

    left, right, up, down = N + 1, -1, N + 1, -1
    for i in range(N):
        for j in range(N):
            if cur[i][j] == '#':
                left = min(j, left)
                right = max(j, right)
                up = min(i, up)
                down = max(i, down)

    shift_left.append(left)
    shift_right.append(N - 1 - right)
    shift_up.append(up)
    shift_down.append(N - 1 - down)

    
# print(shift_left, shift_right, shift_up, shift_down)



def compare(idx, t, strict=False):
    for i in range(-shift_up[idx], shift_down[idx] + 1):
        for j in range(-shift_left[idx], shift_right[idx] + 1):
            # i, j as the offset of b
#             print('debug', idx, i, j)

            # get new matrix
            new_matrix = [['.'] * N for _ in range(N)]
            for r in range(N):
                for c in range(N):
                    rr = r + i
                    cc = c + j
                    if rr < 0 or rr >= N or cc < 0 or cc >= N:
                        continue
                    new_matrix[rr][cc] = parts[idx][r][c]
#            for item in new_matrix:
#                print(''.join(item))

            matched = True
            for r in range(N):
                for c in range(N):
                    if strict:
                        if new_matrix[r][c] != t[r][c]:
                            matched = False
                            continue
                    else:
                        if new_matrix[r][c] == '#' and  t[r][c] == '.':
                            matched = False
                            continue
            if not matched:
                continue
#            print('matched', i, j)
            # matched!
            tt = []
            for r in range(N):
                line = list(t[r])
                for c in range(N):
                    if new_matrix[r][c] == '#':
                        line[c] = '.'
                tt.append(''.join(line))
#            print(tt)
            return tt
    return None
                    

ans = None
for i in range(K):
    for j in range(i + 1, K):
        if parts_cnt[i] + parts_cnt[j] != target_cnt:
            continue
#         print('i, j', i, j)
        left = compare(i, target)
        if left is None:
            continue
#        print('left')
#        for line in left:
#            print(line)
        if compare(j, left, strict=True):
            ans = (i + 1, j + 1)

fout.write(f"{ans[0]} {ans[1]}\n")
fout.close()
