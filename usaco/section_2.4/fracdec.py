"""
ID: huangch7
LANG: PYTHON3
TASK: fracdec
"""

task_name = "fracdec"

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N, D = [int(x) for x in fin.readline().strip().split()]

ans = f"{N // D}."
remainder = N % D

remainder_position = {}


while remainder:
    if remainder in remainder_position:
        break
#    print(remainder)
    remainder_position[remainder] = len(ans)    
    ans += f"{remainder * 10 // D}"
    remainder = (remainder * 10) % D


if remainder == 0:
    if ans[-1] == '.':
        ans += '0'
else:
    ans = ans[:remainder_position[remainder]] + '(' + ans[remainder_position[remainder]:] + ')'
for i in range(0, len(ans), 76):
    fout.write(f"{ans[i: i + 76]}\n")
    
fout.close()
