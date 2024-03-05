import sys


INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = sys.stdin
fout = sys.stdout

T = get_list_from_line()[0]

for _ in range(T):
    nouns = []
    t_verbs = []
    it_verbs = []
    conns = []
    N, C, P = get_list_from_line()
    for _ in range(N):
        word, tp = get_strs_from_line()
        if tp == 'conjunction':
            conns.append(word)
        elif tp == 'noun':
            nouns.append(word)
        elif tp == 'transitive-verb':
            t_verbs.append(word)
        else:
            it_verbs.append(word)
    # valid but without punc

    if len(t_verbs) and len(nouns) >= 2:
        v = t_verbs.pop()
        na = nouns.pop()
        nb = nouns.pop()
        first = f"{na} {v} {nb}"

        with_comma = nouns[:min(C, len(nouns))]
        left = nouns[min(C, len(nouns)):]
        with_and = []
        if len(conns):

            if len(it_verbs):
                if len(left):
                    with_and = ' '.join([conns.pop(), left.pop(), it_verbs.pop()])
                elif len(with_comma):
                    with_and = ' '.join([conns.pop(), with_comma.pop(), it_verbs.pop()])
            elif len(t_verbs):
                if len(left) >= 2:
                    na = left.pop()
                    nb = left.pop()
                    with_and = ' '.join([conns.pop(), na, t_verbs.pop(), nb])
                elif len(left) == 1:
                    if len(with_comma):
                        na = left.pop()
                        nb = with_comma.pop()
                        with_and = ' '.join([conns.pop(), na, t_verbs.pop(), nb])
                else:
                    if len(with_comma) >= 2:
                        na = with_comma.pop()
                        nb = with_comma.pop()
                        with_and = ' '.join([conns.pop(), na, t_verbs.pop(), nb])
            
        ans_lines = [[first, with_comma, with_and]]
        for _ in range(P - 1):
            # find longest
            if len(it_verbs):
                if len(left):
                    with_and = ' '.join([conns.pop(), left.pop(), it_verbs.pop()])
                elif len(with_comma):
                    with_and = ' '.join([conns.pop(), with_comma.pop(), it_verbs.pop()])
            elif len(t_verbs):
                if len(left) >= 2:
                    na = left.pop()
                    nb = left.pop()
                    with_and = ' '.join([conns.pop(), na, t_verbs.pop(), nb])
                elif len(left) == 1:
                    if len(with_comma):
                        na = left.pop()
                        nb = with_comma.pop()
                        with_and = ' '.join([conns.pop(), na, t_verbs.pop(), nb])
                else:
                    if len(with_comma) >= 2:
                        na = with_comma.pop()
                        nb = with_comma.pop()
                        with_and = ' '.join([conns.pop(), na, t_verbs.pop(), nb])
            ans_lines.append([
                            
                
        
        
        
    else:
        valid = []
        while len(t_verbs) and len(nouns):
            valid.append(f"{nouns.pop()} {t_verbs.pop()}")

        buff = []
        while len(valid) >= 2 and len(conns):
            s1 = valid.pop()
            s2 = valid.pop()
            c = conns.pop()
            buff.append(f"{s1} {c} {s2}")
        valid = sorted(valid + buff, key=lambda x: -len(x.split()))
        ans_n = 0
        ans_s = []
        for i in range(min(P, len(valid))):
            ans_n += len(valid[i].split())
            ans_s.append(valid[i] + '.')
        print('debug', nouns, t_verbs, it_verbs, conns, valid)
        print(ans_n)
        print(' '.join(ans_s))
        
        



    ######## first try
    # valids_a = []
    # while len(t_verbs):
    #     v = t_verbs.pop()
    #     if len(nouns) == 0:
    #         break
    #     valids_a.append(f"{nouns.pop()} {v}")
    # print('debug', nouns, t_verbs, it_verbs, conns, valids_a)        
    # valids_b = []
    # while len(it_verbs):
    #     v = it_verbs.pop()
    #     if len(nouns) < 2:
    #         break
    #     na = nouns.pop()
    #     nb = nouns.pop()
    #     valids_b.append(f"{na} {v} {nb}")
    # print('debug', nouns, t_verbs, it_verbs, conns, valids_a, valids_b)
    # if len(valids_b):
    #     n_left = len(nouns)
    #     for _ in range(min(C, n_left)):
    #         valids_b[-1] += f", {nouns.pop()}"
    #         
    # if len(nouns) == 1 and len(it_verbs) and len(valids_a):
    #     word, v = valids_a.pop()
    #     valids_b.append(f"{word} {it_verbs.pop()} {nouns[0]}")
    #     nouns = []
    #     t_verbs.append(v)
    # 
    #     
    # valid = sorted(valids_a + valids_b, key=lambda x: -len(x.split()))
    # # conns
    # buff = []
    # while len(valid) >= 2 and len(conns):
    #     s1 = valid.pop()
    #     s2 = valid.pop()
    #     c = conns.pop()
    #     buff.append(f"{s1} {c} {s2}")
    # valid = sorted(valid + buff, key=lambda x: -len(x.split()))
    # ans_n = 0
    # ans_s = []
    # for i in range(min(P, len(valid))):
    #     ans_n += len(valid[i].split())
    #     ans_s.append(valid[i] + '.')
    # print('debug', nouns, t_verbs, it_verbs, conns, valid)
    # print(ans_n)
    # print(' '.join(ans_s))
         
                   
    
    
fout.close()
