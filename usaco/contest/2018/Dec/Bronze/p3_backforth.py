task_name = "backforth"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()


fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

A = get_list_from_line()
B = get_list_from_line()
ans = set()


def carry(a, b, buckets_a, buckets_b, step):
    global ans
    if step == 5:
        ans.add(a)
        return

    if step % 2:
        for i in range(len(buckets_a)):
            aa = a - buckets_a[i]
            bb = b + buckets_a[i]
            carry(aa, bb, buckets_a[:i] + buckets_a[i+1:], buckets_b + [buckets_a[i]], step + 1)
    else:
        for i in range(len(buckets_b)):
            aa = a + buckets_b[i]
            bb = b - buckets_b[i]
            carry(aa, bb, buckets_a + [buckets_b[i]], buckets_b[:i] + buckets_b[i+1:], step + 1)


carry(1000, 1000, A, B, 1)
#print(len(ans), ans)
fout.write(f"{len(ans)}\n")
fout.close()
