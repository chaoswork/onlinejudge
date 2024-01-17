"""
ID: huangch7
LANG: PYTHON3
TASK: theme
"""
import math

task_name = "theme"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



def kmpGetNext(p):

    i=0
    j=-1
    b = [None] * (len(p) + 1)
    a = [0] * (len(p) + 1)
    b[i] = j;
    while i < len(p):
        while j>=0 and p[i]!=p[j]:
            j=b[j];
#         print(i, j, p[i], p[j])
            
        i+=1
        j+=1
#        print('+1', i, j, p[j])
        b[i]=j
        a[i] = min(b[i], i - j - 1)
    return b

def kmpSearch(t, p):
    b = kmpGetNext(p)
    best = 0
    i=0
    j=0
    ans = []
    while i<len(t):
        while j>=0 and t[i]!=p[j]:
            j=b[j]
        i+=1
        j+=1
        best = max(best, j)
        if j==len(p):
            ans.append(i-j)
            j=b[j]
    return ans, best




fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N = get_list_from_line()[0]
if N == 1:
    fout.write("0\n")
elif N < 4:
    fout.write("1\n")
else:

    seqs = []
    while True:
        parts = get_list_from_line()
        if len(parts) == 0:
            break
        seqs += parts
    
    # print(len(seqs))
    diff = []
    for i in range(1, len(seqs)):
        diff.append(seqs[i] - seqs[i - 1])
    # print(seqs)
#     print(diff)
    best = 0
    for i in range(1, len(diff) - 1):
    #     print('diff=', diff[i:])
    #    print(kmpGetNext(diff[i:]))
        
        ans, cur = kmpSearch(diff[:i], diff[i + 1:])
        best = max(cur, best)
#        print(diff[:i], diff[i + 1:], ans, best)
    best = best + 1
    if best < 5:
        best = 0
    fout.write(f"{best}\n")

# diff= [-4, -4, -4, -4, 64, -4, -4, -4, -4, 1, -3, -4, 5, 15]
# [-1, 0, 1, 2, 3, 0, 1, 2, 3, 4, 0, 0, 1, 0, 0]

# [-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]


fout.close()
