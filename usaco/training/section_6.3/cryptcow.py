"""
ID: huangch7
LANG: PYTHON3
TASK: cryptcow
"""



task_name = "cryptcow"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

target = "Begin the Escape execution at the Break of Dawn"
found = 0
n_crypt = 0

def decrypt(s, n):
    global target, found, n_crypt
    if found:
        return
    if len(s) == len(target):
        if s == target:
            found = 1
            n_crypt = n
        return
    if len(s) < len(target):
        return

    if 'C' not in s:
        if s == target:
            found = 1
            n_crypt = n
        return
    
    if s.count('C') != s.count('O'):
        return
    if s.count('C') != s.count('W'):
        return

    prefix = min(s.find('C'), s.find('O'), s.find('W'))
    if s[prefix] != 'C':
        return
    if prefix > 0 and s[:prefix] != target[:prefix]:
        return

    suffix = max(s.rfind('C'), s.rfind('O'), s.rfind('W'))
    if s[suffix] != 'W':
        return
    if suffix < len(s) and s[suffix + 1:] != target[suffix - len(s) + 1:]:
        return

    p = prefix
    q = p
    p += 1
    while p < suffix:
        if s[p] in 'COW':
            cur = s[q + 1:p]
            if len(cur) and cur not in target:
                return
            q = p
        p += 1
            
    
#    print(s, n)
    for i in range(prefix + 1, suffix):
        if s[i] != 'O':
            continue
        decrypt(s[:prefix] +  s[i + 1: suffix] + s[prefix + 1: i] + s[suffix + 1:], n + 1)
#     for i in range(len(s)):
#         if s[i] != 'C':
#             continue
#         for j in range(i + 1, len(s)):
#             if s[j] != 'O':
#                 continue
#             for k in range(j + 1, len(s)):
#                 if s[k] != 'W':
#                     continue
#                 decrypt(s[:i] +  s[j + 1: k] + s[i + 1: j] + s[k + 1:], n + 1)

source = fin.readline().strip()

decrypt(source, 0)

fout.write(f"{found} {n_crypt}\n")

fout.close()
