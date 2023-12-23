"""
ID: huangch7
LANG: PYTHON3
TASK: ride
"""

def product_num(s):
    res = 1
    for x in s:
        res *= ord(x) - ord('A') + 1
    return res
        
fin = open('ride.in', 'r')
fout = open('ride.out', 'w')

inputs = fin.readlines()

# print(product_num(inputs[0]))
# print(product_num(inputs[1]))

res = 'GO' if product_num(inputs[0].strip()) % 47 == product_num(inputs[1].strip()) % 47 else 'STAY'


fout.write (res + '\n')
fout.close()
