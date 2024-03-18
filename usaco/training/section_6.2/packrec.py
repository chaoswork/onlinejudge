"""
ID: huangch7
LANG: PYTHON3
TASK: packrec
"""



task_name = "packrec"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

rects = []

for _ in range(4):
    rects.append(get_list_from_line())


def rotate(wh):
    return [wh[1], wh[0]]


best = INF
best_pairs = set()

def update(w, h):
    global best, best_pairs
    if w * h < best:
        best = w * h
        best_pairs = set([(min(w, h), max(w, h))])
    elif w * h == best:
        best_pairs.add((min(w, h), max(w, h)))


for i in range(4):
    for j in range(4):
        if j == i:
            continue
        for k in range(4):
            if k in [i, j]:
                continue
            for p in range(4):
                if p in [i, j, k]:
                    continue
                for w1, h1, in [rects[i], rotate(rects[i])]:
                    for w2, h2, in [rects[j], rotate(rects[j])]:
                        for w3, h3 in [rects[k], rotate(rects[k])]:
                            for w4, h4 in [rects[p], rotate(rects[p])]:


                                # case 1
                                w = w1 + w2 + w3 + w4
                                h = max(h1, h2, h3, h4)
                                update(w, h)

                                # case 2
                                w = max(w1, w2 + w3 + w4)
                                h = h1 + max(h2, h3, h4)
                                update(w, h)

                                # case 3
                                #  4
                                # 341
                                # 341
                                #2221
                                w = max(w3 + w4 + w1, w2 + w1)
                                h = max(h1, h2 + h4, h2 + h3)
                                update(w, h)

                                # case 4
                                #  3
                                #1 34
                                #1224
                                #1224
                                # 224
                                
                                w = w1 + max(w2, w3) + w4
                                h = max(h1, h2 + h3, h4)
                                update(w, h)

                                # case 5 same as case 4?

                                # case 6
                                #  4333
                                #  4 22
                                #  4 22
                                # 11122
                                # 11122
                                
                                w = max(w3 + w4, w1 + w2, w2 + w4)
                                h = max(h1 + h4, h2 + h3, h1 + h3)
                                update(w, h)




                        
            
print(best, best_pairs)
fout.write(f"{best}\n")
for w, h in sorted(best_pairs):
    fout.write(f"{w} {h}\n")

fout.close()
