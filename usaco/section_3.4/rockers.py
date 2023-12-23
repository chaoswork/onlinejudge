"""
ID: huangch7
LANG: PYTHON3
TASK: rockers
"""


task_name = "rockers"
INF = 100000000


def get_ints_from_line():
    return [int(x) for x in fin.readline().strip().split()]


def get_strs_from_line():
    return fin.readline().strip().split()


fin = open(f'{task_name}.in', 'r')
fout = open(f'{task_name}.out', 'w')

n, t, m = get_ints_from_line()
songs = get_ints_from_line()

best = 0
visited = set()
cache = {}

def search(disks, songs, fill):
    global best
    if fill + len(songs) < best:
        return
    if len(songs) == 0 or len(disks) == 0:
        if best < fill:
            best = fill
        return
    key = (tuple(disks), tuple(songs))
#    if key in visited:
#         return
    visited.add(key)
    # copy the song
    if disks[0] >= songs[0]:
        left = disks[0] - songs[0]
        if left == 0:
            search(disks[1:], songs[1:], fill + 1)
        else:
            search([left] + disks[1:], songs[1:], fill + 1)
    # drop the song
    search(disks, songs[1:], fill)
    # move to next disk
    search(disks[1:], songs, fill)

def dp(disks, songs):
    global best
#    if fill + len(songs) < best:
#        return
    if len(songs) == 0 or len(disks) == 0:
        return 0
    key = (tuple(disks), tuple(songs))
    if key in cache:
        return cache[key]
    ans = 0
    # copy the song
    if disks[0] >= songs[0]:
        left = disks[0] - songs[0]
        if left == 0:
            ans = max(ans, dp(disks[1:], songs[1:]) + 1)
        else:
            ans = max(ans, dp([left] + disks[1:], songs[1:]) + 1)
    # drop the song
    ans = max(ans, dp(disks, songs[1:]))
    # move to next disk
    ans = max(ans, dp(disks[1:], songs))

    cache[key] = ans
    if best < cache[key]:
        best = cache[key]
    return cache[key]
    
dp([t] * m, songs)

# print(best)

fout.write(f"{best}\n")



    
fout.close()
