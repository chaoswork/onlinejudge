task_name = "censor"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()


fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

S = fin.readline().strip()
T = fin.readline().strip()

ans = ""

for i in range(len(S)):
    ans += S[i]
    if len(ans) >= len(T) and ans.endswith(T):
        ans = ans[:-len(T)]
#     print(ans)
fout.write(ans + "\n")

# while True:
#     idx = S.find(T)
#     if idx >= 0:
#         S = S[:idx] + S[idx + len(T):]
#     else:
#         break
# fout.write(f"{S}\n")

fout.close()
