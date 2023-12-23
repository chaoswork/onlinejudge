"""
ID: huangch7
LANG: PYTHON3
TASK: contact
"""

# topK using heap?

task_name = "contact"

fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

A, B, N = [int(x) for x in fin.readline().strip().split()]

signal = ""

while True:
    line = fin.readline().strip()
    if line == "":
        break
    signal += line

word_count = {}
for start in range(len(signal)):
    for length in range(A, B + 1):
        if start + length > len(signal):
            break
        word = signal[start: start + length]
        if word not in word_count:
            word_count[word] = 0
        word_count[word] += 1

word_count = sorted(word_count.items(), key=lambda x: (-x[1], len(x[0]), x[0]))

topk = []
for i in range(len(word_count)):

    word, freq = word_count[i]
    if len(topk) == 0:
        topk.append([freq, [word]])
    else:
        if freq == topk[-1][0]:
            topk[-1][1].append(word)
        else:
            if len(topk) == N:
                break
            topk.append([freq, [word]])
            
for i in range(len(topk)):
    fout.write(f"{topk[i][0]}\n")
    for j in range(0, len(topk[i][1]), 6):
        fout.write(" ".join(topk[i][1][j:j+6]) + "\n")
        
    


#fout.write(f"{ans}\n")
fout.close()
