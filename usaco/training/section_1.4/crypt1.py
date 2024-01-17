"""
ID: huangch7
LANG: PYTHON3
TASK: crypt1
"""

task_name = "crypt1"

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

n = int(fin.readline())

nums = [int(x) for x in set(fin.readline().strip().split())]
nums = sorted(nums)

def is_valid(x):
    for item in str(x):
        if int(item) not in nums:
            return False
    return True
    
cnt = 0
for a in nums:
    for b in nums:
        for c in nums:
            x = 100 * a + 10 * b + c
            for d in nums:
                larger = x * d
                if larger >= 1000:
                    break
                if not is_valid(larger):
                    continue
                for e in nums:
                    lower = x * e
                    if lower >= 1000:
                        break
                    if not is_valid(lower):
                        continue
                    res = larger * 10 + lower
                    if res >= 10000:
                        break
                    if is_valid(res):
                        cnt += 1
                    
fout.write(f"{cnt}\n")

fout.close()

#        Here are the respective outputs:
#        ----- our output ---------
#        384
#        ---- your output ---------
#        288
#        --------------------------
#
#        ------ Data for Run 4 [length=16 bytes] ------
#        7 
#        4 1 2 5 6 7 3 
