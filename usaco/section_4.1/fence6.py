"""
ID: huangch7
LANG: PYTHON3
TASK: fence6
"""


task_name = "fence6"
INF = 100000000


def get_ints_from_line():
    return [int(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()


fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

adj = {}
length = {}

N = int(fin.readline())

for _ in range(N):
    s, l, n1, n2 = get_ints_from_line()
    length[s] = l
    edges_in = get_ints_from_line()
    edges_out = get_ints_from_line()
    adj[s] = (edges_in, edges_out)

best = INF
fence_to_remove = set()
for sid in adj:
    # remove duplicate fence
    dups = set(adj[sid][0]) & set(adj[sid][1])
    for dup_sid in dups:
        if best is None or best > length[sid] + length[s]:
            best = length[sid] + length[s]
    dups.add(s)
    dups = sorted(dups, key=lambda x: length[x])
    fence_to_remove = fence_to_remove.union(set(dups[1:]))

for sid in fence_to_remove:
    del adj[sid]
for sid in adj:
    adj[sid] = ([x for x in adj[sid][0] if x not in fence_to_remove],
                [x for x in adj[sid][1] if x not in fence_to_remove])

# let the red/blue in the right way
# 0 for red, 1 for blue
node_index = 0
nodes = {sid: [None, None] for sid in adj}
adj_nodes = {}


for sid in adj:
    if nodes[sid][0] is not None and nodes[sid][1] is not None:
        continue
    for i in adj[sid][0]:
        if sid in adj[i][0] and nodes[i][0] is not None:
            nodes[sid][0] = nodes[i][0]
        if sid in adj[i][1] and nodes[i][1] is not None:
            nodes[sid][0] = nodes[i][1]
    for i in adj[sid][1]:
        if sid in adj[i][0] and nodes[i][0] is not None:
            nodes[sid][1] = nodes[i][0]
        if sid in adj[i][1] and nodes[i][1] is not None:
            nodes[sid][1] = nodes[i][1]
    if nodes[sid][0] is None:
        nodes[sid][0] = node_index
        node_index += 1
    if nodes[sid][1] is None:
        nodes[sid][1] = node_index
        node_index += 1

    if nodes[sid][0] not in adj_nodes:
        adj_nodes[nodes[sid][0]] = {}
    if nodes[sid][1] not in adj_nodes:
        adj_nodes[nodes[sid][1]] = {}
    adj_nodes[nodes[sid][0]][nodes[sid][1]] = length[sid]
    adj_nodes[nodes[sid][1]][nodes[sid][0]] = length[sid]


for i in range(len(adj_nodes)):
    for j in adj_nodes[i]:
        # surpose ij is broken
        old_dist = adj_nodes[i][j]
        adj_nodes[i][j] = INF
        adj_nodes[j][i] = INF
        # found the shortest path of i,j
        dist = [INF] * len(adj_nodes)
        dist[i] = 0
        visited = [0] * len(adj_nodes)
        for _ in range(len(adj_nodes)):
            min_node = None
            min_value = INF
            for k in range(len(adj_nodes)):
                if visited[k]:
                    continue
                if min_value > dist[k]:
                    min_value = dist[k]
                    min_node = k
            if min_node is not None:
                visited[min_node] = 1
                for k in adj_nodes[min_node]:
                    dist[k] = min(dist[k], dist[min_node] + adj_nodes[min_node][k])
        if best > dist[j] + old_dist:
            best = dist[j] + old_dist
        # change the dist back
        adj_nodes[i][j] = old_dist
        adj_nodes[j][i] = old_dist
        
fout.write(f"{best}\n")
    
fout.close()
