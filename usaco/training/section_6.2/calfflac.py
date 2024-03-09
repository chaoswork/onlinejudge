"""
ID: huangch7
LANG: PYTHON3
TASK: calfflac
"""


task_name = "calfflac"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

s = ''
while True:
    line = fin.readline()
    if not line:
        break
    s += line

# print(s)
best_n = 0
best_left = None
best_right = None

for i in range(len(s)):
    left, right = i, i
    if not s[left].isalpha() or not s[right].isalpha():
        continue
    n = 0
    for _ in range(len(s)):
        if s[left].lower() != s[right].lower():
            break

        if best_n < 1 + 2 * n:
            best_n = 1 + 2 * n
            best_left = left
            best_right = right
        n += 1
        left -= 1
        right += 1
        while left >= 0 and not s[left].isalpha():
            left -= 1
        if left < 0:
            break
        while right < len(s) and not s[right].isalpha():
            right += 1
        if right == len(s):
            break
# print(best_n)        

for i in range(len(s) - 1):
    left = i

    if not s[left].isalpha():
        continue
    right = i + 1
    while right < len(s) and not s[right].isalpha():
        right += 1
    if right == len(s):
        continue
    
    n = 1
    for _ in range(len(s)):
        if s[left].lower() != s[right].lower():
            break

        if best_n < 2 * n:
            best_n = 2 * n
            best_left = left
            best_right = right
        n += 1
        left -= 1
        right += 1
        while left >= 0 and not s[left].isalpha():
            left -= 1
        if left < 0:
            break
        while right < len(s) and not s[right].isalpha():
            right += 1
        if right == len(s):
            break        
fout.write(f"{best_n}\n")
fout.write(f"{s[best_left: best_right + 1]}\n")

fout.close()
