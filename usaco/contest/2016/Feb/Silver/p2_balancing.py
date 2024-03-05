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

x_list = sorted(set([x for (x, y) in loc]))
y_list = sorted(set([y for (x, y) in loc]))
x_list.append(x_list[-1] + 2)
y_list.append(y_list[-1] + 2)


# try to find the middle first?
x_mid_val = sorted([x for (x, y) in loc])[N//2]
x_mid_idx = x_list.index(x_mid_val)
y_mid_val = sorted([y for (x, y) in loc])[N//2]
y_mid_idx = y_list.index(y_mid_val)



    
    

best = None
# for i in range(len(x_list)):
#     for j in range(len(y_list)):
#         x = x_list[i] - 1
#         y = y_list[j] - 1
k = 50
x_mid_idx = N // 2
y_mid_idx = N // 2
x_list = sorted([x for (x, y) in loc])
y_list = sorted([y for (x, y) in loc])
x_list.append(x_list[-1] + 2)
y_list.append(y_list[-1] + 2)

for x in x_list[max(0, x_mid_idx - k): min(len(x_list), x_mid_idx + k + 1)]:
    x = x - 1
    for y in y_list[max(0, y_mid_idx - k): min(len(y_list), y_mid_idx + k + 1)]:
        y = y - 1

        cnt = [0] * 4
        for xx, yy in loc:
            if xx < x and yy < y:
                cnt[0] += 1
            if xx < x and yy > y:
                cnt[1] += 1
            if xx > x and yy < y:
                cnt[2] += 1
            if xx > x and yy > y:
                cnt[3] += 1
        cur = max(cnt)
        if best is None or cur < best:
            best = cur
fout.write(f"{best}\n")
fout.close()





        
