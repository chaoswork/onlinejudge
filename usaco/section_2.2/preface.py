"""
ID: huangch7
LANG: PYTHON3
TASK: preface
"""

task_name = "preface"

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N = int(fin.readline())


def get_roman(num):
    """
        I   1     L   50    M  1000
        V   5     C  100
        X  10     D  500
    I before V or X;
    X before L or C;
    C before D or M
    """
    res = ""
    if num >= 1000:
        x = num // 1000
        res += "M" * x
        num -= x * 1000
    if num >= 100:
        x = num // 100
        if x == 9:
            res += "CM"
        elif x >= 5:
            res += "D"
            res += "C" * (x - 5)
        elif x == 4:
            res += "CD"
        else:
            res += "C" * x
        num -= 100 * x
    if num >= 10:
        x = num // 10
        if x == 9:
            res += "XC"
        elif x >= 5:
            res += "L"
            res += "X" * (x - 5)
        elif x == 4:
            res += "XL"
        else:
            res += "X" * x
        num -= 10 * x

    if num >= 0:
        x = num
        if x == 9:
            res += "IX"
        elif x >= 5:
            res += "V"
            res += "I" * (x - 5)
        elif x == 4:
            res += "IV"
        else:
            res += "I" * x
        num -= 10 * x
    return res


res = {x: 0 for x in "IVXLCDM"}

for i in range(1, N + 1):
    num = get_roman(i)
    for x in num:
        res[x] += 1

for item in res.items():
    if item[1] > 0:
        fout.write(f"{item[0]} {item[1]}\n")
fout.close()
