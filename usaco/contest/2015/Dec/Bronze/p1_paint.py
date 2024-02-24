task_name = "paint"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()


fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

a, b = get_list_from_line()
c, d = get_list_from_line()

if b < c:
    ans = b - a + d - c
elif d < a:
    ans = b - a + d - c
else:
    ans = max(b, d) - min(a, c)

fout.write(f"{ans}\n")
fout.close()
