task_name = "lineup"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()

cows = sorted(["Bessie", "Buttercup", "Belinda", "Beatrice",
        "Bella", "Blue", "Betsy", "Sue"])


fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N = get_list_from_line()[0]

besides = []

for _ in range(N):
    cols = get_strs_from_line()
    besides.append((cols[0], cols[-1]))

best = []


def less_than(a, b):
    for i in range(len(a)):
        if a[i] == b[i]:
            continue
        return a[i] < b[i]


def santisfy(cur, besides):
    for a, b in besides:
        if abs(cur.index(a) - cur.index(b)) != 1:
            return False
    return True
        

def search(old, cur):
    global best
    if len(cur) == 8:
        if santisfy(cur, besides):
            if len(best) == 0 or less_than(cur, best):
                best = cur
        return
    for i in range(len(old)):
        search(old[:i] + old[i + 1:], cur + [old[i]])
        
search(cows, [])

for line in best:
    fout.write(line)
    fout.write('\n')
fout.close()
        
    





        
