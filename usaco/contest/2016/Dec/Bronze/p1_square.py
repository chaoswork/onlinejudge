task_name = "square"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

xa, ya, Xa, Ya = get_list_from_line()
xb, yb, Xb, Yb = get_list_from_line()

x = max(Xa, Xb) - min(xa, xb)
y = max(Ya, Yb) - min(ya, yb)

area = max(x, y) ** 2

fout.write(f"{area}\n")


fout.close()        
        
    





        
