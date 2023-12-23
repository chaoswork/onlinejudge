"""
ID: huangch7
LANG: PYTHON3
TASK: lgame
"""


task_name = "lgame"
INF = 100000000


def get_ints_from_line():
    return [int(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()


fin = open(f'{task_name}.in', 'r')
fdict = open(f'{task_name}.dict', 'r')
fout = open(f'{task_name}.out', 'w')

inputs = fin.readline().strip()
inputs_cnt = {}
for x in inputs:
    if x not in inputs_cnt:
        inputs_cnt[x] = 0
    inputs_cnt[x] += 1

words = []

while True:
    word = fdict.readline().strip()
    if word == '.' or word == '':
        break
    words.append(word)

# print('read over')
word_base = {}

base = 1
for ch in 'abcdefghijklmnopqrstuvwxyz':
    word_base[ch] = base
    base *= 10
    

    
def get_index(word):
    res = 0
    for ch in word:
        res += word_base[ch]
    return res

score = {
    'q': 7, 'w': 6, 'e': 1, 'r': 2, 't': 2, 'y': 5, 'u': 4, 'i': 1, 'o': 3, 'p':5,
    'a': 2, 's': 1, 'd': 4, 'f': 6, 'g': 5, 'h': 5, 'j': 7, 'k': 6, 'l': 3,
    'z': 7, 'x': 7, 'c': 4, 'v': 6, 'b': 5, 'n': 2, 'm': 5
}


def get_score(word):
    res = 0
    for x in word:
        if x == ' ':
            continue
        res += score[x]
    return res


valid_words = []
# print(get_index(inputs))

def check_valid(word):
    valid = True
    cnt = {}
    for x in word:
        if x == ' ':
            continue
        if x not in inputs_cnt:
            valid = False
            break
        if x not in cnt:
            cnt[x] = 0
        cnt[x] += 1
        if cnt[x] > inputs_cnt[x]:
            valid = False
            break
    return valid
    
for word in words:
    if not check_valid(word):
        continue

    valid_words.append(word)
# print('single word over')
# print(len(valid_words))

best = 0
result = []

for i in range(len(valid_words)):
    cur_score = get_score(valid_words[i])
    if cur_score > best:
        best = cur_score
        result = [valid_words[i]]
    elif cur_score == best:
        result.append(valid_words[i])
            
    for j in range(i, len(valid_words)):
        new_word = valid_words[i] + " " + valid_words[j]
        if valid_words[j] < valid_words[i]:
            new_word = valid_words[j] + " " + valid_words[i]
        if not check_valid(new_word):
            continue
        cur_score = get_score(new_word)
        if cur_score > best:
            best = cur_score
            result = [new_word]
        elif cur_score == best:
            result.append(new_word)
        

fout.write(f"{best}\n")
for word in sorted(result):
    fout.write(word)
    fout.write('\n')

    
fout.close()
