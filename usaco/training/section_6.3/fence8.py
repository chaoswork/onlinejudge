"""
ID: huangch7
LANG: PYTHON3
TASK: fence8
"""



task_name = "fence8"
INF = 100000000


def get_int():
    return int(fin.readline())

def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

# This is a high dimensionality multiple knapsack problem, so we just have to test the cases. Given that the search space has a high out-degree, we will use depth first search with iterative deepening in order to limit the depth of the tree. However, straight DFSID will be too slow, so some tree-pruning is necessary.



boards = []
needs = []
N = get_int()
for _ in range(N):
    boards.append(get_int())

R = get_int()
for _ in range(R):
    needs.append(get_int())

for i in range(R):
    for j in range(i + 1, R):
        for k in range(j + 1, R):
            x = needs[i] + needs[j] + needs[k] 
            if x in boards:
                print(needs[i], needs[j], needs[k], x)
# 对于一个板子来说，只有N + 1种可能，不用，放在1， 放在2，..., 放在 N

dp = 0
# dp[r][v1...vn] 表示前r个物品，第r件物品放到了第n个箱子里，当前箱子容量为v1..vn的状态时，最多有几件.
# 似乎没发保证互斥。

fout.close()

