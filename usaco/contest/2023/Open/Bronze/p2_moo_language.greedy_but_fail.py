import sys


INF = 100000000


def get_list_from_line(dtype=int):
    return [dtype(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()



fin = sys.stdin
fout = sys.stdout

T = get_list_from_line()[0]


def get_longest_without_conj(nouns, borrow, t_verbs, it_verbs, C):
    # n + itv
    ans1 = [0, [], nouns, borrow, t_verbs, it_verbs, C]
    if len(it_verbs):
        if len(nouns):
            ans1 = [2, [nouns[-1], it_verbs[-1]], nouns[:-1], borrow, t_verbs, it_verbs[:-1], C]
        elif len(borrow):
            ans1 = [1, [borrow[-1], it_verbs[-1]], nouns, borrow[:-1], t_verbs, it_verbs[:-1], C]

    # n + tv + n, ...
    ans2 = [0, [], nouns, borrow, t_verbs, it_verbs, C]
    if len(t_verbs):
        if len(nouns) >= 2:
            ans2 = [3, [nouns[-1], t_verbs[-1], nouns[-2]], nouns[:-2], borrow, t_verbs[:-1], it_verbs, C]
        elif len(nouns) == 1:
            if len(borrow):
                ans2 = [2, [nouns[-1], t_verbs[-1], borrow[-1]], nouns[:-1], borrow[:-1], t_verbs[:-1], it_verbs, C]
        elif len(nouns) == 0:
            if len(borrow) >= 2:
                ans2 = [1, [borrow[-1], t_verbs[-1], borrow[-2]], nouns, borrow[:-2], t_verbs[:-1], it_verbs, C]
        if ans2[0] > 0:
            # print('C, nouns', C, nouns)
            if C > 0 and len(nouns) > 0:
                left_nouns = ans2[2]
                left_borrow = ans2[3]
                left_C = ans2[6]
                can_borrow = min(left_C, len(left_nouns))
                ans2 = [ans2[0] + can_borrow, ans2[1], left_nouns[can_borrow:], left_borrow + left_nouns[:can_borrow], ans2[4], ans2[5], left_C - can_borrow]

    if ans1[0] >= ans2[0]:
        return ans1
    else:
        return ans2

def can_get_one(nouns, borrow, t_verbs, it_verbs):
    if len(nouns) + len(borrow) >= 1 and len(it_verbs) >= 1:
        return True
    if len(nouns) + len(borrow) >= 2 and len(t_verbs) >= 1:
        return True
    return False

def get_longest(nouns, borrow, t_verbs, it_verbs, C, conns, P):
    ans = [[], "", [], nouns, borrow, t_verbs, it_verbs, C, conns, P]
    n, a, nouns, borrow, t_verbs, it_verbs, C = get_longest_without_conj(nouns, borrow, t_verbs, it_verbs, C)
    if len(conns) and can_get_one(nouns, borrow, t_verbs, it_verbs):
        n, b, nouns, borrow, t_verbs, it_verbs, C = get_longest_without_conj(nouns, borrow, t_verbs, it_verbs, C)
        return [a, conns[-1], b, nouns, borrow, t_verbs, it_verbs, C, conns[:-1], P - 1]

    return [a, "", [], nouns, borrow, t_verbs, it_verbs, C, conns, P - 1]

    # if P == 0:
    #     return ans
    # if len(conns) == 0:
    #     n, a, nouns, borrow, t_verbs, it_verbs, C = get_longest_without_conj(nouns, borrow, t_verbs, it_verbs, C)
    #     return [a, "", [], nouns, borrow, t_verbs, it_verbs, C, conns, P - 1]
    # else:
    #     # print('debug-borrow', borrow)
    #     # print('debug-f', get_longest_without_conj(nouns, borrow, t_verbs, it_verbs, C))
    #     n, a, nouns, borrow, t_verbs, it_verbs, C = get_longest_without_conj(nouns, borrow, t_verbs, it_verbs, C)
    #     # print('debug-borrow', n, a, nouns, borrow)
    #     # print('debug', a, nouns, borrow, t_verbs, it_verbs, C)
    #     n, b, nouns, borrow, t_verbs, it_verbs, C = get_longest_without_conj(nouns, borrow, t_verbs, it_verbs, C)
    #     # print('debug', a, b, nouns, borrow, t_verbs, it_verbs, C)
    #     # b = get_longest_without_conj(nouns, borrow, t_verbs, it_verbs, C)
    #     return [a, conns[-1], b, nouns, borrow, t_verbs, it_verbs, C, conns[:-1], P - 1]

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
    # print(get_longest_without_conj(nouns, [], t_verbs, it_verbs, C))
    # n: ['bessie', 'elsie', 'farmer', 'john', 'nhoj', 'bob', 'cow', 'elsie', 'bella', 'buttercup', 'envy', 'john', 'nhoj']
    # t:['taught', 'impressed', 'impressed', 'pushed']
    # it:['flew', 'mooed', 'leaped', 'mooed']
    # con:['but', 'and', 'and']
    # nhoj mooed. -> ['john', 'leaped'] 2
    # nhoj impressed john, farmer, elsie, bessie and cow impressed bob. -> ['nhoj', 'pushed', 'john'] con= and b= ['nhoj', 'pushed', 'john'], ['bessie', 'elsie', 'farmer'] 10
    # bella pushed elsie and buttercup flew. -> ['envy', 'impressed', 'buttercup'] con= and b= ['bella', 'impressed', 'elsie'] 6 7
    # envy mooed but john leaped. ->  ['cow', 'taught', 'bob'] con= but b= ['nhoj', 'mooed'] 5 6

    # n itv n itv tv

    # break
    # print(nouns, t_verbs, it_verbs, conns)
    borrow = []
    result = []
    while P:
        a, con, b, nouns, borrow, t_verbs, it_verbs, C, conns, P = \
            get_longest(nouns, borrow, t_verbs, it_verbs, C, conns, P)
        # print('a=', a, 'con=', con, 'b=', b, 'borrow=', borrow, 't_v=', t_verbs, 'itv=', it_verbs, 'C=', C, 'conns=', conns, 'P=', P)

        if len(a) == 0:
            break
        result.append([a, con, b])
    # print(len(result), result, borrow)
    lines = []
    n = 0
    for i in range(len(result)):
        ans = ""
        a, con, b = result[i]
        ans += ' '.join(a)
        n += len(a)

        if len(borrow) and len(a) == 3:
            ans += ", "
            ans += ", ".join(borrow)
            n += len(borrow)
            borrow = []


        if con:
            ans += ' '
            ans += ' '.join([con] + b)
            n += len(b) + 1

        if ans:
            ans += '.'
        lines.append(ans)

    fout.write(f'{n}\n')
    # print(len(' '.join(lines)))
    fout.write(' '.join(lines))
    fout.write('\n')

# nhoj mooed. nhoj impressed john, farmer, elsie, bessie and cow impressed bob. bella pushed elsie and buttercup flew. envy mooed but john leaped.
# nhoj pushed john bessie, elsie and envy impressed buttercup. bella impressed elsie and cow taught bob. nhoj mooed but john leaped. farmer mooed.
# if False:
#
#     if len(t_verbs) and len(nouns) >= 2:
#         v = t_verbs.pop()
#         na = nouns.pop()
#         nb = nouns.pop()
#         first = f"{na} {v} {nb}"
#
#         with_comma = nouns[:min(C, len(nouns))]
#         left = nouns[min(C, len(nouns)):]
#         with_and = []
#         if len(conns):
#
#             if len(it_verbs):
#                 if len(left):
#                     with_and = ' '.join([conns.pop(), left.pop(), it_verbs.pop()])
#                 elif len(with_comma):
#                     with_and = ' '.join([conns.pop(), with_comma.pop(), it_verbs.pop()])
#             elif len(t_verbs):
#                 if len(left) >= 2:
#                     na = left.pop()
#                     nb = left.pop()
#                     with_and = ' '.join([conns.pop(), na, t_verbs.pop(), nb])
#                 elif len(left) == 1:
#                     if len(with_comma):
#                         na = left.pop()
#                         nb = with_comma.pop()
#                         with_and = ' '.join([conns.pop(), na, t_verbs.pop(), nb])
#                 else:
#                     if len(with_comma) >= 2:
#                         na = with_comma.pop()
#                         nb = with_comma.pop()
#                         with_and = ' '.join([conns.pop(), na, t_verbs.pop(), nb])
#
#         ans_lines = [[first, with_comma, with_and]]
#         for _ in range(P - 1):
#             # find longest
#             if len(it_verbs):
#                 if len(left):
#                     with_and = ' '.join([conns.pop(), left.pop(), it_verbs.pop()])
#                 elif len(with_comma):
#                     with_and = ' '.join([conns.pop(), with_comma.pop(), it_verbs.pop()])
#             elif len(t_verbs):
#                 if len(left) >= 2:
#                     na = left.pop()
#                     nb = left.pop()
#                     with_and = ' '.join([conns.pop(), na, t_verbs.pop(), nb])
#                 elif len(left) == 1:
#                     if len(with_comma):
#                         na = left.pop()
#                         nb = with_comma.pop()
#                         with_and = ' '.join([conns.pop(), na, t_verbs.pop(), nb])
#                 else:
#                     if len(with_comma) >= 2:
#                         na = with_comma.pop()
#                         nb = with_comma.pop()
#                         with_and = ' '.join([conns.pop(), na, t_verbs.pop(), nb])
#
#
#
#
#
#
#     else:
#         valid = []
#         while len(t_verbs) and len(nouns):
#             valid.append(f"{nouns.pop()} {t_verbs.pop()}")
#
#         buff = []
#         while len(valid) >= 2 and len(conns):
#             s1 = valid.pop()
#             s2 = valid.pop()
#             c = conns.pop()
#             buff.append(f"{s1} {c} {s2}")
#         valid = sorted(valid + buff, key=lambda x: -len(x.split()))
#         ans_n = 0
#         ans_s = []
#         for i in range(min(P, len(valid))):
#             ans_n += len(valid[i].split())
#             ans_s.append(valid[i] + '.')
#         print('debug', nouns, t_verbs, it_verbs, conns, valid)
#         print(ans_n)
#         print(' '.join(ans_s))





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
