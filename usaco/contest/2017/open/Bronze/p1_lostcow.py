task_name = "lostcow"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

x, y = get_list_from_line()
ans = 0

n = 1
d = 1


if x > y:
    x, y = y, x
    d = -1

cur = x
while cur < y:
    last = cur
    cur = x + n * d
#     print(last, cur)
    ans += abs(cur - last)
    d = -d
    n *= 2

ans -= cur - y

fout.write(f"{ans}\n")
        
        
