



T = int(input())

for _ in range(T):
    nouns = []
    t_verbs = []
    it_verbs = []
    conns = []

    N, C, P = map(int, input().split())
    for _ in range(N):
        word, tp = input().strip().split()
        if tp == 'conjunction':
            conns.append(word)
        elif tp == 'noun':
            nouns.append(word)
        elif tp == 'transitive-verb':
            t_verbs.append(word)
        else:
            it_verbs.append(word)
    best = 0
    best_str = ""
    # t1: #type 1 verb
    for t1 in range(len(it_verbs) + 1):
        # t2: type2 verb
        for t2 in range(len(t_verbs) + 1):
            
            if t1 + 2 * t2 > len(nouns):
                continue
            cur_words = 2 * t1 + 3 * t2
            # t1 + t2 sentences now
            # add conjunction
            nc = min((t1 + t2) // 2, len(conns))
            cur_words += nc
            # t1 + t2 - nc sentences now
            # add periods.
            if t1 + t2 - nc > P:
                continue
            # add comma
            nco = 0
            if t2:
                nco = min(C, len(nouns) - t1 - 2 * t2)
            cur_words += nco
            if best < cur_words:
                best = cur_words
                sentences = []
                sentences += [f"{x} {y}" for x, y in zip(nouns[:t1], it_verbs[:t1])]
                for i in range(t2):
                    sentences.append(" ".join([nouns[t1 + 2 * i], t_verbs[i], nouns[t1 + 2 * i + 1]]))
                comma_list = nouns[t1 + t2 * 2:][:nco]
                if t2 and len(comma_list):
                    for i in range(len(comma_list)):
                        sentences[-1] += ", " + comma_list[i]
                
                lines = []
                for i in range(nc):
                    lines.append(sentences[i * 2] + " " + conns[i] + " " + sentences[i * 2 + 1])
                lines += sentences[2 * nc:]
                # print(lines)
                lines = [x + "." for x in lines]
                ans = " ".join(lines)
                # print(ans)
                best_str = ans
                


                    
    print(best)            
            
    print(best_str)
            
    
