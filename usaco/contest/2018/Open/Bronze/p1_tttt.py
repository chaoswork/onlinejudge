task_name = "tttt"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

ttt = []
for _ in range(3):
    ttt.append(fin.readline().strip())

def check_win(ttt, players,  as_same=[]):
    shadow = {x: x for x in players}
    ans = set()
    if len(as_same):
        shadow[as_same[0]] = as_same[1]
    for i in range(3):
        if shadow[ttt[i][0]] == shadow[ttt[i][1]] == shadow[ttt[i][2]]:
            if len(as_same) == 0 or (len(set(ttt[i])) > 1):
                ans.add(shadow[ttt[i][0]])
        if shadow[ttt[0][i]] == shadow[ttt[1][i]] == shadow[ttt[2][i]]:
            if len(as_same) == 0 or (len(set([ttt[0][i], ttt[1][i], ttt[2][i]])) > 1):
                ans.add(shadow[ttt[0][i]])
    if shadow[ttt[0][0]] == shadow[ttt[1][1]] == shadow[ttt[2][2]]:
        if len(as_same) == 0 or (len(set([ttt[0][0], ttt[1][1], ttt[2][2]])) > 1):
            ans.add(shadow[ttt[1][1]])
    if shadow[ttt[2][0]] == shadow[ttt[1][1]] == shadow[ttt[0][2]]:
        if len(as_same) == 0 or (len(set([ttt[2][0], ttt[1][1], ttt[0][2]])) > 1):
            ans.add(shadow[ttt[1][1]])

    return ans
    

players = list(set(ttt[0]) | set(ttt[1]) | set(ttt[2]))

fout.write(f"{len(check_win(ttt, players))}\n")

pair_cnt = 0
for i in range(len(players)):
    for j in range(i + 1, len(players)):
        if len(check_win(ttt, players, as_same=[players[i], players[j]])):
            print(players[i], players[j])
            pair_cnt += 1

fout.write(f"{pair_cnt}\n")

fout.close()        
        
    





        
