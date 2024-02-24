task_name = "billboard"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

xa, ya, Xa, Ya = get_list_from_line()  # lawmower
feed = get_list_from_line()
xb, yb, Xb, Yb = feed


def is_in_rect(point, rect):
    x, y = point
    return rect[0] < x < rect[2] and rect[1] < y < rect[3]

def get_area(x, y, X, Y):
    return (X - x) * (Y - y)

point_in_rect = []

for x in [xa, Xa]:
    for y in [ya, Ya]:
        point = [x, y]
        if is_in_rect(point, feed):
            point_in_rect.append(point)

area = 0
if len(point_in_rect) < 2:
    area = get_area(xa, ya, Xa, Ya)
elif len(point_in_rect) == 2:
    pa, pb = point_in_rect
    if pa[0] == pb[0]:
        if xa < xb < Xa:
            area = get_area(xa, ya, xb, Ya)
        else: # xa < Xb < XA
            area = get_area(xa, ya, Xa, Ya) - get_area(xa, ya, Xb, Ya)
        
    else:
        if ya < yb < Ya:
            area = get_area(xa, ya, Xa, yb)
        else: # ya < Yb < Ya
            area = get_area(xa, ya, Xa, Ya) - get_area(xa, ya, Xa, Yb)


        

fout.write(f"{area}\n")


fout.close()        
        
    





        
