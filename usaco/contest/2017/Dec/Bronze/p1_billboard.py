task_name = "billboard"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

#1 2 3 5
#6 0 10 4
#2 1 8 3

#5 ###
#4 ###  #####
#3 #xxxxxxx##
#2 #xxxxxxx##
#1  xxxxxxx##
#0      #####
# 01234567890

rect_a = get_list_from_line()
rect_b = get_list_from_line()
rect_c = get_list_from_line()

def get_merged_area(a, b):
    xa, ya, Xa, Ya = a
    xb, yb, Xb, Yb = b

    x = max(xa, xb)
    y = max(ya, yb)
    X = min(Xa, Xb)
    Y = min(Ya, Yb)

    if x >= X or y >= Y:
        return 0

    return (X - x) * (Y - y)

def get_area(a):
    x, y, X, Y = a
    return (X - x) * (Y - y)

ans = get_area(rect_a) - get_merged_area(rect_a, rect_c) \
    + get_area(rect_b) - get_merged_area(rect_b, rect_c)

fout.write(f"{ans}\n")


fout.close()
