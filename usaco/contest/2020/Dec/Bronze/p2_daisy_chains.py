import sys


INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = sys.stdin
fout = sys.stdout

N = get_list_from_line()[0]
flowers = get_list_from_line()

ans = 0
for i in range(N):
    for j in range(i + 1, N + 1):
        avg = sum(flowers[i:j]) / (j - i)
        if avg in flowers[i:j]:
            ans += 1
fout.write(f"{ans}\n")
    
fout.close()
