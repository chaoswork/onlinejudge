import sys

task_name = "tracing"

INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f"{task_name}.in")
fout = open(f"{task_name}.out", 'w')

N, T = get_list_from_line()

infected = "0" + fin.readline().strip()

meet_info = {}
timeline = []

for _ in range(T):
    t, x, y = get_list_from_line()
    timeline.append((t, x, y))

    if x not in meet_info:
        meet_info[x] = [0] * 256
    meet_info[x][t] = y

    if y not in meet_info:
        meet_info[y] = [0] * 256
    meet_info[y][t] = x

timeline = sorted(timeline, key=lambda x: x[0])

k_min = INF
k_max = 0
ans = 0
total_infected = infected.count('1')


for n in range(1, N + 1):
    # check if n is patient zero
    if infected[n] == '0':
        continue
    
    n_ok = False
    for k in range(0, 256):    

        # 不只是一个人在传染，传染后可以再传染
        # 根据时间t进行模拟
        shake_left = {x: 0 for x in range(1, N + 1)}
        shake_left[n] = k
        cur_infected = [0] * (N + 1)
        cur_infected[n] = 1

        for (t, x, y) in timeline:
            if shake_left[x]:
                if shake_left[y]:
                    shake_left[y] -= 1
#                    continue
                else:
                    if cur_infected[y] == 0:
                        cur_infected[y] = 1
                        shake_left[y] = k
                shake_left[x] -= 1
            else:
                if shake_left[y]:
                    if cur_infected[x] == 0:
                        cur_infected[x] = 1
                        shake_left[x] = k
                    shake_left[y] -= 1
                else:
                    continue
                        
        cur_infected = ''.join([str(x) for x in cur_infected])
#        print(cur_infected)
        if cur_infected == infected:
            n_ok = True
            k_min = min(k, k_min)
            k_max = max(k, k_max)
    if n_ok:
        ans += 1
if k_max > 250:
    k_max = 'Infinity'
fout.write(f"{ans} {k_min} {k_max}\n")



fout.close()
