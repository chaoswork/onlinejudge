task_name = "cownomics"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N, M = get_list_from_line()
spot = []
plain = []
for _ in range(N):
    spot.append(get_strs_from_line()[0])
for _ in range(N):
    plain.append(get_strs_from_line()[0])


ans = 0


for j in range(M):
    spot_set = set()
    plain_set = set()
    for i in range(N):
        spot_set.add(spot[i][j])
        plain_set.add(plain[i][j])
    if len(spot_set & plain_set) == 0:
        ans += 1
fout.write(f"{ans}\n")
fout.close()        
