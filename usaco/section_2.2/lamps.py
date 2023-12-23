"""
ID: huangch7
LANG: PYTHON3
TASK: lamps
"""

task_name = "lamps"

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N = int(fin.readline())
C = int(fin.readline())
lamps_on = [int(x) for x in fin.readline().split()[:-1]]
lamps_off = [int(x) for x in fin.readline().split()[:-1]]

# all the lamps is on
# 2^4
# zero button: 0
# one button:    1 2 4 8
# two buttons:   3 5 6 9 10 12
# three buttons: 14 13 11 7
# four buttons:  15
# 5 -> 3/1, 6 -> 4/2/0, 7 -> 3/1
button1 = 2 ** N - 1
button2 = int(("10" * N)[:N], 2)
button3 = int(("01" * N)[:N], 2)
button4 = int(("100" * N)[:N], 2)



def press_button(x):
    """
    1: swap
    2: odd
    3: even
    4: 3k + 1, 1, 4, 7 ...
    """
    lamps = 2 ** N - 1
    if x & 1:
        lamps = lamps ^ button1
    if x & 2:
        lamps = lamps ^ button2
    if x & 4:
        lamps = lamps ^ button3
    if x & 8:
        lamps = lamps ^ button4
    return lamps

press_ans = [None] * 5
press_ans[0] = set([press_button(x) for x in [0]])
press_ans[1] = set([press_button(x) for x in [1, 2, 4, 8]])
press_ans[2] = set([press_button(x) for x in [3, 5, 6, 9, 10, 12]])
press_ans[3] = set([press_button(x) for x in [14, 13, 11, 7]])
press_ans[4] = set([press_button(x) for x in [15]])


filter_on = ["0"] * N
for x in lamps_on:
    filter_on[x - 1] = "1"
filter_on = int("".join(filter_on), 2)

filter_off = ["1"] * N
for x in lamps_off:
    filter_off[x - 1] = "0"
filter_off = int("".join(filter_off), 2)

ans = set()
if C > 4:
    ans = (press_ans[1] | press_ans[3]) if C & 1 else (press_ans[0] | press_ans[2] | press_ans[4])
else:
    while C >= 0:
        ans |= press_ans[C]
        C -= 2
# print(ans)
# print(filter_on)
# print(filter_off)
final = []
for item in ans:
    if (item & filter_on == filter_on) and (item | filter_off == filter_off):
        final.append(item)

final = [bin(x)[2:].zfill(N) for x in final]

if len(final) == 0:
    fout.write("IMPOSSIBLE\n")
else:
    for line in sorted(final):
        fout.write(f"{line}\n")

fout.close()


