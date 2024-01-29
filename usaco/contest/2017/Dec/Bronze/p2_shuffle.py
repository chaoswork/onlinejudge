task_name = "shuffle"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N = get_list_from_line()[0]
pos = [0] + get_list_from_line()
ans = [0] * (N + 1)


for idx, x in enumerate(pos):
    ans[x] = idx
print(ans)

for _ in range(2):
    new_ans = [0] * (N + 1)
    for idx, x in enumerate(ans):
        new_ans[x] = idx
    ans = new_ans
    print(ans)
# print(new_ans)
ids = get_strs_from_line()
ids = [None] + ids

for i in range(1, N + 1):
    fout.write(f"{ids[ans[i]]}\n")




fout.close()
