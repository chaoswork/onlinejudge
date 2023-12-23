"""
ID: huangch7
LANG: PYTHON3
TASK: msquare
"""

task_name = "msquare"

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

target = tuple([int(x) for x in fin.readline().strip().split()])

nodes = set()
adj = {}

def transformA(x):
    # 1234  8765
    # 8765  1234
    return x[4:][::-1] + x[:4][::-1]

def transformB(x):
    # 1234  4123
    # 8765  5876
    return x[3:4] + x[:3] + x[5:] + x[4:5]

def transformC(x):
    # 1234  1724
    # 8765  8635
    return (x[0], x[6], x[1], x[3], x[4], x[2], x[5], x[7])

def display_square(x):
    print(x[:4])
    print(list(reversed(x[4:])))

# display_square(transformA((1, 2, 3, 4, 5, 6, 7, 8)))
# display_square(transformB((1, 2, 3, 4, 5, 6, 7, 8)))
# display_square(transformC((1, 2, 3, 4, 5, 6, 7, 8)))

def dfs(cur, left):
    if len(left) == 0:
        # print(cur)
        key = tuple(cur)
        nodes.add(key)
        if key not in adj:
            adj[key] = {}
        for func in [transformA, transformB, transformC]:
            neighbour = tuple(func(cur))
            adj[key][neighbour] = 1
            
        return

    for i in range(len(left)):
        dfs(cur + [left[i]], left[:i] + left[i + 1:]) 

    
# dfs([], [1, 2, 3])
start = tuple([1, 2, 3, 4, 5, 6, 7, 8])
visited = set([start])


# current node, distane, ans answer
buff = [(start, 0, "")]
found = False
while True:
    if found:
        break
    new_buff = []
    for node in buff:
        if node[0] == target:
            #print(node)
            fout.write(f"{node[1]}\n")
            if node[1] == 0:
                fout.write("\n")
            for i in range(0, len(node[2]), 60):
                fout.write(f"{node[2][i:i+60]}\n")
            found = True
            break
        else:
            for func, action in [(transformA, 'A'), (transformB, 'B'), (transformC, 'C')]:
                node_neighbour = func(node[0])
                if node_neighbour in visited:
                    continue
                new_buff.append((node_neighbour, node[1] + 1, node[2] + action))
                visited.add(node_neighbour)
    buff = new_buff
            



            
            

            


fout.close()
