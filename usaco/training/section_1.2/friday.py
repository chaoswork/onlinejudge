"""
ID: huangch7
LANG: PYTHON3
TASK: friday
"""

months = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]

def is_leap(year):
    if year % 100 == 0:
        return year % 400 == 0
    return year % 4 == 0



        
fin = open('friday.in', 'r')
fout = open('friday.out', 'w')


n = int(fin.readline())
counts = {k: 0 for k in range(7)}

start = 0
for i in range(n):
    if is_leap(1900 + i):
        months[1] = 29
    else:
        months[1] = 28

    for j in range(12):
        # 13th
#        res = (start + 13 % 7) % 7
        res = (start + 13) % 7
        counts[res] += 1
        # new start
#        start = (start + months[j] % 7) % 7
        start = (start + months[j]) % 7
#        print(start)
counts_res = [str(counts[i % 7]) for i in range(6, 6 + 7)]
#print(counts_res)
fout.write(' '.join(counts_res))
fout.write('\n')

    
    
