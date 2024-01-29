task_name = "traffic"
INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

N = get_list_from_line()[0]

limit = []
states = []


last_state = None
none_buf = []
onoff_buf = [0, 0]
for _ in range(N):
    t, s, e = get_strs_from_line()
    s = int(s)
    e = int(e)

    if t == 'none':
        if last_state is not None and last_state != 'none':
            limit.append(onoff_buf)
            states.append('onoff')
            onoff_buf = [0, 0]
        if len(none_buf) == 0:
            none_buf = [s, e]
        else:
            none_buf = [max(s, none_buf[0]), min(e, none_buf[1])]
    else:
        if last_state is not None and last_state == 'none':
            limit.append(none_buf)
            states.append('none')
            none_buf = []
        if t == 'on':
            onoff_buf[0] += s
            onoff_buf[1] += e
        else:
            onoff_buf[0] -= e
            onoff_buf[1] -= s
    last_state = t

if len(none_buf):
    limit.append(none_buf)
    states.append('none')
    none_buf = []
else:
    limit.append(onoff_buf)
    states.append('onoff')
    onoff_buf = [0, 0]
    
# print(limit)
# print(states)
# print(none_buf)
# print(onoff_buf)

start = 0 if states[0] == 'none' else 1
ans_out = [limit[start][0], limit[start][1]]
for i in range(start + 1, len(states)):
    if states[i] == 'none':
        ans_out = [max(ans_out[0], limit[i][0]),
                   min(ans_out[1], limit[i][1])]
    else:
        ans_out[0] += limit[i][0]
        ans_out[1] += limit[i][1]
        ans_out = [max(ans_out[0], 0), max(ans_out[1], 1)]

# print(ans_out)
            
start = len(states) - 1 if states[-1] == 'none' else len(states) - 2
# print(start, limit)
ans_in = [limit[start][0], limit[start][1]]
for i in range(start - 1, -1, -1):
    if states[i] == 'none':
        ans_in = [max(ans_in[0], limit[i][0]),
                  min(ans_in[1], limit[i][1])]
    else:
        ans_in[0] -= limit[i][1]
        ans_in[1] -= limit[i][0]
        ans_in = [max(ans_in[0], 0), max(ans_in[1], 1)]

# print(ans_in)

fout.write(f"{ans_in[0]} {ans_in[1]}\n")
fout.write(f"{ans_out[0]} {ans_out[1]}\n")
# 5 6 -2 -3
# 2 4

# 2 3 -5 -6
# -4 -2

# 3 5 -3 -2
# 
            
fout.close()        
        
    





        
