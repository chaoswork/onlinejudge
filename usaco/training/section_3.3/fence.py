"""
ID: huangch7
LANG: PYTHON3
TASK: fence
"""



task_name = "fence"

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N = int(fin.readline())
edges = {}
for _ in range(N):
    a, b = [int(x) for x in fin.readline().split()]
    if a not in edges:
        edges[a] = []
    edges[a].append(b)
    if b not in edges:
        edges[b] = []
    edges[b].append(a)

for x in edges:
    edges[x] = sorted(edges[x])

ans = []

def eulerian_tour(node):
    while len(edges[node]):
        neighbour = edges[node].pop(0)
        del edges[neighbour][edges[neighbour].index(node)]
        eulerian_tour(neighbour)
    ans.append(node)


    
start = None
for x in edges:
#    print(x, len(edges[x]))
    if len(edges[x]) & 1:
        if start is None or start > x:
            start = x
        
if start is None:
    start = min(edges.keys())
    
# eulerian_tour(start)

stack = [start]
while len(stack):
    node = stack[-1]
    if len(edges[node]) == 0:
        ans.append(node)
        stack.pop()
    else:
        neighbour = edges[node].pop(0)
        del edges[neighbour][edges[neighbour].index(node)]
        stack.append(neighbour)
            

for x in reversed(ans):
    fout.write(f"{x}\n")

fout.close()
